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
void printList(LinkList L);		//打印链表
LNode* getElem(LinkList L, int i);	//按位查找
int locateElem(LinkList L, ElemType e);	//按值查找
bool initListByHead(LinkList* L); //头插法建立链表
bool initListTail(LinkList* L); //尾插法建立链表
bool insertNextNode(LNode* p, ElemType e);	//在指定结点之后插入新结点
bool insertPriorNode(LinkList L, LNode* p, ElemType e);	//在指定结点之前插入新结点
bool insertList(LinkList L, int i, ElemType e);	//按位插入----后插法
bool insertListByForward(LinkList L, int i, ElemType e);	//按位插入---前插法
bool deleteElem(LinkList L, int i, ElemType* e);	//按位删除
bool destroyList(LinkList* L);	//销毁链表
bool isEmpty(LinkList L);		//判空
int length(LinkList L);			//求表长



/*3、链表的常用函数：打印输出*/
void printList(LinkList L)
{
	if (NULL == L)
	{
		printf("链表不存在\n");
		return;
	}
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
	}
	return true;
}
/*5、链表的基本操作：查找*/
// 按位查找
LNode* getElem(LinkList L, int i)
{
	if (i < 0)	//判断i的合法性
	{
		return NULL;
	}
	LNode* p = L->next;				//p指向第一个结点
	int j = 1;					//j为计数器,代表当前结点的位序
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
	LNode* p = L->next;					//p指向第一个结点
	int i = 1;							//i为计数器,链表位序从1开始
	// 因为 && 运算符的规则是, 只要有一个为假,就不再执行后面的判断,所以当这里的p != NULL成立时,才会执行后面的p->data != e
	while (p != NULL && p->data != e)	//循环查找数据域为e的结点
	{
		p = p->next;					//p指向下一个结点
		i++;							//计数器加1
	}
	if (p == NULL)						//查找失败
	{
		return 0;
	}
	return i;							//返回数据域为e的结点的位序
}

/*6、链表的基本操作：插入*/
// 在指定结点之后插入新结点
bool insertNextNode(LNode* p, ElemType e)
{
	// 判断结点是否为空
	if (NULL == p)
	{
		printf("结点为空\n");
		return false;
	}

	// 创建一个新结点
	LNode* newNode = createNewNode(e);
	if (NULL == newNode)	//内存分配失败
	{
		printf("内存分配失败\n");
		return false;
	}

	// 后插法插入新结点
	newNode->next = p->next;	//新结点的指针域指向p的下一个结点
	p->next = newNode;		//p的指针域指向新结点
	return true;
}

// 在指定结点之前插入新结点
bool insertPriorNode(LinkList L, LNode* p, ElemType e)
{
	// 判断结点是否为空
	if (NULL == p)
	{
		printf("结点为空\n");
		return false;
	}

	/*
	// 前插法插入新结点方法一，时间复杂度O(n)
	LNode* q = L;	//q指向头结点
	while (q->next != p)	//查找p的前一个结点
	{
		q = q->next;
	}
	if(NULL == q)	//查找失败
	{
		printf("查找前置结点失败\n");
		return false;
	}
	// 创建一个新结点
	LNode *newNode = createNewNode(e);
	if (NULL == newNode)	//内存分配失败
	{
		printf("内存分配失败\n");
		return false;
	}
	newNode->next = p;	//新结点的指针域指向p
	q->next = newNode;	//q的指针域指向新结点
	return true;
	*/

	// 前插法插入新结点方法二，时间复杂度O(1)
	// 创建一个新结点
	LNode* newNode = createNewNode(e);
	if (NULL == newNode)	//内存分配失败
	{
		printf("内存分配失败\n");
		return false;
	}
	newNode->next = p->next;	//新结点的指针域指向p的下一个结点
	p->next = newNode;		//p的指针域指向新结点
	ElemType temp = p->data;	//交换数据域
	p->data = newNode->data;
	newNode->data = temp;
	return true;
}

// 按位插入 --- 后插法
bool insertList(LinkList L, int i, ElemType e)
{
	printf("操作：在单链表的第%d个位置插入元素%d\n", i, e);
	// 后插法思路:先找到第i-1个结点,然后在第i-1个结点后插入新结点
	// 判断插入位置i的合法性
	if (i < 1)
	{
		printf("插入位置不合法\n");
		return false;
	}

	// 查找第i个结点
	LNode* p = getElem(L, i - 1);
	if (p == NULL)					//查找失败
	{
		printf("查找第%d个结点失败\n", i);
		return false;
	}

	// 调用后插法插入新结点函数
	return insertNextNode(p, e);
}

// 按位插入 --- 前插法
bool insertListByForward(LinkList L, int i, ElemType e)
{
	printf("操作：在单链表的第%d个位置插入元素%d\n", i, e);
	// 前插法思路:先找到第i个结点,然后在第i个结点前插入新结点
	// 判断插入位置i的合法性
	if (i < 1)
	{
		printf("插入位置不合法\n");
		return false;
	}

	// 查找第i个结点
	LNode* p = getElem(L, i);
	if (p == NULL)					//查找失败
	{
		printf("查找第%d个结点失败\n", i);
		return false;
	}

	// 调用前插法插入新结点函数
	return insertPriorNode(L, p, e);

	/*
		前插法有其局限性：如果插入位置是表长+1，前插法无法实现
		因为在定位时，表长+1的位置会被定位到NULL，此时无法找到前一个结点
		除非在定位时，判断插入位置是否为表长+1，如果是，就直接插入到表尾，但这样会增加代码的复杂度
	*/
}


/*7、链表的基本操作：删除*/
// 按位删除
bool deleteElem(LinkList L, int i, ElemType* e)
{
	// 判断删除位置i的合法性
	if (i < 1)
	{
		printf("删除位置不合法\n");
		return false;
	}

	// 查找第i-1个结点
	LNode* p = getElem(L, i - 1);
	if (p == NULL || p->next == NULL)	//查找失败
	{
		printf("查找第%d个结点失败\n", i - 1);
		return false;
	}

	// 删除第i个结点
	LNode* q = p->next;		//q指向第i个结点
	if (NULL != e)
	{
		*e = q->data;			//保存第i个结点的数据域
	}
	p->next = q->next;		//删除第i个结点
	free(q);				//释放第i个结点的内存
	q = NULL;				//q指向NULL,防止产生野指针
	return true;
}

// 按值删除
bool deleteElemByValue(LinkList L, ElemType e)
{
	// 查找值为e的结点
	LNode* p = L;	//p指向头结点
	while (p->next != NULL && p->next->data != e)	//循环查找数据域为e的结点
	{
		p = p->next;	//p指向下一个结点
	}
	if (p->next == NULL)	//查找失败
	{
		printf("查找值为%d的结点失败\n", e);
		return false;
	}

	// 删除值为e的结点
	LNode* q = p->next;		//q指向值为e的结点
	p->next = q->next;		//删除值为e的结点
	free(q);				//释放值为e的结点的内存
	q = NULL;				//q指向NULL,防止产生野指针
	return true;
}


/*8、链表的基本操作：销毁链表*/
bool destroyList(LinkList* L)
{
	// 释放所有结点的内存
	while (NULL != (*L)->next)
	{
		deleteElem(*L, 1, NULL);
	}

	// 释放头结点的内存
	free(*L);
	*L = NULL;

	return true;
}

/*9、链表的常用函数：判空*/
bool isEmpty(LinkList L)
{
	return NULL == L->next;
}

/*10、链表的常用函数：求表长*/

int length(LinkList L)
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
	LinkList L;				//声明一个链表
	initListTail(&L);		//初始化链表
	printList(L);			//打印链表

	insertListByForward(L, 1, 100);		//在第一个位置插入100
	printList(L);			//打印链表

	insertListByForward(L, 2, 200);		//在第二个位置插入200
	printList(L);			//打印链表

	insertList(L, length(L) + 1, 300);		//在最后一个位置插入300
	printList(L);	//打印链表

	// 按值查找测试
	int pos = locateElem(L, 300);	//查找300的位置
	printf("300的位置为：%d\n", pos);

	printf("链表的长度为：%d\n", length(L));	//输出链表的长度

	// 按位删除测试
	deleteElem(L, 1, NULL);	//删除第一个结点
	printList(L);	//打印链表

	deleteElem(L, 3, NULL);	//删除中间结点
	printList(L);	//打印链表

	deleteElem(L, length(L), NULL);	//删除最后一个结点
	printList(L);	//打印链表

	// 按值删除测试
	deleteElemByValue(L, 200);	//删除值为200的结点
	printList(L);	//打印链表
	deleteElemByValue(L, 5959);	//删除不存在的结点

	destroyList(&L);	//销毁链表
	printList(L);	//打印链表

	return 0;
}