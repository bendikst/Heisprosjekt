#include "Door_Timer.h"


void dt_start_timer(void){
    dt_timer = time(NULL);
}

bool dt_is_timeout(void){
	if (dt_timeout = (time(NULL) - dt_timer) > 2) {//HOLDER DETTE?
		dt_timer = _CRT_INT_MAX;
		return true;
	}
	else {
		return false;
	}
}
