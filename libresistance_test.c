#include <stdio.h>
#include "libresistance.h"

int main() {
    int count = 3;
    char conn = 'p';
    float array[] = {25, 35, 70};

    float resistance = calc_resistance(count, conn, array);

    printf("Test program for libresistance \n");
    printf("%f", resistance);
    printf("\nEnd.");

    return (1);

}