#ifndef _LINKLIST_NODE_H_
#define _LINKLIST_NODE_H_

typedef struct _node {
    int value;
    struct _node *next_p;
} Node;

// typedef struct _list {
//     Node* head;
//     Node* tail;  // 还可以加一个指针永远指向链表最后一个结构
// } List;

Node* linklist_create(void);  // 创建一个空的单向链表
void linklist_init(Node** head_p);  // 初始化链表
// void linklist_init(List* plist);
void linklist_print(const Node* head_p);  // 从头到尾输出链表的值
Node* linklist_nodeAtIndex(Node* head_p, int index);  // 按索引查询链表的节点
int linklist_removeByValue(Node** heap_p, int value);  // 按值查询并删除找到的第一个值相同的节点
void linklist_removeByIndex(Node** head_p, int index);  // 按索引移除移除节点
void free_linklist(Node** head_p);  // 释放链表所有节点

#endif