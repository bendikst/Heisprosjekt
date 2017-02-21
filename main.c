#include "elev.h"
#include <stdio.h>
#include <stdbool.h>
#include "state_machine.h"
#include "Door_Timer.h"

void elevator_init();


int main() {
    // Initialize hardware
	elevator_init();

    while (true) {
		//sjekker om heisen ankommer en etasje
		if (elev_get_floor_sensor_signal()) {
			ev_floor_signal(elev_get_floor_sensor_signal());
		}

		//sjekker etter knappetrykk
		for (int i = 0; i < N_FLOORS; i++) {//itererer gjennom alle etasjer
			for (int j = 0; j <= 2; j++) {//iterer gjennom alle typer knapper
				if (elev_get_button_signal(j, i)) {
					ev_button_pressed(j, i);
				}
			}
		}

		//sjekker timeout
		if (dt_is_timeout()) {
			ev_timeout();
		}



    }

    return 0;
}

void elevator_init() {
	if (!elev_init()) {
		printf("Unable to initialize elevator hardware!\n");
		return 1;
	}
	while (elev_get_floor_sensor_signal() == -1)
	{
		elev_set_motor_direction(1);
	}
	elev_set_motor_direction(0);
}
