
#include "elev.h"
#include "Queue_Manager.h"
#include "Linked_list.h"


//Hvor skal variablene initialiseres?

//Updating last passed floor variable.
void qm_update_floor(int floor){
  qm_last_floor = floor;
  while (floor == qm_order_list->head->floor) {//bruker while fordi det hender samme etasjen er m�let to ganger p� rad
	  remove_node(qm_order_list);
  }
}

//Should update queue based on the current direction and orderlist
void qm_update_queue(int floor, elev_button_type_t button){

	if (qm_order_list->head == NULL) { //dersom listen var tom legger vi det inn som f�rste element
		  insert_node(floor, button, NULL, qm_order_list);
		  return;
	}

	else {//dersom det er ett eller flere element i lista kj�rer denne

	int um_last_floor = qm_last_floor;
	elev_motor_direction_t um_next_direction;
	Node* iterator = qm_order_list->head;

		while (iterator != NULL) {//bestillingen legges sortert inn i lista
			//dersom vi har n�dd slutten av lista settes bestillingen inn her

			if (iterator->next == NULL) {
				insert_node(floor, button, iterator, qm_order_list);
			}

			//oppdaterer um_next_direction
			if (um_last_floor < iterator->floor) {
				um_next_direction = DIRN_UP;
			}
			else if (um_last_floor > iterator->floor) {
				um_next_direction = DIRN_DOWN;
			}
			else {
				um_next_direction = DIRN_STOP;
			}

			//fors�ker � legge inn i lista
			if(button == BUTTON_COMMAND){
				//setter inn dersom m�letasjen er mellom den forrige etasjen og den neste etasjen
				if (um_next_direction == DIRN_DOWN && iterator->floor <= floor < um_last_floor) {
					insert_node(floor, button, iterator, qm_order_list);
				}
				else if (um_next_direction == DIRN_UP && iterator->floor >= floor > um_last_floor) {
					insert_node(floor, button, iterator, qm_order_list);
				}
			}
			else if (button == BUTTON_CALL_UP) {
				if (um_next_direction == DIRN_UP && iterator->floor >= floor > um_last_floor) {
					insert_node(floor, button, iterator, qm_order_list);
					return;
				}
			}
			else if (button == BUTTON_CALL_DOWN) {
				if (um_next_direction == DIRN_DOWN && iterator->floor <= floor < um_last_floor) {
					insert_node(floor, button, iterator, qm_order_list);
					return;
				}
			}
			else {
				//det har skjedd en feil
			}

			//oppdaterer um_last_floor
			um_last_floor = iterator->floor;

			iterator = iterator->next;//iterer iterator
		  }
	  }
}


int qm_get_next_floor(void){
	if (qm_order_list->head == NULL) {
		return -1;
	}
	return qm_order_list->head->floor;
}


int qm_get_next_direction(void){
	if (qm_order_list->head == NULL) {
		return 0;
	}
	return qm_order_list->head->buttonType;
}
