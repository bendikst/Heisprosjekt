//
//  Linked_list.h
//
//  Created by Bendik Standal on 21/02/2017.
//  Copyright © 2017 Bendik Standal. All rights reserved.
//

#ifndef Linked_list_h
#define Linked_list_h
#define linked_list_init(...){.head = NULL}

#include <stdio.h>
#include <stdlib.h>
#include "elev.h"

typedef struct node_struct Node;
typedef struct linked_list_struct linked_list;

typedef struct node_struct {
    int floor;
    elev_button_type_t buttonType;
    Node* next;
    //void (*delete_node)(Node*);
}Node;

Node* initialize_node(int floor, elev_button_type_t buttonType);




typedef struct linked_list_struct {
    Node* head;
    //void (*insert_node)(int, elev_button_type_t, Node*, linked_list*);
    //void (*remove_node)(linked_list*);
    //unsigned int (*size)(linked_list*);
}Linked_list;



void insert_node(int floor, elev_button_type_t buttonType, Node* previous, Linked_list* self);

void remove_node(Linked_list* self);

void print_list(Linked_list* list);

void print_list(linked_list* list);





#endif /* Linked_list_h */
