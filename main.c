#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "libcomponent.h"
#include "libpower.h"
#include "libresistance.h"

int main() {
	int component_count;
	int i, antal;
	float totRes;
	float effekt, volt;
	char circuit_type = ' ';
	float resistors[3];
	float *val_pekare=&resistors[0];
	float *component_array;
    printf("Electrotest 2015 HT - linUM at UMU\n");
    printf("Ange spänningskälla (V): ");
    scanf("%f", &volt);
	do {
		printf("Ange koppling [s|p]: ");
		getchar();
		circuit_type = getchar();
        switch (circuit_type)
			{
                case 's':
                printf("Du valde s\n");
                break;
                case 'p':
                printf("Du valde p\n");
                break;
                default:
                break;
			}
	}	while (circuit_type!='p' && circuit_type !='s');
    printf("Ange antal komponenter: ");
    scanf("%d", &component_count);
	component_array = (float*)  malloc(sizeof(float) * component_count);
	// loop som endast visar de komponenter som behövs   
    for (i = 0; i < component_count; i++){
		printf("Ange resistans för komponent %d: ", i + 1);
        scanf("%f", &component_array[i]);
    }
    //anropa resistance-funktion
    float resistance = calc_resistance(component_count, circuit_type, component_array);
    printf("\nErsättningsresistans: %f Ohm\n", resistance);

    //anropa power funktion, skicka med värde från resistance-funktionen
    effekt = calc_power_r(volt, resistance);
    printf("Effekten är: %f Watt\n", effekt);
  
	totRes = resistance ;
	printf("Ersättningsresistanser i E12-serien kopplade i serie: ");
	for (antal = e_resistance(totRes, &resistors[0]); antal>0; antal--){
    /* avrundar till närmaste E12 och skriver ut utan decimal*/
		printf("%1.0f", *val_pekare++);
    /* behövs fler ersättningsresistanser? */
		if (antal>1)
			printf(", ");
	}
	printf("\n");
	free(component_array);
    return (1); // För att gcc inte ska klaga på att main inte returnerar int.

}


