#include "elev.h"
#include <stdio.h>
#include <stdbool.h>
#include "State_machine.h"
#include "Door_Timer.h"

void elevator_init();


int main() {
    // Initialize hardware
	elevator_init();

	bool timeout = true;

  while (true) {
		//sjekker om heisen ankommer en etasje
		if (elev_get_floor_sensor_signal() != -1) {
			ev_floor_signal(elev_get_floor_sensor_signal());
		}

		//sjekker etter knappetrykk
		for (int floor = 0; floor < N_FLOORS; floor++) {//itererer gjennom alle etasjer
			for (int button_type = 0; button_type <= 2; button_type++) {//iterer gjennom alle typer knapper
				if((button_type == BUTTON_CALL_UP && floor == (N_FLOORS - 1))||(button_type == BUTTON_CALL_DOWN && floor == 0)) {
					continue;
					}
				if (elev_get_button_signal(button_type, floor)) {
					ev_button_pressed(button_type, floor);
				}
			}
		}
        
        if(elev_get_stop_signal()){
            while(elev_get_stop_signal()){
                ev_stop_button_pressed();
            }
            ev_stop_button_released();
        }

		//sjekker timeout

		if (dt_is_timeout() && !timeout) {
			ev_timeout();
			printf("timeout \n");
			timeout = true;
		}else {
			timeout = dt_is_timeout();
		}


		sm_go_to_floor();


    }

		qm_delete_queue();
		free(qm_order_list);
		qm_order_list = NULL;

    return 0;
}


void elevator_init() {
	if (!elev_init()) {
		printf("Unable to initialize elevator hardware!\n");
	}
	while (elev_get_floor_sensor_signal() == -1)
	{
		elev_set_motor_direction(1);
	}
	elev_set_motor_direction(0);
	qm_init_queue();
    sm_init_sm();

	sm_stop =0;
}
