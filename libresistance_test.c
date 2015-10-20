#include <stdio.h>
#include "libresistance.h"

void main() {
    int count = 4;
    char conn = 'S';
    float array[] = {25, 35, 70, 50};

    int resistance = calc_resistance(count, conn, array);

    printf("Test program for libresistance \n");
    printf("%d", resistance);
    printf("\nEnd.");


}