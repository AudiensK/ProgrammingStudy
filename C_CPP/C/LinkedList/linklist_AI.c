#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node {
    int data;               // 数据域
    struct Node* next;      // 指针域，指向下一个节点
} Node;

// 创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败！\n");
        exit(1);
        // exit() 是一个标准库函数，用于立即终止程序的执行。它的原型定义在 <stdlib.h> 头文件中
        // 调用 exit() 会导致程序立即结束，并返回到操作系统。程序中未执行的代码（如 main() 函数中剩余的语句）将被跳过。
        // 参数 status 是一个整数，作为程序的退出状态码返回给操作系统。通常：
        //     status == 0 表示程序正常结束（成功）。
        //     status != 0（如 1）表示程序异常结束（失败）。
        // 可以使用 EXIT_SUCCESS 和 EXIT_FAILURE 宏（定义在 <stdlib.h> 中）来提高代码可读性。
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 在链表头部插入节点
Node* insertAtHead(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;  // 返回新的头节点
}

// 在链表尾部插入节点
Node* insertAtTail(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;  // 空链表直接返回新节点
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// 删除指定值的第一个节点
Node* deleteNode(Node* head, int key) {
    Node* current = head;
    Node* previous = NULL;

    // 找到要删除的节点
    while (current != NULL && current->data != key) {
        previous = current;
        current = current->next;
    }

    // 节点不存在
    if (current == NULL) {
        printf("未找到值为 %d 的节点\n", key);
        return head;
    }

    // 删除头节点
    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    return head;
}

// 查找节点
Node* searchNode(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;  // 未找到
}

// 遍历链表
void traverseList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 释放链表内存
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// 主函数测试链表功能
int main() {
    Node* head = NULL;  // 初始化空链表

    // 插入节点
    head = insertAtHead(head, 10);     // 10 -> NULL
    head = insertAtTail(head, 20);     // 10 -> 20 -> NULL
    head = insertAtHead(head, 5);      // 5 -> 10 -> 20 -> NULL
    head = insertAtTail(head, 30);     // 5 -> 10 -> 20 -> 30 -> NULL

    printf("初始链表: ");
    traverseList(head);                // 输出: 5 -> 10 -> 20 -> 30 -> NULL

    // 删除节点
    head = deleteNode(head, 10);       // 5 -> 20 -> 30 -> NULL
    printf("删除值为10的节点后: ");
    traverseList(head);

    // 查找节点
    Node* found = searchNode(head, 20);
    if (found != NULL) {
        printf("找到值为20的节点\n");
    } else {
        printf("未找到值为20的节点\n");
    }

    // 释放链表
    freeList(head);

    return 0;
} 