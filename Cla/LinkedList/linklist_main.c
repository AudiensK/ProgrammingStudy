#include <stdio.h>
#include "linklist_node.h"


// typedef struct _node {
//     int value;
//     struct _node *next_p;
// } Node;


int main(int argc, char const* argv[])
{
    Node *list1 = linklist_create();
    linklist_init(&list1);
    // linklist_init(&list1);
    linklist_print(list1);
    printf("\n");

    printf("Enter Index to print value of the node:\n");
    int i;
    scanf("%d", &i);
    int value = linklist_nodeAtIndex(list1, i)->value;
    printf("value of Index is %d.\n", value);
    printf("\n");

    printf("Enter Index to remove a node:\n");
    scanf("%d", &i);
    linklist_removeByIndex(&list1, i);
    linklist_print(list1);
    printf("\n");

    printf("Free linklist.\n");
    free_linklist(&list1);
    linklist_print(list1);
    printf("\n");

    printf("Any Button to Continue...\n");
    getchar();

    return 0;
}


// gcc linklist_main.c oneway_linklist.c -o linklist.exe