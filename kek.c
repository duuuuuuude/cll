#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* create(int data) {
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
    node* new_tail = malloc(sizeof(node));
    
    tail->next = new_tail;
    new_tail->data = data;
    new_tail->next = NULL;

    return new_tail;
} 

void print_list(node* head) {
    node* n = NULL;
    for (n = head; n != NULL; n = n->next) {
        printf("%d\n", n->data);
    }
}

void menu() {
    printf("---------------------\n");
    printf("1. Prepend an item.\n");
    printf("2. Append an item.\n");
    printf("3. Show list items.\n");
    printf("---------------------\n");
}

int main(int argc, char *argv[]) {
    node* head = create(10);
    node *tail = head;

    // tail = append(20, tail);
    // tail = append(30, tail);
    // tail = append(40, tail);
    
    //print_list(head);
    
    int command = 0;
    int data;
    while(1) {
        menu();
        scanf("%d", &command);
        if (command == -1) 
            break;
        switch(command) {
            case 1:
                printf("Enter a number to prepend: ");
                scanf("%d", &data);
                head = prepend(data, head);
                break;
            case 2:
                printf("Enter a number to append: ");
                scanf("%d", &data);
                tail = append(data, tail);
                break;
            case 3:
                print_list(head);
                break;
            default:
                exit(0);
        }
    }
}






