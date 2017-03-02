//
//  Linked_list.h
//
//  Created by Bendik Standal on 21/02/2017.
//  Copyright © 2017 Bendik Standal. All rights reserved.
//
// Adapted linked list structure for the elevator project, "Heisprosjekt-master"
// for the subject TTK4235 Tilpassede datasystemer

#ifndef Linked_list_h
#define Linked_list_h

#include <stdio.h>
#include <stdlib.h>
#include "elev.h"


typedef struct Node_struct {
    int floor;
    elev_button_type_t buttonType;
    Node* next;
}Node;


typedef struct Linked_list_struct {
    Node* head;
}Linked_list;


Node* initialize_node(int floor, elev_button_type_t buttonType);

void delete_node(Node* self);

void insert_node(int floor, elev_button_type_t buttonType, Node* previous, Linked_list* self);

void remove_node(Linked_list* self);

void print_list(Linked_list* list);


#endif /* Linked_list_h */
