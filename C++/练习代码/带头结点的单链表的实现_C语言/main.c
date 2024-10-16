#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义数据元素类型
typedef int ElemType;

// 定义链表结点类型
typedef struct LNode
{
	ElemType data;			// 数据域，用于存放数据元素
	struct LNode* next;		// 指针域，用于存放后继结点的地址
} LNode, * LinkList;		// LNode 为结点类型，用于强调结点；LinkList 为结点指针类型，用于强调链表

int main() 
{
	printf("Hello, World!\n");
	return 0;
}