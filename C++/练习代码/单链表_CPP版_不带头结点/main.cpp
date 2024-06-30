#include <iostream>
using namespace std;


template <typename T>
struct LNode
{
	T data;														// 数据域
	LNode<T>* next;												// 指针域
	LNode() : next(nullptr) {}									// 无参构造函数
	LNode(T d, LNode<T>* n = nullptr) : data(d), next(n) {}		// 有参构造函数
	~LNode() {}													// 析构函数
};


template <typename T>
class LinkList
{
public:
	LinkList();				//构造函数
	~LinkList();			//析构函数

	// 链表操作
	bool initListByHead();											// 头插法建立链表
	bool initListByTail();											// 尾插法建立链表
	bool insertList(int i, T e);									// 按位插入 ----后插法
	bool insertListByForward(int i, T e);							// 按位插入 ----前插法
	bool deleteElem(int i, T& e);									// 按位删除
	bool clearList();												// 清空链表
	LNode<T>* getElem(int i) const;									// 按位查找
	int locateElem(T e) const;										// 按值查找


	// 常用函数
	int length() const;			//获取链表长度
	bool isEmpty() const;			//判断链表是否为空
	void print() const;			//打印链表

private:
	LNode<T>* createNewNode(T e) const;								// 创建一个新结点
	bool insertNextNode(LNode<T>* p, T e);							// 在指定结点之后插入新结点
	bool insertPriorNode(LNode<T>* p, T e);							// 在指定结点之前插入新结点


private:
	LNode<T> *m_head;		//头指针
	int m_length;			//链表长度
};



int main()
{
	// 以下是测试代码

	// 1、初始化三个链表
	cout << "开始测试，首先初始化三个测试链表" << endl;
	LinkList<int> L1, L2, L3;
	cout << "开始初始化第一个链表，此链表为空表" << endl;
	L1.clearList();
	cout << "开始初始化第二个链表，此链表用前插法初始化" << endl;
	L2.initListByHead();
	cout << "开始初始化第三个链表，此链表用尾插法初始化" << endl;
	L3.initListByTail();

	// 2、打印输出，测试判空和求表长
	cout << "开始打印第一个链表：" << endl;
	L1.print();
	cout << "开始打印第二个链表：" << endl;
	L2.print();
	cout << "开始打印第三个链表：" << endl;
	L3.print();
	cout << "L1是否为空：" << (L1.isEmpty() ? "是" : "否") << endl;
	cout << "L2是否为空：" << (L2.isEmpty() ? "是" : "否") << endl;
	cout << "L3是否为空：" << (L3.isEmpty() ? "是" : "否") << endl;
	cout << "L1的长度：" << L1.length() << endl;
	cout << "L2的长度：" << L2.length() << endl;
	cout << "L3的长度：" << L3.length() << endl;

	// 3、L2按位查找，分别测试首尾元素和中间的元素
	cout << "开始测试L2按位查找" << endl;
	LNode<int>* p1 = L2.getElem(1);
	LNode<int>* p2 = L2.getElem(3);
	LNode<int>* p3 = L2.getElem(L2.length());
	LNode<int>* p4 = L2.getElem(L2.length() + 1);
	cout << "L2第1个元素：" << p1->data << endl;
	cout << "L2第3个元素：" << p2->data << endl;
	cout << "L2最后一个元素：" << p3->data << endl;
	cout << "测试是否能判断越界行为:" << "L2第" << L2.length() + 1 << "个元素：" << (p4 == nullptr ? "不存在" : "存在") << endl;

	// 4、L2按值查找，分别测试首尾元素和中间的元素
	cout << "开始测试L2按值查找" << endl;
	int i1 = L2.locateElem(1);
	int i2 = L2.locateElem(3);
	int i3 = L2.locateElem(L2.getElem(1)->data);
	int i4 = L2.locateElem(9999);//不存在的元素
	cout << "元素1的位置：" << i1 << endl;
	cout << "元素3的位置：" << i2 << endl;
	cout << "初始化时最后输入的元素的位置：" << i3 << endl;
	cout << "测试是否能判断不存在的元素:" << "元素9999的位置：" << i4 << endl;

	// 5、L3按位插入，分别以前插、后插的方式，在表头，表尾，表中插入元素
	cout << "开始测试L3按位插入" << endl;
	cout << "在表头以前插方式插入元素100," << (L3.insertListByForward(1, 100) ? "成功" : "失败") << endl;
	cout << "在表尾以前插方式插入元素200," << (L3.insertListByForward(L3.length() + 1, 200) ? "成功" : "失败") << endl;
	cout << "在链表倒数第二个位置以前插方式插入元素300," << (L3.insertListByForward(L3.length(), 300) ? "成功" : "失败") << endl;
	L3.print();
	cout << "在表头以后插方式插入元素400," << (L3.insertList(1, 400) ? "成功" : "失败") << endl;
	cout << "在表尾以后插方式插入元素500," << (L3.insertList(L3.length() + 1, 500) ? "成功" : "失败") << endl;
	cout << "在链表倒数第二个位置以后插方式插入元素600," << (L3.insertList(L3.length(), 600) ? "成功" : "失败") << endl;
	L3.print();

	// 6、L3删除元素，分别删除表头、表尾、表中元素
	cout << "开始测试L3删除元素" << endl;
	cout << "删除表头元素：" << (L3.deleteElem(1, i1) ? "成功" : "失败") << "，删除的元素是：" << i1 << endl;
	L3.print();
	cout << "删除表尾元素：" << (L3.deleteElem(L3.length(), i2) ? "成功" : "失败") << "，删除的元素是：" << i2 << endl;
	L3.print();
	cout << "删除表中元素：" << (L3.deleteElem(L3.length() / 2, i3) ? "成功" : "失败") << "，删除的元素是：" << i3 << endl;
	L3.print();

	// 7、清空三个链表
	cout << "开始清空三个链表,为了测试清空空表，先将L1置为空表" << endl;
	L1.clearList();
	cout << "清空L1：" << (L1.clearList() ? "成功" : "失败") << endl;
	cout << "清空L2：" << (L2.clearList() ? "成功" : "失败") << endl;
	cout << "清空L3：" << (L3.clearList() ? "成功" : "失败") << endl;
	L1.print();
	L2.print();
	L3.print();

	// 8、结束语
	cout << "测试结束" << endl;
	return 0;
}


template<typename T>
LinkList<T>::LinkList()
	: m_head(nullptr), m_length(0)
{
}

template<typename T>
LinkList<T>::~LinkList()
{
	clearList();
}

template<typename T>
bool LinkList<T>::initListByHead()
{
	clearList();
	T e;
	while (true)
	{
		cout << "请输入数据(以9999结束): ";
		cin >> e;
		if (e == 9999)
		{
			break;
		}
		LNode<T> *newNode = createNewNode(e);		// 创建新结点
		if (newNode == nullptr)						// 创建失败
		{
			cerr << "创建新结点失败" << endl;
			clearList();							// 清空链表
			return false;							// 退出函数
		}
		newNode->next = m_head;							// 新结点指向头结点
		m_head = newNode;								// 头指针指向新结点
		m_length++;										// 链表长度加1
	}
	cout << "头插法建立链表成功" << endl;
	return true;
}

template<typename T>
bool LinkList<T>::initListByTail()
{
	clearList();
	T e;
	LNode<T> *tail = m_head;	// 尾指针
	while (true)
	{
		cout << "请输入数据(以9999结束): ";
		cin >> e;
		if (e == 9999)
		{
			break;
		}
		LNode<T> *newNode = createNewNode(e);		// 创建新结点
		if (newNode == nullptr)						// 创建失败
		{
			cerr << "创建新结点失败" << endl;
			clearList();							// 清空链表
			return false;							// 退出函数
		}
		if (m_head == nullptr)						// 链表为空
		{
			m_head = newNode;						// 头指针指向新结点
			tail = newNode;							// 尾指针指向新结点
		}
		else
		{
			tail->next = newNode;					// 尾结点指向新结点
			tail = newNode;							// 尾指针指向新结点
		}
		m_length++;									// 链表长度加1
	}
	cout << "尾插法建立链表成功" << endl;
	return true;
}

template<typename T>
bool LinkList<T>::insertList(int i, T e)
{
	if (i < 1 || i > m_length + 1)
	{
		cout << "插入位置不合法" << endl;
		return false;
	}

	// 特殊情况:插入位置为头结点
	if (i == 1)
	{
		LNode<T> *newNode = createNewNode(e);	// 创建新结点
		if (newNode == nullptr)					// 创建失败
		{
			return false;
		}
		newNode->next = m_head;					// 新结点指向头结点
		m_head = newNode;						// 头指针指向新结点
		m_length++;								// 链表长度加1
		return true;
	}

	// 一般情况:插入位置不为头结点
	LNode<T> *p = getElem(i - 1);				// 获取第i-1个结点
	if (p == nullptr)							// 未找到第i-1个结点
	{
		cout << "未找到第" << i - 1 << "个结点" << endl;
		return false;
	}
	return insertNextNode(p, e);				// 在第i-1个结点之后插入新结点
}

template<typename T>
bool LinkList<T>::insertListByForward(int i, T e)
{
	if (i < 1 || i > m_length + 1)
	{
		cout << "插入位置不合法" << endl;
		return false;
	}

	// 特殊情况:插入位置为头结点
	if (i == 1)
	{
		LNode<T> *newNode = createNewNode(e);	// 创建新结点
		if (newNode == nullptr)					// 创建失败
		{
			return false;
		}
		newNode->next = m_head;					// 新结点指向头结点
		m_head = newNode;						// 头指针指向新结点
		m_length++;								// 链表长度加1
		return true;
	}

	// 一般情况:插入位置不为头结点
	LNode<T> *p = getElem(i);				// 获取第i-1个结点
	if (p == nullptr)							// 未找到第i-1个结点
	{
		cout << "未找到第" << i<< "个结点" << endl;
		return false;
	}
	return insertPriorNode(p, e);				// 在第i个结点之前插入新结点
}

template<typename T>
bool LinkList<T>::deleteElem(int i, T& e)
{
	if(i < 1 || i > m_length)
	{
		cout << "删除位置不合法" << endl;
		return false;
	}

	if(isEmpty())
	{
		cout << "链表为空" << endl;
		return false;
	}

	// 特殊情况:删除头结点
	if(i == 1)
	{
		LNode<T> *p = m_head;		// p指向头结点
		m_head = m_head->next;		// 头指针指向第二个结点
		e = p->data;				// 保存删除结点的数据域
		delete p;					// 删除结点
		m_length--;					// 链表长度减1
		return true;
	}
	else
	{
		LNode<T>* p = getElem(i - 1);	// 获取第i-1个结点
		if (p == nullptr)				// 未找到第i-1个结点
		{
			cout << "未找到第" << i - 1 << "个结点" << endl;
			return false;
		}
		LNode<T>* q = p->next;			// q指向第i个结点
		if (q == nullptr)				// 未找到第i个结点
		{
			cout << "未找到第" << i << "个结点" << endl;
			return false;
		}
		p->next = q->next;				// 删除第i个结点
		e = q->data;					// 保存删除结点的数据域
		delete q;						// 删除结点
		m_length--;						// 链表长度减1
		return true;
	}
}

template<typename T>
int LinkList<T>::length() const
{
	return m_length;
}

template<typename T>
bool LinkList<T>::isEmpty() const
{
	return m_head == nullptr;
}

template<typename T>
void LinkList<T>::print() const
{
	LNode<T>* p = m_head;
	while (p != nullptr)
	{
		cout << p->data << "-->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

template<typename T>
LNode<T>* LinkList<T>::createNewNode(T e) const
{
	LNode<T> *newNode = new LNode<T>(e);			// 创建新结点	
	if (newNode == nullptr)						// 创建失败
	{
		cout << "创建新结点失败" << endl;
		return nullptr;
	}
	return newNode;							// 返回新结点
}

template<typename T>
bool LinkList<T>::insertNextNode(LNode<T>* p, T e)
{
	if(p == nullptr)
	{
		cout << "插入位置不合法" << endl;
		return false;
	}
	LNode<T>* newNode = createNewNode(e);	// 创建新结点
	if (newNode == nullptr)					// 创建失败
	{
		return false;
	}
	newNode->next = p->next;				// 新结点指向p的后继结点
	p->next = newNode;						// p指向新结点
	m_length++;								// 链表长度加1
	return true;
}

template<typename T>
bool LinkList<T>::insertPriorNode(LNode<T>* p, T e)
{
	if(p == nullptr)
	{
		cout << "插入位置不合法" << endl;
		return false;
	}

	// 特殊情况:插入位置为头结点
	if(p == m_head)
	{
		LNode<T> *newNode = createNewNode(e);	// 创建新结点
		if(newNode == nullptr)					// 创建失败
		{
			return false;
		}
		newNode->next = m_head;					// 新结点指向头结点
		m_head = newNode;						// 头指针指向新结点
		m_length++;								// 链表长度加1
		return true;
	}

	// 一般情况:插入位置不为头结点
	// 方法一:通过找到p的前驱结点,然后插入新元素,时间复杂度O(n)
	/*
	LNode<T> *q = m_head;	// q指向头结点,从头开始遍历,找到p的前驱结点
	while (q != p)
	{
		q = q->next;
	}
	if(q == nullptr)
	{
		cout << "未找到p的前驱结点" << endl;
		return false;
	}
	LNode<T> *newNode = createNewNode(e);	// 创建新结点
	if(newNode == nullptr)					// 创建失败
	{
		return false;
	}
	newNode->next = q->next;				// 新结点指向p
	q->next = newNode;						// q指向新结点
	m_length++;								// 链表长度加1
	return true;
	*/

	// 方法二:通过交换p和p的前驱结点的数据域,时间复杂度O(1)
	LNode<T> *newNode = createNewNode(e);	// 创建新结点
	if(newNode == nullptr)					// 创建失败
	{
		return false;
	}
	newNode->next = p->next;						// 新结点指向p
	p->next = newNode;								// p指向新结点
	// 交换p和p的前驱结点的数据域
	T temp = p->data;								
	p->data = newNode->data;
	newNode->data = temp;
	m_length++;										// 链表长度加1
	return true;
}

template<typename T>
bool LinkList<T>::clearList()
{
	LNode<T>* p = m_head;
	while (p != NULL)
	{
		LNode<T>* q = p->next;
		delete p;
		p = q;
	}
	m_head = nullptr;
	m_length = 0;
	return true;
}

template<typename T>
LNode<T>* LinkList<T>::getElem(int i) const
{
	if(isEmpty())
	{
		cout << "链表为空" << endl;
		return nullptr;
	}
	if(i < 1 || i > m_length)
	{
		cout << "查找位置不合法" << endl;
		return nullptr;
	}
	LNode<T>* p = m_head;
	for (int j = 1; j < i; j++)
	{
		p = p->next;
	}
	return p;
}

template<typename T>
int LinkList<T>::locateElem(T e) const
{
	if(isEmpty())
	{
		cout << "链表为空" << endl;
		return -1;
	}
	LNode<T>* p = m_head;
	int i = 1;
	while (p != nullptr)
	{
		if(p->data == e)
		{
			return i;
		}
		p = p->next;
		i++;
	}
	cout << "未找到元素" << endl;
	return -1;
}
