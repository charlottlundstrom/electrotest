/* P=U*I dvs spänning gånger strömmen  */
#include "libpower.h"

float calc_power_i(float volt, float current) {
	float effect;
	effect = volt * current;
	return effect;

}
