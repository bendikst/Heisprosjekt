#ifndef State_machine_h
#define State_machine_h

#include"elev.h"

#include"Queue_Manager.h"
#include"Door_Timer.h"


static int sm_last_floor; //DETTE MÅ ENDRES! INGEN VITS MED STATIC I H-FIL
static int sm_target_floor;
static int sm_next_direction;
int sm_stop;


void ev_button_pressed(elev_button_type_t buttonType, int floor);
void ev_timeout(void);
void ev_floor_signal(int floor);
void ev_stop_button_pressed();
void ev_stop_button_released();
void sm_arrived_at_target_floor(int floor);
void sm_go_to_floor(void);
void sm_init_sm(void);


#endif /*State_machine_h*/
