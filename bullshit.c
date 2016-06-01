#include <stdlib.h>
#include <stdio.h>

#define LENGTH  (100)

int main (int argc, char ** argv)
{
  char* string = (char*) malloc (LENGTH * sizeof (char));
  int i = 0;

  for (i = 0; i < LENGTH; i++)
  {
    //from : http://stackoverflow.com/questions/19724346/generate-random-characters-in-c
    *(string + i) = (char) "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand () % 26];
  }
  printf ("%s\n", string);
  free (string);
  return 0;
}

  
