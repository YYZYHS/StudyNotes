#include <iostream>                                // 输入输出流

using namespace std;                               // 使用标准命名空间
typedef int Elemtype;                              // 定义Elemtype为int类型
/* 链表节点结构体 */
typedef struct LNode {
    Elemtype val;                                   // 节点值
    LNode *next;                                    // 指向下一节点的指针

    // 构造函数，当以LNode(Elemtype x)方式初始化时，自动赋值val=x, next=nullptr
    LNode(Elemtype x) : val(x), next(nullptr) {}
} LNode, *LinkList;                                 // LNode为节点的结构体类型，LinkList为指向节点的指针类型

int main()
{
    /* 带头结点的链表 */
    // 创建链表
    LinkList list1 = nullptr;
    // 创建头结点(又称哑结点),头结点不存储具体的数据，只是为了方便操作
    LinkList dummy = new LNode(0);
    // 将头结点连接到链表上
    list1 = dummy;
    // 此处模拟初始化链表 1 -> 3 -> 2 -> 5 -> 4
    // 初始化各个节点
    LNode *node1 = new LNode(1);
    LNode *node2 = new LNode(3);
    LNode *node3 = new LNode(2);
    LNode *node4 = new LNode(5);
    LNode *node5 = new LNode(4);
    // 连接各个节点
    dummy->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    /* 不带头结点的链表 */
    // 创建链表
    LinkList list2 = nullptr;
    // 此处模拟初始化链表 1 -> 3 -> 2 -> 5 -> 4
    // 初始化各个节点
    LNode *node11 = new LNode(1);
    LNode *node12 = new LNode(3);
    LNode *node13 = new LNode(2);
    LNode *node14 = new LNode(5);
    LNode *node15 = new LNode(4);
    // 连接各个节点
    node11->next = node12;
    node12->next = node13;
    node13->next = node14;
    node14->next = node15;
    // 将链表头指针指向第一个节点
    list2 = node11;


}
