#include "Door_Timer.h"


void dt_start_timer(void){
    dt_timer = time(NULL);
}

bool dt_is_timeout(void){
	if ((time(NULL) - dt_timer) > 2) {
		//dt_timer = 2147483648;//max int
		//printf("starter timer\n");
		dt_timeout = true;
	}
	else {
		dt_timeout = false;
	}
	return dt_timeout;
}

void dt_stop_timer(void){

}


/*
bool dt_is_timeout(void){
	dt_timeout = (time(NULL) - dt_timer > 2);
	//dt_timer = 2147483648;
	return dt_timeout;
}
*/

void dt_init_timer(void){
dt_timeout = false;
dt_timer= 2147483648;
}