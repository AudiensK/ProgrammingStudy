#include <stdio.h>
#include "linklist_node.h"


// typedef struct _node {
//     int value;
//     struct _node *next_p;
// } Node;


int main(int argc, char const* argv[])
{
    Node *list1 = linklist_create();
    // List* plist1;
    // plist1->head = list1;  
    // 只是将list1赋值给head，因此对head的值得操作不会影响list1的值，\
    但是对head所指向的结构的值进行操作，还是会影响list1指向的结构的值，\
    因为目前head和list1值（指向的地址）相同，指向同一个结构。

    // linklist_init(plist1);
    linklist_init(&list1);
    // linklist_print(plist1->head);
    linklist_print(list1);
    printf("\n");

    printf("Enter Index to print value of the node:\n");
    int i;
    scanf("%d", &i);
    Node* node = linklist_nodeAtIndex(list1, i);
    if (node) {
        int value = node->value;
        printf("value of Index is %d.\n", value);
    }
    printf("\n");

    printf("Enter Index to remove a node:\n");
    scanf("%d", &i);
    linklist_removeByIndex(&list1, i);
    linklist_print(list1);
    printf("\n");

    printf("Enter Value to remove a node:\n");
    scanf("%d", &i);
    linklist_removeByValue(&list1, i);
    linklist_print(list1);
    printf("\n");

    printf("Free linklist.\n");
    free_linklist(&list1);
    linklist_print(list1);
    printf("\n");

    printf("Any Button to Continue...\n");
    getchar();
    getchar();

    return 0;
}


// gcc linklist_main.c oneway_linklist.c -o linklist.exe