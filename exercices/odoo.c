/**
* You have a huge file named "data.bin" that does not fit in memory, code a
* program that deletes every 7th byte of it, without opening other files.
* truncate can be used to change its size.
* Compile with : gcc -Wall -Werror -std=c99 -D_XOPEN_SOURCE=500 -o main odoo.c
**/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define N_BYTES (7)

int main(int argc, char** argv)
{
  char* buf = malloc(sizeof(6));
  long int old_offset;
  long int after_write_offset;
  // a counter to know the number of removed bytes
  long long int count = 0;
  long int file_size;

  if (argc < 2)
  {
    printf("Missing argument : filename\n");
    return -1;
  }

  FILE* f = fopen(argv[1], "rb+");
  if (!f)
  {
    perror("Error while opening file");
    return -1;
  }

  // get the size of the file
  fseek(f, 0, SEEK_END);
  file_size = ftell(f);

  // Set the file position to the beginning of the file
  fseek(f, SEEK_SET, 0);

  while(1) 
  {
    fseek(f, N_BYTES, SEEK_CUR);
    if (feof(f))
      break;
    old_offset = ftell(f);
    fgets(buf, N_BYTES, f);
    if (feof(f))
      break;
    fseek(f, old_offset-1, SEEK_SET);
    if (feof(f))
      break;
    fputs(buf, f);
    after_write_offset = ftell(f);
    if (feof(f))
      break;
    fseek(f, after_write_offset+1, SEEK_SET);
    if (feof(f))
      break;
    //Increment the counter of the amout of removed bytes
    count++;
  }
  //Now we can truncate the file to change its size :
  off_t to_remove = (off_t) (file_size - count);
  int tr = truncate(argv[1], to_remove);

  if (tr < 0)
  {
    perror("truncate error");
  }

  int err = fclose(f);
  if (err < 0)
  {
    perror("Error while closing file");
    return -1;
  }
  free(buf);

  return 0;
}

