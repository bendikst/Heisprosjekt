
#include "Linked_list.h"


Node* initialize_node(int floor, elev_button_type_t buttonType){ //Allocating dynamic memory for new node
    Node* n = malloc(sizeof(Node));
    n->buttonType = buttonType;
    n->floor = floor;
    n->next = NULL;
    n->prev = NULL;
    return n;
}


void delete_node(Node* self){
    free(self);
    self = NULL;
}



void insert_node(int floor, elev_button_type_t buttonType, Node* after, Linked_list* self){
    Node* new = initialize_node(floor, buttonType);
    
    if(self->head == NULL) { //lista er tom 
        new->next = self->head;
        self->head = new;
        self->tail = new;
        new->prev = NULL;
    }else if(after == NULL){ //push_back
        self->tail->next = new;
        new->next = NULL;
        new->prev = self->tail;
        self->tail = new;
    }else if(after->prev == NULL){ //push_front
        self->head->prev = new;
        new->next = self->head;
        new->prev = NULL;
        self->head = new;
    }else{
        after->prev->next = new;
        new->next = after;
        new->prev = after->prev;
        after->prev = new;
    }
}



void remove_node(Linked_list* self){//Remove from front
    if (self->head == NULL){
        return;
    } else {
        Node* temp = self->head;
        self->head->prev = NULL;
        if(self->tail->prev == NULL) self->tail = NULL;
        self->head = self->head->next;
        delete_node(temp);
    }
}



//This function should be removed before FAT?
void print_list(Linked_list* list){
    Node* it = list->head;
    printf("start \n");
    while(it != NULL){
        printf("Floor: %d, \t buttonType: %d\t next: %d\n", it->floor, it->buttonType, it->next);
        it = it->next;
    }
    printf("end \n");
}





