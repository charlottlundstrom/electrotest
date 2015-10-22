#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "libcomponent.h"
#include "libpower.h"
#include "libresistance.h"

void main() {
    /* 
    Just nu så genererar main en lista på resistor-värden i E12 serien. 
    Detta kanske bör kopieras och flyttas till libcomponent.c
    */
    
    int resistor_count = 25; // resistor values between 10 and 1000 ohm.
    // int resistor_count = 61; // resistor values between 10 and 1000000 (1M) ohm.
    
    int resistor_values[9999] = {10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82}; // The [9999] is just to make sure that there always is enough space in the array.
    int decade = 10;
    int i = 0;
    int j = 12;

// Detta är förslag till main, tänkt som ett upplägg att arbeta utifrån
    printf("Electrotest 2015 - linUM at UMU\n");
    printf("Ange spänningskälla: ");
    //scanna %f, &variabelNamn
    printf("Ange koppling [S|P]: ");
    //scanna %c, &variabelNamn
    printf("Ange antal komponenter: ");
    //scanna %d, &variabelNamn
    
    // loop som endast visar de komponenter som behövs
    printf("Ange Ohm för komponent 1: ");
    //scanna och spara
    printf("Ange Ohm för komponent 2: ");
    //scanna och spara
    printf("Ange Ohm för komponent 3: ");
    //scanna och spara
    
    //anropa resistance-funktion
    printf("Ersättningsresistans: %f Ohm\n", varNamn);
    
    //anropa power funktion, skicka med värde från resistance-funktionen
    printf("Effekt: %f Watt\n", varNamn);
  
    //anropa component
    printf("Ersättningsresistanser i E12-serien kopplade i serie: ");
    //loopa och skriv ut rätt antal ersättningsresistanser
//

    while (j < resistor_count) {
        
        for(i = 0; i <= 11; i++) 
        {
            resistor_values[j] = resistor_values[i] * decade;
            j++;
        }

        decade = decade * 10;

    }

    printf("E12 resistor values : ");
    for (i = 0; i < resistor_count; i++)
        printf("%d, ", resistor_values[i]);
    printf("\nEnd.");

    // int sum = add(1, 5);
    // printf("%d", sum);

}


