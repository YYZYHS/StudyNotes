//【1】预编译部分
#include <stdio.h>
#include <stdlib.h>

//【2】宏定义部分 ---- bool
#define bool char
#define true 1
#define false 0
//【3】自定义数据元素类型
typedef int ElemType;
//【4】单链表的结构体
typedef struct LNode
{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;

//【5】单链表的初始化（头结点的初始化）
bool InitLinkList(LinkList L)
{
    L->data = 0;    //头结点的data域用来存储表长
    L->next = NULL; //头结点的next域用来指向链表的第一个结点
}

LNode* InitLinkList_1()//第二种初始化方法
{
    LNode *L = (LNode*)malloc(sizeof(LNode));
    L->data = 0;    //头结点的data域用来存储表长
    L->next = NULL; //头结点的next域用来指向链表的第一个结点
    return L;
}

//【6】单链表的打印
bool PrintLinkList(LinkList L)
{
    LNode *p;
    p = L;
    while(p->next)
    {
        p = p->next;
        printf("%d-->",p->data);
    }
    printf("NULL\n");
    return true;
}

//【7】单链表的头插法创建链表
bool HeadInsertLinkList(LinkList L)
{
    LNode *NewNode;             //新结点
    ElemType NewNode_data;      //新节点的数据域值
    printf("Please enter a number(9999 means the end):");
    scanf("%d",&NewNode_data);
    while(NewNode_data != 9999)
    {
        //进行插入操作
        NewNode = (LNode*)malloc(sizeof(LNode));
        NewNode->next = L->next;
        L->next = NewNode;
        NewNode->data = NewNode_data;
        L->data++;
        printf("Please enter a number(9999 means the end):");
        scanf("%d",&NewNode_data);
    }
    return true;
}

//【8】单链表的尾插法创建链表
bool TailInsertLinkList(LinkList L)
{
    LNode *NewNode;//指向新结点的指针
    LNode *TailNode = L;//指向尾结点的指针
    ElemType NewNode_data;//新结点的data域
    while(TailNode->next != NULL)
    {
        TailNode = TailNode->next;
    }
    printf("Please enter a number(9999 means the end):");
    scanf("%d",&NewNode_data);
    while(NewNode_data != 9999)
    {
        NewNode = (LNode*)malloc(sizeof(LNode));
        NewNode->data = NewNode_data;
        TailNode->next = NewNode;
        NewNode->next = NULL;
        TailNode = NewNode;
        L->data++;
        printf("Please enter a number(9999 means the end):");
        scanf("%d",&NewNode_data);
    }
    return true;
}

//【9】按位查找数据元素
LNode* GetElem(LinkList L,int i)
{
    //[1]判断i的合法性
    if(i == 0)
    {
        printf("The Linklist's element you are looking for does not exist!\nReturn the head pointer of the Linklist!\n");
        return L;
    }
    if(i < 1 || i > L->data)
    {
        printf("The Linklist's element you are looking for does not exist!\nReturn NULL!\n");
        return NULL;
    }
    //[2]查找数据元素
    LNode *p = L;
    for(int j = 1; j <= i;j++)
    {
        p = p->next;
    }
    return p;
}

//【10】按值查找数据元素
LNode* LocateElem(LinkList L,ElemType e)
{
    if(!L->next)
    {
        printf("This Linklist is empty!\n");
        return L;
    }
    LNode *p = L;
    while(p->next)
    {
        p = p->next;
        if(p->data == e)
        return p;
    }
    printf("The Linklist's element you are looking for does not exist!\n");
    return NULL;
}

//【11】单链表的按位插入
bool LocalInsertElem(LinkList L,int i,ElemType e)
{
    //[1]判断i的合法性
    if(i < 1 || i > (L->data + 1))
    {
        printf("The position of the element to be inserted is invalid!\n");
        return false;
    }
    //[2]插入新元素
    LNode *p = GetElem(L,i-1);
    LNode *NewNode = (LNode*)malloc(sizeof(LNode));
    NewNode->data = e;
    NewNode->next = p->next;
    p->next = NewNode;
    L->data++;
    return true;
}

//【12】单链表的按位删除
bool LocalDeletElem(LinkList L,int i,ElemType *e)
{
    //[1]检查i的合法性
    if(!L->next)
    {
        printf("This linklist is empty!\n");
        *e = 9999;
        return false;
    }
    if(i < 1 || i > L->data)
    {
        printf("The position of the element to be deloeted is invalid!\n");
        *e = 9999;
        return false;
    }
    //[2]删除指定元素
    LNode *p = GetElem(L,i-1);//待删除元素的前驱结点
    LNode *q = p->next;//待删除元素
    p->next = q->next;
    *e = q->data;
    free(q);
    L->data--;
    return true;
}
//【13】销毁单链表
bool DestoryLinkList(LinkList L)
{
    int e;
    while(L->data)
    {
        LocalDeletElem(L,1,&e);
        PrintLinkList(L);
    }
    free(L);
}


int main()
{
    LinkList L;//L是一个指针
    L = (LNode*)malloc(sizeof(LNode));
    InitLinkList(L);
    // HeadInsertLinkList(L);
    TailInsertLinkList(L);
    PrintLinkList(L);
    DestoryLinkList(L);
    return 0;
}
