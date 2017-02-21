//This is a test for the module Queue Manager

#ifndef Queue_Manager_test_h
#define Queue_Manager_test_h

static int qm_last_floor;
static elev_motor_direction_t qm_next_direction;
static int qm_order_list[]; //Her vil vi heller ha en lenket liste
static elev_motor_direction_t qm_curr_direction;

void qm_update_floor(int floor);
void qm_update_queue(int floor, elev_button_type_t button);
int qm_get_next_floor(void);
int qm_get_next_direction(void);



#endif /* Queue_Manager_test_h */