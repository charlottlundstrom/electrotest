#include <stdio.h>
#include <stdlib.h>

void main() {
    
    int resistor_count = 25; // resistor values between 10 and 1000 ohm.
    // int resistor_count = 61; // resistor values between 10 and 1000000 (1M) ohm.
    
    int resistor_values[9999] = {10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82};
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

    printf("E12 resistor values: ");
    for (i = 0; i < resistor_count; i++)
        printf("%d, ", resistor_values[i]);
    printf("\nEnd.");

    //return (0);

}


