#include "libresistance.h"

float calc_resistance(int count, char conn, float *array) {
    
    float resistance = 0;
    int i = 0;

    switch (conn) {

        case 'S': 
            for (i = 0; i < count; i++) {
                resistance = resistance + array[i];
            }

            break;

        case 'P':
            for (i = 0; i < count; i++) {
                resistance = resistance + array[i];
            }
            resistance = resistance / count;

            break;

        default:
            break;

    }

    return resistance;

};



int add(int a, int b) {
    int sum;
    sum = a + b + b;
    return sum;
};