
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "scordatura.h"

#ifndef MUSKEY
  #define MUSKEY 24
#endif

#ifndef CARLEN
  #define CARLEN 80
#endif

void headstock(const char *sequ);
char *pegbox(const char *sequ, char *yarn, unsigned short harp);


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

      if (strlen(argv[count]) > MUSKEY/2) {
        printf("\t%s ?\n\n", argot);
        continue;
      }

      while(strncmp(clave, "ETB", 3))
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
    while(strncmp(clave, "ETB", 3))
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


/* designate tuning */
void headstock(const char *sequ)
{
  static unsigned short tuned[] = { BJ, FN, CN, GN, DN, AN, EN, BN, FK };
  static unsigned short notes = sizeof(tuned) / sizeof(tuned[0]);
  unsigned short count;
  char yarn[CARLEN];

  for (count = 0; count < notes; ++count)
    puts(pegbox(sequ, yarn, tuned[count]));

  putchar('\n');
}


char *pegbox(const char *sequ, char *yarn, unsigned short harp)
{
  char cord[CARLEN];

  strcpy(cord, sequ + harp);
  strncat(cord, sequ, harp);

  sprintf(yarn, "\t%s", cord);
  return yarn;
}

