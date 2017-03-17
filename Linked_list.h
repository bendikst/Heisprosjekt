//  Linked_list.h
//
// Adapted linked list structure for the elevator project, "Heisprosjekt-master"
// for the subject "TTK4235 Tilpassede datasystemer"


#ifndef Linked_list_h
#define Linked_list_h


#include <stdlib.h>
#include "elev.h"

typedef struct Order_struct Order;


typedef struct Order_struct {
    int floor;
    elev_button_type_t button_type;
    Order *next;
    Order *prev;
}Order;


typedef struct Linked_list_struct {
    Order* head;
    Order* tail;
}Linked_list;


/*
  Allocating memory and initializing variables for a new order.
  @param values set to the Order_struct.
  @param button Can be BUTTON_CALL_UP,
    BUTTON_CALL_DOWN or BUTTON_COMMAND.
*/
Order* initialize_order(int floor, elev_button_type_t button_type);


/*
  Freeing memory used by an Order_struct.
  @param self Pointer to the object being deleted.
*/
void delete_order(Order* self);


/*
  Inserting order in the linked list, either push_front, push_back based on
  @param after, which points to the Order-element being inserted in front of.
  @param floor Used by initialize_order().
  @param button Can be BUTTON_CALL_UP,
    BUTTON_CALL_DOWN or BUTTON_COMMAND.
  @param self Points to the list being updated.
*/
void insert_order(int floor, elev_button_type_t button_type, Order* after, Linked_list* self);


/*
  Removing the first order in the list.
  @param self Points to the list to remove from.
*/
void remove_order(Linked_list* self);


/*
  Printing linked list for debugging. Printing Floor, button_type and adress
  of next for each order.
  @param list Points to list being printed.
*/
void print_list(Linked_list* list);


#endif /* Linked_list_h */
