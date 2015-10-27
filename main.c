#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "libcomponent.h"
#include "libpower.h"
#include "libresistance.h"


int main() {

    int component_count;
  int count, i, antal;
  float totRes;
>>>>>>> upstream/master
    float effekt, volt;
    char circuit_type = ' '; //declare variable as character
	float resistors[3];
	float *val_pekare=&resistors[0];


// Detta är förslag till main, tänkt som ett upplägg att arbeta utifrån
    printf("Electrotest 2015 - linUM at UMU\n");
    
    printf("Ange spänningskälla (V): ");
    scanf("%f", &volt);


    // Här följer användar indata för calc_resistance();
    printf("Ange koppling [s|p]: ");
    do {
        circuit_type = getchar();
        if (circuit_type != 's' || circuit_type != 'p') {
            printf("Felval, välj [s|p]: "); // Detta skrivs ut två gånger?! Varför?
        }
    } while (circuit_type != 's' && circuit_type != 'p');

    printf("Ange antal komponenter: ");
    scanf("%d", &component_count);
    // Skapa en array med storleken component_count.
    float component_array[component_count];

    // loop som endast visar de komponenter som behövs   
    for (i = 0; i < component_count; i++)
    {
        printf("Ange resistans för komponent %d: ", i + 1);
        scanf("%f", &component_array[i]);
    }



    //anropa resistance-funktion
    float resistance = calc_resistance(component_count, circuit_type, component_array);
    printf("\nErsättningsresistans: %f Ohm\n", resistance);



    //anropa power funktion, skicka med värde från resistance-funktionen
    effekt = calc_power_r(volt, resistance);
    printf("Effekten är: %f Watt\n", effekt);
  
    //anropa component
   //  printf("Ersättningsresistanser i E12-serien kopplade i serie: ");
    //loopa och skriv ut rätt antal ersättningsresistanser
//
// enligt min deluppgift är det totRes som ersättningsresistansen ska heta
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

    return (1); // För att gcc inte ska klaga på att main inte returnerar int.

}


