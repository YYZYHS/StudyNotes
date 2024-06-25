#include <stdio.h>		//标准输入输出
#include <stdlib.h>		//标准库函数,包含了一些常用的函数,如malloc(),free(),exit(),system()
#include <stdbool.h>	//C99标准引入的头文件,定义了bool,true,false

/*
 *  这是C语言版带头结点的单链表的简单实现案例
 *  主要实现了链表的初始化,插入,删除,查找,遍历等功能
 *
 *  按照带头结点的单链表的实现思路,头结点不存储数据,只是作为一个头指针使用，但因为本案例中，
 *  头结点的数据域是int类型，所以头结点的数据域可以用来记录表长，也可以不用，视具体情况而定
 */

 /*1、前置准备*/
typedef int ElemType;			//定义链表存储的数据类型,这里以int为例
typedef struct LNode
{
	ElemType data;				//数据域
	struct LNode* next;			//指针域
}LNode, * LinkList;				//LNode为结点类型,LinkList为链表指针类型

/*2、链表操作函数声明*/
bool initList(LinkList* L);		//链表初始化
LNode* createNewNode(ElemType e);	//创建一个新结点

bool initListByHead(LinkList* L); //头插法建立链表
bool initListTail(LinkList* L); //尾插法建立链表

/*3、链表的常用函数：打印输出*/
void printList(LinkList L)
{
	printf("链表中的元素为: ");
	LNode* p = L->next;			//p指向第一个结点
	while (p != NULL)			//p不为空,即p指向的结点存在
	{
		printf("%d-->", p->data);	//输出结点数据
		p = p->next;			//p指向下一个结点
	}
	printf("NULL");				//输出NULL表示链表结束
	printf("\n");
}

/*4、链表的基本操作：初始化*/
// 创建一个带头结点的空链表
bool initList(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(LNode));	//分配一个头结点
	if (*L == NULL)							//内存分配失败
	{
		return false;
	}
	(*L)->data = 0;							//将头结点的数据域利用起来，记录链表的长度
	(*L)->next = NULL;						//头结点的指针域置空
	return true;
}

// 创建一个新结点
LNode* createNewNode(ElemType e)
{
	LNode* node = (LNode*)malloc(sizeof(LNode));	//分配一个新结点
	if (node == NULL)								//内存分配失败
	{
		return NULL;
	}
	node->data = e;									//新结点的数据域赋值
	node->next = NULL;								//新结点的指针域置空
	return node;
}

// 头插法建立链表
bool initListByHead(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(LNode));	//分配一个头结点
	if (*L == NULL)							//内存分配失败
	{
		return false;
	}
	(*L)->data = 0;							//将头结点的数据域利用起来，记录链表的长度
	(*L)->next = NULL;						//头结点的指针域置空

	while (true)							//循环输入元素的值
	{
		ElemType value;						//定义一个变量存储输入的值
		printf("请输入一个元素的值,输入9999视作结束创建动作：");
		int len = scanf("%d", &value);		//输入一个值
		if (value == 9999)					//判定结束输入的条件
		{
			break;
		}
		LNode* newNode = createNewNode(value);	//创建一个新结点
		if (NULL == newNode)				//内存分配失败
		{
			return false;
		}
		newNode->next = (*L)->next;			//新结点的指针域指向头结点的下一个结点
		(*L)->next = newNode;				//头结点的指针域指向新结点
		(*L)->data++;						//链表长度加1
	}
	return true;
}
// 尾插法建立链表
bool initListTail(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(LNode));	//分配一个头结点
	if (*L == NULL)							//内存分配失败
	{
		return false;
	}
	(*L)->data = 0;							//将头结点的数据域利用起来，记录链表的长度
	(*L)->next = NULL;						//头结点的指针域置空

	LNode* tail = *L;						//tail指向头结点
	while (true)							//循环输入元素的值
	{
		ElemType value;						//定义一个变量存储输入的值
		printf("请输入一个元素的值,输入9999视作结束创建动作：");
		int len = scanf("%d", &value);		//输入一个值
		if (value == 9999)					//判定结束输入的条件
		{
			break;
		}
		LNode* newNode = createNewNode(value);	//创建一个新结点
		if (NULL == newNode)				//内存分配失败
		{
			return false;
		}
		tail->next = newNode;				//尾结点的指针域指向新结点
		tail = newNode;						//尾结点指向新结点
		(*L)->data++;						//链表长度加1
	}
	return true;
}
/*5、链表的基本操作：查找*/
// 按位查找
LNode* getElem(LinkList L, int i)
{
	if (i < 0 || i > L->data)	//判断i的合法性
	{
		return NULL;
	}
	LNode* p = L->next;			//p指向第一个结点
	int j = 1;					//j为计数器,链表位序从1开始
	while (p != NULL && j < i)	//循环查找第i个结点
	{
		p = p->next;			//p指向下一个结点
		j++;					//计数器加1
	}
	return p;					//返回第i个结点的指针
}

// 按值查找
int locateElem(LinkList L, ElemType e)
{
	LNode* p = L->next;			//p指向第一个结点
	int i = 1;					//i为计数器,链表位序从1开始
	while (p != NULL && p->data != e)	//循环查找数据域为e的结点
	{
		p = p->next;			//p指向下一个结点
		i++;					//计数器加1
	}
	if (p == NULL)				//查找失败
	{
		return 0;
	}
	return i;					//返回数据域为e的结点的位序
}

/*6、链表的基本操作：插入*/
// 按位插入 --- 前插法
bool insertListByForward(LinkList L, int i, ElemType e)
{
	// 思路：要插入到第i个位置，且是插在某个结点的前面，所以要找到第i个结点，并将第i-1个结点的指针域指向新结点

	// 判断i插入位置的合法性
	if (i < 1 || i > L->data + 1)	
	{
		return false;
	}

	// 寻找第i-1个结点
	LNode* p = getElem(L, i - 1);
	if(NULL == p)	// 查找失败
	{
		return false;
	}

	// 创建一个新结点
	LNode* newNode = createNewNode(e);
	if(NULL == newNode)	// 内存分配失败
	{
		return false;
	}
	
	// 前插法插入新结点
	newNode->next = p->next;
	p->next = newNode;

	// 链表长度加1
	L->data++;
	return true;
}

// 按位插入 --- 后插法
bool insertListByBack(LinkList L, int i, ElemType e)
{
	if (i < 1 || i > L->data + 1)	//判断i的合法性
	{
		return false;
	}
	LNode* p = getElem(L, i);		//查找第i个结点
	if (p == NULL)					//查找失败
	{
		return false;
	}
	LNode* newNode = createNewNode(e);	//创建一个新结点
	if (newNode == NULL)			//内存分配失败
	{
		return false;
	}
	newNode->next = p->next;		//新结点的指针域指向第i+1个结点
	p->next = newNode;			//第i个结点的指针域指向新结点
	L->data++;					//链表长度加1
	return true;
}

/*7、链表的基本操作：删除*/
// 按位删除

// 按值删除

/*8、链表的基本操作：销毁链表*/
bool destroyList(LinkList* L)
{

}

/*9、链表的常用函数：判空*/
bool isEmpty(LinkList L)
{
	return NULL == L->next;
}

/*10、链表的常用函数：求表长*/
// 基于本案例特殊情况下，求表长的时间复杂度可以为O(1)
int length1(LinkList L)
{
	return L->data;		// 头结点的数据域存储的是链表的长度
}

// 基于一般情况下，求表长的时间复杂度为O(n)
int length2(LinkList L)
{
	int len = 0;		//初始化长度为0
	LNode* p = L->next;
	while (p != NULL)	//遍历链表
	{
		len++;
		p = p->next;
	}
	return len;
}

int main()
{
	LinkList L;		//声明一个链表
	initListTail(&L);

	printList(L);	//打印链表
	printf("链表的长度为：%d\n", length1(L));	//输出链表的长度
	printf("链表的长度为：%d\n", length2(L));	//输出链表的长度

	return 0;
}