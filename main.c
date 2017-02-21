#include "elev.h"
#include <stdio.h>
#include<stdbool.h>

void elevator_init();


int main() {
    // Initialize hardware
	elevator_init();

    while (true) {


    }

    return 0;
}

void elevator_init() {
	if (!elev_init()) {
		printf("Unable to initialize elevator hardware!\n");
		return 1;
	}
	while (elev_get_floor_sensor_signal == -1)
	{
		elev_set_motor_direction(1);
	}
	elev_set_motor_direction(0);
}