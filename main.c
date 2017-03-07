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
		//Pollinf for arrival at floors
		if (elev_get_floor_sensor_signal() != -1) {
			ev_floor_signal(elev_get_floor_sensor_signal());
		}

		//Polling for button press
		for (int floor = 0; floor < N_FLOORS; floor++) {//iterate through all floors
			for (int button_type = 0; button_type <= 2; button_type++) {//iterate throough all buttons
				if((button_type == BUTTON_CALL_UP && floor == (N_FLOORS - 1))||(button_type == BUTTON_CALL_DOWN && floor == 0)) {
					continue;//skip illegal buttons
					}
				if (elev_get_button_signal(button_type, floor)) {
					ev_button_pressed(button_type, floor);
				}
			}
		}
        
		//Polling for stop signal
        if(elev_get_stop_signal()){
            while(elev_get_stop_signal()){//stop all other activity while stop is pressed
                ev_stop_button_pressed();
            }
            ev_stop_button_released();
        }

		//poll for timeout
		if (dt_is_timeout() && !timeout) {
			ev_timeout();
			printf("timeout \n");
			timeout = true;
		}else {
			timeout = dt_is_timeout();
		}

		//drive elevator
		sm_go_to_floor();
    }
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
}
