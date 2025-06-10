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


// 第一种办法是定义一个全局变量head_p，然后传入指针，在函数内部就可以直接修改指针的值，但是全局变量是有害，尽量避免
// 第二中方法是传入指针head_p，然后在最后将这个指针返回出去，然后将返回的指针赋值给原指针，这种办法需要使用者注意函数用法
// 第三种办法还是传入指针的指针，直接修改指针指向的地址
// 第四种办法是声明一个结构,然后传入这个结构的指针:
/*
typedef struct _list {
    Node* head;
    Node* tail;  // 还可以加一个指针永远指向链表最后一个结构
} List;
List list;
list.head = list.tail = NULL;  // 初始化
这种方案可以进一步改进，拥有更大的潜力
*/
void linklist_init(Node** head_p)
// void linklist_init(List* plist)
{
    int number;
    Node *last_p;
    // 方案1：先判断是否为空链表，不是空链表无法初始化，是则开始初始化，\
        先录入头节点数据，把头节点当作尾节点（last_p），然后再做一个循环持续接入新的节点，\
        如果number不是-1，则将尾节点的next_p指向新分配的节点，然后将尾节点指向新节点，再录入number的值，\
        如果number是-1，表示当前尾节点点是最后一个节点，因此将next_p=NULL。\
        该方案只有一个循环，不需要重复定位链表最后一个节点，但是逻辑稍复杂，无法在任意链表后面插入新节点
    // if (*head_p) {
    //     printf("The head of the linked list is not NULL!\n");
    // } else {
    //     printf("Entering integers to initialize a linked list and entering -1 to finish:\n");
    //     scanf("%d", &number);
    //     if (number != -1) {
    //         *head_p = (Node*)malloc(sizeof(Node));
    //         (*head_p)->value = number;
    //         (*head_p)->next_p = NULL;
    //         last_p = *head_p;

    //         do {
    //             scanf("%d", &number);
    //             if (number != -1) {
    //                 last_p->next_p = (Node*)malloc(sizeof(Node));
    //                 last_p = last_p->next_p;
    //                 last_p->value = number;
    //             } else {
    //                 last_p->next_p = NULL;
    //             }
    //         } while (number != -1);    
    //     } else {
    //         printf("Failure Initialization!\n");
    //     }
    // }


    // 方案2：先将输入的数据分配一个临时节点，且next_p的NULL，这个节点作为待接入的尾节点，\
        然后做一个循环，从头节点出发一直寻找到链表当前的尾节点，然后把临时尾节点接上去，\
        处理特殊情况，当头节点是NULL时（空链表），直接将临时尾节点作为链表的头节点。\
        该方案可以在任意链表尾插入数据,，但是循环嵌套循环，每次循环都要通过第二个循环寻找链表的最后一个节点用于插入新节点。
    printf("Entering integers to initialize a linked list and entering -1 to finish:\n");
    do {
        scanf("%d", &number);
        if (number != -1) {
            Node* p = (Node*)malloc(sizeof(Node));  // 创建新节点
            if (p == NULL) {  // 如果分配内存失败
                exit(1);  // 终止程序，返回错误代码1
            }
            p->value = number;  // 录入数据
            p->next_p = NULL;  // 新节点将最后一个节点接入链表，因此next_p = NULL
            
            last_p = *head_p;
            // last_p = plist->head;
            if (*head_p) {
            // if (plist->head) {
                while (last_p->next_p) {  // 寻找链表当前的尾节点
                    last_p = last_p->next_p;
                }
                last_p->next_p = p;  // 找到尾节点后接上新节点
            } else {
                *head_p = p;  // 如果头节点为NULL，直接将头节点指向新节点
                // plist->head = p;
            }
        }
    } while (number != -1);   
}


void linklist_print(const Node* head_p)
{
    if (head_p) {
        // head_p是const类型指针，赋值给一个非const类型指针会报错，\
        因为可以通过这个非const指针修改const的指针指向的变量的值
        const Node *last_p;
        printf("Values of the linked list:\n");
        int cnt = 0;

        // last_p = head_p;
        // while (last_p->next_p) {
        //     if (cnt == 10) {  // Print a newline every cnt values.
        //         printf("\n");
        //         cnt = 0;
        //     }
        //     printf("%d ", last_p->value);
        //     last_p = last_p->next_p;
        //     cnt++;
        // }
        // if (cnt == 10) {
        //     printf("\n");
        //     cnt = 0;
        // }
        // printf("%d ", last_p->value);  // Print the last value.

        // 以下for循环写法十分常见，这种情况下相比于while循环也更方便。
        // 指针last_p = head_p作为初始值；循环终止条件为last_p == NULL;每经历一个循环，last_p指向下一个节点，直到最后一个节点。
        for (last_p = head_p; last_p; last_p = last_p->next_p) {
            // if (cnt++ == 10) {  // 先判断，再自增，因此重置后的cnt要从1开始
            //     printf("\n");
            //     cnt = 1;
            // }
            // // if (++cnt == 10) {  // 先自增，再判断，第一行cnt从-1开始，重置后cnt从0开始
            //     printf("\n");
            //     cnt = 0;
            // }
            if (cnt == 10) {
                printf("\n");
                cnt = 0;
            }
            printf("%d ", last_p->value);
            cnt++; // 可以把cnt自增放在外面，重置后cnt从0开始
        }
        
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


int linklist_removeByValue(Node** heap_p, int value)
{
    Node *p, *q;
    int success = 1;
    for(q = NULL, p = *heap_p; p; q = p, p = p->next_p) {
        if (value == p->value) {
            if (q) {
                q->next_p = p->next_p;
            } else {
                *heap_p = p->next_p;
            }
            free(p);
            goto ret;
        }
    }
    
    printf("Can not find the value.\n");
    success = 0;

ret:
    return success;
}


void free_linklist(Node** head_p)
{
    // if (*head_p) {
    //     do {
    //         Node* next = (*head_p)->next_p;
    //         free(*head_p);
    //         *head_p = next;
    //     } while (*head_p);
    // }

    for (Node* next; *head_p; *head_p = next) {
        next = (*head_p)->next_p;
        free(*head_p);
    }
}