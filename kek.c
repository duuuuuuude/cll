#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

node* prepend(int data, node* prev_head) {
    node* new_head = (node*)malloc(sizeof(node));

    new_head->data = data;
    new_head->next = prev_head;

    return new_head;
}

node* append(int data, node* tail) {
    node* new_node = malloc(sizeof(node));
    
    tail->next = new_node;
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
} 

void print_list(node* head) {
    node* n = NULL;
    for (n = head; n != NULL; n = n->next) {
        printf("%d\n", n->data);
    }
}

int main(int argc, char *argv[]) {
    node* head = create_node(20);
    node *tail = head;

    tail = append(20, tail);
    tail = append(30, tail);
    tail = append(40, tail);
    
    print_list(head);
}






