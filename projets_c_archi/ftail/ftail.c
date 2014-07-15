#include <sys/select.h>
#include <sys/inotify.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define EVENT_BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )

/*NICOLAS OOGHE SINF12BA*/

void *followFile(void *file)
{
	int fd; int wd;
	int r = 0;
	char buffer[EVENT_BUF_LEN];
	struct inotify_event *event;
	int i = 0;
	char c;
	FILE *fp;
	long pos;

	fd = inotify_init();


	if(fd<0)
	{
		perror("inotify_init");
		pthread_exit(0);
	}

	wd = inotify_add_watch(fd, file, IN_MODIFY);

	if(wd<0)
	{
		perror("inotify_add_watch");
		pthread_exit(0);
	}



	fp = fopen(file, "r");
	while(fgetc(fp)!=EOF);
	pos = ftell(fp);
	fclose(fp);
	while(1)
	{
	
				
		r = read(fd, buffer, EVENT_BUF_LEN);
		if(r<0)
		{
			perror("read");
			pthread_exit(0);
		}
		event = (struct inotify_event *) &buffer[i];

		if(event->mask & IN_MODIFY)
		{
			fp = fopen(file, "r");
			fseek(fp, pos, SEEK_SET);
			while((c=fgetc(fp))!=EOF)
			{
				printf("%c", c);
			}
			pos = ftell(fp);
			fclose(fp);
		}

	}
	pthread_exit(0);
}


int main(int argc, char *argv[])
{
	pthread_t th[argc-1];

	int k;
	for(k=1 ; k<argc ; k++)
	{
		pthread_create(&th[k-1], NULL, followFile, argv[k]);
	} 
	for(k=1 ; k<argc ; k++)
	{
		pthread_join(th[k-1], NULL);
	}
	return 0;
}

