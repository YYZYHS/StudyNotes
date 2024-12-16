#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//设置bool
#define bool char
#define true 1
#define false 0

//定义顺序表的数据Elemtype
typedef int Elemtype;

/*定义结点和链表的数据结构*/
//【1】循环单链表的结点结构
typedef struct Node
{
    Elemtype data;
    struct Node *next;
}Node,*PNode;

//【2】循环单链表的链表结构
typedef struct CLinkList
{
    PNode head;//指向头节点
    PNode tail;//指向尾结点
    int length;
}CLinkList;

/*循环单链表的初始化*/
bool CLinkListInit(CLinkList *L)
{
    //[1]申请头结点
    PNode HeadNode = (PNode)malloc(sizeof(Node));
    //[2]判错
    assert(HeadNode);
    //[3]然单链表结构体和头结点结构体相连
    L->head = L->tail = HeadNode;
    L->length = 0;
    //[4]让头节点的next指针指向头指针
    HeadNode->next = L->head;
}

/*创建新节点*/
PNode CreatNode(Elemtype e)
{
    //[1]申请新节点的空间
    PNode newNode = (PNode)malloc(sizeof(Node));
    //[2]为新节点赋值
    newNode->data = e;
    newNode->next = NULL;
}

/*定位*/
//【1】按位序定位
PNode GetElem(CLinkList *L,int i)
{
    //[1]判断要定位的结点是否合法或特殊
    assert(L);//检查L链表是否存在
    if(i == 0) return L->head;//返回头指针的情况，用于按位删除或者插入时使用
    if(L->length < i || i < 1) return NULL;//检查输入的节点位序是否存在
    //[2]生成定位指针
    PNode p = L->head->next;
    //[3]循环定位
    while (i > 1)
    {
        p = p->next;
        i--;
    }
    //[4]返回p
    return p;
}
//【2】按内容值定位
PNode LocateElem(CLinkList *L,Elemtype e)
{
    //[1]判错
    assert(L);//检查L链表是否存在
    //[2]生成定位指针
    PNode p = L->head->next;
    //[3]循环定位
    for (int i = 1; i < L->length; i++)
    {
        if(p->data == e) return p;
        p = p->next;
    }
    return NULL;
}

/*王道书上的判空方式*/
//按照头结点的指针是否指向头指针为判空条件
bool IfEmpty(CLinkList *L)
{
    return (L->head->next == L->head);
}

/*插入新节点*/
//【1】头插法
bool CLinListHeadInsert(CLinkList *L,Elemtype e)
{
    //[1]创建新节点
    PNode newNode = CreatNode(e);
    //[2]插入新节点
    newNode->next = L->head->next;
    L->head->next = newNode;
    //[3]判断这是否是第一个结点
    if(L->head == L->tail)
    L->tail = newNode;
    //[4]链表长度加1
    L->length++;
    //[5]插入成功，返回信息
    return 1;
}
//【2】尾插法
bool CLinListTailInsert(CLinkList *L,Elemtype e)
{
    //[1]创建新节点
    PNode newNode = CreatNode(e);
    //[2]定位最后一个节点
    //可以用for循环，也可以用表长定位
    //如果有尾指针，可直接用尾指针
    PNode p = L->tail;//其实不设置p也可以，直接用L->tail就行了
    //[3]插入新节点
    newNode->next = p->next;
    p->next = newNode;
    L->tail = newNode;
    //[4]链表长度加1
    L->length++;
    //[5]插入成功，返回信息
    return 1;
}
//【3】按位插入
bool CLinListLocalInsert(CLinkList *L,int i,Elemtype e)
{
    //[1]判断插入的位置是否合法或特殊
    if(i > L->length+1 || i < 1)  return 0;
    if(IfEmpty(L))              return 0;
    //[2]定位
    PNode p = GetElem(L,i-1);
    //[3]创建新节点
    PNode newNode = CreatNode(e);
    //[4]插入新节点
    newNode->next = p->next;
    p->next = newNode;
    //[5]链表长度加1
    L->length++;
    //[6]插入成功，返回信息
    return 1;    
}

/*遍历链表*/
int printList(CLinkList *L)
{
    //[1]判空
    if(IfEmpty(L))  
    {
        printf("表空！\n");
        return 0;
    }
    //[2]生成定位指针
    PNode p = L->head->next;
    //[2]for循环遍历
    printf("HEADNODE ==> ");
    for(int i = 1;i <= L->length;i++)
    {
        printf("%d ==> ",p->data);
        p = p->next;
        if(i == L->length)
        printf("HEADNODE\n");
    }
    return 0;
}

/*删除节点*/
//【1】按位删除
bool DeleteNode(CLinkList *L,int i)
{
    //[1]判断插入的位置是否合法
    if(i > L->length || i < 1)  return 0;
    if(IfEmpty(L))              return 0;
    //[2]定位待删除节点和它的前一节点
    PNode p = GetElem(L,i-1);//待删除节点的前一节点
    PNode q = p->next;//待删除节点
    //[3]执行删除操作
    p->next = p->next->next;
    free(q);
    //[4]链表长度-1
    L->length--;
    //[5]删除成功，返回信息
    return 1; 
}
//【2】删除所有节点
bool DestoryNode(CLinkList *L)
{
    //[1]判断插入的位置是否合法
    if(IfEmpty(L))              return 0;
    //[2]生成指向待删除节点的指针
    PNode p = NULL;
    //[3]for循环陆续删除当前的第一个节点
    for (int i = 1; i <= L->length; i++)
    {
        p = L->head->next;
        L->head->next = L->head->next->next;
        free(p);
    }
    //[4]显示删除所有节点的信息，并返回参数
    printf("已删除所有节点！\n");
    return 0;
}

/*主函数：测试代码*/
int main()
{
    CLinkList L;
    CLinkListInit(&L);
    CLinListHeadInsert(&L,1);
    CLinListHeadInsert(&L,2);
    CLinListHeadInsert(&L,3);
    CLinListHeadInsert(&L,4);
    CLinListHeadInsert(&L,5);
    CLinListHeadInsert(&L,6);
    printList(&L);
    CLinListTailInsert(&L,7);
    CLinListTailInsert(&L,8);
    CLinListTailInsert(&L,9);
    CLinListTailInsert(&L,10);
    printList(&L);
    CLinListLocalInsert(&L,11,66666);
    printList(&L);
    printf("%d\n",LocateElem(&L,2)->data);
    DeleteNode(&L,1);
    printList(&L);
    DestoryNode(&L);
    printList(&L);
    return 0;
}

