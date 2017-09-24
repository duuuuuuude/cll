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
    node* new_tail = (node*)malloc(sizeof(node));
    
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
    printf("0. Create first node.\n");
    printf("1. Prepend an item.\n");
    printf("2. Append an item.\n");
    printf("3. Show list items.\n");
    printf("---------------------\n");
}

int main(int argc, char *argv[]) {
    node* head = NULL;
    node* tail = NULL;

    int command = 0;
    int data;

    while(1) {
        // clear the console: https://stackoverflow.com/questions/2347770/
        printf("\033[2J\033[1;1H");
        menu();
        scanf("%d", &command);
        if (command == -1) 
            break;
        switch(command) {
            case 0:
                printf("\033[2J\033[1;1H");
                menu();
                if (head || tail) {
                    printf("Noo way...\n");
                    break;
                }
                printf("Enter a number for first node: ");
                scanf("%d", &data);
                head = tail = create(data);
                break;

            case 1:
                printf("\033[2J\033[1;1H");
                menu();
                printf("Enter a number to prepend: ");
                scanf("%d", &data);
                head = prepend(data, head);
                break;

            case 2:
                printf("\033[2J\033[1;1H");
                menu();
                printf("Enter a number to append: ");
                scanf("%d", &data);
                tail = append(data, tail);
                break;

            case 3:
                printf("\033[2J\033[1;1H");
                menu();
                print_list(head);
                while(getchar()!='\n');
                getchar();
                break;

            default:
                exit(0);
        }
    }
}



