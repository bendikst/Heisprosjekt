//test
#include"elev.h"


int main() {
		// Initialize hardware
	if (!elev_init()) {
		printf("Unable to initialize elevator hardware!\n");
		return 1;
	}
	initialize();
	while (1) {
		if (elev_get_floor_sensor_signal()) {
			
		}

	}


	return 0;
}