#include <stdio.h>                          //标准输入输出
#include <stdlib.h>                         //标准库---malloc函数、free函数所需

typedef int Elemtype;                       // 定义节点值类型
/* 链表节点结构体 */
typedef struct LNode {
    Elemtype val;                            // 节点值
    struct LNode *next;                      // 指向下一节点的指针
}  LNode, *LinkList;                         // LNode为节点的结构体类型，LinkList为指向节点的指针类型

/* 构造函数 */
LNode *newLNode(Elemtype val) {
    LNode *node;                             // 定义一个节点指针
    node = (LNode *) malloc(sizeof(LNode));  // 为节点分配内存
    node->val = val;                         // 为节点赋值
    node->next = NULL;                       // 将节点的指针域置为空
    return node;                             // 返回指向节点的指针
}

int main()
{
    /*带头节点的单链表的初始化*/
    // 创建链表
    LinkList list1 = NULL;
    // 创建头结点(又称哑结点),头结点不存储具体的数据，只是为了方便操作
    LNode *dummy = newLNode(0);
    // 将头结点连接到链表上
    list1 = dummy;
    // 此处模拟初始化链表 1 -> 3 -> 2 -> 5 -> 4
    // 初始化各个节点
    LNode *node1 = newLNode(1);
    LNode *node2 = newLNode(3);
    LNode *node3 = newLNode(2);
    LNode *node4 = newLNode(5);
    LNode *node5 = newLNode(4);
    // 连接各个节点
    dummy->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    /*不带头节点的单链表的初始化*/
    // 创建链表
    LNode *list2 = NULL;
    // 此处模拟初始化链表 1 -> 3 -> 2 -> 5 -> 4
    // 初始化各个节点
    LNode *node11 = newLNode(1);
    LNode *node12 = newLNode(3);
    LNode *node13 = newLNode(2);
    LNode *node14 = newLNode(5);
    LNode *node15 = newLNode(4);
    // 连接各个节点
    node11->next = node12;
    node12->next = node13;
    node13->next = node14;
    node14->next = node15;
    // 将链表头指针指向第一个节点
    list2 = node11;
}
