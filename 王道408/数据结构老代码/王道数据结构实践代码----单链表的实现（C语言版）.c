#include <stdio.h>
#include <stdlib.h>

//C语言自定义bool操作
#define bool char
#define false 0
#define true 1

/*数据元素类型*/
typedef int ElemType;

/*单链表结构体定义*/
typedef struct LNode        //定义单链表结点类型
{
    ElemType data;          //每个结点存放一个数据元素
    struct LNode *next;     //指针指向下一节点
}LNode,*LinkList;

/*
    上面的代码等价于
    typedef struct Lnode Lnode;
    typedef struct Lnode * Linklist;
*/

//LinkList L; //声明一个指向单链表第一个结点的指针,这种方法代码可读性更强
/*
    上面的代码也可写成:
    LNode *L;
    //声明一个指向单链表第一个结点的指针,但这种方法可读性不强,
    //无法第一时间看出L是指向整个链表的头指针,还是仅仅是个新的结点
*/

//链表初始化函数
LinkList ListInit()
{
    //[1]申请一块LinkList类型的存储空间给L
    LinkList L = (LinkList)malloc(sizeof(LinkList));
    //[2]设置L的指针域为空
    L->next = NULL;
    //返回L指针
    return L;
}

//创建新结点
LNode* createNote(int data)
{
    //[1]为新节点申请空间
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    //[2]如果内存满了,则分配失败,返回0
    if(newNode == NULL) 
    {
        printf("分配结点失败,请检查内存!");
        return NULL;
    }
    //[3]为新节点的数据域和指针域分别赋值
    newNode->data = data;
    newNode->next = NULL;
    //[4]返回新节点的指针
    return newNode;
}


//头插法
bool ListHeadInsert(LinkList L,ElemType data)
{
    //[1]调用创建新节点函数,为其赋值
    LNode* newNode = createNote(data);
    //[2]先给新节点的指针域赋值(指向原来链表的第一个节点)
    newNode->next = L->next;
    //[3]再让头结点指向新结点
    L->next = newNode;
    //[4]返回true,表示插入成功
    return true;
}

//尾插法(不带尾指针的尾插法)
bool ListTailInsert(LinkList L,ElemType data)
{
    //[1]申请新节点
    LNode* newNode = createNote(data);
    //[2]生成工具指针
    LNode* p = L->next;
    //[3]遍历链表,找到最后的元素,用工具指针指向它
    while (p->next != NULL)
    {
        p = p->next;
    }
    //[4]尾插入新节点
    newNode->next = NULL;
    p->next = newNode;
}

//按位序插入(for循环发,后面有用函数封装起来的简易版)
bool ListInsert(LinkList L,int i,ElemType data)
{
    int count;
    LNode* newNode = createNote(data);
    LNode* p = L;
    for ( count = 0; count < i-1; count++)
    {
        if(p->next == NULL) return false;
        p = p->next;
    }
    newNode->next = p->next;
    p->next = newNode;
}

//按序号查找节点值
LNode *GetElem(LinkList L,int i)
{
    //[1]设置一个变量计数
    int j = 1;
    //[2]设置待返回的结点p,开始指向第一个结点
    LNode *p = L->next;
    //[3]检查参数
    if(i == 0) {p = L; return p;}
    if(i < 1) { return NULL;}
    //[4]开始循环
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    //[5]输出值,此处返回第i个结点的指针，若i大于表长，则返回NULL
    return p;
}

//按值查找表节点
LNode* LocateElem(LinkList L,ElemType e)
{
    //[1]设置待返回的结点p,开始指向第一个结点
    LNode *p = L->next;
    //[2]开始循环比较
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    //[3]/找到后返回该结点指针，否则返回ULL
    return p;
}

//后插插入节点操作
bool LocateTailInsert(LinkList L,int i,ElemType e)
{
    //[1]生成指向目标节点的指针p
    LNode* p = GetElem(L,i-1);
    //[2]生成新节点s
    LNode* s = createNote(e);
    //[3]插入
    s->next = p->next;
    p->next = s;
}

//前插插入节点操作
bool LocateHeadInsert(LinkList L,int i,ElemType e)
{
    //[1]生成指向目标节点的指针p
    LNode* p = GetElem(L,i);
    //[2]生成新节点s
    LNode* s = createNote(e);
    //[3]插入
    ElemType temp = p->data;
    s->next = p->next;
    p->next = s;
    p->data = s->data;
    s->data = temp;
}

//删除指定结点(遍历方法)
bool ElemDelete(LinkList L,int i)
{
    //[1]定位
    LNode *p = GetElem(L,i-1);
    LNode *q = p->next;
    //[2]删除
    p->next = q->next;
    //[3]释放被删除节点
    free(q);
}

//删除指定节点(删除后继的方法)
bool LocateElemDelete(LinkList L,int i)
{
    //[1]定位
    LNode *p = GetElem(L,i);
    LNode *q = p->next;
    //[2]复制数据
    p->data = q->data;
    p->next = q->next;
    //[3]释放结点
    free(q);
}

//求表长
int ListLength(LinkList L)
{
    int count = 0;
    while (L->next != NULL)
    {
        L = L->next;
        count++;
    }
    return count;    
}

//打印输出
void Listprint(LinkList L)
{
    LNode* p = L->next;
    while (p != NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
    printf("\n");
}


int main()
{
    //[1]定义一个链表
    LinkList L = NULL;
    // printf("%d",L->next);//可以尝试,此时L->next无法输出
    //[2]将链表初始化
    L = ListInit();
    ListHeadInsert(L,1);
    ListHeadInsert(L,2);
    ListHeadInsert(L,3);
    ListHeadInsert(L,4);
    ListHeadInsert(L,5);
    ListTailInsert(L,6);
    ListTailInsert(L,7);
    ListTailInsert(L,8);
    ListTailInsert(L,9);
    ListTailInsert(L,10);
    ListInsert(L,3,666);
    ListInsert(L,1,88888);
    LocateTailInsert(L,8,6969);
    LocateHeadInsert(L,2,3333);
    ElemDelete(L,3);
    LocateElemDelete(L,5);
    Listprint(L);
    printf("链表长度为:%d\n",ListLength(L));
    return 0;
}