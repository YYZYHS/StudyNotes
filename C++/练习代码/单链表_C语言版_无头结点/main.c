#include <stdlib.h>				// 标准库函数,包含了一些常用的函数,如malloc(),free(),exit()等
#include <stdio.h>				// 标准输入输出库函数,包含了一些常用的输入输出函数,如printf(),scanf()等
#include <stdbool.h>			// C99b标准引入的头文件,定义了bool、true、false等宏

/*
 *		这是C语言版不带头结点的单链表的简单实现案例
 *		主要包括了单链表的创建、插入、删除、查找、遍历等操作
 *
 *		由于不带头结点,所以在插入、删除等操作时需要特别注意处理头结点的情况
 */

 /*1、前置准备*/
typedef int ElemType;		// 定义链表存储的数据类型,这里为整型
typedef struct LNode
{
	ElemType data;			// 数据域
	struct LNode* next;		// 指针域
}LNode, * LinkList;			// LNode为结点类型,LinkList为结点指针类型

/*2、链表操作函数声明*/
void printList(LinkList L);								// 打印输出链表
LNode* createNewNode(ElemType e);						// 创建新结点
bool initList(LinkList* L);								// 初始化一个空表
bool initListByHeadInsert(LinkList* L);					// 用前插法初始化一个链表
bool initListByTailInsert(LinkList* L);					// 用尾插法初始化一个链表
LNode* getElem(LinkList L, int i);						// 按位查找
int locateElem(LinkList L, ElemType e);					// 按值查找
bool insertPreNode(LinkList* L, LNode* p, ElemType e);	// 在指定结点的前面插入新结点
bool insertNextNode(LNode* p, ElemType e);				// 在指定结点的后面插入新结点
bool insertElem(LinkList* L, int i, ElemType e);			// 按位插入---后插法
bool insertElemByHead(LinkList* L, int i, ElemType e);	// 按位插入---前插法
bool deleteElem(LinkList* L, int i);						// 删除
bool destroyList(LinkList *L);							// 销毁
bool isEmpty(LinkList L);								// 判空
int length(LinkList L);									// 获取长度


/*3、链表的常用函数：打印输出*/
void printList(LinkList L)
{
	if(NULL == L)											// 如果链表为空
	{
		printf("链表为空\n");
		return;
	}
	LNode* p = L;											// 从头结点开始遍历
	while (p != NULL)										// 遍历链表
	{
		printf("%d-->", p->data);							// 输出结点数据
		p = p->next;										// 移动到下一个结点
	}
	printf("NULL\n");										// 输出链表结束标志
}

/*4、链表的基本操作：初始化*/
// 创建新结点
LNode* createNewNode(ElemType e)
{
	LNode* newNode = (LNode*)malloc(sizeof(LNode));			// 为新结点分配内存
	if (newNode == NULL)									// 内存分配失败
	{
		printf("内存分配失败\n");
		exit(0);
	}
	newNode->data = e;										// 将数据存入新结点
	newNode->next = NULL;									// 将新结点的指针域置空
	return newNode;											// 返回新结点
}

// 初始化一个空表
bool  initList(LinkList* L)
{
	// 因为不带头结点，所以初始化时不需要分配头结点，直接将头指针置空即可
	*L = NULL;
	return true;
}

// 用前插法初始化一个链表
bool initListByHeadInsert(LinkList* L)
{
	if(*L != NULL)														// 如果链表不为空，先置空
	{
		*L = NULL;
	}

	ElemType data = 9999;												// 用于存放输入的数据
	while (true)														// 循环输入数据
	{
		printf("请输入一个元素的值,输入9999视作结束创建动作：");
		int len = scanf("%d", &data);									// 输入数据
		if (data == 9999)
		{
			break;
		}
		LNode* newNode = createNewNode(data);							// 创建新结点
		if(NULL == newNode)												// 创建失败
		{
			printf("内存分配失败!创建链表失败！\n");
			destroyList(*L);											// 销毁已创建的链表
			return false;
		}
		newNode->next = *L;												// 将新结点插入到表头
		*L = newNode;													// 更新头指针
	}
	printf("链表创建成功\n");
	return true;
}

// 用尾插法初始化一个链表
bool initListByTailInsert(LinkList* L)
{
	if(NULL != *L)														// 如果链表不为空，先置空
	{
		*L = NULL;
	}
	ElemType data = 9999;												// 用于存放输入的数据
	LNode *tail = NULL;													// 尾指针
	while (true)														// 循环输入数据
	{
		printf("请输入一个元素的值,输入9999视作结束创建动作：");
		int len = scanf("%d", &data);									// 输入数据
		if (data == 9999)
		{
			break;
		}
		LNode* newNode = createNewNode(data);							// 创建新结点
		if(NULL == newNode)												// 创建失败
		{
			printf("内存分配失败!创建链表失败！\n");
			destroyList(*L);											// 销毁已创建的链表
			return false;
		}
		if(NULL == *L)													// 如果是第一个结点
		{
			*L = newNode;												// 更新头指针
			tail = newNode;												// 更新尾指针
		}
		else
		{
			tail->next = newNode;										// 将新结点插入到表尾
			tail = newNode;												// 更新尾指针
		}
	}
	printf("链表创建成功\n");
	return true;
}

/*5、链表的基本操作：查找*/
// 按位查找
LNode* getElem(LinkList L, int i)
{
	if(isEmpty(L))													// 如果链表为空
	{
		printf("链表为空\n");
		return NULL;
	}
	if(i < 1)														// 位置不合法
	{
		printf("位置不合法\n");
		return NULL;
	}
	LNode* p = L;													// 从头结点开始遍历
	int j = 1;														// 计数器
	while (p != NULL && j < i)										// 遍历链表
	{
		p = p->next;												// 移动到下一个结点
		j++;														// 计数器加1
	}
	if(j == i && NULL != p)											// 找到了第i个结点
	{
		return p;													// 返回该结点
	}
	else															// 没找到
	{
		printf("第%d个元素不存在\n", i);
		return NULL;
	}
}

// 按值查找
int locateElem(LinkList L, ElemType e)
{
	if(isEmpty(L))													// 如果链表为空
	{
		printf("链表为空\n");
		return -1;
	}
	LNode* p = L;													// 从头结点开始遍历
	int i = 1;														// 计数器
	while (p != NULL && p->data != e)								// 遍历链表
	{
		p = p->next;												// 移动到下一个结点
		i++;														// 计数器加1
	}
	if(p != NULL)													// 找到了元素
	{
		return i;													// 返回元素位置
	}
	else															// 没找到
	{
		printf("元素%d不存在\n", e);
		return -1;
	}
}

/*6、链表的基本操作：插入*/
// 在指定结点的前面插入新结点
bool insertPreNode(LinkList* L, LNode* p, ElemType e)
{
	if(NULL == p)													// 如果指定结点为空
	{
		printf("指定结点为空\n");
		return false;
	}
	/*
	// 前插法插入新结点方法一，时间复杂度O(n)
	// 如果指定结点是头结点
	LNode* q = L;													// 创建一个指针q，从头结点开始遍历,寻找p的前驱结点
	while (q != p)
	{
		q = q->next;
	}
	if (q == NULL)
	{
		printf("指定结点不在链表中\n");
		return false;
	}
	if(p == L)
	{
		LNode* newNode = createNewNode(e);							// 创建新结点
		if(NULL == newNode)											// 创建失败
		{
			printf("内存分配失败!插入失败！\n");
			return false;
		}
		newNode->next = L;											// 将新结点插入到表头
		L = newNode;												// 更新头指针
		return true;
	}
	else
	{
		LNode* newNode = createNewNode(e);							// 创建新结点
		if(NULL == newNode)											// 创建失败
		{
			printf("内存分配失败!插入失败！\n");
			return false;
		}
		newNode->next = p;											// 将新结点插入到指定结点的前面
		q->next = newNode;											// 更新指定结点的前驱结点的指针域
		return true;
	}
	*/

	// 前插法插入新结点方法二，时间复杂度O(1)
	LNode* newNode = createNewNode(e);								// 创建新结点
	if(NULL == newNode)												// 创建失败
	{
		printf("内存分配失败!插入失败！\n");
		return false;
	}
	if(p == *L)														// 如果指定结点是头结点
	{
		newNode->next = *L;											// 将新结点插入到表头
		*L = newNode;												// 更新头指针
		return true;
	}
	else
	{
		// 先以后插法插入新结点，然后交换数据域
		newNode->next = p->next;									// 后插法插入新结点
		p->next = newNode;
		ElemType temp = p->data;									// 交换数据域
		p->data = newNode->data;
		newNode->data = temp;
	}
}

// 在指定结点的后面插入新结点
bool insertNextNode(LNode* p, ElemType e)
{
	if(NULL == p)													// 如果指定结点为空
	{
		printf("指定结点为空\n");
		return false;
	}
	LNode* newNode = createNewNode(e);								// 创建新结点
	if(NULL == newNode)												// 创建失败
	{
		printf("内存分配失败!插入失败！\n");
		return false;
	}
	newNode->next = p->next;										// 将新结点插入到指定结点的后面
	p->next = newNode;												// 更新指定结点的指针域
	return true;
}

// 按位插入 --- 后插法
bool insertElem(LinkList* L, int i, ElemType e)
{
	if (i < 1)														// 位置不合法
	{
		printf("插入位置不合法\n");
		return false;
	}
	
	if (i == 1)
	{
		LNode* newNode = createNewNode(e);							// 创建新结点
		if (NULL == newNode)											// 创建失败
		{
			printf("内存分配失败!插入失败！\n");
			return false;
		}
		newNode->next = *L;											// 将新结点插入到表头
		*L = newNode;												// 更新头指针
		return true;

	}
	LNode* p = getElem(*L, i - 1);									// 获取第i-1个结点
	return insertNextNode(p, e);									// 在第i-1个结点后插入新结点
}

// 按位插入 --- 前插法
bool insertElemByHead(LinkList* L, int i, ElemType e)
{
	if(i < 1)														// 位置不合法
	{
		printf("插入位置不合法\n");
		return false;
	}

	LNode* p = getElem(*L, i);										// 获取第i个结点
	return insertPreNode(L, p, e);									// 在第i个结点前插入新结点
}


/*7、链表的基本操作：删除*/
bool deleteElem(LinkList* L, int i)
{
	if(i < 1)	// 位置不合法
	{
		printf("删除位置不合法\n");
		return false;
	}

	if(isEmpty(*L))	// 如果链表为空
	{
		printf("链表为空\n");
		return false;
	}

	if(i == 1)	// 删除头结点
	{
		LNode* p = *L;	// 保存头结点
		*L = (*L)->next;	// 更新头指针
		free(p);	// 释放头结点
		return true;
	}
	else
	{
		LNode* p = getElem(*L, i - 1);	// 获取第i-1个结点
		if(p == NULL || p->next == NULL)	// 如果第i-1个结点不存在或者第i个结点不存在
		{
			printf("删除位置不合法\n");
			return false;
		}
		LNode* q = p->next;	// 保存第i个结点
		p->next = q->next;	// 删除第i个结点
		free(q);	// 释放第i个结点
		return true;
	}
}


/*8、链表的基本操作：销毁*/
bool destroyList(LinkList *L)
{
	if(NULL == L)	// 如果链表指针为空
	{
		printf("链表指针为空\n");
		return false;
	}
	LNode* p = *L;	// 从头结点开始销毁
	while (p != NULL)
	{
		LNode* q = p->next;	// 保存下一个结点
		free(p);	// 释放当前结点
		p = q;	// 移动到下一个结点
	}
	*L = NULL;	// 头指针置空
	return true;
}

/*9、链表的常用函数：判空*/
bool isEmpty(LinkList L)
{
	return L == NULL;
}

/*10、链表的常用函数：获取长度*/
int length(LinkList L)
{
	int len = 0;
	LNode* p = L;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

/*11、主函数*/
int main()
{
	// 以下是测试代码

	// 1、初始化三个链表
	printf("开始测试，首先初始化三个测试链表\n");
	LinkList L1 = NULL, L2 = NULL, L3 = NULL;
	printf("开始初始化第一个链表，此链表为空表\n");
	initList(&L1);
	printf("开始初始化第二个链表，此链表用前插法初始化\n");
	initListByHeadInsert(&L2);
	printf("开始初始化第三个链表，此链表用尾插法初始化\n");
	initListByTailInsert(&L3);

	// 2、第一次打印输出，测试判空和求表长
	printf("开始打印第一个链表：\n");
	printList(L1);
	printf("开始打印第二个链表：\n");
	printList(L2);
	printf("开始打印第三个链表：\n");
	printList(L3);
	printf("L1是否为空：%s\n", isEmpty(L1) ? "是" : "否");
	printf("L2是否为空：%s\n", isEmpty(L2) ? "是" : "否");
	printf("L3是否为空：%s\n", isEmpty(L3) ? "是" : "否");
	printf("L1的长度：%d\n", length(L1));
	printf("L2的长度：%d\n", length(L2));
	printf("L3的长度：%d\n", length(L3));

	// 3、L2按位查找，分别测试首尾元素和中间的元素
	printf("开始测试L2按位查找\n");
	LNode* p1 = getElem(L2, 1);
	LNode* p2 = getElem(L2, 3);
	LNode* p3 = getElem(L2, length(L2));
	LNode* p4 = getElem(L2, length(L2) + 1);
	printf("L2第1个元素：%d\n", p1->data);
	printf("L2第3个元素：%d\n", p2->data);
	printf("L2最后一个元素：%d\n", p3->data);
	printf("L2第%d个元素：%s\n", length(L2) + 1, p4 == NULL ? "不存在" : "存在");

	// 4、L2按值查找，分别测试首尾元素和中间的元素
	printf("开始测试L2按值查找\n");
	int i1 = locateElem(L2, 1);
	int i2 = locateElem(L2, 3);
	int i3 = locateElem(L2, length(L2));
	printf("元素1的位置：%d\n", i1);
	printf("元素3的位置：%d\n", i2);
	printf("最后一个元素的位置：%d\n", i3);

	// 5、L3按位插入，分别以前插、后插的方式，在表头，表尾，表中插入元素
	printf("开始测试L3按位插入\n");
	printf("在表头以前插方式插入元素100,%s\n", insertElemByHead(&L3, 1, 100) ? "成功" : "失败");
	printf("在表尾以前插方式插入元素200,%s\n", insertElemByHead(&L3, length(L3) + 1, 200) ? "成功" : "失败");
	printf("在链表倒数第二个位置以前插方式插入元素300,%s\n", insertElemByHead(&L3, length(L3), 300) ? "成功" : "失败");
	printList(L3);
	printf("在表头以后插方式插入元素400,%s\n", insertElem(&L3, 1, 400) ? "成功" : "失败");
	printf("在表尾以后插方式插入元素500,%s\n", insertElem(&L3, length(L3) + 1, 500) ? "成功" : "失败");
	printf("在链表倒数第二个位置以后插方式插入元素600,%s\n", insertElem(&L3, length(L3), 600) ? "成功" : "失败");
	printList(L3);

	// 6、L3删除元素，分别删除表头、表尾、表中元素
	printf("开始测试L3删除元素\n");
	printf("删除表头元素：%s\n", deleteElem(&L3, 1) ? "成功" : "失败");
	printList(L3);
	printf("删除表尾元素：%s\n", deleteElem(&L3, length(L3)) ? "成功" : "失败");
	printList(L3);
	printf("删除表中元素：%s\n", deleteElem(&L3, length(L3) / 2) ? "成功" : "失败");
	printList(L3);

	// 7、销毁三个链表
	printf("开始销毁三个链表,为了测试销毁空表，先将L1置为空表\n");
	while (!isEmpty(L1))
	{
		deleteElem(&L1, 1);
	}
	printf("销毁L1：%s\n", destroyList(&L1) ? "成功" : "失败");
	printf("销毁L2：%s\n", destroyList(&L2) ? "成功" : "失败");
	printf("销毁L3：%s\n", destroyList(&L3) ? "成功" : "失败");
	printList(L1);
	printList(L2);
	printList(L3);

	// 8、结束语
	printf("测试结束\n");
	return 0;

}