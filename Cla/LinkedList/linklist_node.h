#ifndef _LINKLIST_NODE_H_
#define _LINKLIST_NODE_H_

typedef struct _node {
    int value;
    struct _node *next_p;
} Node;

Node* linklist_create(void);  // 创建一个空的单向链表
int linklist_init(Node** head_p);  // 初始化链表
void linklist_print(Node* head_p);  // 从头到尾输出链表的值
Node* linklist_nodeAtIndex(Node* head_p, int index);  // 按索引查询链表的节点
void linklist_removeByIndex(Node** head_p, int index);  // 按索引移除移除节点
void free_linklist(Node** head_p);  // 释放链表所有节点

#endif