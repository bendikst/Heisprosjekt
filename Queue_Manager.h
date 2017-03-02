/*®Alexander Johansen & Bendik Standal  */
#ifndef Queue_Manager_h
#define Queue_Manager_h
#include "Linked_list.h"

static int qm_last_floor; //Her må vi endre, se melding på ITS
static elev_motor_direction_t qm_next_direction; //-----||-------
Linked_list* qm_order_list;


void qm_update_floor(int floor);
void qm_update_queue(int floor, elev_button_type_t button);
int qm_get_next_floor(void);
int qm_get_next_direction(void);
void qm_init_queue(void);
void qm_delete_queue(void);



#endif /* Queue_Manager_h */
