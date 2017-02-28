
#include "elev.h"
#include "Queue_Manager.h"
#include "Linked_list.h"


//Hvor skal variablene initialiseres?

//Updating last passed floor variable.
void qm_update_floor(int floor){
  qm_last_floor = floor;
if(qm_order_list->head ==NULL){
	return;
}
  while (floor == qm_order_list->head->floor) {//bruker while fordi det hender samme etasjen er målet to ganger på rad
	  remove_node(qm_order_list);
	  if(qm_order_list->head == NULL){
	  	return;
	  }
  }
}

//Should update queue based on the current direction and orderlist
void qm_update_queue(int floor, elev_button_type_t button){
	if (qm_order_list->head == NULL) { //dersom listen var tom legger vi det inn som første element
		  insert_node(floor, button, NULL, qm_order_list);
		  return;
	}
 
	else {//dersom det er ett eller flere element i lista kjører denne

	int um_last_floor = qm_last_floor;
	elev_motor_direction_t um_next_direction;
	Node* iterator = qm_order_list->head;
			while (iterator != NULL) {//bestillingen legges sortert inn i lista
			//dersom vi har nådd slutten av lista settes bestillingen inn her

			if((iterator->floor == floor ) && (iterator->buttonType == button)){//orderen er alerede i lista
				return;
			}
			iterator = iterator->next;
		}
		iterator = qm_order_list->head;

		while (iterator != NULL) {//bestillingen legges sortert inn i lista
			//dersom vi har nådd slutten av lista settes bestillingen inn her


			if (iterator->next == NULL) {
				insert_node(floor, button, iterator, qm_order_list);
				return;
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

			//forsøker å legge inn i lista
			if(button == BUTTON_COMMAND){
				//setter inn dersom måletasjen er mellom den forrige etasjen og den neste etasjen
				if ((um_next_direction == DIRN_DOWN) && (iterator->floor <= floor < um_last_floor)) {
					insert_node(floor, button, iterator, qm_order_list);
					return;
				}
				else if ((um_next_direction == DIRN_UP) && (iterator->floor >= floor > um_last_floor)) {
					insert_node(floor, button, iterator, qm_order_list);
					return;
				}
			}
			else if (button == BUTTON_CALL_UP) {
				if ((um_next_direction == DIRN_UP) && (iterator->floor >= floor > um_last_floor)) {
					insert_node(floor, button, iterator, qm_order_list);
					return;
				}
			}
			else if (button == BUTTON_CALL_DOWN) {
				if ((um_next_direction == DIRN_DOWN) && (iterator->floor <= floor < um_last_floor)) {
					insert_node(floor, button, iterator, qm_order_list);
					return;
				}
			}
			else {
				printf("somthing happened \n");
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
		return -1;
	}
	return qm_order_list->head->buttonType;
}

void qm_init_queue(void){
	qm_order_list = malloc(sizeof(linked_list));
	qm_order_list->head = NULL;
}
