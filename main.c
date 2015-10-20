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

    printf("Electrotest 2015 - linUM at UMU\n");

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


