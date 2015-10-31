#include <stdio.h>
#include "libresistance.h"

int main() {
    int count = 3;
    char conn = 'P';
    float array[] = {25, 35, 70};

    int resistance = calc_resistance(count, conn, array);

    printf("Test program for libresistance \n");
    printf("%d", resistance);
    printf("\nEnd.");

    return (1);

}