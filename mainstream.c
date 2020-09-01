
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "scordatura.h"

void headstock(const char sequ[]);
void pegbox(const char sequ[], unsigned short span, unsigned short tune);


int main(int argc, char *argv[])
{
  unsigned short count, clave;
  unsigned long epoch = time(NULL);

  if (argc > 1) {  
    puts("");
    for (count = 1; count <= argc-1; count++)
    {
      while(! strstr(databank[clave].signat, "EOF"))
      {
        if (strstr(databank[clave].signat, argv[count])) {
          printf("\t%s-i%lu\n", databank[clave].signat, epoch);
          headstock(databank[clave].course);
        }
        clave++;
      }
      clave = 0;
    }
  } else {
    putchar('\n');
    while(! strstr(databank[clave].signat, "EOF"))
    {
      if (!clave) {
         ++clave;
        continue;
      } else if (clave % 7 != 0) {
        printf("\t%s", databank[clave].signat);
      } else {
        printf("\t%s\n", databank[clave].signat);
      }
      clave++;
    }
    printf("\t%s\n\n", databank[0].signat);
  }
 
  return 0;
}


/* designate matrix tuning */
void headstock(const char sequ[])
{
  static unsigned short pitch[] = { BJ, FN, CN, GN, DN, AN, EN, BN, FK };
  static unsigned short notes = sizeof(pitch) / sizeof(pitch[0]);
  unsigned short count, span = strlen(sequ);

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

