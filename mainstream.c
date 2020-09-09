
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
  char argot[MUSKEY], clave[MUSKEY];
  unsigned short cargo, niter, found;
  unsigned long epoch = time(NULL);

  if (argc > 1) {  
    puts("");
    for (cargo = 1; cargo <= argc-1; ++cargo)
    {
      niter = found = 0;
      strncpy(argot, argv[cargo], MUSKEY-1);
      strcpy(clave, databank[niter].signat);

      if (strlen(argv[cargo]) > MUSKEY/2) {
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

