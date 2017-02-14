#include "Door_Timer.h"


void dt_start_timer(void){
    dt_timer = time(NULL);
}


bool dt_is_timeout(){
    dt_timeout = (time(NULL)-dt_timer) > 2; //HOLDER DETTE?
    return dt_timeout;
}
