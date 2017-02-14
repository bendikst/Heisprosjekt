//This is a test for the module Queue Manager

#ifndef Queue_Manager_test_h
#define Queue_Manager_test_h

static int qm_last_floor;
static int qm_next_direction; //-1, 0 , 1
static int qm_order_list[];


void qm_update_floor(int floor);
void qm_update_queue(int floor, button_type_t button);
int qm_next_floor(void);
int qm_next_direction(void);


//noen testkommentarer for å se hva som skjer :)
#endif /* Queue_Manager_test_h */
