#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "libcomponent.h"
#include "libpower.h"
#include "libresistance.h"


void main() {

    int i, component_count;
    char circuit_type;
    char *val;
    char *pointer_s = "s";
    char *pointer_p = "p";
    char input[3];

// Detta är förslag till main, tänkt som ett upplägg att arbeta utifrån
    printf("Electrotest 2015 - linUM at UMU\n");
    
    printf("Ange spänningskälla: ");
    //scanna %f, &variabelNamn

/*
    // Här följer användar indata för calc_resistance();
    printf("Ange koppling [s|p]: ");
    do {
        fgets(input, sizeof input, stdin);
        strtol(input, &val, 10);
        printf("Du har valt: %s \n", val);  // För felkontroll
        printf("s: %d\n", strcmp(pointer_s, val));   // För felkontroll
        printf("p: %d\n", strcmp(pointer_p, val));   // För felkontroll
    }
    while (strcmp(pointer_s, val) == 1 && strcmp(pointer_p, val) == 1); // Avsluta loopen om s eller p anges

    if (strcmp(pointer_s, val) == -1 && strcmp(pointer_p, val) == 1){   // s blir valt
        circuit_type = 's';
    }
    else {
        circuit_type = 'p';
    }

    printf("Ange antal komponenter: ");
    scanf("%d", &component_count);
    // Skapa en array av viss storlek.
    float component_array[component_count];

    // loop som endast visar de komponenter som behövs   
    for (i = 0; i < component_count; i++)
    {
        printf("Ange resistans för komponent %d: ", i + 1);
        scanf("%f", &component_array[i]);
    }

    for (i = 0; i < component_count; i++)
        printf("Komponent %d: %f ", i + 1, component_array[i]);
    //anropa resistance-funktion
    float resistance = calc_resistance(component_count, circuit_type, component_array);
    printf("\nErsättningsresistans: %f Ohm\n", resistance);

*/

    //anropa power funktion, skicka med värde från resistance-funktionen
    //printf("Effekt: %f Watt\n", varNamn);
  
    //anropa component
    printf("Ersättningsresistanser i E12-serien kopplade i serie: ");
    //loopa och skriv ut rätt antal ersättningsresistanser
//


    /* 
    Generera main lista på resistor-värden i E12 serien. 
    */
    int resistor_count = 25; // resistor values between 10 and 1000 ohm.
    // int resistor_count = 61; // resistor values between 10 and 1000000 (1M) ohm.
    
    int resistor_values[9999] = {10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82}; // The [9999] is just to make sure that there always is enough space in the array.
    int decade = 10;
    int j = 12;

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


