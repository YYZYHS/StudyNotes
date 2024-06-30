#include <iostream>
using namespace std;

template <class T>
struct LNode
{
	T data;														// 数据域
	LNode<T> *next;												// 指针域
	LNode() : next(nullptr) {}									// 无参构造函数
	LNode(T d, LNode<T> *n = nullptr) : data(d), next(n) {}		// 有参构造函数
	~LNode() {}													// 析构函数
};

template <class T>
class LinkList
{
public:
	LinkList();														// 无参构造函数
	~LinkList();													// 析构函数

	// 主要函数
	void initListByHead();											// 头插法建立链表
	void initListByTail();											// 尾插法建立链表
	bool insertList(int i, T e);									// 按位插入 ----后插法
	bool insertListByForward(int i, T e);							// 按位插入 ----前插法
	bool deleteElem(int i, T &e);									// 按位删除
	bool clearList();												// 清空链表
	LNode<T>* getElem(int i) const;									// 按位查找
	int locateElem(T e) const;										// 按值查找

	// 常用函数
	void print() const;												// 打印链表
	bool isEmpty() const;											// 判空
	int length() const;												// 求表长

private:
	LNode<T>* createNewNode(T e) const;								// 创建一个新结点
	bool insertNextNode(LNode<T>* p, T e);							// 在指定结点之后插入新结点
	bool insertPriorNode(LNode<T>* p, T e);							// 在指定结点之前插入新结点



private:
	LNode<T> *m_dymmyNode;												// 头指针
	int m_length;														// 链表长度
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
	cout << "测试是否能判断越界行为:"<< "L2第" << L2.length() + 1 << "个元素：" << (p4 == nullptr ? "不存在" : "存在") << endl;

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

template<class T>
LinkList<T>::LinkList()
	: m_dymmyNode{ new LNode<T> }, m_length(0)
{
}


template<class T>
LinkList<T>::~LinkList()
{
	clearList();
	m_dymmyNode = nullptr;
	m_length = 0;
}

template<class T>
void LinkList<T>::initListByHead()
{
	clearList();									// 清空链表
	T e;
	while (true)								// 输入数据
	{
		cout << "请输入数据(以9999结束): ";
		cin >> e;
		if (e == 9999)							// 输入9999结束
		{
			break;
		}
		LNode<T> *newNode = createNewNode(e);		// 创建新结点
		newNode->next = m_dymmyNode->next;			// 新结点指向头结点的后继结点
		m_dymmyNode->next = newNode;				// 头结点指向新结点
		++m_length;									// 长度加1
	}
}

template<class T>
void LinkList<T>::initListByTail()
{
	clearList();									// 清空链表
	T e;
	LNode<T> *tail = m_dymmyNode;					// 尾指针
	while (true)								// 输入数据
	{
		cout << "请输入数据(以9999结束): ";
		cin >> e;
		if (e == 9999)								// 输入9999结束
		{
			break;
		}
		LNode<T> *newNode = createNewNode(e);		// 创建新结点
		tail->next = newNode;						// 尾结点指向新结点
		tail = newNode;								// 尾指针指向新结点
		++m_length;									// 长度加1
	}

}

template<class T>
bool LinkList<T>::insertList(int i, T e)
{
	if(i < 1 || i > m_length + 1)						// 判断位置是否合法
	{
		cerr << "插入位置不合法" << endl;
		return false;
	}
	if(i == 1)
	{
		return insertNextNode(m_dymmyNode, e);			// 在头结点后插入新结点
	}
	LNode<T> *p = getElem(i - 1);						// 找到第i-1个结点
	return insertNextNode(p, e);						// 在第i-1个结点后插入新结点
}

template<class T>
bool LinkList<T>::insertListByForward(int i, T e)
{
	if(i < 1 || i > m_length + 1)						// 判断位置是否合法
	{
		cerr << "插入位置不合法" << endl;
		return false;
	}
	LNode<T> *p = getElem(i);							// 找到第i个结点
	return insertPriorNode(p, e);						// 在第i-1个结点前插入新结点
}

template<class T>
bool LinkList<T>::deleteElem(int i, T& e)
{
	if(i < 1 || i > m_length)						// 判断位置是否合法
	{
		cerr << "删除位置不合法" << endl;
		return false;
	}
	LNode<T> *p = getElem(i - 1);					// 找到第i-1个结点
	LNode<T> *q = p->next;							// 找到第i个结点
	e = q->data;									// 保存数据
	p->next = q->next;								// 删除结点
	delete q;										// 释放空间
	--m_length;										// 长度减1
	return true;
}

template<class T>
bool LinkList<T>::clearList()
{
	LNode<T> *p = m_dymmyNode->next;
	while (p != nullptr)
	{
		LNode<T> *q = p->next;
		delete p;
		p = q;
	}
	m_dymmyNode->next = nullptr;
	m_length = 0;
	return true;
}

template<class T>
LNode<T>* LinkList<T>::getElem(int i) const
{
	if (i == 0)
	{
		cout << "没有第0个元素,此处返回头结点" << endl;
		return m_dymmyNode;							// 返回头结点
	}
	if(i < 1 || i > m_length)						// 判断位置是否合法
	{
		cerr << "位置不合法" << endl;
		return nullptr;
	}
	LNode<T> *p = m_dymmyNode->next;				// 创建一个指针p指向头结点
	for (int j = 1; j < i; ++j)						// 找到第i个结点
	{
		p = p->next;
	}
	return p;										// 返回第i个结点
}

template<class T>
int LinkList<T>::locateElem(T e) const
{
	LNode<T> *p = m_dymmyNode->next;				// 创建一个指针p指向头结点
	int i = 1;										// 计数器
	while (p != nullptr)							// 遍历链表
	{
		if(p->data == e)							// 找到元素
		{
			return i;								// 返回位置
		}
		p = p->next;
		++i;
	}
	return 0;										// 没有找到元素
}

template<class T>
void LinkList<T>::print() const
{
	LNode<T> *p = m_dymmyNode->next;
	while (p != nullptr)
	{
		cout << p->data << "-->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

template<class T>
bool LinkList<T>::isEmpty() const
{
	return m_length == 0;
}

template<class T>
int LinkList<T>::length() const
{
	return m_length;
}

template<class T>
LNode<T>* LinkList<T>::createNewNode(T e) const
{
	LNode<T> *newNode = new LNode<T>(e);		// 创建新结点
	if (newNode == nullptr)						// 创建失败
	{
		cerr << "创建新结点失败" << endl;
		exit(1);
	}
	return newNode;								// 返回新结点
}

template<class T>
bool LinkList<T>::insertNextNode(LNode<T>* p, T e)
{
	if(p == nullptr)									// 判断结点是否为空
	{
		cerr << "插入位置不合法" << endl;
		return false;
	}

	LNode<T> *newNode = createNewNode(e);					// 创建新结点
	newNode->next = p->next;								// 新结点指向p的后继结点
	p->next = newNode;										// p指向新结点
	++m_length;												// 长度加1
	return true;
}

template<class T>
bool LinkList<T>::insertPriorNode(LNode<T>* p, T e)
{
	if(p == nullptr)									// 判断结点是否为空
	{
		cerr << "插入位置不合法" << endl;
		return false;
	}

	// 方法一: 交换数据域,时间复杂度O(1)
	LNode<T> *newNode = createNewNode(e);					// 创建新结点
	if(newNode == nullptr)									// 创建失败
	{
		cerr << "创建新结点失败" << endl;
		return false;
	}
	newNode->next = p->next;								// 新结点指向p的后继结点
	p->next = newNode;										// p指向新结点
	swap(p->data, newNode->data);							// 交换数据域
	++m_length;												// 长度加1

	// 方法二: 时间复杂度O(n)
	//LNode<T> *q = m_head;									// 创建一个指针q指向头结点
	//while (q->next != p)									// 找到p的前驱结点
	//{
	//	q = q->next;
	//}
	//if(q == nullptr)										// 没有找到p的前驱结点
	//{
	//	cerr << "插入位置不合法" << endl;
	//	return false;
	//}
	//LNode<T> *newNode = createNewNode(e);						// 创建新结点
	//if(newNode == nullptr)									// 创建失败
	//{
	//		cerr << "创建新结点失败" << endl;
	// 		return false;
	//}
	//newNode->next = p;										// 新结点指向p
	//q->next = newNode;										// q指向新结点
	//++m_length;												// 长度加1

	return true;
}
