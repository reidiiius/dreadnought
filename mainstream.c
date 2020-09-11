
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
char *pegbox(const char *cart, char *yarn, unsigned short harp);


int main(int argc, char *argv[])
{
  char clave[MUSKEY];
  unsigned short cargo, niter;
  unsigned long epoch = time(NULL);
  struct digraphs *prop;
  prop = databank;

  if (argc > 1) {
    char argot[MUSKEY];
    unsigned short found;

    putchar('\n');
    for (niter = 1; niter <= argc-1; ++niter)
    {
      cargo = strlen(argv[niter]);
      strncpy(argot, argv[niter], MUSKEY-1);

      if (cargo < 2 || cargo > MUSKEY/2) {
        printf("\t%s ?\n\n", argot);
        continue;
      } else {
        strcpy(clave, prop->signat);
      }

      while(strncmp(clave, "ETB", cargo))
      {
        found = 0;

        if (!strcmp(clave, argot)) {
          printf("\t%s-i%lu\n", clave, epoch);
          headstock(prop->course);
          ++found;
          break;
        }

        strcpy(clave, (++prop)->signat);
      }

      if (!found) printf("\t%s ?\n\n", argot);

      prop = &databank[0];
    }
  } else {
    niter = 0;
    strcpy(clave, prop->signat);
    cargo = strlen(clave);

    putchar('\n');
    while(strncmp(clave, "ETB", cargo))
    {
      if (++niter % 7 != 0) {
        printf("\t%s", clave);
      } else {
        printf("\t%s\n", clave);
      }

      strcpy(clave, (++prop)->signat);
      cargo = strlen(clave);
    }

    putchar('\n');
  }
 
  return 0;
}


/* designate tuning */
void headstock(const char *sequ)
{
  static unsigned short tuned[] = { BJ, FN, CN, GN, DN, AN, EN, BN, FK };
  static unsigned short notes = sizeof(tuned) / sizeof(tuned[0]);
  unsigned short pitch;
  char wire[CARLEN];

  for (pitch = 0; pitch < notes; ++pitch)
    puts(pegbox(sequ, wire, tuned[pitch]));

  putchar('\n');
}


char *pegbox(const char *cart, char *yarn, unsigned short harp)
{
  char cord[CARLEN];

  strcpy(cord, cart + harp);
  strncat(cord, cart, harp);

  sprintf(yarn, "\t%s", cord);
  return yarn;
}

