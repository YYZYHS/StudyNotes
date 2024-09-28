/**
* @brief 静态顺序表的实现
* @file main.c
* @auther YYZYHS
* @date 2024年8月17日
* @version 1.0
* @note 本代码是静态顺序表的实现，包括初始化、插入、删除、查找、输出等操作
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 顺序表的特点是表中元素的逻辑顺序与其物理顺序相同，
// 线性表中的任一数据元素都可以随机存取，所以线性表的顺序存储结构是一种随机存取的存储结构。
// 通常用高级程序设计语言中的数组来描述线性表的顺序存储结构。
// 
// 
// ====================数据类型别名========================
// 别名的好处是可以简化代码，提高代码的可读性
typedef int Elemtype;  /// 静态顺序表的数据类型，此处为整型

// ====================全局变/常量========================
// 在静态顺序表中，其容量会在代码编译时即确定，代码运行时不可更改
#define MAX_SIZE 15				/// 静态顺序表的最大长度，用来规定顺序表的最大容量

// ====================结构体定义====================
/// 静态顺序表的结构体
typedef struct SqList
{
	Elemtype m_data[MAX_SIZE];	/// 静态顺序表的数据域
	int m_length;					/// 静态顺序表的长度
}SqList;						/// 静态顺序表的别名

// ====================函数声明======================

// 静态顺序表的基本操作
bool initList(SqList *L); /// 静态顺序表的初始化
bool destoryList(SqList *L); /// 静态顺序表的销毁
bool insertList(SqList *L, int i, Elemtype e); /// 静态顺序表的插入
bool deleteList(SqList* L, int i, Elemtype *e); /// 静态顺序表的删除
bool getElem(const SqList *L, int i, Elemtype *e); /// 静态顺序表的查找
bool locateElem(const SqList *L, Elemtype e, int *i); /// 静态顺序表的定位
bool isEmpty(const SqList *L); /// 判断静态顺序表是否为空
int length(const SqList *L); /// 获取静态顺序表的长度
bool printList(const SqList *L); /// 输出静态顺序表

// 静态顺序表的扩展操作
bool push_front(SqList* L, Elemtype e); /// 头插
bool push_back(SqList *L, Elemtype e); /// 尾插
bool pop_front(SqList* L, Elemtype* e); /// 头删
bool pop_back(SqList *L, Elemtype *e); /// 尾删

// 静态顺序表的高阶操作
bool sortListByBubble(SqList *L); /// 冒泡排序
bool sortListBySelect(SqList *L); /// 选择排序
bool mergeList(SqList *L1, SqList *L2, SqList *L3); /// 两个有序表的合并

// 测试函数
int test(); /// 测试函数

// ====================函数定义======================


int main()
{
	test();
	return 0;
}

/**
* @brief 初始化静态顺序表
* @param L 待初始化的静态顺序表
* @return 初始化成功返回true，否则返回false
* @note
*		函数功能：
*			本函数用于初始化一个静态顺序表，将其长度置为0
* 		函数思路：
*			1. 判断参数是否合法，如果顺序表的指针无效（即为NULL），则初始化失败
* 			2. 将静态顺序表的长度置为0
* 		注意：
* 			1. 因为要修改静态顺序表的数据，所以此处传入的是一个指向静态顺序表的指针，这样在函数内部修改静态顺序表的数据会影响到外部
* 			2. 静态顺序表的初始化操作的时间复杂度为O(1)，空间复杂度为O(1)
* 			3. 因为静态顺序表的存储空间是在栈上分配的，所以无需考虑内存的释放问题，当静态顺序表所在的函数或者代码块执行完毕后，静态顺序表的存储空间会自动释放
*/
bool initList(SqList* L)
{
	printf("[INFO] initList() is called!\n");
	// 判断参数是否合法
	if (NULL == L)
	{
		printf("[ERROR] initList() 参数错误,L为空，初始化失败！\n");
		return false;
	}
	// 初始化长度
	L->m_length = 0;
	printf("[INFO] 静态顺序表初始化成功！\n");
	return true;
}

/**
 * @brief 销毁静态顺序表
 * @param L 待销毁的静态顺序表
 * @return 销毁成功返回true，否则返回false
 * @note
 * 			函数功能：
 * 					本函数用于销毁一个静态顺序表，因为静态顺序表的特殊性，此函数和清空顺序表的功能相同。
 * 			思路：
 *					1. 判断参数是否合法，如果静态顺序表的指针无效（即为NULL），则销毁失败
 * 					2.因为静态顺序表的存储空间是在栈上分配的，所以不需要手动释放内存，只需要将静态顺序表的长度置为0，以此表示静态顺序中已经没有元素。
 * 			注意：
 * 					1.因为要修改静态顺序表的数据，所以此处传入的是一个指向静态顺序表的指针，这样在函数内部修改静态顺序表的数据会影响到外部。
 */
bool destoryList(SqList *L)
{
	printf("[INFO] destoryList() is called!\n");
	// 判断参数是否合法
	if (NULL == L)
	{
		printf("[ERROR] destoryList() 参数错误,L为空，销毁失败！\n");
		return false;
	}
	// 销毁静态顺序表
	L->m_length = 0;
	printf("[INFO] 静态顺序表销毁成功！\n");
	return true;
}

/**
* @brief 静态顺序表的按位插入
* @param L 待插入的静态顺序表
* @param i 待插入的位置
* @param e 待插入的元素
* @return 插入成功返回true，否则返回false
* @note
* 		函数功能：
* 		本函数用于在静态顺序表的第i个位置插入元素e，如果插入位置不合法或者静态顺序表已满，则插入失败
*		思路：
* 			1. 判断参数是否合法，包括静态顺序表是否无效（即L为NULL），插入位置是否合法，静态顺序表是否已满，只要有一个条件不满足，则插入失败
* 			2. 将第i个元素及之后的元素依次后移，为新元素腾出位置
* 			3. 将新元素插入到第i个位置
* 			4. 静态顺序表的长度加1
*		注意：
* 			1. 在顺序表中，位序i从1开始，而数组下标从0开始，不要混淆
* 			2. 因为需要修改静态顺序表的数据，所以此处顺序表传入的是指针，这样在函数内部修改静态顺序表的数据会影响到外部
* 			3. 插入操作的时间复杂度为O(n)，空间复杂度为O(1)
*			4. 在for循环中，j的本质是数组下标，当需要用j表示元素位序时，应该+1，
* 			   所以根据“将第i个元素及之后的元素后移”这句话，位序j+1的范围为[i,length],
*			   所以数组下标j的范围为[i-1,length-1]
*/
bool insertList(SqList* L, int i, Elemtype e)
{
	printf("[INFO] insertList() is called：尝试在第%d位插入新元素%d\n", i, e);
	// 判断参数是否合法
	if (NULL == L) // 判断静态顺序表是否为空
	{
		printf("[ERROR] insertList() 参数错误,L为空，插入失败！\n");
		return false;
	}
	if (i < 0 || i > L->m_length + 1) // 判断插入位置是否合法
	{
		printf("[ERROR] insertList() 参数错误,插入位置不合法，插入失败！\n");
		return false;
	}
	if (L->m_length >= MAX_SIZE) // 判断静态顺序表是否已满
	{
		printf("[ERROR] insertList() 参数错误,静态顺序表已满，插入失败！\n");
		return false;
	}
	// 插入元素
	for(int j = L->m_length-1; j >= i-1; j--) // 将第i个元素及之后的元素后移
	{
		L->m_data[j+1] = L->m_data[j];
	}
	L->m_data[i-1] = e; // 插入新元素
	L->m_length++;	// 表长加一
	printf("[INFO] 静态顺序表插入元素成功！\n");
	return true;
}

/**
 * @brief 静态顺序表的删除操作
 * @param L 待删除的静态顺序表
 * @param i 待删除的位置
 * @param e 删除的元素
 * @return 删除成功返回true，否则返回false
 * @note
 * 		函数功能：
 * 				本函数用于删除静态顺序表中第i个位置的元素，并将其存储到e中
 * 		思路：
 * 				1. 判断参数是否合法，包括静态顺序表是否无效（即L为NULL），静态顺序表是否为空，删除位置是否合法，只要有一个条件不满足，则删除失败。
 * 				2. 若通过合法性检查，将待删除元素存储到e中。
 * 				3. 将第i个元素之后的元素前移。
 * 
 * 		注意：
 * 				1. 在顺序表中，位序i从1开始，而数组下标从0开始，不要混淆。
 * 				2. 因为需要修改静态顺序表的数据，所以此处顺序表传入的是指针，这样在函数内部修改静态顺序表的数据会影响到外部。
 * 				3. 在for循环中，j的本质是数组下标，当用j来表示元素位序时，应该+1，
 *				   所以根据“将第i个元素之后的元素前移”这句话，位序j+1的范围为[i+1,length],
 *				   因此，数组下标j的范围为[i,length-1]。
 * 				4. 删除操作的时间复杂度为O(n)，空间复杂度为O(1)。
 */
bool deleteList(SqList* L, int i, Elemtype* e)
{
	printf("[INFO] deleteList() is called：尝试删除第%d位的元素\n", i);
	// 判断参数是否合法
	if (NULL == L) // 判断静态顺序表是否为空
	{
		printf("[ERROR] deleteList() 参数错误,L为空，删除失败！\n");
		return false;
	}
	if (i < 1 || i > L->m_length) // 判断删除位置是否合法
	{
		printf("[ERROR] deleteList() 参数错误,删除位置不合法，删除失败！\n");
		return false;
	}
	// 删除元素
	*e = L->m_data[i - 1]; // 保存删除的元素
	for(int j = i; j <= L->m_length - 1; j++) // 将第i个元素之后的元素前移
	{
		L->m_data[j - 1] = L->m_data[j];
	}

	L->m_length--; // 表长减一
	printf("[INFO] 静态顺序表删除元素成功！\n");
	return true;
}

/**
* @brief 静态顺序表的按位查找
* @param L 待查找的静态顺序表
* @param i 待查找的位置
* @param e 查找到的元素
* @return 查找成功返回true，否则返回false
* @note
* 	函数功能：
* 		本函数用于查找静态顺序表中第i个位置的元素，并将被删除元素存储到e中。
*	思路：
*		1. 判断参数是否合法，包括静态顺序表的指针是否为空，顺序表是否为空，查找位置是否合法，如果有一个条件不满足，则查找失败
* 		2. 查找元素，将第i个位置的元素（即数组下标为i-1的元素）存储到e中
*	注意：
* 		1. 在顺序表中，位序i从1开始，而数组下标从0开始，不要混淆
*		2. 查找操作本身不需要修改静态顺序表的数据，所以此处传入的是一个指向静态顺序表的常量指针(const SqList*)，
*		   传入指针是为了减少内存开销，传入常量是为了防止在不需要修改的情况下修改了数据
*		3. 顺序表的查找操作的时间复杂度为O(1)，空间复杂度为O(1)
* 		4. 参数i指的是元素的位序，从1开始，而数组下标是从0开始的，不要混淆
*/
bool getElem(const SqList* L, int i, Elemtype* e)
{
	printf("[INFO] getElem() is called：尝试查找第%d位的元素\n", i);
	// 判断参数是否合法
	if(NULL == L)
	{
		printf("[ERROR] getElem() 参数错误,L为空，查找失败！\n");
		return false;
	}
	// 判断查找位置是否合法，该判断中已经隐含了静态顺序表是否为空的判断
	if(i < 1 || i > L->m_length)
	{
		printf("[ERROR] getElem() 参数错误,查找位置不合法，查找失败！\n");
		return false;
	}
	// 查找元素
	*e = L->m_data[i - 1];
	return true;
}

/**
* @brief 静态顺序表的按值查找
* @param L 待查找的静态顺序表
* @param e 待查找的元素
* @param i 查找到的位置
* @return 查找成功返回true，否则返回false
* @note
*		函数功能：
* 			本函数用于查找静态顺序表中元素值为e的元素，并将其位置存储到i中
*		思路：
*			1. 判断参数是否合法，包括静态顺序表指针是否有效，顺序表是否为空，只要有一个合法条件不满足，则查找失败
* 			2. 查找元素，从第一个元素开始遍历，查找值为e的元素，如果找到，则将其位置存储到i中，返回true，否则返回false
*		注意：
* 			1. 查找操作本身不需要修改静态顺序表的数据，所以传入的是一个指向静态顺序表的常量指针（const SqList*），
* 			   传入指针是为了减少内存开销，传入常量是为了防止在不需要修改的情况下修改了数据
* 			2. 最基础的按值查找有其局限性，即只能找到第一个符合条件的元素，如果有多个符合条件的元素，只会返回第一个符合的元素的位序
* 			3. 查找操作的时间复杂度为O(n)，空间复杂度为O(1)
* 			4. 顺序表的位序是从1开始的，而数组的下标是从0开始的，不要混淆
*/
bool locateElem(const SqList* L, Elemtype e, int* i)
{
	printf("[INFO] locateElem() is called：尝试查找元素值为%d的元素\n", e);
	// 判断参数是否合法
	if(NULL == L)
	{
		printf("[ERROR] locateElem() 参数错误,L为空，查找失败！\n");
		return false;
	}
	// 查找元素，for循环中已经隐含了静态顺序表是否为空的判断，即L->length == 0时，不会进入for循环
	for(*i = 0; *i < L->m_length; (*i)++)
	{
		if(L->m_data[*i] == e)
		{
			(*i)++; // 位序从1开始
			return true;
		}
	}
	printf("[ERROR] 未找到值为%d的元素！\n", e);
	return false;
}

/**
* @brief 静态顺序表的测试函数
* @return 测试成功返回0
* @note
* 	 本函数用于测试静态顺序表的基本操作，包括初始化、判空、输出表长、输出静态顺序表等操作
*/
int test()
{
	printf("[INFO] ↓========================↓\n[INFO] 现在开始测试静态顺序表的基本操作\n");
	printf("\n");
	printf("[INFO] ↓========================↓\n[INFO] 测试1：生成并初始化一个静态顺序表，同步测试判空、输出表长、输出静态顺序表（空表）的操作\n");
	SqList L;
	initList(&L);
	printf("[INFO] ↓========================↓\n[INFO] 执行判空操作\n");
	printf("[INFO] 静态顺序表当前%s\n", isEmpty(&L) ? "为空" : "不为空");
	printf("[INFO] ↓========================↓\n[INFO] 输出表长\n");
	printf("[INFO] 静态顺序表当前的长度为%d\n", length(&L));
	printf("[INFO] ↓========================↓\n[INFO] 输出静态顺序表\n");
	printList(&L);
	printf("[INFO] ↓========================↓\n[INFO] 测试1结束\n");
	printf("\n\n\n");

	printf("[INFO] ↓========================↓\n[INFO] 测试2：在静态顺序表中插入元素，插入完成后，再次执行判空、输出表长、输出静态顺序表的操作\n");
	printf("[INFO] ↓========================↓\n[INFO] 开始顺序插入元素\n");
	insertList(&L, 1, 1);
	insertList(&L, 2, 2);
	insertList(&L, 3, 3);
	insertList(&L, 4, 4);
	insertList(&L, 5, 5);
	insertList(&L, 6, 6);
	insertList(&L, 7, 7);
	insertList(&L, 8, 8);
	printf("[INFO] ↓========================↓\n[INFO] 顺序插入元素完成，打印静态顺序表\n");
	printList(&L);

	printf("[INFO] ↓========================↓\n[INFO] 尝试在顺序表的不同位置插入元素\n");
	printf("[INFO] ↓========================↓\n[INFO] 开始在第3位插入元素100\n");
	insertList(&L, 3, 100);
	printf("[INFO] ↓========================↓\n[INFO] 开始在表头插入元素200\n");
	insertList(&L, 1, 200);
	printf("[INFO] ↓========================↓\n[INFO] 开始在表尾插入元素300\n");
	insertList(&L, length(&L) + 1, 300);
	printf("[INFO] ↓========================↓\n[INFO] 在顺序表的不同位置插入元素完成，打印静态顺序表\n");
	printList(&L);


	printf("[INFO] ↓========================↓\n[INFO] 开始测试插入不符合安全性要求的元素\n");
	insertList(&L, length(&L) + 2, 100);
	insertList(NULL, 12, 100);
	printf("[INFO] ↓========================↓\n[INFO] 执行判空操作\n");
	printf("[INFO] 静态顺序表当前%s\n", isEmpty(&L) ? "为空" : "不为空");
	printf("[INFO] ↓========================↓\n[INFO] 输出表长\n");
	printf("[INFO] 静态顺序表当前的长度为%d\n", length(&L));
	printf("[INFO] ↓========================↓\n[INFO] 输出静态顺序表\n");
	printList(&L);
	printf("[INFO] ↓========================↓\n[INFO] 测试2结束\n");
	printf("\n\n\n");

	printf("[INFO] ↓========================↓\n[INFO] 测试3：测试按位查找和按值查找功能\n");
	printf("[INFO] ↓========================↓\n[INFO] 测试按位查找\n");
	Elemtype e;
	if(getElem(&L, 2, &e))
	{
		printf("[INFO] 查找静态顺序表中第2位的元素成功，该元素为%d\n", e);
	}
	else
	{
		printf("[ERROR] 静态顺序表中第2位的元素查找失败！\n");
	}

	printf("[INFO] ↓========================↓\n[INFO] 测试按位查找表头和表尾元素\n");
	if(getElem(&L, 1, &e))
	{
		printf("[INFO] 查找静态顺序表中第1位的元素成功，该元素为%d\n", e);
	}
	else
	{
		printf("[ERROR] 静态顺序表中第1位的元素查找失败！\n");
	}
	int tmpPos = length(&L);
	if(getElem(&L, tmpPos, &e))
	{
		printf("[INFO] 查找静态顺序表中第%d位的元素成功，该元素为%d\n", tmpPos, e);
	}
	else
	{
		printf("[ERROR] 静态顺序表中第%d位的元素查找失败！\n", tmpPos);
	}


	printf("[INFO] ↓========================↓\n[INFO] 测试按值查找\n");
	int i;
	if(locateElem(&L, 3, &i))
	{
		printf("[INFO] 查找顺序表中元素值为3的元素成功，该元素位于第%d位\n", i);
	}
	else
	{
		printf("[ERROR] 静态顺序表中元素值为3的元素查找失败！\n");
	}

	printf("[INFO] ↓========================↓\n[INFO] 测试按位查找和按值查找中的错误情况\n");
	printf("[INFO] ↓========================↓\n[INFO] 尝试取出表长+1位的元素\n");
	tmpPos = length(&L) + 1;
	if(getElem(&L, tmpPos, &e))
	{
		printf("[INFO] 查找静态顺序表中第%d位的元素成功，该元素为%d\n", tmpPos, e);
	}
	else
	{
		printf("[ERROR] 静态顺序表中第%d位的元素查找失败！\n", tmpPos);
	}
	printf("[INFO] ↓========================↓\n[INFO] 尝试查找元素值为9999的元素\n");
	if(locateElem(&L, 9999, &i))
	{
		printf("[INFO] 查找静态顺序表中元素值为9999的元素成功，该元素位于第%d位\n", i);
	}
	else
	{
		printf("[ERROR] 静态顺序表中元素值为9999的元素查找失败！\n");
	}
	printf("[INFO] ↓========================↓\n[INFO] 测试3结束\n");
	printf("[INFO] ↓========================↓\n[INFO] 输出静态顺序表\n");
	printList(&L);
	printf("\n\n\n");



	printf("[INFO] ↓========================↓\n[INFO] 测试4：测试删除操作\n");
	printf("[INFO] ↓========================↓\n[INFO] 开始删除第3位的元素\n");
	deleteList(&L, 3, &e);
	printf("[INFO] ↓========================↓\n[INFO] 删除第3位的元素成功，删除的元素为%d\n", e);
	printf("[INFO] ↓========================↓\n[INFO] 开始删除表头的元素\n");
	deleteList(&L, 1, &e);
	printf("[INFO] ↓========================↓\n[INFO] 删除表头的元素成功，删除的元素为%d\n", e);
	printf("[INFO] ↓========================↓\n[INFO] 开始删除表尾的元素\n");
	deleteList(&L, length(&L), &e);
	printf("[INFO] ↓========================↓\n[INFO] 删除表尾的元素成功，删除的元素为%d\n", e);
	printf("[INFO] ↓========================↓\n[INFO] 删除操作完成，打印静态顺序表\n");
	printList(&L);
	printf("[INFO] ↓========================↓\n[INFO] 开始测试删除不符合安全性要求的元素\n");
	tmpPos = length(&L) + 1;
	deleteList(&L, tmpPos, &e);
	deleteList(NULL, 12, &e);
	printf("[INFO] ↓========================↓\n[INFO] 执行判空操作\n");
	printf("[INFO] 静态顺序表当前%s\n", isEmpty(&L) ? "为空" : "不为空");
	printf("[INFO] ↓========================↓\n[INFO] 输出表长\n");
	printf("[INFO] 静态顺序表当前的长度为%d\n", length(&L));
	printf("[INFO] ↓========================↓\n[INFO] 输出静态顺序表\n");
	printList(&L);
	printf("[INFO] ↓========================↓\n[INFO] 测试4结束\n");
	printf("\n\n\n");

	printf("[INFO] ↓========================↓\n[INFO] 测试5：测试销毁操作\n");
	printf("[INFO] ↓========================↓\n[INFO] 开始销毁静态顺序表\n");
	printf("[INFO] 静态顺序表销毁%s\n", destoryList(&L) ? "成功" : "失败");
	printf("[INFO] ↓========================↓\n[INFO] 执行判空操作\n");
	printf("[INFO] 静态顺序表当前%s\n", isEmpty(&L) ? "为空" : "不为空");
	printf("[INFO] ↓========================↓\n[INFO] 输出表长\n");
	printf("[INFO] 静态顺序表当前的长度为%d\n", length(&L));
	printf("[INFO] ↓========================↓\n[INFO] 输出静态顺序表\n");
	printList(&L);
	printf("[INFO] ↓========================↓\n[INFO] 测试5结束\n");
	printf("\n\n\n");

	printf("[INFO] 开始测试静态顺序表的扩展操作\n");
	printf("[INFO] ↓========================↓\n[INFO] 测试6：测试头插操作\n");
	printf("[INFO] ↓========================↓\n[INFO] 尝试在空表中头插元素100\n");
	printf("[INFO] 静态顺序表头插元素%s\n", push_front(&L, 100) ? "成功" : "失败");
	printf("[INFO] ↓========================↓\n[INFO] 尝试在非空表中头插元素1000\n");
	printf("[INFO] 静态顺序表头插元素%s\n", push_front(&L, 1000) ? "成功" : "失败");
	printf("[INFO] ↓========================↓\n[INFO] 头插操作完成，打印静态顺序表\n");
	printList(&L);
	printf("[INFO] ↓========================↓\n[INFO] 测试6结束\n");
	printf("\n\n\n");

	printf("[INFO] ↓========================↓\n[INFO] 测试7：测试尾插操作\n");
	printf("[INFO] ↓========================↓\n[INFO] 执行顺序表的销毁操作\n");
	printf("[INFO] 静态顺序表销毁%s\n", destoryList(&L) ? "成功" : "失败");
	printf("[INFO] ↓========================↓\n[INFO] 尝试在空表中尾插元素100\n");
	printf("[INFO] 静态顺序表尾插元素%s\n", push_back(&L, 100) ? "成功" : "失败");
	printf("[INFO] ↓========================↓\n[INFO] 尝试在非空表中尾插元素1000\n");
	printf("[INFO] 静态顺序表尾插元素%s\n", push_back(&L, 1000) ? "成功" : "失败");
	printf("[INFO] ↓========================↓\n[INFO] 尾插操作完成，打印静态顺序表\n");
	printList(&L);
	printf("[INFO] ↓========================↓\n[INFO] 测试7结束\n");
	printf("\n\n\n");

	printf("[INFO] ↓========================↓\n[INFO] 测试8：测试头删操作\n");
	printf("[INFO] ↓========================↓\n[INFO] 执行顺序表的销毁操作\n");
	printf("[INFO] 静态顺序表销毁%s\n", destoryList(&L) ? "成功" : "失败");
	printf("[INFO] ↓========================↓\n[INFO] 尝试在空表中头删元素\n");
	if (pop_front(&L, &e))
	{
		printf("[INFO] 静态顺序表头删元素成功，删除的元素为%d\n", e);
	}
	else
	{
		printf("[INFO] 静态顺序表头删元素失败\n");
	}	
	printf("[INFO] ↓========================↓\n[INFO] 尝试在非空表中头删元素\n");
	printf("[INFO] 先以尾插的方式插入元素1、2、3\n");
	push_back(&L, 1);
	push_back(&L, 2);
	push_back(&L, 3);
	if(pop_front(&L, &e))
	{
		printf("[INFO] 静态顺序表头删元素成功，删除的元素为%d\n", e);
	}
	else
	{
		printf("[INFO] 静态顺序表头删元素失败\n");
	}
	printf("[INFO] ↓========================↓\n[INFO] 头删操作完成，打印静态顺序表\n");
	printList(&L);
	printf("[INFO] ↓========================↓\n[INFO] 测试8结束\n");
	printf("\n\n\n");

	printf("[INFO] ↓========================↓\n[INFO] 测试9：测试尾删操作\n");
	printf("[INFO] ↓========================↓\n[INFO] 执行顺序表的销毁操作\n");
	printf("[INFO] 静态顺序表销毁%s\n", destoryList(&L) ? "成功" : "失败");
	printf("[INFO] ↓========================↓\n[INFO] 尝试在空表中尾删元素\n");
	if (pop_back(&L, &e))
	{
		printf("[INFO] 静态顺序表尾删元素成功，删除的元素为%d\n", e);
	}
	else
	{
		printf("[INFO] 静态顺序表尾删元素失败\n");
	}
	printf("[INFO] ↓========================↓\n[INFO] 尝试在非空表中尾删元素\n");
	printf("[INFO] 先以尾插的方式插入元素1、2、3\n");
	push_back(&L, 1);
	push_back(&L, 2);
	push_back(&L, 3);
	if(pop_back(&L, &e))
	{
		printf("[INFO] 静态顺序表尾删元素成功，删除的元素为%d\n", e);
	}
	else
	{
		printf("[INFO] 静态顺序表尾删元素失败\n");
	}
	printf("[INFO] ↓========================↓\n[INFO] 尾删操作完成，打印静态顺序表\n");
	printList(&L);
	printf("[INFO] ↓========================↓\n[INFO] 测试9结束\n");


	printf("[INFO] 测试静态顺序表的扩展操作结束\n");
	printf("\n\n\n");

	printf("[INFO] 开始测试静态顺序表的高阶操作\n");
	printf("[INFO] ↓========================↓\n[INFO] 测试10：测试静态顺序表的冒泡排序操作\n");
	printf("[INFO] ↓========================↓\n[INFO] 执行顺序表的销毁操作\n");
	printf("[INFO] 静态顺序表销毁%s\n", destoryList(&L) ? "成功" : "失败");
	printf("[INFO] ↓========================↓\n[INFO] 尝试对空表进行冒泡排序\n");
	printf("[INFO] 对静态顺序表空表进行冒泡排序%s\n", sortListByBubble(&L) ? "成功" : "失败");
	printf("[INFO] ↓========================↓\n[INFO] 尝试对非空表进行冒泡排序\n");
	printf("[INFO] ↓========================↓\n[INFO] 先以尾插的方式插入元素3、2、1、4、5、6、7、8\n");
	push_back(&L, 3);
	push_back(&L, 2);
	push_back(&L, 1);
	push_back(&L, 4);
	push_back(&L, 5);
	push_back(&L, 6);
	push_back(&L, 7);
	push_back(&L, 8);
	printf("[INFO] ↓========================↓\n[INFO] 输出静态顺序表\n");
	printList(&L);
	printf("[INFO] ↓========================↓\n[INFO] 执行冒泡排序操作\n");
	printf("[INFO] 对静态顺序表进行冒泡排序%s\n", sortListByBubble(&L) ? "成功" : "失败");
	printf("[INFO] ↓========================↓\n[INFO] 冒泡排序操作完成，打印静态顺序表\n");
	printList(&L);
	printf("[INFO] ↓========================↓\n[INFO] 测试10结束\n");
	printf("\n\n\n");

	printf("[INFO] ↓========================↓\n[INFO] 测试11：测试静态顺序表的选择排序操作\n");
	printf("[INFO] ↓========================↓\n[INFO] 执行顺序表的销毁操作\n");
	printf("[INFO] 静态顺序表销毁%s\n", destoryList(&L) ? "成功" : "失败");
	printf("[INFO] ↓========================↓\n[INFO] 尝试对空表进行选择排序\n");
	printf("[INFO] 对静态顺序表空表进行选择排序%s\n", sortListBySelect(&L) ? "成功" : "失败");
	printf("[INFO] ↓========================↓\n[INFO] 尝试对非空表进行选择排序\n");
	printf("[INFO] ↓========================↓\n[INFO] 先以尾插的方式插入元素3、2、1、4、5、6、7、8\n");
	push_back(&L, 3);
	push_back(&L, 2);
	push_back(&L, 1);
	push_back(&L, 4);
	push_back(&L, 5);
	push_back(&L, 6);
	push_back(&L, 7);
	push_back(&L, 8);
	printf("[INFO] ↓========================↓\n[INFO] 输出静态顺序表\n");
	printList(&L);
	printf("[INFO] ↓========================↓\n[INFO] 执行选择排序操作\n");
	printf("[INFO] 对静态顺序表进行选择排序%s\n", sortListBySelect(&L) ? "成功" : "失败");
	printf("[INFO] ↓========================↓\n[INFO] 选择排序操作完成，打印静态顺序表\n");
	printList(&L);
	printf("[INFO] ↓========================↓\n[INFO] 测试11结束\n");
	printf("\n\n\n");

	printf("[INFO] ↓========================↓\n[INFO] 测试12：测试两个有序静态顺序表的合并操作\n");
	printf("[INFO] ↓========================↓\n[INFO] 执行顺序表的销毁操作\n");
	printf("[INFO] 静态顺序表销毁%s\n", destoryList(&L) ? "成功" : "失败");
	printf("[INFO] ↓========================↓\n[INFO] 先以尾插的方式插入元素1、3、5、7\n");
	push_back(&L, 1);
	push_back(&L, 3);
	push_back(&L, 5);
	push_back(&L, 7);
	printf("[INFO] ↓========================↓\n[INFO] 输出静态顺序表1\n");
	printList(&L);
	printf("[INFO] ↓========================↓\n[INFO] 创建静态顺序表2\n");
	SqList L2;
	printf("[INFO] ↓========================↓\n[INFO] 初始化静态顺序表2\n");
	initList(&L2);
	printf("[INFO] ↓========================↓\n[INFO] 先以尾插的方式插入元素2、4、6、8\n");
	push_back(&L2, 2);
	push_back(&L2, 4);
	push_back(&L2, 6);
	push_back(&L2, 8);
	printf("[INFO] ↓========================↓\n[INFO] 输出静态顺序表2\n");
	printList(&L2);
	printf("[INFO] ↓========================↓\n[INFO] 执行合并操作\n");
	SqList L3;
	initList(&L3);
	printf("[INFO] 静态顺序表合并%s\n", mergeList(&L, &L2,&L3) ? "成功" : "失败");
	printf("[INFO] ↓========================↓\n[INFO] 合并操作完成，打印静态顺序表3\n");
	printList(&L3);
	printf("[INFO] ↓========================↓\n[INFO] 将静态顺序表2扩容，测试超过最大容量的合并情况\n");
	printf("[INFO] ↓========================↓\n[INFO] 执行顺序表2的销毁操作\n");
	printf("[INFO] 静态顺序表销毁%s\n", destoryList(&L2) ? "成功" : "失败");
	printf("[INFO] ↓========================↓\n[INFO] 为静态顺序表2插入%d个元素\n", MAX_SIZE);
	for(int i = 0; i < MAX_SIZE; i++)
	{
		push_back(&L2, i);
	}
	printf("[INFO] ↓========================↓\n[INFO] 输出静态顺序表2\n");
	printList(&L2);
	printf("[INFO] ↓========================↓\n[INFO] 执行顺序表3的销毁操作\n");
	printf("[INFO] 静态顺序表销毁%s\n", destoryList(&L3) ? "成功" : "失败");
	printf("[INFO] ↓========================↓\n[INFO] 执行合并操作\n");
	printf("[INFO] 静态顺序表合并%s\n", mergeList(&L, &L2, &L3) ? "成功" : "失败");
	printf("[INFO] ↓========================↓\n[INFO] 合并操作完成，打印静态顺序表3\n");
	printList(&L3);
	printf("[INFO] ↓========================↓\n[INFO] 测试12结束\n");


	return 0;
}

/**
* @brief 静态顺序表判空操作
* @param L 待判断的静态顺序表
* @return 静态顺序表为空返回true，否则返回false
* @note
*		函数功能：
* 			本函数用于判断静态顺序表是否为空，如果静态顺序表为空，则返回true，否则返回false
*		思路：
* 			1. 判断参数是否合法，如果静态顺序表的指针无效(即L为NULL)，则判空失败，返回false
* 			2. 如果静态顺序表的长度为0，则静态顺序表为空，返回true，否则返回false
* 		注意：
* 			1. 判空操作本身不需要修改静态顺序表的数据，所以传入的是一个指向静态顺序表的常量指针（const SqList*），
* 			   传入指针是为了减少内存开销，传入常量是为了防止在不需要修改的情况下修改了数据
* 			2. 判空操作的时间复杂度为O(1)，空间复杂度为O(1)
*/
bool isEmpty(const SqList *L)
{
	printf("[INFO] isEmpty() is called!\n");
	if(NULL == L)
	{
		printf("[ERROR] isEmpty() 参数错误,L为空，判空失败！\n");
		return false;
	}
	return L->m_length == 0;
}

/**
* @brief 输出静态顺序表的长度
* @param L 待输出的静态顺序表
* @return 返回静态顺序表的长度
* @note
*		函数功能：
* 			本函数用于输出静态顺序表的长度
* 		函数思路：
* 			1. 判断参数是否合法，如果静态顺序表的指针无效(即L为NULL)，则获取长度失败，返回-1。
* 			2. 合法性判断通过后，直接返回静态顺序表的长度
* 		注意：
* 			1. 获取长度操作本身不需要修改静态顺序表的数据，所以传入的是一个指向静态顺序表的常量指针（const SqList*），
* 			   传入指针是为了减少内存开销，传入常量是为了防止在不需要修改的情况下修改了数据
* 			2. 获取长度操作的时间复杂度为O(1)，空间复杂度为O(1)
* 			3. 静态顺序表的长度是指静态顺序表中元素的个数，而不是静态顺序表的容量
* 			4. 静态顺序表的位序是从1开始的，而数组的下标是从0开始的，不要混淆
*/
int length(const SqList* L)
{
	printf("[INFO] length() is called!\n");
	if(NULL == L)
	{
		printf("[ERROR] length() 参数错误,L为空，获取长度失败！\n");
		return -1;
	}
	return L->m_length;
}

/**
* @brief 输出静态顺序表
* @param L 待输出的静态顺序表
* @return 输出成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于输出静态顺序表的元素
* 		函数思路：
* 			1. 判断参数是否合法，如果静态顺序表的指针无效(即L为NULL)，则输出失败
* 			2. 如果静态顺序表为空，则无需输出，直接返回true
* 			3. 如果静态顺序表不为空，则依次输出静态顺序表的元素
* 		注意：
* 			1. 输出操作本身不需要修改静态顺序表的数据，所以传入的是一个指向静态顺序表的常量指针（const SqList*），
* 			   传入指针是为了减少内存开销，传入常量是为了防止在不需要修改的情况下修改了数据
* 			2. 输出操作的时间复杂度为O(n)，空间复杂度为O(1)
* 			3. 静态顺序表的位序是从1开始的，而数组的下标是从0开始的，不要混淆
*/
bool printList(const SqList* L)
{
	printf("[INFO] printList() is called!\n");
	if(NULL == L)
	{
		printf("[ERROR] printList() 参数错误,L为空，输出失败！\n");
		return false;
	}
	if(L->m_length == 0)
	{
		printf("[INFO] 静态顺序表为空，无需输出！\n");
		return true;
	}
	printf("[INFO] 静态顺序表的元素为：");
	for(int i = 0; i < L->m_length; i++)
	{
		printf("%d, ", L->m_data[i]);
	}
	printf("end\n");
	return true;
}


/**
* @brief 静态顺序表的头插
* @param L 待插入的静态顺序表
* @param e 待插入的元素
* @return 插入成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于在静态顺序表的表头插入元素e，如果静态顺序表已满，则插入失败
* 		思路：
* 			1. 判断顺序表的指针是否有效，如果无效，则插入失败
* 			2. 判断静态顺序表是否已满，如果已满，则插入失败
* 			3. 如果通过了安全性检查，将静态顺序表中的元素依次后移，为新元素腾出位置
* 			4. 将新元素插入到第1个位置
* 			5. 静态顺序表的长度加1
* 		注意：
* 			1. 头插操作的时间复杂度为O(n)，空间复杂度为O(1)
* 			2. 头插操作是在静态顺序表的表头插入元素，所以插入后，原来的第1个元素变成了第2个元素，原来的第2个元素变成了第3个元素，以此类推
* 			3. 静态顺序表的位序是从1开始的，而数组的下标是从0开始的，不要混淆
* 			4. 因为需要修改静态顺序表的数据，所以此处传入的是一个指向静态顺序表的指针，这样在函数内部修改静态顺序表的数据会影响到外部
*			5. 在for循环中，j的本质是数组下标，当需要用j表示元素位序时，应该+1，
* 			   所以根据“将第i个元素及之后的元素后移”这句话，位序j+1的范围为[i,length],
* 			   所以数组下标j的范围为[i-1,length-1]，这里i=1，所以数组下标j的范围为[0,length-1]
*			6. 在实际的开发中，头插法其实可以直接调用insertList()函数，将i设置为1即可，这里只是为了演示头插法的实现而特意写出算法的实现过程
*/
bool push_front(SqList* L, Elemtype e)
{
	printf("[INFO] push_back() is called：尝试在表头插入新元素%d\n", e);
	// 判断参数是否合法
	if (NULL == L) // 判断静态顺序表是否为空
	{
		printf("[ERROR] push_back() 参数错误,L为空，插入失败！\n");
		return false;
	}
	if (L->m_length >= MAX_SIZE) // 判断静态顺序表是否已满
	{
		printf("[ERROR] push_back() 参数错误,静态顺序表已满，插入失败！\n");
		return false;
	}
	// 插入元素
	for(int j = L->m_length-1; j >= 0; j--) // 将第i个元素及之后的元素后移
	{
		L->m_data[j+1] = L->m_data[j];
	}
	L->m_data[0] = e; // 插入新元素
	L->m_length++;	// 表长加一
	printf("[INFO] 静态顺序表表头插入元素成功！\n");
	return true;
}


/**
* @brief 静态顺序表的尾插
* @param L 待插入的静态顺序表
* @param e 待插入的元素
* @return 插入成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于在静态顺序表的表尾插入元素e，如果静态顺序表已满，则插入失败
* 		思路：
* 			1. 判断顺序表的指针是否有效，如果无效（即L为NULL），则插入失败。
* 			2. 判断静态顺序表是否已满，如果已满，则插入失败
* 			3. 将新元素插入到第length+1个位置（即数组的第length个位置）
* 			4. 静态顺序表的长度加1
* 		注意：
* 			1. 尾插操作的时间复杂度为O(1)，空间复杂度为O(1)
* 			2. 尾插操作是在静态顺序表的表尾插入元素，因为顺序表支持随机访问，所以直接在表尾插入元素即可
* 			3. 静态顺序表的位序是从1开始的，而数组的下标是从0开始的，不要混淆
* 			4. 因为需要修改静态顺序表的数据，所以此处传入的是一个指向静态顺序表的指针，这样在函数内部修改静态顺序表的数据会影响到外部
*			5. 在实际的开发中，尾插法其实可以直接调用insertList()函数，将i设置为length+1即可，这里只是为了演示尾插法的实现而特意写出算法的实现过程
*/

bool push_back(SqList* L, Elemtype e)
{
	printf("[INFO] push_back() is called：尝试在表尾插入新元素%d\n", e);
	// 判断参数是否合法
	if (NULL == L) // 判断静态顺序表是否为空
	{
		printf("[ERROR] push_back() 参数错误,L为空，插入失败！\n");
		return false;
	}
	if (L->m_length >= MAX_SIZE) // 判断静态顺序表是否已满
	{
		printf("[ERROR] push_back() 参数错误,静态顺序表已满，插入失败！\n");
		return false;
	}
	// 插入元素
	L->m_data[L->m_length] = e; // 插入新元素
	L->m_length++;	// 表长加一
	printf("[INFO] 静态顺序表表尾插入元素成功！\n");
	return true;
}

/**
* @brief 静态顺序表的头删操作
* @param L 待删除的静态顺序表
* @param e 被删除的元素
* @return 删除成功返回true，否则返回false
* @note
*		函数功能：
* 			本函数用于删除静态顺序表的表头元素
* 		函数思路：
* 			1. 判断参数是否合法，如果静态顺序表的指针无效（即L为NULL），则删除失败
* 			2. 判断静态顺序表是否为空，如果为空，则删除失败
* 			3. 将静态顺序表中的元素依次前移，覆盖掉第1个元素
* 			4. 静态顺序表的长度减1
* 		注意：
* 			1. 头删操作的时间复杂度为O(n)，空间复杂度为O(1)
* 			2. 头删操作是删除静态顺序表的表头元素，删除后，原来的第2个元素变成了第1个元素，原来的第3个元素变成了第2个元素，以此类推
* 			3. 静态顺序表的位序是从1开始的，而数组的下标是从0开始的，不要混淆
* 			4. 因为需要修改静态顺序表的数据，所以此处传入的是一个指向静态顺序表的指针，这样在函数内部修改静态顺序表的数据会影响到外部
* 			5. 在for循环中，j的本质是数组下标，当需要用j表示元素位序时，应该+1，
* 			   所以根据“将第i个元素之后的元素前移”这句话，位序j+1的范围为[i+1,length],
* 			   所以数组下标j的范围为[i,length-1]，这里i=1，所以数组下标j的范围为[1,length-1]
*/
bool pop_front(SqList* L, Elemtype* e)
{
	printf("[INFO] pop_front() is called：尝试删除表头元素\n");
	// 判断参数是否合法
	if (NULL == L) // 判断静态顺序表指针是否有效
	{
		printf("[ERROR] pop_front() 参数错误,L为空，删除失败！\n");
		return false;
	}
	if (L->m_length == 0) // 判断静态顺序表是否为空
	{
		printf("[ERROR] pop_front() 参数错误,静态顺序表为空，删除失败！\n");
		return false;
	}
	// 删除元素
	*e = L->m_data[0]; // 保存被删除的元素
	for(int j = 1; j <= L->m_length-1; j++) // 将第i个元素之后的元素前移
	{
		L->m_data[j-1] = L->m_data[j];
	}
	L->m_length--;	// 表长减一
	printf("[INFO] 静态顺序表表头删除元素成功！\n");
	return true;
}


/**
* @brief 静态顺序表的尾删操作
* @param L 待删除的静态顺序表
* @param e 被删除的元素
* @return 删除成功返回true，否则返回false
* @note
 		函数功能：
 			本函数用于删除静态顺序表的表尾元素。
 		函数思路：
 			1. 判断参数是否合法，如果静态顺序表的指针无效（即L为NULL），则删除失败。
 			2. 判断静态顺序表是否为空，如果为空，则删除失败。
 			3. 直接返回静态顺序表的最后一个元素，静态顺序表的长度减1即可。
 		注意：
 			1. 尾删操作的时间复杂度为O(1)，空间复杂度为O(1)。
 			2. 尾删操作是删除静态顺序表的表尾元素，因为顺序表支持随机访问，所以直接删除表尾元素即可。
 			3. 静态顺序表的位序是从1开始的，而数组的下标是从0开始的，不要混淆。
 			4. 因为需要修改静态顺序表的数据，所以此处传入的是一个指向静态顺序表的指针，这样在函数内部。修改静态顺序表的数据会影响到外部
*/
bool pop_back(SqList* L, Elemtype* e)
{
	printf("[INFO] pop_back() is called：尝试删除表尾元素\n");
	// 判断参数是否合法
	if (NULL == L) // 判断静态顺序表指针是否有效
	{
		printf("[ERROR] pop_back() 参数错误,L为空，删除失败！\n");
		return false;
	}
	if (L->m_length == 0) // 判断静态顺序表是否为空
	{
		printf("[ERROR] pop_back() 参数错误,静态顺序表为空，删除失败！\n");
		return false;
	}
	// 删除元素
	*e = L->m_data[L->m_length-1]; // 保存被删除的元素
	L->m_length--;	// 表长减一
	printf("[INFO] 静态顺序表表尾删除元素成功！\n");
	return true;
}

/**
* @brief 静态顺序表的冒泡排序操作
* @param L 待排序的静态顺序表
* @return 排序成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于对静态顺序表进行冒泡排序
* 		函数思路：
* 			1. 判断参数是否合法，如果静态顺序表的指针无效，则排序失败
* 			2. 如果静态顺序表为空，则无需排序，直接返回true
* 			3. 依次比较相邻的两个元素，如果前一个元素大于（或小于）后一个元素，则交换两个元素的位置
* 			4. 一轮比较下来，最大（或小于）的元素被交换到了最后的位置
* 			5. 重复上述步骤，直到所有元素都有序
* 		注意：
* 			1. 冒泡排序的时间复杂度为O(n^2)，空间复杂度为O(1)
* 			2. 冒泡排序是一种稳定的排序算法，即相同元素的相对位置在排序前后不会发生变化
* 			3. 冒泡排序是一种原地排序算法，即不需要额外的辅助空间
* 			4. 冒泡排序是一种交换排序算法，即通过不断的交换相邻的元素，将最大（或最小）的元素交换到最后的位置
* 			5. 冒泡排序是一种简单的排序算法，适用于元素个数较少的情况
*			6. 冒泡排序的第一层循环控制比较的轮数，
			   即需要比较n-1轮，因为最后一轮只剩下一个元素，不需要比较，
			   因此其循环不变量i的范围为[0,length-2]
*			7. 冒泡排序的第二层循环控制每轮比较的次数，
			   即每轮比较n-1-i次，因为每轮比较后，最大（或最小）的元素已经被交换到了最后的位置，不需要再比较，
			   因此其循环不变量j的范围为[0,length-2-i]
*			8. 注意，6和7中的i，j都是用来表示数组下标的，如果需要用来表示元素位序，应该+1
*			9. 此处的冒泡排序是升序排序，如果需要降序排序，只需要将if语句中的比较符号由>改为<即可
*/
bool sortListByBubble(SqList* L)
{
	printf("[INFO] sortListByBubble() is called：尝试对静态顺序表进行冒泡排序\n");
	// 判断参数是否合法
	if (NULL == L) // 判断静态顺序表是否为空
	{
		printf("[ERROR] sortListByBubble() 参数错误,L为空，排序失败！\n");
		return false;
	}
	if (L->m_length == 0) // 判断静态顺序表是否为空
	{
		printf("[INFO] sortListByBubble() 参数错误,静态顺序表为空，无需排序！\n");
		return true;
	}
	// 排序
	for(int i = 0; i < L->m_length-1; i++) // 外层循环控制比较的轮数
	{
		for(int j = 0; j < L->m_length-1-i; j++) // 内层循环控制每轮比较的次数
		{
			if(L->m_data[j] > L->m_data[j+1]) // 如果前一个元素大于后一个元素，则交换两个元素的位置
			{
				Elemtype tmp = L->m_data[j];
				L->m_data[j] = L->m_data[j+1];
				L->m_data[j+1] = tmp;
			}
		}
	}
	printf("[INFO] 静态顺序表冒泡排序成功！\n");
	return true;
}

/**
* @brief 静态顺序表的选择排序操作
* @param L 待排序的静态顺序表
* @return 排序成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于对静态顺序表进行选择排序
* 		函数思路：
* 			1. 判断参数是否合法，如果静态顺序表的指针无效（即L为NULL），则排序失败
* 			2. 如果静态顺序表为空，则无需排序，直接返回true
* 			3. 如果静态顺序表不为空，依次找到静态顺序表中的最小（或最大）元素，将其与第i个元素交换位置
* 			4. 重复上述步骤，直到所有元素都有序
* 		注意：
* 			1. 选择排序的时间复杂度为O(n^2)，空间复杂度为O(1)
* 			2. 选择排序是一种不稳定的排序算法，即相同元素的相对位置在排序前后可能发生变化
* 			3. 选择排序是一种原地排序算法，即不需要额外的辅助空间
* 			4. 选择排序是一种交换排序算法，即通过不断的交换元素的位置，将最小（或最大）的元素交换到最前面
* 			5. 选择排序是一种简单的排序算法，适用于元素个数较少的情况
*			6. 选择排序的第一层循环控制比较的轮数，
			   即需要比较n-1轮，因为最后一轮只剩下一个元素，不需要比较，
			   因此其循环不变量i的范围为[0,length-2]
*			7. 选择排序的第二层循环控制每轮比较的次数，
 			   因为每轮比较后，最小（或最大）的元素已经被交换到了最前面，不需要再比较，
			   因此每轮比较的下标从未比较过的元素开始，即从i+1开始，而结束点一直为length-1，
			   因此其循环不变量j的范围为[i+1,length-1]
*			8. 注意，6和7中的i，j都是用来表示数组下标的，如果需要用来表示元素位序，应该+1
* 			9. 此处的选择排序是升序排序，如果需要降序排序，只需要将if语句中的比较符号由<改为>即可
*/
bool sortListBySelect(SqList* L)
{
	printf("[INFO] sortListBySelect() is called：尝试对静态顺序表进行选择排序\n");
	// 判断参数是否合法
	if (NULL == L) // 判断静态顺序表是否为空
	{
		printf("[ERROR] sortListBySelect() 参数错误,L为空，排序失败！\n");
		return false;
	}
	if (L->m_length == 0) // 判断静态顺序表是否为空
	{
		printf("[INFO] sortListBySelect() 参数错误,静态顺序表为空，无需排序！\n");
		return true;
	}
	// 排序
	for(int i = 0; i < L->m_length-1; i++) // 外层循环控制比较的轮数
	{
		int min = i; // 记录最小元素的下标
		for(int j = i+1; j < L->m_length; j++) // 内层循环控制每轮比较的次数
		{
			if(L->m_data[j] < L->m_data[min]) // 如果第j个元素小于第min个元素，则更新min的值
			{
				min = j;
			}
		}
		if(min != i) // 如果min的值发生了变化，则交换两个元素的位置
		{
			Elemtype tmp = L->m_data[i];
			L->m_data[i] = L->m_data[min];
			L->m_data[min] = tmp;
		}
	}
	printf("[INFO] 静态顺序表选择排序成功！\n");
	return true;
}

/**
* @brief 两个有序静态顺序表的合并操作
* @param L1 第一个有序静态顺序表
* @param L2 第二个有序静态顺序表
* @param L3 合并后的有序静态顺序表
* @return 合并成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于将两个有序静态顺序表合并成一个有序静态顺序表。
* 		函数思路：
* 			1. 判断参数是否合法，如果静态顺序表的指针无效（即L为NULL），则合并失败。
*			2. 判断两个顺序表L1、L2的长度之和是否大于L3的容量，如果大于，则合并失败。
* 			3. 通过合法性测试后，如果静态顺序表L1为空，则直接将L2复制到L3中，合并成功。
* 			4. 如果静态顺序表L2为空，则直接将L1复制到L3中，合并成功。
* 			5. 如果L1、L2均不为空，依次比较L1和L2中的元素，将较小的元素插入到L3中。
* 			6. 如果L1中的元素已经全部插入到L3中，则将L2中的剩余元素插入到L3中。
* 			7. 如果L2中的元素已经全部插入到L3中，则将L1中的剩余元素插入到L3中。
* 		注意：
* 			1. 合并操作的时间复杂度为O(n)，空间复杂度为O(1)。
* 			2. 合并操作是将两个有序静态顺序表合并成一个有序静态顺序表，
			   所以合并后的静态顺序表也是有序的，且合并后的静态顺序表的长度等于两个静态顺序表的长度之和。
* 			3. 合并操作是一种简单的合并算法，适用于两个静态顺序表的元素个数较少的情况。
* 			4. 合并操作是一种原地合并算法，即不需要额外的辅助空间。
* 			5. 合并操作是一种稳定的合并算法，即相同元素的相对位置在合并前后不会发生变化。
* 			6. 合并操作是一种插入排序的变种，即通过不断的比较两个静态顺序表的元素，将较小的元素插入到新的静态顺序表中。
*			7. 在合并算法中，需要维护三个指针，分别指向三个静态顺序表的当前元素，以便于比较和插入。
* 			8. 静态顺序表的局限性：静态顺序表的容量是固定的，不支持动态扩容，所以在合并操作中，需要保证合并后的静态顺序表的容量足够。
*/
bool mergeList(SqList* L1, SqList* L2, SqList* L3)
{
	printf("[INFO] mergeList() is called：尝试合并两个有序静态顺序表\n");
	// 判断参数是否合法
	if (NULL == L1 || NULL == L2 || NULL == L3) // 判断静态顺序表是否为空
	{
		printf("[ERROR] mergeList() 参数错误,L1或L2或L3为空，合并失败！\n");
		return false;
	}
	if (L1->m_length + L2->m_length > MAX_SIZE) // 判断静态顺序表的长度之和是否大于L3的容量
	{
		printf("[ERROR] mergeList() 参数错误,静态顺序表的长度之和大于L3的容量，合并失败！\n");
		return false;
	}
	// 合并
	int pos1 = 0; // 指向L1的当前元素
	int pos2 = 0; // 指向L2的当前元素
	int pos3 = 0; // 指向L3的当前元素
	while(pos1 < L1->m_length && pos2 < L2->m_length) // 比较L1和L2中的元素
	{
		if(L1->m_data[pos1] < L2->m_data[pos2]) // 如果L1中的元素小于L2中的元素，则将L1中的元素插入到L3中
		{
			L3->m_data[pos3++] = L1->m_data[pos1++];
		}
		else // 如果L1中的元素大于等于L2中的元素，则将L2中的元素插入到L3中
		{
			L3->m_data[pos3++] = L2->m_data[pos2++];
		}
	}
	while(pos1 < L1->m_length) // 如果L2中的元素已经全部插入到L3中，则将L1中的剩余元素插入到L3中
	{
		L3->m_data[pos3++] = L1->m_data[pos1++];
	}
	while(pos2 < L2->m_length) // 如果L1中的元素已经全部插入到L3中，则将L2中的剩余元素插入到L3中
	{
		L3->m_data[pos3++] = L2->m_data[pos2++];
	}
	L3->m_length = L1->m_length + L2->m_length; // 合并后的静态顺序表的长度等于两个静态顺序表的长度之和
	printf("[INFO] 静态顺序表合并成功！\n");
}