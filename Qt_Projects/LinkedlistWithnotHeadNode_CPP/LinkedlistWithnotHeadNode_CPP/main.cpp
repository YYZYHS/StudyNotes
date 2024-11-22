/**
 * @file main.c
 * @brief 本文件使用C++实现不带头结点的单链表，包括链表的初始化、插入、删除、查找、销毁等操作。
 * @author YYZYHS
 * @date 2024-11-21
 */

#include <iostream>
using namespace std;

/**
 * @class LNode
 * @brief 单链表结点类模板
 * @tparam T 数据类型
 * @code
 * LNode<int> *node = new LNode<int>(10);
 * LNode<int> *node = new LNode<int>();
 * @endcode
 */
template <class T>
class LNode
{
public:
    LNode() : data(0), next(NULL) {};
    LNode(T e) : data(e), next(NULL) {};
    ~LNode() {};
    T data;
    LNode *next;
};

/**
 * @class LinkList
 * @brief 单链表类模板
 * @tparam T 数据类型
 * @code
 * LinkList<int> *list = new LinkList<int>();
 * @endcode
 */
template <class T>
class LinkList
{
public:
    LinkList():head(nullptr), len(0) {};
    ~LinkList();
    bool initList();
    bool destroyList();
    bool printList();
    bool isEmpty();
    int length();
    LNode<T>* getElem(int i);
    LNode<T>* locateElem(int *i, T e);
    bool insert(int i, T e);
    bool insertListByForward(int i, T e);
    bool removeNode(int i, T *e);
    bool set(int i, T e);
private:
    bool insertNextNode(LNode<T> *p, T e);
    bool insertPriorNode(LNode<T> *p, T e);
    LNode<T> *head;     // 头指针
    int len;            // 链表长度（可选）
};

void test1();
void test2();

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

template<class T>
LinkList<T>::~LinkList()
{
    destroyList();
}

template<class T>
bool LinkList<T>::initList()
{
    if (NULL != head)
    {
        destroyList();
    }
    head = new LNode<T>();
    if (NULL == head)
    {
        return false;
    }
    len = 0;
    return true;
}

template<class T>
bool LinkList<T>::destroyList()
{
    LNode<T> *p = head;
    LNode<T> *q = NULL;
    while (NULL != p)
    {
        q = p->next;
        delete p;
        p = q;
    }
    head = NULL;
    len = 0;
    return true;
}

template<class T>
bool LinkList<T>::printList()
{
    if (NULL == head)
    {
        return false;
    }
    LNode<T> *p = head;
    cout << "List: ";
    while (NULL != p)
    {
        cout << p->data << "-->";
        p = p->next;
    }
    cout << "NULL" << endl;
}

template<class T>
bool LinkList<T>::isEmpty()
{
    // 方法1：判断头指针是否为空
    return (NULL == head);
    // 方法2：判断链表长度是否为0
    return (0 == len);
}

template<class T>
int LinkList<T>::length()
{
    if (NULL == head)
    {
        return -1;  // 链表未初始化
    }
    LNode<T> *p = head;
    int count = 0;
    while (NULL != p)
    {
        p = p->next;
        count++;
    }
    return count;
}

template<class T>
LNode<T> *LinkList<T>::getElem(int i)
{
    if (NULL == head)
    {
        cout << "查找失败！Error: 链表未初始化" << endl;
        return NULL;
    }
    if (i < 0)
    {
        cout << "查找失败！Error: i值非法(小于0)" << endl;
        return NULL;
    }
    LNode<T> *p = head;
    int j = 0;
    while (NULL != p && j < i)
    {
        p = p->next;
        j++;
    }
    if (NULL == p)
    {
        cout << "查找失败！Error: i值非法(大于链表长度)" << endl;
        return NULL;
    }
    return &(p->data);
}

template<class T>
LNode<T> *LinkList<T>::locateElem(int *i, T e)
{
    if (NULL == head)
    {
        cout << "查找失败！Error: 链表未初始化" << endl;
        return NULL;
    }
    LNode<T> *p = head;
    int j = 0;
    while (NULL != p && p->data != e)
    {
        p = p->next;
        j++;
    }
    if (NULL == p)
    {
        cout << "查找失败！Error: 未找到元素" << endl;
        return NULL;
    }
    *i = j;
    return p;
}

template<class T>
bool LinkList<T>::insert(int i, T e)
{
    if (NULL == head)
    {
        cout << "插入失败！Error: 链表未初始化" << endl;
        return false;
    }
    if (i < 0)
    {
        cout << "插入失败！Error: i值非法(小于0)" << endl;
        return false;
    }
    LNode<T> *p = head;
    int j = 0;
    while (NULL != p && j < i)
    {
        p = p->next;
        j++;
    }
    if (NULL == p)
    {
        cout << "插入失败！Error: i值非法(大于链表长度)" << endl;
        return false;
    }
    return insertNextNode(p, e);
}

template<class T>
bool LinkList<T>::insertNextNode(LNode<T> *p, T e)
{
    if (NULL == p)
    {
        return false;
    }
    LNode<T> *newNode = new LNode<T>(e);
    if (NULL == newNode)
    {
        return false;
    }
    newNode->next = p->next;
    p->next = newNode;
    return true;
}

template<class T>
bool LinkList<T>::insertPriorNode(LNode<T> *p, T e)
{
    if (NULL == p)
    {
        return false;
    }
    LNode<T> *newNode = new LNode<T>(e);
    if (NULL == newNode)
    {
        return false;
    }
    // 先后插，再交换
    newNode->next = p->next;
    p->next = newNode;
    T temp = p->data;
    p->data = newNode->data;
    newNode->data = temp;
    return true;
}
