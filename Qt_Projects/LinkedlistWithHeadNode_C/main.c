/**
 * @file main.c
 * @brief 本文件用于实现带头结点的单链表，包括链表的初始化、插入、删除、查找、销毁等操作。
 * @author YYZYHS
 * @date 2024-11-19
 */

#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h> // 可以使用stdbool.h库中的bool类型，true和false宏定义，也可以如下文自己定义。


// ============================预处理信息============================
typedef int bool; // 定义bool类型
#define true 1    // 定义true
#define false 0   // 定义false
typedef int ElemType; // 定义链表存储的数据类型

// ============================单链表的结构定义============================
typedef struct LNode
{
    ElemType data;          // 数据域
    struct LNode *next;     // 指针域
} LNode, *LinkList;         // LNode为结点类型，*LinkList为结点指针类型,即指向结点的指针。
                            // 前者强调这是一个结点，后者强调这是一个链表。

// ============================函数声明============================
// 基本操作
bool initList(LinkList *L); /// 初始化链表
bool destroyList(LinkList *L); /// 销毁链表
bool printList(const LinkList L); /// 打印链表
bool isEmpty(const LinkList L);   /// 判断链表是否为空
int length(const LinkList L);     /// 求链表长度
LNode *createNewNode(ElemType e); /// 创建新结点
bool insertNextNode(LNode *p, ElemType e);     /// 在指定结点后插入结点
bool insertList(LinkList L, int i, ElemType e);/// 常用的插入操作（后插）
LNode* getElem(LinkList L, int i); /// 按位查找
LNode* locateElem(LinkList L, int *i, ElemType e);       /// 按值查找
bool insertPriorNode(LNode *p, ElemType e);   /// 在指定结点前插入结点
bool insertListByForward(LinkList L, int i, ElemType e);/// 常用的插入操作（前插）
bool removeNode(LinkList L, int i, ElemType *e);   /// 删除结点
bool setNode(LinkList L, int i, ElemType e); /// 修改结点
// 测试用例
void test1(); /// 测试用例1
void test2(); /// 测试用例2
// ============================函数实现============================

/**
 * @brief 主函数入口
 *      本函是程序的入口，程序的执行从这里开始。
 * @return int
 *      0: 正常退出
 */
int main()
{
    // test1();
    test2();
    return 0;
}

void test1()
{
    printf("=========================================\n");
    printf("=\t单链表的测试用例1\t=\n");
    printf("=\t测试清单：       \t=\n");
    printf("=\t1. 初始化链表    \t=\n");
    printf("=\t2. 判断链表是否为空 \t=\n");
    printf("=\t3. 输出链表长度   \t=\n");
    printf("=\t4. 打印链表     \t=\n");
    printf("=\t5. 常用的按位插入操作\t=\n");
    printf("=\t6. 销毁链表     \t=\n");
    printf("=========================================\n");
    printf("[INFO] 开始执行测试用例1...\n");
    printf("[INFO] 创建一个链表并初始化...\n");
    LinkList L = NULL;
    initList(&L);
    printf("[INFO] 判断链表是否为空...\n");
    printf("[INFO] 链表是否为空：%s\n", isEmpty(L)?"是":"否");
    printf("[INFO] 输出链表长度...\n");
    length(L);
    printf("[INFO] 打印链表...\n");
    printList(L);

    printf("[INFO] 顺序插入结点...\n");
    insertList(L, 1, 1);
    insertList(L, 2, 2);
    insertList(L, 3, 3);
    insertList(L, 4, 4);
    insertList(L, 5, 5);
    printf("[INFO] 判断链表是否为空...\n");
    printf("[INFO] 链表是否为空：%s\n", isEmpty(L)?"是":"否");
    printf("[INFO] 输出链表长度...\n");
    length(L);
    printf("[INFO] 打印链表...\n");
    printList(L);

    printf("[INFO] 乱序插入结点...\n");
    insertList(L, 1, 6);    // 特殊位置：表头
    insertList(L, 4, 7);
    insertList(L, 6, 8);
    insertList(L, 8, 9);
    insertList(L, 10, 10);  // 特殊位置：表尾
    printf("[INFO] 测试：在非法位置插入结点...\n");
    insertList(L, 0, 11);   // 非法位置：小于1
    insertList(L, 12, 12);  // 非法位置：大于链表长度+2
    printf("[INFO] 判断链表是否为空...\n");
    printf("[INFO] 链表是否为空：%s\n", isEmpty(L)?"是":"否");
    printf("[INFO] 输出链表长度...\n");
    length(L);
    printf("[INFO] 打印链表...\n");
    printList(L);


    printf("[INFO] 销毁链表...\n");
    destroyList(&L);
    printf("[INFO] 判断链表是否为空...\n");
    printf("[INFO] 链表是否为空：%s\n", isEmpty(L)?"是":"否");
    printf("[INFO] 输出链表长度...\n");
    length(L);
    printf("[INFO] 尝试打印已销毁的链表...\n");
    printList(L);
    printf("[INFO] 测试用例1执行完毕！\n");
}
void test2()
{
    printf("=========================================\n");
    printf("=\t单链表的测试用例2\t=\n");
    printf("=\t测试清单：       \t=\n");
    printf("=\t1. 按位查找      \t=\n");
    printf("=\t2. 按值查找      \t=\n");
    printf("=\t3. 按位插入(前插)\t=\n");
    printf("=\t4. 按位删除      \t=\n");
    printf("=\t5. 修改结点      \t=\n");
    printf("=========================================\n");
    printf("[INFO] 开始执行测试用例2...\n");
    printf("[INFO] 创建一个链表并初始化...\n");
    LinkList L = NULL;
    initList(&L);
    printf("[INFO] 顺序插入结点...\n");
    insertList(L, 1, 1);
    insertList(L, 2, 2);
    insertList(L, 3, 3);
    insertList(L, 4, 4);
    insertList(L, 5, 5);
    printf("[INFO] 打印链表...\n");
    printList(L);
    printf("[INFO] 按位查找结点...\n");
    LNode *p = NULL;    // 创建临时指针p
    p = getElem(L, 0);  // 查找头结点
    p = getElem(L, 1);  // 查找第一个元素
    printf("[INFO] 当前p的数据为：%d\n", p->data);
    p = getElem(L, 3);  // 查找中间元素
    printf("[INFO] 当前p的数据为：%d\n", p->data);
    p = getElem(L, length(L)); // 查找最后一个元素
    printf("[INFO] 当前p的数据为：%d\n", p->data);

    printf("[INFO] 按值查找结点...\n");
    int i = 0;
    p = locateElem(L, &i, getElem(L, 1)->data); // 查找第一个元素
    printf("[INFO] 当前p的数据为：%d，位序为：%d\n", p->data, i);
    p = locateElem(L, &i, 3); // 查找中间元素
    printf("[INFO] 当前p的数据为：%d，位序为：%d\n", p->data, i);
    p = locateElem(L, &i, getElem(L, length(L))->data); // 查找最后一个元素
    printf("[INFO] 按值查找结点完毕！\n");

    printf("[INFO] 按位插入结点(前插)...\n");
    insertListByForward(L, 1, 0); // 表头前插
    printf("[INFO] 打印链表...\n");
    printList(L);
    insertListByForward(L, 3, 8); // 中间前插
    printf("[INFO] 打印链表...\n");
    printList(L);
    insertListByForward(L, length(L) + 1, 9); // 表尾前插
    printf("[INFO] 打印链表...\n");
    printList(L);
    insertListByForward(L, 0, 10); // 非法位置前插
    printf("[INFO] 打印链表...\n");
    printList(L);
    insertListByForward(L, length(L) + 2, 11); // 非法位置前插
    printf("[INFO] 打印链表...\n");
    printList(L);

    printf("[INFO] 按位删除结点...\n");
    ElemType e = 0;
    removeNode(L, 1, &e); // 表头删除
    printf("[INFO] 删除的结点数据为：%d\n", e);
    printf("[INFO] 打印链表...\n");
    printList(L);
    removeNode(L, 3, &e); // 中间删除
    printf("[INFO] 删除的结点数据为：%d\n", e);
    printf("[INFO] 打印链表...\n");
    printList(L);
    removeNode(L, length(L), &e); // 表尾删除
    printf("[INFO] 删除的结点数据为：%d\n", e);
    printf("[INFO] 打印链表...\n");
    printList(L);
    removeNode(L, 0, &e); // 非法位置删除
    printf("[INFO] 打印链表...\n");
    printList(L);
    removeNode(L, length(L) + 1, &e); // 非法位置删除
    printf("[INFO] 打印链表...\n");
    printList(L);

    printf("[INFO] 修改结点...\n");
    setNode(L, 1, 100); // 修改表头结点
    printf("[INFO] 打印链表...\n");
    printList(L);
    setNode(L, 3, 200); // 修改中间结点
    printf("[INFO] 打印链表...\n");
    printList(L);
    setNode(L, length(L), 300); // 修改表尾结点
    printf("[INFO] 打印链表...\n");
    printList(L);
    setNode(L, 0, 400); // 非法位置修改
    printf("[INFO] 打印链表...\n");
    printList(L);
    setNode(L, length(L) + 1, 500); // 非法位置修改
    printf("[INFO] 打印链表...\n");
    printList(L);

    printf("[INFO] test2执行完毕！\n");
    return;
}

/**
 * @brief 初始化链表
 *      初始化一个带头结点的单链表
 * @param LinkList *L
 *      指向链表的指针
 * @return bool
 *      true: 初始化成功
 *      false: 初始化失败
 * @note
 *      函数功能
 *          本函数用于初始化一个带头结点的单链表，头结点是一个空结点，不存储数据。
 *      函数思路：
 *          1.通过在堆上分配内存生成一个头结点。
 *          2.判断生成头结点是否成功，成功则返回true，否则返回false。
 *          3.头结点的next指针指向NULL。
 *          4.初始化成功返回true。
 *      注意：
 *          1.参数L为指向链表的指针，其本质是一个二级指针，即LNode **L。
 *            L是一个指向指针的指针，对L的操作会改变L指向的地址的内容。
 *            *L是指向链表的头指针，即头结点的地址，对*L的操作会改变头结点的内容。
 *            因此，这么写的原理是在函数内部改变*L的内容，从而改变外部指针L指向的地址的内容。
 *            如果参数是LinkList L（即LNode *L），即直接传递指针，那么只能改变指针的内容，无法改变指针指向的地址的内容。
 *          2.在堆上分配内存的操作有可能失败，所以需要判断是否分配成功。
 *          3.头结点本身不存储数据，但遵循定义变量即初始化的原则，将头结点的data域初始化为0。
 */
bool initList(LinkList *L)
{
    printf("[INFO] initList()函数被调用...\n");
    *L = (LinkList)malloc(sizeof(LNode)); // 生成头结点
    if(NULL == *L)
    {
        printf("[ERROR] 初始化链表失败！ErrorText: 在堆上分配内存失败！\n");
        return false;
    }
    printf("[INFO] 初始化链表成功！\n");
    (*L)->data = 0; // 头结点不存储数据,但初始化为0
    (*L)->next = NULL;
    return true;
}


/**
 * @brief 销毁链表
 *      销毁一个带头结点的单链表
 * @param LinkList *L
 *      指向链表的指针
 * @return bool
 *      true: 销毁成功
 *      false: 销毁失败
 * @note
 *     函数功能
 *          本函数用于销毁一个带头结点的单链表。
 *     函数思路
 *          1. 判断链表指针是否有效（即L和*L是否为NULL），如果无效则返回false。
 *          2. 创建两个临时指针p和q，p指向头结点，q用于释放结点。
 *          3. 循环遍历链表，释放每个结点的内存空间。
 *          4. 释放完所有结点后，将头指针置为NULL。
 *          5. 销毁成功返回true。
 *     注意
 *          1. 销毁链表时，需要释放每个结点的内存空间，否则会造成内存泄漏。
 *          2. 代码中释放结点内存的过程是将首元素从链表中断开，原位于首元素之后的元素成为新的首元素，然后释放原首元素的内存，如此循环。
 *          3. 销毁链表后，需要将头结点的内存空间也释放掉，同时将头指针置为NULL，否则在链表最终被销毁后，会导致有一块分配到堆区的内存空间没有被释放，造成内存泄漏。
 *          4. 销毁算法的时间复杂度为O(n)，其中n为链表的长度，空间复杂度为O(1)。
 *          5. 关于函数参数的说明，详见initList()函数的说明，
 *             简而言之，initList()和destoryList()函数都需要对指向链表的指针进行操作，所以参数必须是指向“指向链表的指针”的指针，
 *             而其他函数如printList()、insertList()等只需要对链表进行访问或操作，所以参数只需要是指向链表的指针即可。
 */
bool destroyList(LinkList *L)
{
    printf("[INFO] destroyList()函数被调用...\n");
    if(NULL == L || NULL == *L)
    {
        printf("[ERROR] 销毁链表失败！ErrorText: 链表不存在！\n");
        return false;
    }
    LinkList p = *L;    // 创建临时指针p指向头结点
    LinkList q = NULL;  // 创建临时指针q
    while(p->next != NULL) // 循环遍历链表
    {
        q = p->next;        // q指向第一个元素
        p->next = q->next;  // 断链操作，将首元素从链表中断开，头结点p指向第二个元素
        free(q);            // 释放原首元素q的内存空间
    }
    free(*L); // 释放头结点的内存空间
    *L = NULL;
    printf("[INFO] 销毁链表成功！\n");
    return true;
}

/**
 * @brief 打印链表
 *      打印一个带头结点的单链表
 * @param const LinkList L
 *      链表
 * @return bool
 *      true: 打印成功
 *      false: 打印失败
 * @note
 *      函数功能
 *          本函数用于打印一个带头结点的单链表。
 *      函数思路
 *          1.判断链表是否有效，即L是否为NULL，如果无效则返回false。
 *          2.创建临时指针p指向链表中的第一个元素。
 *          3.循环遍历链表，打印每个元素的值。
 *          4.打印成功返回true。
 *      注意
 *          1.打印链表前，需要判断链表是否存在，否则会导致空指针异常。
 *          2.打印链表的时间复杂度为O(n)，其中n为链表的长度，空间复杂度为O(1)。
 *          3.函数参数const LinkList L表示传递的是一个指向常量的指针，
 *          使用LinkList而不是LNode *L是为了增加代码的可读性，且传递指针可节省内存空间，
 *          而用const修饰表示不允许修改指针指向的内容，这样可以避免误操作。
 */
bool printList(const LinkList L)
{
    printf("[INFO] printList()函数被调用...\n");
    if(NULL == L)
    {
        printf("[ERROR] 打印链表失败！ErrorText: 链表不存在！\n");
        return false;
    }
    LinkList p = L->next; // 创建临时指针p指向链表中的第一个元素
    printf("[INFO] 链表元素：[HNode]-->"); // 打印头结点
    while(p != NULL)
    {
        printf("[%d]-->", p->data);
        p = p->next;
    }
    printf("[NULL]\n");
    return true;
}


/**
 * @brief 判断链表是否为空
 *      判断一个带头结点的单链表是否为空
 * @param const LinkList L
 *      链表
 * @return bool
 *      true: 链表为空
 *      false: 链表不为空
 * @note
 *      函数功能
 *          本函数用于判断一个带头结点的单链表是否为空。
 *      函数思路
 *          1.判断链表是否有效，即L是否为NULL，如果无效则返回true。
 *          2.判断链表的第一个元素是否为NULL，如果是则返回true，否则返回false。
 *      注意
 *          1.判断链表是否为空时，需要先判断链表是否存在，否则会导致空指针异常。
 *          2.判断链表是否为空的时间复杂度为O(1)，空间复杂度为O(1)。
 *          3.函数参数const LinkList L的说明详见printList()函数的说明。
 */
bool isEmpty(const LinkList L)
{
    printf("[INFO] isEmpty()函数被调用...\n");
    if(NULL == L || NULL == L->next)
    {
        printf("[INFO] 链表不存在或为空！\n");
        return true;
    }
    else
    {
        printf("[INFO] 链表不为空！\n");
        return false;
    }
}

/**
 * @brief 求链表长度
 *      求一个带头结点的单链表的长度
 * @param const LinkList L
 *      链表
 * @return int
 *      链表的长度
 * @note
 *      函数功能
 *          本函数用于求一个带头结点的单链表的长度。
 *      函数思路
 *          1.判断链表是否存在，如果不存在则返回-1。
 *          2.创建一个变量len用于存储链表的长度，初始化为0。
 *          3.创建一个临时指针p指向链表中的第一个元素。
 *          4.循环遍历链表，每遍历一个元素，len加1。
 *          5.遍历完链表后，返回len。
 *      注意
 *          1.求链表长度时，需要先判断链表是否存在，否则会导致空指针异常。
 *          2.求链表长度的时间复杂度为O(n)，其中n为链表的长度，空间复杂度为O(1)。
 *          3.函数参数const LinkList L的说明详见printList()函数的说明。
 */
int length(const LinkList L)
{
    printf("[INFO] length()函数被调用...\n");
    if(NULL == L)
    {
        printf("[ERROR] 求链表长度失败！ErrorText: 链表不存在！\n");
        return -1;
    }
    int len = 0;
    LinkList p = L->next;
    while(NULL != p)
    {
        len++;
        p = p->next;
    }
    printf("[INFO] 链表长度为：%d\n", len);
    return len;
}

/**
 * @brief createNewNode
 *      创建新结点
 * @param e
 *     结点数据
 * @return
 *    成功：返回新结点指针
 *    失败：返回NULL
 * @note
 *      函数功能
 *          本函数用于创建一个新结点。
 *      函数思路
 *          1.在堆上分配内存生成一个新结点。
 *          2.判断生成新结点是否成功，如果失败则返回NULL。
 *          3.将新结点的数据域赋值为e，指针域赋值为NULL。
 *          4.创建成功返回新结点指针。
 *      注意
 *          1.因为在堆上分配内存会有失败的可能，所以需要判断是否分配成功。
 *          2.新结点的next指针最好初始化为NULL，这样符合指针创建即初始化的原则。
 */
LNode* createNewNode(ElemType e)
{
    printf("[INFO] createNewNode()函数被调用...\n");
    LNode *node = (LNode *)malloc(sizeof(LNode));// 在堆上分配内存
    if(NULL == node)
    {
        printf("[ERROR] 创建新结点失败！ErrorText: 在堆上分配内存失败！\n");
        return NULL;
    }
    node->data = e;
    node->next = NULL;
    return node;
}

/**
 * @brief insertNextNode
 *      在指定结点后插入结点
 * @param p
 *      指定结点
 * @param e
 *      结点数据
 * @return bool
 *      true: 插入成功
 *      false: 插入失败
 * @note
 *      函数功能
 *          本函数用于在指定结点后插入结点。
 *      函数思路
 *          1.判断指定结点是否存在，如果不存在则返回false。
 *          2.创建一个新结点，并判断是否创建成功，如果创建失败则返回false。
 *          3.将新结点的next指针指向指定结点的next指针。
 *          4.将指定结点的next指针指向新结点。
 *          5.插入成功返回true。
 *      注意
 *          1.参数p为LNode *类型，即指向结点的指针，表示指定结点，
 *            此处使用指针的原因是为了在函数内部改变指定结点的指针域的内容。
 *          2.插入新结点时，
 *            必须先让指定结点的后继结点成为新结点的后继结点(即将指定结点的next域赋值给新结点的next域)，
 *            然后再让新结点成为指定结点的后继结点(即将新结点的地址赋值给指定结点的next域)，
 *            二者顺序不能颠倒，否则会导致链表断裂。
 *          3.插入结点的时间复杂度为O(1)，空间复杂度为O(1)。
 */
bool insertNextNode(LNode *p, ElemType e)
{
    printf("[INFO] insertNextNode()函数被调用...\n");
    if(NULL == p)
    {
        printf("[ERROR] 插入结点失败！ErrorText: 指定结点不存在！\n");
        return false;
    }
    LNode *newNode = createNewNode(e);
    if(NULL == newNode)
    {
        printf("[ERROR] 插入结点失败！ErrorText: 创建新结点失败！\n");
        return false;
    }
    // 插入结点，注意顺序不能颠倒
    newNode->next = p->next;
    p->next = newNode;
    printf("[INFO] 插入结点成功！\n");
    return true;
}

/**
 * @brief getElem
 *     按位查找
 * @param LinkList L
 *      链表
 * @param int i
 *      位置
 * @note
 *     函数功能
 *          本函数用于按位查找链表中的元素。
 *     函数思路
 *          1.判断链表是否存在，如果不存在则返回NULL。
 *          2.判断位置i是否合法，如果不合法则返回NULL。
 *          3.特殊情况：获取头结点，即i=0时，直接返回头结点。
 *          4.创建一个临时指针p指向链表中的第一个元素，创建一个变量pos用于记录当前遍历的元素位序。
 *          5.循环遍历链表，直到找到第i个元素。
 *          6.判断是否找到第i个元素，如果没有找到则返回NULL。
 *          7.找到第i个元素后，返回该结点的指针。
 *     注意
 *          1.按位查找的时间复杂度为O(n)，其中n为链表的长度，空间复杂度为O(1)。
 *          2.链表的位序从1开始。
 */
LNode* getElem(LinkList L, int i)
{
    printf("[INFO] getElem()函数被调用...\n");
    printf("[INFO] 尝试获取链表的第%d个元素...\n", i);
    // 合法性检查
    if(NULL == L)
    {
        printf("[ERROR] 获取结点失败！ErrorText: 链表不存在！\n");
        return NULL;
    }
    if(i < 0)
    {
        printf("[ERROR] 获取结点失败！ErrorText: 位置i非法（小于0）！\n");
        return NULL;
    }
    // 特殊情况：获取头结点
    if(0 == i)
    {
        printf("[INFO] 待查找位置为0，即头结点！\n");
        return L;
    }
    // 遍历链表，直到找到第i个元素
    LNode *p = L->next; // 创建临时指针p指向链表中的第一个元素
    int pos = 1;        // 创建变量pos用于记录当前遍历的元素位序
    while(NULL != p && pos < i) // 遍历链表
    {
        p = p->next;
        pos++;
    }
    // 判断是否找到第i个元素
    if(NULL == p)
    {
        printf("[ERROR] 获取结点失败！ErrorText: 未找到第%d个元素！\n", i);
        return NULL;
    }
    printf("[INFO] 获取结点成功！结点数据为：%d\n", p->data);
    return p;
}


/**
 * @brief locateElem
 *      按值查找
 * @param LinkList L
 *      链表
 * @param int *i
 *      位置
 * @param ElemType e
 *      结点数据
 * @return LNode*
 *      要查找的结点的指针，如果查找失败则返回NULL
 * @note
 *      函数功能
 *          本函数用于按值查找链表中的元素。
 *      函数思路
 *          1.首先进行合法性检查，判断链表是否存在，如果不存在则返回NULL。
 *          2.创建一个临时指针p指向链表中的第一个元素，创建一个变量pos用于记录当前遍历的元素位序。
 *          3.遍历链表，直到找到数据域为e的元素。
 *          4.判断是否找到数据域为e的元素，如果没有找到则返回NULL。
 *          5.找到数据域为e的元素后，返回该结点的指针。
 *      注意
 *          1.按值查找的时间复杂度为O(n)，其中n为链表的长度，空间复杂度为O(1)。
 */
LNode* locateElem(LinkList L,int *i, ElemType e)
{
    printf("[INFO] locateElem()函数被调用...\n");
    printf("[INFO] 尝试查找链表中数据为%d的元素...\n", e);
    // 合法性检查
    if(NULL == L)
    {
        printf("[ERROR] 查找结点失败！ErrorText: 链表不存在！\n");
        return NULL;
    }
    // 创建临时指针p指向链表中的第一个元素
    LNode *p = L->next;
    int pos = 1; // 创建变量pos用于记录当前遍历的元素位序
    // 遍历链表，直到找到数据域为e的元素
    while(NULL != p && p->data != e)
    {
        p = p->next;
        pos++;
    }
    // 判断是否找到数据域为e的元素
    if(NULL == p)
    {
        printf("[ERROR] 查找结点失败！ErrorText: 未找到数据域为%d的元素！\n", e);
        return NULL;
    }
    *i = pos;
    printf("[INFO] 查找结点成功！结点位序为：%d\n", pos);
    return p;
}

/**
 * @brief insertList
 *      常用的插入操作（后插）
 * @param L
 *      链表
 * @param i
 *      位置
 * @param e
 *      结点数据
 * @return bool
 *      true: 插入成功
 *      false: 插入失败
 * @note
 *      函数功能
 *          本函数是常用的插入操作，即在指定位置i后插入结点。
 *      函数思路
 *          1.首先进行合法性检查，判断链表是否存在，如果不存在则返回false。
 *          2.判断位置i是否合法，如果不合法则返回false。
 *          3.调用getElem()函数查找第i-1个元素，即指定结点的前驱结点，如果找不到则返回false。
 *          4.调用insertNextNode()函数插入新结点。
 *      注意
 *          1.在指定结点之后插入新结点的时间复杂度为O(1),但按位插入需要遍历链表，所以时间复杂度为O(n)，其中n为链表的长度。
 *          2.插入操作不需要额外的内存空间，所以空间复杂度为O(1)。
 *          3.插入算法允许在表尾插入新元素，但不允许在超过链表长度+1的位置插入新元素，否则会导致链表断裂。
 */
bool insertList(LinkList L, int i, ElemType e)
{
    printf("[INFO] insertList()函数被调用...\n");
    printf("[INFO] 尝试在链表的第%d个位置插入数据%d...\n", i, e);
    // 合法性检查
    if(NULL == L)
    {
        printf("[ERROR] 插入结点失败！ErrorText: 链表不存在！\n");
        return false;
    }
    if(i < 1)
    {
        printf("[ERROR] 插入结点失败！ErrorText: 位置i非法（小于1）！\n");
        return false;
    }
    LNode *p = getElem(L, i - 1); // 获取第i-1个元素
    // 判断是否找到第i-1个元素
    if(NULL == p)
    {
        printf("[ERROR] 插入结点失败！ErrorText: 位置i非法（大于链表长度+2）！\n");
        return false;
    }
    // 调用insertNextNode()函数插入新结点
    return insertNextNode(p, e);
}




/**
 * @brief insertPriorNode
 *      在指定结点前插入结点
 * @param p
 *      指定结点
 * @param e
 *      结点数据
 * @return bool
 *      true: 插入成功
 *      false: 插入失败
 * @note
 *      函数功能
 *          本函数用于在指定结点前插入结点。
 *      函数思路
 *          1.判断指定结点是否存在，如果不存在则返回false。
 *          2.创建一个新结点，并判断是否创建成功，如果创建失败则返回false。
 *          3.先以后插法插入新结点，再交换数据。
 *          4.插入成功返回true。
 *      注意
 *          1.常规的前插操作是找到指定结点的前驱结点，然后在前驱结点后插入新结点，此法时间复杂度为O(n)，不推荐使用。
 *          2.本函数是在指定结点后插入新结点，然后交换指定结点和新结点的数据，时间复杂度为O(1)。
 */
bool insertPriorNode(LNode *p, ElemType e)
{
    printf("[INFO] insertPriorNode()函数被调用...\n");
    // 合法性检查
    if(NULL == p)
    {
        printf("[ERROR] 插入结点失败！ErrorText: 指定结点不存在！\n");
        return false;
    }
    // 创建新结点
    LNode *newNode = createNewNode(e);
    if(NULL == newNode)
    {
        printf("[ERROR] 插入结点失败！ErrorText: 创建新结点失败！\n");
        return false;
    }
    // 先以后插法插入新结点，再交换数据
    newNode->next = p->next;
    p->next = newNode;
    ElemType temp = p->data;// 临时变量temp用于交换
    p->data = newNode->data;
    newNode->data = temp;
    printf("[INFO] 插入结点成功！\n");
    return true;
}

/**
 * @brief insertListByForward
 *      常用的前插操作
 * @param L
 *      链表
 * @param i
 *      位置
 * @param e
 *      结点数据
 * @return bool
 *      true: 插入成功
 *      false: 插入失败
 * @note
 *      函数功能
 *          本函数是常用的前插操作，即在指定位置i前插入结点。
 *      函数思路
 *          1.首先进行合法性检查，判断链表是否存在，如果不存在则返回false。
 *          2.再判断位置i是否合法，如果不合法则返回false。
 *          3.调用getElem()函数查找第i个元素，即指定结点，如果找不到则返回false。
 *          4.调用insertPriorNode()函数插入新结点。
 *      注意
 *          1.在指定结点之前插入新结点的时间复杂度为O(1),但按位插入需要遍历链表，所以时间复杂度为O(n)，其中n为链表的长度。
 *          2.插入操作不需要额外的内存空间，所以空间复杂度为O(1)。
 *          3.前插操作理论上不能实现在表尾插入新元素，因为定位第i位元素时，会定位到NULL，从而无法找到第i-1位元素。
 *            但是稍微修改一下逻辑，即当第i-1位元素存在但第i位元素不存在时，即第i位为表尾，此时调用insertNextNode()函数即可插入到表尾。
 */
bool insertListByForward(LinkList L, int i, ElemType e)
{
    printf("[INFO] insertListByForward()函数被调用...\n");
    printf("[INFO] 尝试在链表的第%d个位置前插入数据%d...\n", i, e);
    // 合法性检查
    if(NULL == L)
    {
        printf("[ERROR] 插入结点失败！ErrorText: 链表不存在！\n");
        return false;
    }
    if(i < 1)
    {
        printf("[ERROR] 插入结点失败！ErrorText: 位置i非法（小于1）！\n");
        return false;
    }

    // 查找第i-1个元素
    LNode *p = getElem(L, i - 1);
    if(NULL == p)
    {
        printf("[ERROR] 插入结点失败！ErrorText: 位置i非法（大于链表长度+2）！\n");
        return false;
    }

    // 如果第i-1个元素p存在但是p->next不存在，说明p是最后一个元素
    // 则第i位为表尾，此时调用insertNextNode()函数即可插入到表尾
    if(NULL == p->next)
    {
        return insertNextNode(p, e);
    }
    return insertPriorNode(p->next, e);
}


/**
 * @brief removeNode
 *      删除结点
 * @param L
 *      链表
 * @param i
 *      位置
 * @param e
 *      结点数据
 * @return bool
 *      true: 删除成功
 *      false: 删除失败
 * @note
 *      函数功能
 *          本函数用于删除链表中的第i个结点。
 *      函数思路
 *          1.首先进行合法性检查，判断链表是否存在，如果不存在则返回false。
 *          2.再判断位置i是否合法，如果不合法则返回false。
 *          3.调用getElem()函数查找第i-1个元素，即指定结点的前驱结点，如果找不到则返回false。
 *          4.将待删除结点的数据保存到e中，再将其后继结点赋值给前驱结点的next指针。
 *          5.释放待删除结点的内存空间，删除成功返回true。
 *      注意
 *          1.删除结点时，需要释放结点的内存空间，否则会造成内存泄漏。
 *          2.删除指定结点的时间复杂度为O(n)，其中n为链表的长度，空间复杂度为O(1)。
 */
bool removeNode(LinkList L, int i, ElemType *e)
{
    printf("[INFO] removeNode()函数被调用...\n");
    printf("[INFO] 尝试删除链表的第%d个结点...\n", i);
    // 合法性检查
    if(NULL == L || NULL == e)
    {
        printf("[ERROR] 删除结点失败！ErrorText: 链表不存在或e不存在！\n");
        return false;
    }
    if(i < 1)
    {
        printf("[ERROR] 删除结点失败！ErrorText: 位置i非法（小于1）！\n");
        return false;
    }
    // 查找第i-1个元素
    LNode *p = getElem(L, i - 1);
    if(NULL == p || NULL == p->next)
    {
        printf("[ERROR] 删除结点失败！ErrorText: 位置i非法（大于链表长度）！\n");
        return false;
    }
    // 删除结点
    LNode *q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    printf("[INFO] 删除结点成功！\n");
    return true;
}

/**
 * @brief setNode
 *      修改结点数据
 * @param L
 *      链表
 * @param i
 *      位置
 * @param e
 *      结点数据
 * @return bool
 *      true: 修改成功
 *      false: 修改失败
 * @note
 *      函数功能
 *          本函数用于修改链表中的第i个结点的数据。
 *      函数思路
 *          1.首先进行合法性检查，判断链表是否存在，如果不存在则返回false。
 *          2.再判断位置i是否合法，如果不合法则返回false。
 *          3.调用getElem()函数查找第i个元素，如果找不到则返回false。
 *          4.修改结点数据，修改成功返回true。
 *      注意
 *          1.修改结点数据的时间复杂度为O(n)，其中n为链表的长度，空间复杂度为O(1)。
 */
bool setNode(LinkList L, int i, ElemType e)
{
    printf("[INFO] setNode()函数被调用...\n");
    printf("[INFO] 尝试修改链表的第%d个结点的数据为%d...\n", i, e);
    // 合法性检查
    if(NULL == L)
    {
        printf("[ERROR] 修改结点失败！ErrorText: 链表不存在！\n");
        return false;
    }
    if(i < 1)
    {
        printf("[ERROR] 修改结点失败！ErrorText: 位置i非法（小于1）！\n");
        return false;
    }
    // 查找第i个元素
    LNode *p = getElem(L, i);
    if(NULL == p)
    {
        printf("[ERROR] 修改结点失败！ErrorText: 位置i非法（大于链表长度）！\n");
        return false;
    }
    // 修改结点数据
    p->data = e;
    printf("[INFO] 修改结点成功！\n");
    return true;
}
