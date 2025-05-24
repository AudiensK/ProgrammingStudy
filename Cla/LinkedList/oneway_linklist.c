#include <stdio.h>
#include <stdlib.h>

#include "linklist_node.h"

// typedef struct _node {
//     int value;
//     struct _node *next_p;
// } Node;

Node* linklist_create(void)
{
    Node *head_p = NULL;

    return head_p;
}


int linklist_init(Node** head_p)
{
    int number;
    Node *last_p;
    int ret = 0;

    if (*head_p) {
        printf("The head of the linked list is not NULL!\n");
    } else {
        printf("Entering integers to initialize a linked list and entering -1 to finish.\n");
        scanf("%d", &number);
        if (number != -1) {
            *head_p = (Node*)malloc(sizeof(Node));
            (*head_p)->value = number;
            (*head_p)->next_p = NULL;
            last_p = *head_p;

            do {
                scanf("%d", &number);
                if (number != -1) {
                    last_p->next_p = (Node*)malloc(sizeof(Node));
                    last_p = last_p->next_p;
                    last_p->value = number;
                } else {
                    last_p->next_p = NULL;
                    ret = 1;
                }
            } while (number != -1);    
        } else {
            printf("Failure Initialization!\n");
        }
    }

    return ret;  // success->return 1; failure->return 0;
}


void linklist_print(Node* head_p)
{
    if (head_p) {
        Node *last_p = head_p;
        printf("Values of the linked list:\n");
        int cnt = 0;
        while (last_p->next_p) {
            if (cnt == 10) {  // Print a newline every cnt values.
                printf("\n");
                cnt = 1;
            }
            printf("%d ", last_p->value);
            last_p = last_p->next_p;
            cnt++;
        }
        if (cnt == 10) {
            printf("\n");
            cnt = 0;
        }
        printf("%d ", last_p->value);  // Print the last value.
    } else {
        printf("The linked list is NULL!\n");
    }
}

int linklist_size(Node* head_p)
{
    int cnt;
    if (head_p) {
        cnt = 1;
        while (head_p->next_p) {
            cnt++;
            head_p = head_p->next_p;
        }
    } else {
        cnt = 0;
    }

    return cnt;
}

Node* linklist_nodeAtIndex(Node* head_p, int index)
{
    Node* ret;
    int cnt = 0;
    if (head_p == NULL) {
        printf("The linked list is invalid.\n");
        return NULL;
    }

    int sizeOfList = linklist_size(head_p);
    if (index < 0 || index >= sizeOfList) {
        printf("Index out of range.\n");
        ret = NULL;
    } else {
        do {
            ret = head_p;
            head_p = head_p->next_p;
        } while (cnt++ < index);
    }

    return ret;
}


void linklist_removeByIndex(Node** head_p, int index)
{
    Node* node_p = linklist_nodeAtIndex(*head_p, index);
    if (node_p) {
        int size = linklist_size(*head_p);
        if (index == 0) {
            *head_p = node_p->next_p;
            free(node_p);
        } else {
            linklist_nodeAtIndex(*head_p, index - 1)->next_p = node_p->next_p;
            free(node_p);
        }
    } else {
        printf("Can not remove this node.\n");
    }
}


void free_linklist(Node** head_p)
{
    if (*head_p) {
        do {
            Node* next = (*head_p)->next_p;
            free(*head_p);
            *head_p = next;
        } while (*head_p);
    }
}