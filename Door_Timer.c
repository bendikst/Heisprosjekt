#include "Door_Timer.h"


void dt_start_timer(void){
    dt_timer = time(NULL);
}

bool dt_is_timeout(void){
	if ((time(NULL) - dt_timer) > 2) {//HOLDER DETTE?
		dt_timer = 2147483648;//max int
		return true;
	}
	else {
		return false;
	}
}
