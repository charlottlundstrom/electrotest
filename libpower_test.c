#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libpower.h"

int main (void) {
	float volt, current, resistance, effekt;
	char *val;
	char *pointer_m = "m";
	char *pointer_s = "s";
	char input[3];

	printf("Ange spänning: ");
	scanf("%f", &volt);
	printf("Du angav %.2f V \n", volt);

	printf("Välj motstånd eller ström (m/s): ");
	do {
		fgets(input, sizeof input, stdin);
		strtol(input, &val, 10);
/*		printf("Du har valt: %s \n", val);		// För felkontroll
		printf("s: %d\n", strcmp(pointer_s, val));
		printf("m: %d\n", strcmp(pointer_m, val));*/
	}
	while (strcmp(pointer_s, val) == 1 && strcmp(pointer_m, val) == 1);		/* Avsluta iteration om m eller s anges */

		if (strcmp(pointer_m, val) == -1 && strcmp(pointer_s, val) == 1){	/* m blir valt */
			printf("Ange motstånd: ");
			scanf("%f", &resistance);
			printf("Du angav %.2f Ohm\n", resistance);
			effekt = calc_power_r(volt, resistance);
			printf("Effekten är: %f Watt\n", effekt);
		}
		else {
			printf("Ange ström: ");						/* Alla andra situationer, dvs. s */
			scanf("%f", &current);
			printf("Du angav %.2f A \n", current);
			effekt = calc_power_i(volt, current);
			printf("Effekten är: %f Watt\n", effekt);
		}
	return 0;
}
