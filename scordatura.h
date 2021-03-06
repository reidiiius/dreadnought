

#ifndef _SCORDATURA_H
#define _SCORDATURA_H  1

#ifndef _STDIO_H
  #include <stdio.h>
#endif

#ifndef _STRING_H
  #include <string.h>
#endif

#ifndef _TIME_H
  #include <time.h>
#endif

#define MUSKEY 24
#define CARLEN 80


void entryway(unsigned cargo, char **veils);

void syllabus(void);

void headstock(const char *sequ);

char *pegbox(unsigned harp, const char *cart, char *yarn);


enum enharmonic {
  BK =  0, CN =  0,
  CK =  3, DJ =  3,
  DN =  6,
  DK =  9, EJ =  9,
  EN = 12, FJ = 12,
  EK = 15, FN = 15,
  FK = 18, GJ = 18,
  GN = 21,
  GK = 24, AJ = 24,
  AN = 27,
  AK = 30, BJ = 30,
  BN = 33, CJ = 33
};


struct digraphs
{
  char signat[MUSKEY];
  char course[CARLEN];
}; 


struct digraphs databank[] = {
       {"z0", "__ __ __ __ __ __ __ __ __ __ __ __ "},
       {"j2", "vv zq __ __ ry wu __ uw __ sx __ qz "},
       {"j3", "vt __ tv xq __ ws __ uu __ sw __ qx "},
       {"j5", "wr __ ut __ sv oq qo __ __ tu __ rw "},
       {"j6", "vu __ tw __ rx wt __ uv yq __ __ qy "},
       {"k1", "__ qx vt __ tv xq __ ws __ uu __ sw "},
       {"k2", "yr __ __ qz vv zq __ xs __ wu __ uw "},
       {"k5", "xr __ wt __ uv yq __ __ qy vu __ tw "},
       {"k6", "vs __ tu __ rw wr __ ut __ __ oq qo "},
       {"n0", "vr __ tt __ rv wq __ us __ su __ qw "},
      {"j17", "__ __ tu __ rw wr __ ut __ sv oq qo "},
      {"j23", "vv zq __ xs __ wu __ uw __ sx __ qz "},
      {"j25", "qr vp __ __ pv rq wo __ __ yu __ ow "},
      {"j26", "vv zq __ __ ry wu __ uw yr __ __ qz "},
      {"j36", "vu __ tw xr __ wt __ uv yq __ __ qy "},
      {"j56", "xr __ wt __ uv yq so __ qy __ __ tw "},
      {"k12", "__ sx __ qz vv zq __ xs __ wu __ uw "},
      {"k15", "__ rx wt __ uv yq __ __ qy vu __ tw "},
      {"k25", "yr __ __ qz vv zq __ __ ry wu __ uw "},
      {"k26", "vp __ __ pv rq wo __ uy __ __ ow qr "},
      {"k34", "wr __ ut __ __ oq qo vs __ tu __ rw "},
      {"k56", "vu __ tw __ rx wt __ __ yq __ os qy "},
     {"j236", "vv zq __ xs __ wu __ uw yr __ __ qz "},
     {"j256", "qr vp __ __ pv rq wo __ uy __ __ ow "},
     {"j2k5", "qr vp __ __ pv rq __ __ uy yu __ ow "},
     {"j2k6", "vv zq __ __ ry wu __ uw __ __ ot qz "},
     {"j2l3", "vv zq to __ __ wu __ uw __ sx __ qz "},
     {"j3k5", "yr __ ot qz __ zq __ __ ry wu __ uw "},
     {"j3k6", "vo __ ty xu __ ww __ ux __ __ ov qq "},
     {"j5l6", "wr __ ut __ sv oq qo vs __ __ __ rw "},
     {"k125", "__ sx __ qz vv zq __ __ ry wu __ uw "},
     {"k1j5", "__ ux yt __ ov qq vo __ __ xu __ ww "},
     {"k1j6", "__ zq to __ ry wu __ uw yr __ __ qz "},
     {"k256", "vp __ __ pv rq wo __ __ yu __ ow qr "},
     {"k2j5", "yr __ __ qz vv zq to __ __ wu __ uw "},
     {"k2j6", "vp __ __ pv rq wo __ uy yu __ __ qr "},
     {"k2m1", "__ __ ot qz vv zq __ xs __ wu __ uw "},
     {"k6m5", "vs __ tu __ rw wr __ __ __ sv oq qo "},
     {"n167", "yr __ __ qz __ zq to __ ry wu __ uw "},
     {"n345", "__ zq __ __ ry wu __ uw yr __ ot qz "},
     {"n5l2", "vp __ __ pv rq __ __ uy yu __ ow qr "},
     {"n6m2", "qr vp __ __ pv rq wo __ uy yu __ __ "},
    {"j17l2", "vs __ __ __ rw wr __ ut __ sv oq qo "},
    {"j23k6", "vv zq __ xs __ wu __ uw __ __ ot qz "},
    {"j25l6", "or qp __ __ tv pq ro ws __ __ __ sw "},
    {"j26l3", "vv zq to __ __ wu __ uw yr __ __ qz "},
    {"j2k34", "or qp __ __ __ pq ro ws __ uu __ sw "},
    {"j2k56", "vv zq __ __ ry wu __ __ yr __ ot qz "},
    {"j34k6", "vt __ tv pq ro __ __ uu __ __ or qp "},
    {"j56l7", "xr __ wt __ uv yq so __ qy vu __ __ "},
    {"k12j5", "__ sx __ qz vv zq to __ __ wu __ uw "},
    {"k17j5", "or qp vt __ tv pq ro __ __ uu __ __ "},
    {"k2j17", "__ __ __ pq ro ws __ uu __ sw or qp "},
    {"k25m1", "__ __ ot qz vv zq __ __ ry wu __ uw "},
    {"k26m5", "vt __ __ pq ro ws __ __ __ sw or qp "},
    {"k2j56", "yr __ __ qz vv zq to __ ry __ __ uw "},
    {"k34m2", "wr __ __ __ sv oq qo vs __ tu __ rw "},
    {"k56m4", "vu __ tw __ rx __ __ uv yq __ os qy "},
    {"n25m6", "or qp vt __ __ pq ro ws __ __ __ sw "},
    {"n26l5", "__ __ tv pq ro ws __ __ __ sw or qp "},
    {"n45l2", "vo __ __ xu __ ww __ ux yt __ ov qq "},
    {"n67m2", "__ ux __ __ ov qq vo __ ty xu __ ww "},
   {"j136l7", "__ __ tw xr __ wt __ uv yq so __ qy "},
   {"j167l2", "vu __ __ __ rx wt __ uv yq __ os qy "},
   {"j246l3", "vv zq to __ ry __ __ uw yr __ __ qz "},
   {"j26l34", "vv zq to xs __ __ __ uw yr __ __ qz "},
   {"j2k6m5", "vv zq __ __ ry wu __ __ __ sx ot qz "},
   {"j2k6l3", "vv zq to __ __ wu __ uw __ __ ot qz "},
   {"j346l5", "yr __ ot qz vv zq __ __ ry __ __ uw "},
   {"j3k5m4", "vu __ tw xr __ __ __ uv yq so __ qy "},
   {"k135m4", "__ rx wt __ __ yq __ os qy vu __ tw "},
   {"k157m6", "vv zq to __ ry wu __ __ yr __ __ qz "},
   {"k1j6l7", "__ rx wt __ uv yq __ os qy vu __ __ "},
   {"k257m1", "yr __ ot qz vv zq __ __ ry wu __ __ "},
   {"k25m17", "__ sx ot qz vv zq __ __ ry wu __ __ "},
   {"k2j5m1", "__ __ ot qz vv zq to __ __ wu __ uw "},
   {"k2j5l6", "yr __ __ qz vv zq to xs __ __ __ uw "},
   {"k345m2", "xr __ __ __ uv yq so __ qy vu __ tw "},
   {"n167m4", "vu __ __ xr __ wt __ uv yq so __ qy "},
   {"n345l7", "__ rx __ __ uv yq __ os qy vu __ tw "},
  {"j2k56m4", "vv zq __ __ ry __ __ uw yr __ ot qz "},
  {"j3k56m4", "vo __ ty xu __ __ __ ux yt __ ov qq "},
  {"k1j56l7", "__ ux yt __ ov qq vo __ ty xu __ __ "},
  {"k2j56l7", "yr __ __ qz vv zq to __ ry wu __ __ "},
  {"ETB", ""}
};


#ifndef MUSKEY
  #define MUSKEY 24
#endif

#ifndef CARLEN
  #define CARLEN 80
#endif


void entryway(unsigned cargo, char **veils)
{
  char clave[MUSKEY];
  unsigned niter, quant;
  unsigned long epoch = time(NULL);
  struct digraphs *prop;
  prop = databank;

  if (cargo > 1) {
    if (strlen(veils[1]) > 8) {
      syllabus();
    } else { 
      char argot[MUSKEY];
      unsigned found;

      putchar('\n');
      for (niter = 1; niter <= cargo-1; ++niter)
      {
        strncpy(argot, veils[niter], MUSKEY-1);
        argot[MUSKEY-1] = '\0';
        quant = strlen(argot);

        if (quant > 1 && quant < MUSKEY/2) {
          strcpy(clave, prop->signat);
        } else {
          printf("\t%s ?\n\n", argot);
          continue;
        }

        while(strncmp(clave, "ETB", quant))
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
    }
  } else {
    niter = 0;
    strcpy(clave, prop->signat);
    quant = strlen(clave);

    putchar('\n');
    while(strncmp(clave, "ETB", quant))
    {
      if (++niter % 7 != 0) {
        printf("\t%s", clave);
      } else {
        printf("\t%s\n", clave);
      }

      strcpy(clave, (++prop)->signat);
      quant = strlen(clave);
    }

    putchar('\n');
  }
} 
 

void syllabus(void)
{
  unsigned crown, recount = sizeof(databank) / sizeof(databank[0]);
  unsigned long epoch = time(NULL);
  struct digraphs *prop;
  prop = databank;

  putchar('\n');
  for (crown = 0; crown < recount-1; ++crown) {
    printf("\t%s-i%lu\n", prop->signat, epoch);
    headstock(prop->course);
    ++prop;
  }
}


/* designate tuning */
void headstock(const char *sequ)
{
  unsigned narcs = strlen(sequ);

  if (narcs > 35 && narcs < 73) {
    static unsigned tuned[] = { BJ, FN, CN, GN, DN, AN, EN, BN, FK };
    static unsigned notes = sizeof(tuned) / sizeof(tuned[0]);
    char wire[CARLEN];
    unsigned pitch;

    for (pitch = 0; pitch < notes; ++pitch)
      puts(pegbox(tuned[pitch], sequ, wire));

  } else {
    printf("\tWidth: %u ?\n", narcs);
    printf("\tFile: %s\n", __FILE__);
    printf("\tLine: %d\n", __LINE__);
  }

  putchar('\n');
}


char *pegbox(unsigned harp, const char *cart, char *yarn)
{
  unsigned narcs = strlen(cart); 
  char cord[CARLEN];

  if (narcs > 35 && narcs < 73) {
    strcpy(cord, cart + harp);
    strncat(cord, cart, harp);
  } else {
    sprintf(cord, "Width: %u ?\n\tFile: %s\n\tLine: %d",
      narcs, __FILE__, __LINE__);
  }

  sprintf(yarn, "\t%s", cord);
  return yarn;
}


#endif /* scordatura.h */

