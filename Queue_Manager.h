/*®Alexander Johansen & Bendik Standal  */
#ifndef Queue_Manager_h
#define Queue_Manager_h
#include "Linked_list.h"

static int qm_last_floor; //The elevators last floor
Linked_list* qm_order_list; //sorted list that contains all orders

/*
@param floor sets qm_last_floor to value of floor. If floor is the same as Can be 0,1,2,3.
   if floor matches the floor value in next Order in qm_order_list it is deleted
*/
void qm_update_floor(int floor);

/* 
Interprets parameters as a new Order.
@param floor: floor value in Order.
@param button: button value in Order. Must be BUTTON_CALL_UP,
   BUTTON_CALL_DOWN or BUTTON_COMMAND

Inserts this Order into qm_order_list at a sorted position.
Priority is given to earier orders.
New Order inserted only if it is in a floor the elevator would pass regardless,
otherwise it is pushed to back.

*/
void qm_update_queue(elev_button_type_t button, int floor);

/*
@return the floor value of the next Order in qm_order_list
   if the list is empty returns -1

*/
int qm_get_next_floor(void);

/*
@return the button value of the next Order in qm_order_list
  if the list is empty returns -1

*/
int qm_get_button_type(void);

/*
Assignes the memory needed for qm_order_list


 */
void qm_init_queue(void);

/*
Deletes all Orders in queue
*/
void qm_delete_queue(void);



#endif /* Queue_Manager_h */
