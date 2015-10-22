/* P=U²/R dvs spänning i kvadrat delat i resistans  */
#include "libpower.h"

float calc_power_r(float volt, float resistance) {
	float effect;
	effect = (volt*volt)/resistance;
	return effect;
}
