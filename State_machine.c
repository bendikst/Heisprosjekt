#include"State_machine.h"


void ev_button_pressed(elev_button_type_t button, int floor) {
	qm_update_queue(button, floor);
	elev_set_button_lamp(button, floor, 1);
}


void ev_timeout(void) {
	elev_set_door_open_lamp(0);
	sm_stop = 0;
}


void ev_floor_signal(int floor) {
	sm_last_floor = floor;
  
	if(floor != -1) {
	  elev_set_floor_indicator(floor);
		if(floor == sm_target_floor){
			sm_arrived_at_target_floor(floor);
		}
	}
    qm_update_floor(floor);
}


void ev_stop_button_pressed(void) {
	sm_stop = 1;
	elev_set_motor_direction(0);
	elev_set_stop_lamp(1);

    //Turn off all lights
    for (int floor = 0; floor < N_FLOORS; floor++) {
	    for (int button_type = 0; button_type <= 2; button_type++) {
		    if((button_type == BUTTON_CALL_UP && floor == (N_FLOORS - 1))||(button_type == BUTTON_CALL_DOWN && floor == 0)) {
				continue;
				}
			elev_set_button_lamp(button_type, floor, 0);
		}
	}
    
	if (elev_get_floor_sensor_signal() != -1) {//open door if in floor
		elev_set_door_open_lamp(1);
	}
	qm_delete_queue();
}


void ev_stop_button_released(void) {
	elev_set_stop_lamp(0);
	if (elev_get_floor_sensor_signal() != -1) {
		dt_start_timer();
	}
}


void sm_arrived_at_target_floor(int floor) {
	elev_set_motor_direction(0);
	elev_set_button_lamp(BUTTON_COMMAND, floor, 0);

	if (qm_get_button_type() != -1) {
		elev_set_button_lamp(qm_get_button_type(), floor, 0);
	}
	
    elev_set_door_open_lamp(1);
	dt_start_timer();
	sm_stop = 1;
}


void sm_go_to_floor(void){
    sm_target_floor = qm_get_next_floor();

	if((sm_target_floor==-1 ) || sm_stop ){
		elev_set_motor_direction(0);
	}
	else if (sm_last_floor >= sm_target_floor){
		elev_set_motor_direction(-1);
    
	}else if (sm_last_floor <= sm_target_floor){
		elev_set_motor_direction(1);
	}
}

void sm_init_sm(void){
    sm_target_floor = -1;
    sm_stop = 0;
}
