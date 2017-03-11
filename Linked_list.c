//  Linked_list.c
//
// Adapted linked list structure for the elevator project, "Heisprosjekt-master"
// for the subject "TTK4235 Tilpassede datasystemer"
//
// Copyright © 2017 Alexander Johansen & Bendik Standal. All rights reserved.
#include "Linked_list.h"
#include <stdio.h>


Order* initialize_order(int floor, elev_button_type_t button_type){
    Order* n = malloc(sizeof(Order)); //Allocating memory for new order
    n->button_type = button_type;
    n->floor = floor;
    n->next = NULL;
    n->prev = NULL;
    return n;
}


void delete_order(Order* self){
    free(self);
    self = NULL;
}



void insert_order(int floor, elev_button_type_t button_type, Order* after, Linked_list* self){
    Order* new = initialize_order(floor, button_type);

    if(self->head == NULL) { //Empty list
        new->next = self->head;
        self->head = new;
        self->tail = new;
        new->prev = NULL;
    }else if(after == NULL) { //push_back
        self->tail->next = new;
        new->next = NULL;
        new->prev = self->tail;
        self->tail = new;
    }else if(after->prev == NULL) { //push_front
        self->head->prev = new;
        new->next = self->head;
        new->prev = NULL;
        self->head = new;
    }else {
        after->prev->next = new;
        new->next = after;
        new->prev = after->prev;
        after->prev = new;
    }
}



void remove_order(Linked_list* self){//Remove from front
    if (self->head == NULL) {
        return;
    } else {
        Order* temp = self->head;
        self->head->prev = NULL;
        if(self->tail->prev == NULL) self->tail = NULL;
        self->head = self->head->next;
        delete_order(temp);
    }
}



void print_list(Linked_list* list){
    Order* it = list->head;
    printf("start \n");
    while(it != NULL){
        printf("Floor: %d, \t button_type: %d\t next: %d\n", it->floor, it->button_type, it->next);
        it = it->next;
    }
    printf("end \n");
}
