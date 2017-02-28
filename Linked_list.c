
#include "Linked_list.h"


Node* initialize_node(int floor, elev_button_type_t buttonType){ //Allocating dynamic memory for new node
    Node* n = malloc(sizeof(Node));
    n->buttonType = buttonType;
    n->floor = floor;
    n->next = NULL;
    return n;
}


void delete_node(Node* self){
    free(self);
    self = NULL;
}



void insert_node(int floor, elev_button_type_t buttonType, Node* previous, Linked_list* self){
    Node* n = initialize_node(floor, buttonType);
    if (self->head == NULL || previous == NULL){ //Empty list, or push_front
        n->next = self->head;
        self->head = n;
    }
    else if (previous->next == NULL) { //push_back
        previous->next = n;
        n->next = NULL;
    } else {
        n->next = previous->next;
        previous->next = n;
    }
}



void remove_node(Linked_list* self){//Remove from front
    if (self->head == NULL){
        return;
    } else {
        Node* temp = self->head->next;
        self->head = self->head->next;
        delete_node(temp);
    }
}


//Counts number of elements in list.

unsigned int size(Linked_list* self){
    unsigned int size = 0;
    Node* iterator = self->head;
    while (iterator != NULL){
        size++;
        iterator = iterator->next;
    }
    return size;
}


void print_list(Linked_list* list){
    Node* it = list->head;
    printf("start \n");
    while(it != NULL){
        printf("Floor: %d, \t buttonType: %d\t next: %d\n", it->floor, it->buttonType, it->next);
        it = it->next;
    }
    printf("end \n");
}
