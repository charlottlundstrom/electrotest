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
<<<<<<< HEAD
	do {
		printf("Ange koppling [s|p]: ");
		getchar();
		circuit_type = getchar();
        switch (circuit_type)
			{
=======


    // Här följer användar indata för calc_resistance();
   // printf("Ange koppling [s|p]: ");
   // do {
    //    circuit_type = getchar();
    //    if (circuit_type != 's' || circuit_type != 'p') {
     //       printf("Felval, välj [s|p]: "); // Detta skrivs ut två gånger?! Varför?
     //   }
    //} while (circuit_type != 's' && circuit_type != 'p');
// Här följer förslag till ändring av koden så att det inte skrivs ut flera ggr
do {
  printf("Ange koppling [s|p]: ");
    scanf("%c", &circuit_type);
        getchar();
        switch (circuit_type)
        {
>>>>>>> 200111b58b3f8d9cc0f04be7f2a4a4c1b2b1ea51
                case 's':
                printf("Du valde s\n");
                break;
                case 'p':
                printf("Du valde p\n");
                break;
                default:
                break;
<<<<<<< HEAD
			}
	}	while (circuit_type!='p' && circuit_type !='s');
    printf("Ange antal komponenter: ");
    scanf("%d", &component_count);
	component_array = (float*)  malloc(sizeof(float) * component_count);
	// loop som endast visar de komponenter som behövs   
    for (i = 0; i < component_count; i++){
		printf("Ange resistans för komponent %d: ", i + 1);
=======
        }
} while (circuit_type!='p' && circuit_type !='s');
    printf("Ange antal komponenter: ");
    scanf("%d", &component_count);
    // Skapa en array med storleken component_count 
	// Ändrade till att använda malloc, ska se ut på detta sätt som jag fattat det, finns en free() i slutet av main som 
	// släpper allokeringen
	component_array = (float*)  malloc(sizeof(float) * count);

    // loop som endast visar de komponenter som behövs   
    for (i = 0; i < component_count; i++)
    {
        printf("Ange resistans för komponent %d: ", i + 1);
>>>>>>> 200111b58b3f8d9cc0f04be7f2a4a4c1b2b1ea51
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
<<<<<<< HEAD
=======
/*
    /* 
    Generera main lista på resistor-värden i E12 serien. 
    */
    // int resistor_count = 25; // resistor values between 10 and 1000 ohm.
    // int resistor_count = 61; // resistor values between 10 and 1000000 (1M) ohm.
    
   // int resistor_values[9999] = {10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82}; // The [9999] is just to make sure that there always is enough space in the array.
    // int decade = 10;
    // int j = 12;

    // while (j < resistor_count) {
        
       // for(i = 0; i <= 11; i++) 
        //{
          //  resistor_values[j] = resistor_values[i] * decade;
            // j++;
        // }

        // decade = decade * 10;

    // }

    // printf("E12 resistor values : ");
    // for (i = 0; i < resistor_count; i++)
      //  printf("%d, ", resistor_values[i]);
    // printf("\nEnd.");

    // int sum = add(1, 5);
    // printf("%d", sum);
>>>>>>> 200111b58b3f8d9cc0f04be7f2a4a4c1b2b1ea51
	free(component_array);
    return (1); // För att gcc inte ska klaga på att main inte returnerar int.

}


