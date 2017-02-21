
#include "elev.h"
#include "Queue_Manager.h"


//Hvor skal variablene initialiseres?

//Updating last passed floor variable.
void qm_update_floor(int floor){
  qm_last_floor = floor;
  while (floor == qm_order_list[0].floor) {//bruker while fordi det hender samme etasjen er m�let to ganger p� rad
	  // ----Remove first element----
  }
}

//Should update queue based on the current direction and orderlist
void qm_update_queue(int floor, elev_button_type_t button){
if (qm_order_list[0].next == NULL) { //dersom listen var tom legger vi det inn som f�rste element
	  // ----insert node-----
	  return;
}

else {//dersom det er mer enn ett element i lista kj�rer denne

int um_last_floor = qm_last_floor;
elev_motor_direction_t um_next_direction;
	for (int i = 0; i < /*size of list*/; i++) {//bestillingen legges sortert inn i lista
		//dersom vi har n�dd slutten av lista settes bestillingen inn her
		if (qm_order_list[i].next == NULL) {
			//insert order
		}

		//oppdaterer um_next_direction
		if (um_last_floor < qm_order_list[i].floor) {
			um_next_direction = DIRN_UP;
		}
		else if (um_last_floor > qm_order_list[i].floor) {
			um_next_direction = DIRN_DOWN;
		}
		else {
			um_next_direction = DIRN_STOP;
		}
		//oppdaterer um_last_floor
		um_last_floor = qm_order_list[i].floor;

		//fors�ker � legge inn i lista
		if(button == BUTTON_COMMAND){
			//setter inn dersom m�letasjen er mellom den forrige etasjen og den neste etasjen
			if (um_next_direction == DIRN_DOWN && qm_order_list[i].floor <= floor < um_last_floor) {
				//insert node
			}
			else if (um_next_direction == DIRN_UP && qm_order_list[i].floor >= floor > um_last_floor) {
				//insert node
			}
		}
		else if (button == BUTTON_CALL_UP) {
			if (um_next_direction == DIRN_UP && qm_order_list[i].floor >= floor > um_last_floor) {
				// ----insert node----
				return;
			}
		}
		else if (button == BUTTON_CALL_DOWN) {
			if (um_next_direction == DIRN_DOWN && qm_order_list[i].floor <= floor < um_last_floor) {
				//  ----insert node----
				return;
			}
		}
		else {
			//det har skjedd en feil
		}


	  }
  }
}


int qm_get_next_floor(void){
	if (qm_order_list[0].next == NULL) {
		return qm_order_list[0].floor;
	}
	return 0;
}


int qm_get_next_direction(void){
	if (qm_order_list[0].next == NULL) {
		return qm_order_list[0].button;
	}
	return 0;
}
