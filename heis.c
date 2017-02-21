//test
#include"elev.h"
#include "state_machine.h"

int main() {
		// Initialize hardware
	if (!elev_init()) {
		printf("Unable to initialize elevator hardware!\n");
		return 1;
	}
	initialize();
	while (1) {
		if (elev_get_floor_sensor_signal()) {
			ev_floor_signal(elev_get_floor_sensor_signal());
		}
		for (int i = 0; i < N_FLOORS; i++)//iterates through all floors
			for (int j = 0; j <= 2; j++) {//iterates through all button types
				if (elev_get_button_signal(j, i)) {
					ev_button_pressed(j, i);
				}
			}


	}


	return 0;
}