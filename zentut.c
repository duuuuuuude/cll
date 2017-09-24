#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef void (*callback)(node* data);

node* create(int data, node* next) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = next;

    return new_node;
}

node* prepend(node* head, int data) {
    node* new_node = create(data, head);
    head = new_node;
    return head;
}

node* append(node* head, int data) {
    if (head == NULL) {
        return NULL;
    }

    node* cursor = head;
    while(cursor->next != NULL) {
        cursor = cursor->next;
    }

    node* new_node = create(data, NULL);
    cursor->next = new_node;

    return head;
}

node* insert_after(node* head, int data, node* prev) {
    if (head == NULL || prev == NULL) {
        return NULL;
    }

    node* cursor = head;
    while(cursor != prev) {
        cursor = cursor->next;
    }

    if (cursor != NULL) {
        node* new_node = create(data, cursor->next);
        cursor->next = new_node;
        return head;
    } else {
        return NULL;
    }
}

node* insert_before(node* head, int data, node* nxt) {
    if (nxt == NULL || head == NULL) {
        return NULL;
    }

    if (head == nxt) {
        head = prepend(head, data);
        return head;
    }
    
    node* cursor = head;
    while(cursor != NULL) {
        if (cursor->next == nxt) {
            break;
        }
        cursor = cursor->next;
    }
    
    if (cursor != NULL) {
        node* new_node = create(data, cursor->next);
        cursor->next = new_node;
        return head;
    } else {
        return NULL;
    }
}

void traverse(node* head, callback f) {
    node* cursor = head;
    while(cursor != NULL) {
        f(cursor);
        cursor = cursor->next;
    }
}

node* remove_front(node* head) {
    if (head == NULL) {
        return NULL;
    }
    
    node* front = head;
    head = head->next;
    front->next = NULL;

    if (front == head) {
        head = NULL;
    }
    free(front);
    return head;
}

node* remove_back(node* head) {
    if (head == NULL) {
        return NULL;
    }

    node* cursor = head;
    node* back = NULL;
    while(cursor->next != NULL) { // back stays here, cursor goes 1 step further
        back = cursor;
        cursor = cursor->next;
    }

    if (back != NULL) {
        back->next = NULL;
    }

    if (cursor == head) {
        head = NULL;
    } 

    free(cursor);
    return head;
}

void display(node* n) {
    if (n != NULL) {
        printf("%d ", n->data);
    }
}

node* search(node* head, int data) {
    node* cursor = head;
    while(cursor != NULL) {
        if (cursor->data == data) {
            return cursor;
        }
        cursor = cursor->next;
    }
    return NULL;
}

void dispose(node* head) {
    node *cursor, *tmp;

    if (head != NULL) {
        cursor = head->next;
        head->next = NULL; // THE POINTER becomes null, not an address it pointed to
        while(cursor != NULL) {
            tmp = cursor->next;
            free(cursor);
            cursor = tmp;
        }
    }
}

int count(node* head) {
    node* cursor = head;
    int c = 0;
    while(cursor != NULL) {
        c++;
        cursor = cursor->next;
    }
    return c;
}

node* reverse(node* head) {
    node* prev = NULL;
    node* current = head;
    node* next;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void menu() {
    printf("--- C Linked List Demonstration --- \n\n");
    printf("0.menu\n");
    printf("1.prepend an element\n");
    printf("2.append an element\n");
    printf("3.search for an element\n");
    printf("4.insert after an element\n");
    printf("5.insert before an element\n");
    printf("6.remove front node\n");
    printf("7.remove back node\n");
    printf("8.remove any node\n");
    printf("9.sort the list\n");
    printf("10.Reverse the linked list\n");
    printf("-1.quit\n"); 
}

