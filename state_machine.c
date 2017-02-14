#include"state_machine.h"



void ev_button_pressed(elev_button_type_t buttonType, int floor) {
	qm_update_queue(buttonType, floor);
	elev_set_button_lamp(buttonType, floor, 1);


}

void ev_timeout() {
	elev_set_door_open_lamp(0);
}

void ev_floor_signal(int floor) {
	sm_last_floor = floor;
	qm_update_floor(floor);
	elev_set_floor_indicator(floor);
}

void ev_stop_button_pressed() {
	elev_set_motor_direction(0);
	elev_set_stop_lamp(1);
	if (elev_get_floor_sensor_signal() != -1) {//åpner døren hvis i etasje
		elev_set_door_open_lamp(1);
	}
	//slette queue
}
void ev_stop_button_released() {
	elev_set_stop_lamp(1);
	if (elev_get_floor_sensor_signal() != -1) {//åpner døren hvis i etasje
		dt_start_timer();
	}
	//opretter ny QM?
}
void sm_arrived_at_floor(floor) {
	elev_set_motor_direction(0);
	
}