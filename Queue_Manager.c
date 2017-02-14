
#include "elev.h"
#include "Queue_Manager.h"


//Hvor skal variablene initialiseres?

//Updating last passed floor variable.
void qm_update_floor(int floor){
  qm_last_floor = floor;
}

//Should update queue based on the current direction and orderlist
void qm_update_queue(int floor, elev_button_type_t button){

}


int qm_get_next_floor(int floor){
  return qm_order_list[0];
}


int qm_get_next_direction(void){
  return qm_next_direction;
}
