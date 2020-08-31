
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "scordatura.h"

void headstock(const char sequ[]);
void pegbox(const char sequ[], unsigned short span, unsigned short tune);

int main(int argc, char *argv[])
{
  unsigned short count, clave = 0;
  unsigned long epoch = time(NULL);

  if (argc > 1)
  {  
    puts("");
    for (count = 1; count <= argc-1; count++)
    {
      while(! strstr(databank[clave].signat, "EOF"))
      {
        if (strstr(databank[clave].signat, argv[count]))
        {
          printf("\t%s-i%lu\n", databank[clave].signat, epoch);
          headstock(databank[clave].course);
        }
        clave++;
      }
      clave = 0;
    }
  } else {
    puts("\n  Usage:\n");
    puts("\tgcc -o fingerboard mainstream.c -Wall\n");
    puts("\t./fingerboard n0 j236\n");
  }
 
  return 0;
}

void headstock(const char sequ[])
{
  unsigned short count, notes, span = strlen(sequ);

  unsigned short pitch[] = { BJ, FN, CN, GN, DN, AN, EN, BN, FK };

  notes = sizeof(pitch) / sizeof(pitch[0]);

  for (count = 0; count < notes; ++count)
    pegbox(sequ, span, pitch[count]);

  putchar('\n');
}

void pegbox(const char sequ[], unsigned short span, unsigned short tune)
{
  char course[CARLEN];

  strcpy(course, sequ + tune);
  strncat(course, sequ, tune);

  printf("\t%s\n", course);
}

