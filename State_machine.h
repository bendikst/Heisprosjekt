#ifndef State_machine_h
#define State_machine_h

#include"elev.h"

#include"Queue_Manager.h"
#include"Door_Timer.h"


static int sm_last_floor;	//The last floor the elevator passed
static int sm_target_floor;	//Elevetors target floor(-1 if none)
static int sm_stop;			//State variable, when 1 the elevator cannot move

/*
@param button ttype of button pressed. Must be BUTTON_CALL_UP,
   BUTTON_CALL_DOWN or BUTTON_COMMAND
@param floor floor button was pressed in

updates queue with parameters, sets button lamp
*/
void ev_button_pressed(elev_button_type_t button, int floor);

/*
closes door and enables movement
*/
void ev_timeout(void);

/*
@param floor updates sm_last_floor and floor indicator and runs qm_update_floor
	if floor matches sm_target floor, runs sm_arrived_at_target_floor
*/
void ev_floor_signal(int floor);

/*
stops elevator, turns off all lamps, open door if in floor, deletes queue
*/
void ev_stop_button_pressed(void);

/*
starts door timer if in floor, enables movement 
*/
void ev_stop_button_released(void);

/*
stops elevator, sets lamps, opens door, disables movement
*/
void sm_arrived_at_target_floor(int floor);

/*
moves in direction of target floor if it can
*/
void sm_go_to_floor(void);

/*
initalizes target floor and enables movement
*/
void sm_init_sm(void);

#endif /*State_machine_h*/
