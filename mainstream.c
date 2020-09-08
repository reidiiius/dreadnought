
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "scordatura.h"

#ifndef MUSKEY
  #define MUSKEY 16
#endif

#ifndef CARLEN
  #define CARLEN 48
#endif

void headstock(const char sequ[]);
void pegbox(const char sequ[], unsigned short span, unsigned short tune);


int main(int argc, char *argv[])
{
  char argot[MUSKEY], clave[MUSKEY];
  unsigned short count, niter, found;
  unsigned long epoch = time(NULL);

  if (argc > 1) {  
    puts("");
    for (count = 1; count <= argc-1; ++count)
    {
      niter = found = 0;
      strncpy(argot, argv[count], MUSKEY-1);
      strcpy(clave, databank[niter].signat);

      if (strlen(argv[count]) > 8) {
        printf("\t%s ?\n\n", argot);
        continue;
      }

      while(strncmp(clave, "EOF", 3))
      {
        if (!strcmp(clave, argot)) {
          printf("\t%s-i%lu\n", clave, epoch);
          headstock(databank[niter].course);
          ++found;
          break;
        }

        strcpy(clave, databank[++niter].signat);
      }

      if (!found) printf("\t%s ?\n\n", argot);
    }
  } else {
    niter = 1;
    strcpy(clave, databank[niter].signat);

    putchar('\n');
    while(strncmp(clave, "EOF", 3))
    {
      if (niter % 7 != 0) {
        printf("\t%s", clave);
      } else {
        printf("\t%s\n", clave);
      }

      strcpy(clave, databank[++niter].signat);
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

