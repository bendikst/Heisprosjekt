

#include "Queue_Manager.h"


//Hvor skal variablene initialiseres?

//Updating last passed floor variable.
void qm_update_floor(int floor){
  qm_last_floor = floor;
}





int qm_next_floor(int floor){
  return qm_order_list[0];
}


int qm_next_direction(void){
  return qm_next_direction;
}
