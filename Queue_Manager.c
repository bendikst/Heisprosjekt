
#include "elev.h"
#include "Queue_Manager.h"
#include "Linked_list.h"


void qm_update_floor(int floor) {
  qm_last_floor = floor;

  if (qm_order_list->head == NULL) {//if the list is empty, return
	  return;
  }else if (floor == qm_order_list->head->floor) {
	  remove_order(qm_order_list);
  }
}


//Should update queue based on the current direction and orderlist
void qm_update_queue(elev_button_type_t button, int floor) {

	if (qm_order_list->head == NULL) { //If the qm_order_list is empty, insert order
		  insert_order(floor, button, NULL, qm_order_list);
		  return;
	}

	else {//if there is more than one order in qm_order_list

		int uq_last_floor = qm_last_floor;			//defining update queue variables
		elev_motor_direction_t uq_next_direction;	
		Order* iterator = qm_order_list->head;		//defining iterator

		while (iterator != NULL) {//Check if order is in list

			if((iterator->floor == floor ) && (iterator->buttonType == button)) {
					return; //If the order already exists, return
				}
			iterator = iterator->next;
		}

		iterator = qm_order_list->head;	//resetting terator

		while (iterator != NULL) {//insert Order into qm_order_list
				
				//Update uq_next_direction every loop
				//this variable keeps track of the elevators estimated path
				if (uq_last_floor < iterator->floor) {
					uq_next_direction = DIRN_UP;
				}
				else if (uq_last_floor > iterator->floor) {
					uq_next_direction = DIRN_DOWN;
				}
				else {
					uq_next_direction = DIRN_STOP;
				}

				//Try to insirt order into list
				//If the order is for a floor that the elevator is passing, and the button matches,
				//insert it into qm_order_list
				if(button == BUTTON_COMMAND){
					if ((uq_next_direction == DIRN_DOWN) && (iterator->floor <= floor) && (floor < uq_last_floor)) {
						insert_order(floor, button, iterator, qm_order_list);
						return;
					}
					else if ((uq_next_direction == DIRN_UP) && (iterator->floor >= floor) && (floor > uq_last_floor)) {
						insert_order(floor, button, iterator, qm_order_list);
						return;
					}
				}
				else if (button == BUTTON_CALL_UP) {
					if ((uq_next_direction == DIRN_UP) && (iterator->floor >= floor) && (floor > uq_last_floor)) {
						insert_order(floor, button, iterator, qm_order_list);
						return;
					}
				}
				else if (button == BUTTON_CALL_DOWN) {
					if ((uq_next_direction == DIRN_DOWN) && (iterator->floor <= floor) && (floor < uq_last_floor)) {
						insert_order(floor, button, iterator, qm_order_list);
						return;
					}
				}
				else {
					printf("something happened in queue manager during insertiion to list\n");
				}

				if (iterator->next == NULL) {//Reached end of list, push_back
					insert_order(floor, button, NULL, qm_order_list);
					printf("push_back\n");
					return;
				}

				//iterate uq_last_floor and iterator
				uq_last_floor = iterator->floor;
				iterator = iterator->next;
			}
	  }
}


int qm_get_next_floor(void) {
	if (qm_order_list->head == NULL) {
		return -1;
	}
	return qm_order_list->head->floor;
}


int qm_get_button_type(void){
	if (qm_order_list->head == NULL) {
		return -1;
	}
	return qm_order_list->head->buttonType;
}


void qm_init_queue(void) {
	qm_order_list = malloc(sizeof(Linked_list));
  }


void qm_delete_queue(void){
	Order* iterator = qm_order_list->head;
	while (iterator != NULL){//remove the first order in qm_order_list until there are no more orders
			remove_order(qm_order_list);
			iterator = qm_order_list->head;
	}
	qm_order_list->head = NULL;
}
