/**************************************
 * fork-zombie.c
 * 
 * Programme d'exemple d'utilisation de 
 * fork qui cr�e un zombie
 *
 *************************************/
///AAA
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main (int argc, char *argv[])  {
  pid_t pid;
  int err;

  pid=fork();

  if (pid==-1) {
    // erreur � l'ex�cution de fork
    perror("fork");
    exit(EXIT_FAILURE);
  }
  // pas d'erreur
  if (pid==0) {
    // fin du fils
    printf("pid du zombie: %d\n",getpid());
    return(EXIT_SUCCESS);
  }
  else {
    // processus p�re
    sleep(50);
    err=wait(NULL);
    if(err!=0) {
      perror("fork");
      exit(EXIT_FAILURE);
    }
    printf("Fin du processus p�re [%d]\n",getpid());
    return(EXIT_SUCCESS);
  }
}
///BBB
