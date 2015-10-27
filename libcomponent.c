#include <stdio.h>
#include <stdlib.h>
/* finns 61 värden i serien mellan 10 ohm och 1 megaohm */
#define E12_MIN 10
#define E12_MAX 1000000
/* vilka e12 som finns att välja på och 10 multiplar av dem */
  int antal;
  float totRes=83;
  float resistors[3];
  float *val_pekare=&resistors[0];
  const float E12[]={10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82, 100};
  int hitta_E12_component(float value, float *res_pointer)

{
  const float *val_pekare = &E12[0];
  int tiopotens=1;
  int hittad = 0;

  *res_pointer=0;
 if (value > E12_MIN/2){
    hittad = 1;
    if (value > E12_MAX)
      *res_pointer = E12_MAX;
    else{
      while (value > 100){
	value /= 10;
	tiopotens *= 10;
      }
      while (value > *++val_pekare);
      *res_pointer = *(val_pekare-1) * tiopotens;
    }
  }
  return hittad;
}

  int e_resistance(float orig_resistance, float *res_array)
{
  int i, count=0;
  float log = 0.001;

  for (i=3; i>0; i--){
    if (orig_resistance  < 56 )
      log = 0.1;
    count += hitta_E12_component(orig_resistance*(1+log), res_array);
    orig_resistance -= *res_array++;
    log *=10;
    }

  return count;
}
