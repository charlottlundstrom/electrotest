#include <stdlib.h>
#include <stdio.h>
#include "libcomponent.h"

int antal
float totRes
float resistors[3];
float *val_pekare=&resistors[0];
float *res_array
int main() {
	printf("Ersättningsresistansen [Ohm] : ");
	if (scanf("%f", &totRes)!=1) { printf ("Error - Inmatat värde är inte en integer\n"); return -1; }
	printf("Ersättningsresistanser i E12-serien kopplade i serie: ");
	for (antal = e_resistance(totRes, &resistors[0]); antal>0; antal--){
    /* avrundar till närmaste E12 och skriver ut utan decimal*/
		printf("%1.0f", *val_pekare++);
    /* behövs fler ersättningsresistanser? */
		if (antal>1)
			printf(", ");
	}
	printf("\n");
	}