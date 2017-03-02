#include "Door_Timer.h"


void dt_start_timer(void){
    dt_timer = time(NULL);
}


bool dt_is_timeout(void){
	if ((time(NULL) - dt_timer) > 2) {//Skrive denne mer ryddig?
		dt_timeout = true;
	}
	else {
		dt_timeout = false;
	}
	return dt_timeout;
}


void dt_init_timer(void){ //Trenger vi denne?
dt_timeout = false;
dt_timer= 2147483648;
}
