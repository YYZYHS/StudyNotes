/**
 * @brief 双链表练习代码
 * @file main.c
 * @date 2024年8月7日
 * @version 1.0
 * @author YYZYHS
 * @note
 *		这是一个双链表的练习代码,计划实现双链表的基本操作:
 *		1.初始化双链表
 * 		2.销毁双链表
 *		3.清空双链表
 *      4.判断双链表是否为空
 *		5.获取双链表的长度
 */

#include <stdlib.h>
#include <stdio.h>
#include <cstdbool>

// 定义元素类型
typedef int Element;

// 定义双链表结点
typedef struct DNode
{
	Element data;			// 数据域
	struct DNode* prior;	// 前驱指针
	struct DNode* next;		// 后继指针
}DNode, * DLinkList;

/**
* @brief 初始化双链表
 * @param L 双链表
 * @return 初始化成功返回1,否则返回0
 */

int main() {
	printf("Hello, World!\n");
	return 0;
}
