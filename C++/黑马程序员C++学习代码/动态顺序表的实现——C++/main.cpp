/**
* @brief 动态顺序表的实现
* @file main.c
* @auther YYZYHS
* @date 2024年8月21日
* @version 1.0
* @note 本代码是动态顺序表的C++实现，包括初始化、插入、删除、查找、输出、扩容等操作
*/

#include <iostream>
using namespace std;

// ====================动态顺序表类定义====================
// 这里使用模板类实现，支持任意数据类型
template <class T>
class DSeqList		// D - Dynamic Se-Sequence
{
public:
// 基本操作
	DSeqList(int capacity = 10);	/// 有参构造函数，默认容量为10
	~DSeqList();	/// 析构函数
	bool init();	/// 初始化
	bool destroy();	/// 销毁
	bool clear();	/// 清空
	bool isEmpty() const;	/// 判空
	int length() const;	/// 求长度
	int capacity() const;	/// 求容量
	bool increase(int len);	/// 扩容
	bool insert(int i, T e);	/// 插入
	bool remove(int i, T& e);	/// 删除
	bool locate(T e, int& i) const;	/// 按值查找
	bool get(int i, T& e) const;	/// 按位查找
	bool set(int i, T e);	/// 赋值
	bool print() const;	/// 输出
// 拓展操作
	bool push_front(T e);	/// 头插
	bool pop_front(T& e);	/// 头删
	bool push_back(T e);	/// 尾插
	bool pop_back(T& e);	/// 尾删
// 高阶操作
	bool removeDuplicate();	/// 去重
	bool reverse();	/// 逆置
	bool merge(const DSeqList<T>& list);	/// 合并
	bool sortByInsert();	/// 插入排序
	bool swap(int i, int j);	/// 交换
	bool sortByQuick(int left = 1, int right = -1);	/// 快速排序

private:
	T* m_data;		/// 数据区
	int m_size;		/// 当前元素个数,即长度
	int m_capacity;	/// 当前容量,即最大元素个数
};

void test1();
void test2();
void test3();
void test4();
void test5();

int main()
{
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试开始！" << endl;
	test1();
	cout << endl << endl << endl;
	test2();
	cout << endl << endl << endl;
	test3();
	cout << endl << endl << endl;
	test4();
	cout << endl << endl << endl;
	test5();
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试结束！" << endl;
	return 0;
}


/*
* @brief 有参构造函数
* @param capacity 动态顺序表的容量
* @return 无，因为是构造函数，不需要返回值
* @note 
*		函数功能：
*			本函数在动态顺序表对象创建时被自动调用，用于初始化动态顺序表对象。
*		函数思路：
*			1. 初始化动态顺序表的容量。
* 			2. 调用init()函数初始化动态顺序表，若初始化成功则什么都不做，否则释放内存。
*		注意：
*			1. 该函数是构造函数，不需要返回值。
*			2. 该函数在动态顺序表对象创建时被自动调用，无需用户手动调用。
*			3. 该函数的参数用来指定动态顺序表初始容量，若不指定则默认为10（在函数声明时已经指定了默认值）。
*			4. 当用户自定义了有参构造函数时，系统不会再提供无参构造函数，因此如果需要用无参构造函数生成对象，需要显式定义无参构造函数。
*/
template<class T>
DSeqList<T>::DSeqList(int capacity)
{
	cout << endl << "[INFO] 构造函数DSeqList(int capacity)被调用" << endl;
	m_capacity = capacity;
	if (!init())
	{
		m_data = NULL;
		m_size = 0;
		m_capacity = 0;
	}
}

/*
* @brief 析构函数
* @param 无
* @return 无，因为是析构函数，不需要返回值
* @note
* 		函数功能：
* 			本函数在动态顺序表对象销毁时被自动调用，用于销毁动态顺序表对象。
* 		函数思路：
* 			1. 调用destroy()函数销毁动态顺序表对象。
*       注意：
* 			1. 该函数是析构函数，不需要返回值。
* 			2. 该函数在动态顺序表对象销毁时被自动调用，无需用户手动调用。
*/
template<class T>
DSeqList<T>::~DSeqList()
{
	cout << endl << "[INFO] 析构函数~DSeqList()被调用" << endl;
	destroy();
}

/*
* @brief 初始化
* @param 无
* @return 初始化成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于初始化动态顺序表。
* 		函数思路：
* 			1. 申请动态顺序表的数据区，若申请成功则初始化成功，否则初始化失败。
* 			2. 如果初始化成功，则将当前元素个数置为0，即长度为0。
* 			3. 返回初始化结果。
* 		注意：
* 			1. 初始化操作会改变动态顺序表的状态，因此不设置为常成员函数。
* 			2. 初始化操作时间复杂度为O(1)，空间复杂度为O(1)。
* 			3. 初始化操作会将数据域创建到堆，该操作可能会失败，因此在申请内存后一定要判断是否申请成功。
*/
template<class T>
bool DSeqList<T>::init()
{
	cout << endl << "[INFO] init()被调用" << endl;
	m_data = new T[m_capacity];
	if (NULL == m_data)
	{
		cout << "[ERROR] 内存分配失败，动态顺序表初始化失败！" << endl;
		return false;
	}
	m_size = 0;
	cout << "[INFO] 动态顺序表初始化成功！" << endl;
	return true;
}

/*
* @brief 销毁
* @param 无
* @return 销毁成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于销毁动态顺序表。
* 		函数思路：
* 			1. 释放动态顺序表的数据区，若释放成功则销毁成功，否则销毁失败。
* 			2. 如果销毁成功，则将当前元素个数置为0，即长度为0。
* 			3. 返回销毁结果。
* 		注意：
* 			1. 销毁操作会改变动态顺序表的状态，因此不设置为常成员函数。
* 			2. 销毁操作时间复杂度为O(1)，空间复杂度为O(1)。
* 			3. 销毁操作会释放动态顺序表的数据区，因此在销毁前需要判断数据区指针是否合法，如果指针为NULL则不需要释放。
*/
template<class T>
bool DSeqList<T>::destroy()
{
	cout << endl << "[INFO] destroy()被调用" << endl;
	if (NULL != m_data)
	{
		delete[] m_data;
		m_data = NULL;
		m_size = 0;
		m_capacity = 0;
	}
	cout << "[INFO] 动态顺序表销毁成功！" << endl;
	return true;
}

/*
* @brief 清空
* @param 无
* @return 清空成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于清空动态顺序表。
* 		函数思路：
* 			1. 将当前元素个数置为0，即长度为0。
* 			2. 清空成功返回true。
* 		注意：
* 			1. 清空操作会改变动态顺序表的状态，因此不设置为常成员函数。
* 			2. 清空操作时间复杂度为O(1)，空间复杂度为O(1)。
* 			3. 该清空操作为逻辑上的清空，因此数据区的内存空间（即m_data）不会被释放。
*/
template<class T>
bool DSeqList<T>::clear()
{
	cout << endl << "[INFO] clear()被调用" << endl;
	m_size = 0;
	return true;
}

/*
* @brief 判空
* @param 无
* @return 若动态顺序表为空则返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于判断动态顺序表是否为空。
* 		函数思路：
* 			1. 顺序表有成员变量m_size记录当前元素个数，若m_size为0则表示顺序表为空，因此直接返回m_size是否为0即可。
* 	    注意：
* 			1. 因为判空操作不会改变动态顺序表的状态，因此设置为常成员函数。
* 			2. 判空操作时间复杂度为O(1)，空间复杂度为O(1)。
*/
template<class T>
bool DSeqList<T>::isEmpty() const
{
	cout << endl << "[INFO] isEmpty()被调用" << endl;
	return m_size == 0;
}

/*
* @brief 求长度
* @param 无
* @return 返回动态顺序表的长度
* @note
* 		函数功能：
* 			本函数用于求动态顺序表的长度。
* 		函数思路：
* 			1. 顺序表有成员变量m_size记录当前元素个数，直接返回m_size即可。
* 		注意：
* 			1. 因为求长度操作不会改变动态顺序表的状态，因此设置为常成员函数。
* 			2. 求长度操作时间复杂度为O(1)，空间复杂度为O(1)。
*/
template<class T>
int DSeqList<T>::length() const
{
	cout << endl << "[INFO] length()被调用" << endl;
	return m_size;
}


/*
 * @brief 求容量
 * @param 无
 * @return 返回动态顺序表的容量
 * @note
 *		函数功能：
 *			本函数用于求动态顺序表的容量（即表的最大长度）。
 *      函数思路：
 *			1. 顺序表有成员变量m_capacity记录当前容量，直接返回m_capacity即可。
 *		注意：
 *			1. 因为求容量操作不会改变动态顺序表的状态，因此设置为常成员函数。
 *			2. 求容量操作时间复杂度为O(1)，空间复杂度为O(1)。
 */
template<class T>
int DSeqList<T>::capacity() const
{
	cout << endl << "[INFO] capacity()被调用" << endl;
	return m_capacity;
}

/*
* @brief 扩容
* @param len 扩容的长度
* @return 扩容成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于扩容动态顺序表。
* 		函数思路：
* 			1. 申请新的数据区，长度为原数据区长度加上扩容长度。
* 			2. 将原数据区的元素复制到新数据区。
*			3. 释放原数据区。
* 			4. 将新数据区的地址赋给原数据区。
* 			5. 扩容成功返回true。
* 		注意：
* 			1. 扩容操作会改变动态顺序表的状态，因此不设置为常成员函数。
* 			2. 扩容操作时间复杂度为O(m_size)，空间复杂度为O(len),其中m_size为当前元素个数, len为扩容长度。
* 			3. 扩容操作会将数据域创建到堆，该操作可能会失败，因此在申请内存后一定要判断是否申请成功。
*/
template<class T>
bool DSeqList<T>::increase(int len)
{
	cout << endl << "[INFO] increase(int len)被调用，扩容长度为" << len << endl;
	T* new_data = new T[m_capacity + len];
	if (NULL == new_data)
	{
		cout << "[ERROR] 内存分配失败，动态顺序表扩容失败！" << endl;
		return false;
	}
	// 将原数据区的元素复制到新数据区
	// 方法一：使用内存拷贝函数memcpy
	// memcpy(new_data, m_data, m_size * sizeof(T));

	// 方法二：通过for循环逐个复制
	for (int i = 0; i < m_size; i++)
	{
		new_data[i] = m_data[i];
	}
	delete[] m_data;
	m_data = new_data;
	m_capacity += len;
	cout << "[INFO] 动态顺序表扩容成功！" << endl;
	return true;
}

/*
* @brief 按位插入
* @param i 插入位置
* @param e 插入元素
* @return 插入成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于在动态顺序表的第i个位置插入元素e。
* 		函数思路：
* 			1. 首先进行合法性检查，判断动态顺序表是否已初始化，插入位置是否合法，只要有一个不合法则插入失败。
* 			2. 判断动态顺序表是否已满，若已满则需要先扩容再插入，如果扩容失败则插入失败。
* 			3. 从后往前遍历，将第i个位置及其后的元素依次后移一位。
* 			4. 将元素e插入到第i个位置。
* 			5. 元素个数加1。
* 			6. 插入成功返回true。
* 		注意：
* 			1. 顺序表的位序从1开始，而数组的下标从0开始，不要混淆。
* 			2. 在函数中，参数i是指插入位置，其本质为顺序表的位序，从1开始；
*			   而for循环中的j变量的本质是数组的下标，从0开始，因此当用j来表示顺序表的位序时，需要加1；
*			   因此，由“将第i个位置及其后的元素依次后移一位”这句话可知j+1的范围为[i,m_size],
* 			   由于j是数组下标，所以j的范围为[i-1,m_size-1]，所以for循环的范围为[j=m_size-1;j>=i-1;j--]。
* 			3. 因为插入操作会改变动态顺序表的状态，所以不设置为常成员函数。
* 			4. 插入操作时间复杂度为O(n)，空间复杂度为O(1)。
*/
template<class T>
bool DSeqList<T>::insert(int i, T e)
{
	cout << endl << "[INFO] insert(int i, T e)被调用，插入位置为" << i << "，插入元素为" << e << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] 动态顺序表未初始化！" << endl;
		return false;
	}
	if (i < 1 || i > m_size + 1)
	{
		cout << "[ERROR] 插入位置不合法！" << endl;
		return false;
	}
	if (m_size >= m_capacity)
	{
		cout << "[INFO] 动态顺序表已满，开始默认扩容10个元素" << endl;
		if (!increase(10))
		{
			cout << "[ERROR] 扩容失败，插入失败！" << endl;
			return false;
		}
	}
	for (int j = m_size - 1; j >= i - 1; j--)
	{
		m_data[j + 1] = m_data[j];
	}
	m_data[i - 1] = e;
	m_size++;
	return true;
}

/*
* @brief 按位删除
* @param i 删除位置
* @param e 被删除元素
* @return 删除成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于删除动态顺序表的第i个位置的元素。
*		函数思路：
* 			1. 首先进行合法性检查，判断动态顺序表是否已初始化，删除位置是否合法，只要有一个不合法则删除失败。
* 			2. 若通过合法性检查，则将被删除的元素赋值给e。
* 			3. 从前往后遍历，将第i+1个位置及其后的元素依次前移一位。
* 			4. 元素个数减1。
* 			5. 删除成功返回true。
* 		注意：
* 			1. 顺序表的位序从1开始，而数组的下标从0开始，不要混淆。
* 			2. 在函数中，参数i是指删除位置，其本质为顺序表的位序，从1开始；
* 			   而for循环中的j变量的本质是数组的下标，从0开始，因此当用j来表示顺序表的位序时，需要加1；
* 			   因此，由“将第i+1个位置及其后的元素依次前移一位”这句话可知j+1的范围为[i+1,m_size],
* 			   由于j是数组下标，所以j的范围为[i,m_size-1]，所以for循环的范围为[j=i;j<=m_size-1;j++]。
*			3. 因为删除操作会改变动态顺序表的状态，所以不设置为常成员函数。
* 			4. 删除操作时间复杂度为O(n)，空间复杂度为O(1)。
*/
template<class T>
bool DSeqList<T>::remove(int i, T& e)
{
	cout << endl << "[INFO] remove(int i, T& e)被调用，删除位置为" << i << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] 动态顺序表未初始化！" << endl;
		return false;
	}
	if (i < 1 || i > m_size)
	{
		cout << "[ERROR] 删除位置不合法！" << endl;
		return false;
	}
	e = m_data[i - 1];
	for (int j = i; j < m_size; j++)
	{
		m_data[j - 1] = m_data[j];
	}
	m_size--;
	return true;
}

/*
* @brief 按值查找
* @param e 要查找的元素
* @param i 用于返回元素的位序
* @return 查找成功返回true，否则返回false
* @note
*		函数功能：
* 			本函数用于在动态顺序表中查找元素e的位序。
*		函数思路：
*			1. 首先进行合法性检查，判断动态顺序表是否已初始化，如果未初始化则查找失败。
*			2. 从第一个元素开始遍历，若找到元素e则返回true，否则返回false。
*		注意：
*			1. 顺序表的位序从1开始，而数组的下标从0开始，不要混淆。
*			2. 本函数无需判空操作，因为for循环中已经包含了顺序表为空的情况。
*			3. 按值查找操作时间复杂度为O(n)，空间复杂度为O(1)。
*			4. 本函数不需要改变顺序表中的任何值，因此设置为常成员函数。
*/
template<class T>
bool DSeqList<T>::locate(T e, int& i) const
{
	cout << endl << "[INFO] locate(T e, int& i)被调用，查找元素为" << e << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] 动态顺序表未初始化！" << endl;
		return false;
	}for (i = 0; i < m_size; i++)
	{
		if (m_data[i] == e)
		{
			cout << "[INFO] 元素" << e << "的位序为" << ++i << endl; // i+1为元素的位序
			return true;
		}
	}
	cout << "[INFO] 元素" << e << "不存在！" << endl;
	return false;
}

/*
* @brief 按位查找
* @param i 要查找的位序
* @param e 用于返回元素
* @return 查找成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于在动态顺序表中查找位序为i的元素。
* 		函数思路：
* 			1. 首先进行合法性检查，判断动态顺序表是否已初始化，查找位置是否合法，只要有一个不合法则查找失败。
* 			2. 若通过合法性检查，则将第i个位置的元素赋值给e。
* 			3. 查找成功返回true。
* 		注意：
* 			1. 顺序表的位序从1开始，而数组的下标从0开始，不要混淆。
* 			2. 本函数无需判空操作，因为在合法性检查中已经包含了顺序表为空的情况，即（i < 1 || i > m_size）中的m_size为0时。
* 			3. 按位查找操作时间复杂度为O(1)，空间复杂度为O(1)。
* 			4. 本函数不需要改变顺序表中的任何值，因此设置为常成员函数。
*/
template<class T>
bool DSeqList<T>::get(int i, T& e) const
{
	cout << endl << "[INFO] get(int i, T& e)被调用，查找位序为" << i << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] 动态顺序表未初始化！" << endl;
		return false;
	}
	if (i < 1 || i > m_size)
	{
		cout << "[ERROR] 查找位置不合法！" << endl;
		return false;
	}
	e = m_data[i - 1];
	cout << "[INFO] 位序为" << i << "的元素为" << e << endl;
	return true;
}

/*
* @brief 赋值
* @param i 要赋值的位序
* @param e 赋值的元素
* @return 赋值成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于将动态顺序表中第i个位置的元素赋值为e。
* 		函数思路：
* 			1. 首先进行合法性检查，判断动态顺序表是否已初始化，赋值位置是否合法，只要有一个不合法则赋值失败。
* 			2. 若通过合法性检查，则将第i个位置的元素赋值为e。
* 			3. 赋值成功返回true。
* 		注意：
* 			1. 顺序表的位序从1开始，而数组的下标从0开始，不要混淆。
* 			2. 本函数无需判空操作，因为在合法性检查中已经包含了顺序表为空的情况，即（i < 1 || i > m_size）中的m_size为0时。
* 			3. 赋值操作时间复杂度为O(1)，空间复杂度为O(1)。
* 			4. 本函数会改变顺序表中的值，因此不设置为常成员函数。
*/
template<class T>
bool DSeqList<T>::set(int i, T e)
{
	cout << endl << "[INFO] set(int i, T e)被调用，赋值位置为" << i << "，赋值元素为" << e << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] 动态顺序表未初始化！" << endl;
		return false;
	}
	if (i < 1 || i > m_size)
	{
		cout << "[ERROR] 赋值位置不合法！" << endl;
		return false;
	}
	m_data[i - 1] = e;
	cout << "[INFO] 位序为" << i << "的元素赋值为" << e << endl;
	return true;
}

void test1()
{
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试1：静态顺序表的初始化和销毁" << endl;
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 生成一个容量为5的动态顺序表" << endl;
	DSeqList<int> list(5);
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 销毁生成的动态顺序表" << endl; 
	list.destroy();
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试1结束！" << endl;

}

void test2()
{
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试2：测试静态顺序表的插入、输出、清空、判空、表长、主动扩容和查询容量等操作" << endl;
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 生成一个容量为5的动态顺序表" << endl;
	DSeqList<int> list(5);
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试插入操作" << endl;
	list.insert(1, 1);
	list.insert(2, 2);
	list.insert(3, 3);
	list.insert(4, 4);
	list.insert(3, 8);
	list.insert(4, 6);
	list.insert(8, 7);
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试输出操作" << endl;
	list.print();
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试判空操作" << endl;
	cout << "[INFO] 动态顺序表是否为空：" << list.isEmpty() << endl;
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试表长操作" << endl;
	cout << "[INFO] 动态顺序表的长度为：" << list.length() << endl;
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试清空操作" << endl;
	list.clear();
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试判空操作" << endl;
	cout << "[INFO] 动态顺序表是否为空：" << list.isEmpty() << endl;
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试表长操作" << endl;
	cout << "[INFO] 动态顺序表的长度为：" << list.length() << endl;
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试主动扩容操作" << endl;
	cout << "[INFO] 当前动态顺序表的容量为：" << list.capacity() << endl;
	list.increase(5);
	cout << "[INFO] 扩容后动态顺序表的容量为：" << list.capacity() << endl;
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试2结束！" << endl;
}

void test3()
{
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试3：测试静态顺序表的删除、按位查找、按值查找、修改等操作" << endl;
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 生成一个容量为10的动态顺序表" << endl;
	DSeqList<int> list(10);
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 插入10个元素" << endl;
	for (int i = 1; i <= 10; i++)
	{
		list.insert(i, i);
	}
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 输出当前动态顺序表的内容" << endl;
	list.print();
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试按位删除操作" << endl;
	int e;
	if (list.remove(5, e))
	{
		cout << "[INFO] 删除成功，被删除的元素为：" << e << endl;
	}
	else
	{
		cout << "[ERROR] 删除失败！" << endl;
	}
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 输出当前动态顺序表的内容" << endl;
	list.print();
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试按位删除表头和表尾" << endl;
	if (list.remove(1, e))
	{
		cout << "[INFO] 删除表头元素成功，被删除的元素为：" << e << endl;
	}
	else
	{
		cout << "[ERROR] 删除表头元素失败！" << endl;
	}
	cout << endl << endl << "[INFO] 输出当前动态顺序表的内容" << endl;
	list.print();
	if (list.remove(list.length(), e))
	{
		cout << "[INFO] 删除表尾元素成功，被删除的元素为：" << e << endl;
	}
	else
	{
		cout << "[ERROR] 删除表尾元素失败！" << endl;
	}
	cout << endl << endl << "[INFO] 输出当前动态顺序表的内容" << endl;
	list.print();
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试按值查找操作" << endl;
	int i;
	if (list.locate(3, i))
	{
		cout << "[INFO] 按值查找元素3成功，其位序为：" << i << endl;
	}
	else
	{
		cout << "[ERROR] 按值查找元素3失败！" << endl;
	}
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试按值查找表头和表尾元素" << endl;
	if (list.locate(2, i))
	{
		cout << "[INFO] 按值查找表头元素2成功，其位序为：" << i << endl;
	}
	else
	{
		cout << "[ERROR] 按值查找表头元素2失败！" << endl;
	}
	if (list.locate(9, i))
	{
		cout << "[INFO] 按值查找表尾元素9成功，其位序为：" << i << endl;
	}
	else
	{
		cout << "[ERROR] 按值查找表尾元素9失败！" << endl;
	}

	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试按位查找操作" << endl;
	if (list.get(3, e))
	{
		cout << "[INFO] 按位查找位序为3的元素成功，其值为：" << e << endl;
	}
	else
	{
		cout << "[ERROR] 按位查找位序为3的元素失败！" << endl;
	}
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试按位查找表头和表尾元素" << endl;
	if (list.get(1, e))
	{
		cout << "[INFO] 按位查找表头元素成功，其值为：" << e << endl;
	}
	else
	{
		cout << "[ERROR] 按位查找表头元素失败！" << endl;
	}
	if (list.get(list.length(), e))
	{
		cout << "[INFO] 按位查找表尾元素成功，其值为：" << e << endl;
	}
	else
	{
		cout << "[ERROR] 按位查找表尾元素失败！" << endl;
	}

	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试修改操作" << endl;
	if (list.set(3, 5))
	{
		cout << "[INFO] 修改位序为3的元素成功，修改后的元素为：" << 5 << endl;
	}
	else
	{
		cout << "[ERROR] 修改位序为3的元素失败！" << endl;
	}
	cout << endl << endl << "[INFO] 输出当前动态顺序表的内容" << endl;
	list.print();

	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试对表头和表尾元素进行修改" << endl;
	if (list.set(1, 10))
	{
		cout << "[INFO] 修改表头元素成功，修改后的元素为：" << 10 << endl;
	}
	else
	{
		cout << "[ERROR] 修改表头元素失败！" << endl;
	}
	if (list.set(list.length(), 20))
	{
		cout << "[INFO] 修改表尾元素成功，修改后的元素为：" << 20 << endl;
	}
	else
	{
		cout << "[ERROR] 修改表尾元素失败！" << endl;
	}
	cout << endl << endl << "[INFO] 输出当前动态顺序表的内容" << endl;
	list.print();

	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试对空表进行按值查找和按位查找操作" << endl;
	cout << "[INFO] 首先将动态顺序表清空" << endl;
	list.clear();
	cout << "[INFO] 开始按值查找元素值为3的元素" << endl;
	if (list.locate(3, i))
	{
		cout << "[INFO] 按值查找元素3成功，其位序为：" << i << endl;
	}
	else
	{
		cout << "[ERROR] 按值查找元素3失败！" << endl;
	}

	cout << endl << "[INFO] 开始按位查找位序为3的元素" << endl;
	if (list.get(3, e))
	{
		cout << "[INFO] 按位查找位序为3的元素成功，其值为：" << e << endl;
	}
	else
	{
		cout << "[ERROR] 按位查找位序为3的元素失败！" << endl;
	}

}

void test4()
{
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试4：测试静态顺序表的拓展功能" << endl;
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 生成一个容量为10的动态顺序表" << endl;
	DSeqList<int> list(10);
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 插入5个元素" << endl;
	for (int i = 1; i <= 5; i++)
	{
		list.insert(i, i);
	}
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 输出当前动态顺序表的内容" << endl;
	list.print();
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试头插操作" << endl;
	if(list.push_front(0))
	{
		cout << "[INFO] 头插元素0成功！" << endl;
	}
	else
	{
		cout << "[ERROR] 头插元素0失败！" << endl;
	}
	cout << endl << endl << "[INFO] 输出当前动态顺序表的内容" << endl;
	list.print();
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试尾插操作" << endl;
	if (list.push_back(6))
	{
		cout << "[INFO] 尾插元素6成功！" << endl;
	}
	else
	{
		cout << "[ERROR] 尾插元素6失败！" << endl;
	}
	cout << endl << endl << "[INFO] 输出当前动态顺序表的内容" << endl;
	list.print();
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试尾删操作" << endl;
	int e;
	if (list.pop_back(e))
	{
		cout << "[INFO] 尾删成功，被删除的元素为：" << e << endl;
	}
	else
	{
		cout << "[ERROR] 尾删失败！" << endl;
	}
	cout << endl << endl << "[INFO] 输出当前动态顺序表的内容" << endl;
	list.print();
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试头删操作" << endl;
	if (list.pop_front(e))
	{
		cout << "[INFO] 头删成功，被删除的元素为：" << e << endl;
	}
	else
	{
		cout << "[ERROR] 头删失败！" << endl;
	}
	cout << endl << endl << "[INFO] 输出当前动态顺序表的内容" << endl;
	list.print();
	cout << endl << endl << "[INFO] 测试对空表进行拓展功能操作" << endl;
	cout << "[INFO] 首先将动态顺序表清空" << endl;
	list.clear();
	cout << endl << endl << "[INFO] 输出当前动态顺序表的内容" << endl;
	list.print();
	cout << endl << endl << "[INFO] 开始头插元素0" << endl;
	if (list.push_front(0))
	{
		cout << "[INFO] 头插元素0成功！" << endl;
	}
	else
	{
		cout << "[ERROR] 头插元素0失败！" << endl;
	}
	cout << endl << endl << "[INFO] 输出当前动态顺序表的内容" << endl;
	list.print();
	cout << "[INFO] 再次清空动态顺序表" << endl;
	list.clear();
	cout << endl << endl << "[INFO] 输出当前动态顺序表的内容" << endl;
	list.print();
	cout << endl << endl << "[INFO] 开始尾插元素1" << endl;
	if (list.push_back(1))
	{
		cout << "[INFO] 尾插元素1成功！" << endl;
	}
	else
	{
		cout << "[ERROR] 尾插元素1失败！" << endl;
	}
	cout << endl << endl << "[INFO] 输出当前动态顺序表的内容" << endl;
	list.print();
	cout << "[INFO] 再次清空动态顺序表" << endl;
	list.clear();
	cout << endl << endl << "[INFO] 输出当前动态顺序表的内容" << endl;
	list.print();
	cout << endl << endl << "[INFO] 开始头删操作" << endl;
	if (list.pop_front(e))
	{
		cout << "[INFO] 头删成功，被删除的元素为：" << e << endl;
	}
	else
	{
		cout << "[ERROR] 头删失败！" << endl;
	}
	cout << endl << endl << "[INFO] 开始尾删操作" << endl;
	if (list.pop_back(e))
	{
		cout << "[INFO] 尾删成功，被删除的元素为：" << e << endl;
	}
	else
	{
		cout << "[ERROR] 尾删失败！" << endl;
	}
	cout << endl << endl << "[INFO] 输出当前动态顺序表的内容" << endl;
	list.print();
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试4结束！" << endl;

}

void test5()
{
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试5：测试静态顺序表的高阶操作" << endl;
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 生成一个容量为10的动态顺序表" << endl;
	DSeqList<int> list(10);
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 插入10个元素" << endl;
	list.insert(1, 5);
	list.insert(2, 3);
	list.insert(3, 7);
	list.insert(4, 2);
	list.insert(5, 8);
	list.insert(6, 4);
	list.insert(7, 9);
	list.insert(8, 1);
	list.insert(9, 6);
	list.insert(10, 10);
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 输出当前动态顺序表的内容" << endl;
	list.print();
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试排序操作" << endl;
	//list.sortByQuick();
	list.sortByInsert();
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 输出排序后的动态顺序表的内容" << endl;
	list.print();
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试逆置操作" << endl;
	list.reverse();
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 输出逆置后的动态顺序表的内容" << endl;
	list.print();
	cout << endl << endl << "[INFO] ↓========================↓" << endl << "[INFO] 测试5结束！" << endl;
}

/*
* @brief 输出
* @param 无
* @return 输出成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于输出动态顺序表的所有元素。
* 		函数思路：
* 			1. 首先进行合法性检查，判断动态顺序表是否已初始化，如果未初始化则输出失败。
* 			2. 判断动态顺序表是否为空，如果为空则输出失败。
* 			3. 如果不为空，则从第一个元素开始遍历输出所有元素。
* 			4. 输出成功返回true。
* 		注意：
* 			1. 输出操作不会改变动态顺序表的状态，因此设置为常成员函数。
* 			2. 输出操作时间复杂度为O(n)，空间复杂度为O(1)。
* 			3. 顺序表的位序从1开始，而数组的下标从0开始，不要混淆。
*/
template<class T>
bool DSeqList<T>::print() const
{
	cout << endl << "[INFO] print()被调用" << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] 动态顺序表未初始化！" << endl;
		return false;
	}
	if (isEmpty())
	{
		cout << "[INFO] 动态顺序表为空！" << endl;
		return false;
	}
	cout << "[INFO] 动态顺序表的元素为：";
	for (int i = 0; i < m_size; i++)
	{
		cout << m_data[i] << " ";
	}
	cout << endl;
	return true;
}


/*
* @brief 头插元素
* @param e 要插入的元素
* @return 插入成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于在动态顺序表的头部插入元素e。
* 		函数思路：
* 			1. 首先进行合法性检查，判断动态顺序表是否已初始化，是否已满，若未初始则插入失败,若已满则需要考虑扩容。
* 			2. 从后往前遍历，将所有元素依次后移一位，空出第一个位置。
* 			3. 将元素e插入到顺序表的第一个位置，即数组下标为0的位置。
* 			4. 元素个数加1。
* 			5. 插入成功返回true。
* 		注意：
* 			1. 顺序表的位序从1开始，而数组的下标从0开始，不要混淆。
* 			2. 在for循环中，j的本质是数组下标，当需要用j表示元素位序时，应该+1，
* 			   所以根据插入操作中“将第i个元素及之后的元素后移”这句话，位序j+1的范围为[i,m_size]，
* 			   又因为该函数是头插操作，所以i=1，j+1的范围为[1,m_size]，所以j的范围为[0,m_size-1]，所以for循环的范围为[j=m_size-1;j>=0;j--]。
* 			3. 因为插入操作会改变动态顺序表的状态，所以不设置为常成员函数。
* 			4. 该头插操作的时间复杂度为O(n)，空间复杂度为O(1)。
* 			5. 在实际的开发中，头插法其实可以直接调用insert(1,e)来实现，这里只是为了演示头插法的实现原理而特意写出来的。
*/
template<class T>
bool DSeqList<T>::push_front(T e)
{
	cout << endl << "[INFO] push_front(T e)被调用，插入元素为" << e << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] 动态顺序表未初始化！" << endl;
		return false;
	}
	if (m_size >= m_capacity)
	{
		cout << "[INFO] 动态顺序表已满，开始默认扩容10个元素" << endl;
		if (!increase(10))
		{
			cout << "[ERROR] 扩容失败，插入失败！" << endl;
			return false;
		}
	}
	for (int j = m_size - 1; j >= 0; j--)
	{
		m_data[j + 1] = m_data[j];
	}
	m_data[0] = e;
	m_size++;
	return true;
}


/*
* @brief 头删元素
* @param e 用于返回被删除的元素
* @return 删除成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于删除动态顺序表的表头元素。
* 		函数思路：
* 			1. 首先进行合法性检查，判断动态顺序表是否已初始化，是否为空，若未初始化或为空则删除失败。
* 			2. 将表头元素赋值给e。
* 			3. 从前往后遍历，将第2个位置及其后的元素依次前移一位，覆盖掉第1个位置的元素。
* 			4. 元素个数减1。
* 			5. 删除成功返回true。
* 		注意：
* 			1. 顺序表的位序从1开始，而数组的下标从0开始，不要混淆。
* 			2. 因为删除操作会改变动态顺序表的状态，所以不设置为常成员函数。
* 			3. 该头删操作的时间复杂度为O(n)，空间复杂度为O(1)。
*			4. 在for循环中，j的本质是数组下标，当需要用j表示元素位序时，应该+1，
* 			   所以根据删除操作中“将第i+1个元素及之后的元素前移”这句话，位序j+1的范围为[i+1,m_size]，
* 			   又因为该函数是头删操作，所以i=1，j+1的范围为[2,m_size]，所以j的范围为[1,m_size-1]，所以for循环的范围为[j=1;j<=m_size-1;j++]。
* 			5. 顺序表的头删操作其实可以直接调用remove(1,e)来实现，这里只是为了演示头删操作的实现原理而特意写出来的。
*/
template<class T>
bool DSeqList<T>::pop_front(T& e)
{
	cout << endl << "[INFO] pop_front(T& e)被调用" << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] 动态顺序表未初始化！" << endl;
		return false;
	}
	if (isEmpty())
	{
		cout << "[ERROR] 动态顺序表为空，删除失败！" << endl;
		return false;
	}
	e = m_data[0];
	for (int j = 1; j < m_size; j++)
	{
		m_data[j - 1] = m_data[j];
	}
	m_size--;
	return true;
}

/*
* @brief 尾插元素
* @param e 要插入的元素
* @return 插入成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于在动态顺序表的尾部插入元素e。
* 		函数思路：
* 			1. 首先进行合法性检查，判断动态顺序表是否已初始化，是否已满，若未初始则插入失败,若已满则需要考虑扩容。
* 			2. 将元素e插入到顺序表的第m_size+1个位置，即数组的第m_size个位置。
* 			3. 元素个数加1。
* 			4. 插入成功返回true。
* 		注意：
* 			1. 顺序表的位序从1开始，而数组的下标从0开始，不要混淆。
* 			2. 在不考虑扩容操作的情况下，尾插操作的时间复杂度为O(1)，空间复杂度为O(1)；
*			   如果需要扩容，则时间复杂度为O(m_size)，空间复杂度为O(len)，其中m_size为当前元素个数，len为扩容长度。
* 			3. 顺序表的尾插操作其实可以直接调用insert(m_size+1,e)来实现，这里只是为了演示尾插操作的实现原理而特意写出来的。
*/
template<class T>
bool DSeqList<T>::push_back(T e)
{
	cout << endl << "[INFO] push_back(T e)被调用，插入元素为" << e << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] 动态顺序表未初始化！" << endl;
		return false;
	}
	if (m_size >= m_capacity)
	{
		cout << "[INFO] 动态顺序表已满，开始默认扩容10个元素" << endl;
		if (!increase(10))
		{
			cout << "[ERROR] 扩容失败，插入失败！" << endl;
			return false;
		}
	}
	m_data[m_size] = e;
	m_size++;
	return true;
}

/*
* @brief 尾删元素
* @param e 用于返回被删除的元素
* @return 删除成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于删除动态顺序表的表尾元素。
* 		函数思路：
* 			1. 首先进行合法性检查，判断动态顺序表是否已初始化，是否为空，若未初始化或为空则删除失败。
* 			2. 将表尾元素赋值给e，即顺序表的第m_size个元素，数组下标为m_size-1的元素。
* 			3. 元素个数减1。
* 			4. 删除成功返回true。
* 		注意：
* 			1. 顺序表的位序从1开始，而数组的下标从0开始，不要混淆。
* 			2. 因为删除操作会改变动态顺序表的状态，所以不设置为常成员函数。
* 			3. 该尾删操作的时间复杂度为O(1)，空间复杂度为O(1)。
* 			4. 顺序表的尾删操作其实可以直接调用remove(m_size,e)来实现，这里只是为了演示尾删操作的实现原理而特意写出来的。
*/
template<class T>
bool DSeqList<T>::pop_back(T& e)
{
	cout << endl << "[INFO] pop_back(T& e)被调用" << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] 动态顺序表未初始化！" << endl;
		return false;
	}
	if (isEmpty())
	{
		cout << "[ERROR] 动态顺序表为空，删除失败！" << endl;
		return false;
	}
	e = m_data[m_size - 1];
	m_size--;
	return true;
}

/*
* @brief 删除重复元素
* @param 无
* @return 删除成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于删除动态顺序表中的重复元素。
* 		函数思路：
* 			1. 首先进行合法性检查，判断动态顺序表是否已初始化，是否不为空，若未初始化或为空则删除失败。
* 			2. 从第一个元素开始遍历，若找到重复元素则删除，否则继续遍历。
* 			3. 删除成功返回true。
* 		注意：
* 			1. 顺序表的位序从1开始，而数组的下标从0开始，不要混淆。
* 			2. 因为删除操作会改变动态顺序表的状态，所以不设置为常成员函数。
*			3. 由于删除一个元素后，后面的元素会前移，所以需要将j--，否则会漏掉一个元素。
* 			4. 该删除重复元素操作的时间复杂度为O(n^2)，空间复杂度为O(1)。
*/
template<class T>
bool DSeqList<T>::removeDuplicate()
{
	cout << endl << "[INFO] removeDuplicate()被调用" << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] 动态顺序表未初始化！" << endl;
		return false;
	}
	if (isEmpty())
	{
		cout << "[ERROR] 动态顺序表为空，删除失败！" << endl;
		return false;
	}
	for (int i = 0; i < m_size; i++)
	{
		for (int j = i + 1; j < m_size; j++)
		{
			if (m_data[i] == m_data[j])
			{
				T e;
				remove(j + 1, e);// remove函数中已经会将m_size--，所以这里不需要再m_size--。
				j--;
			}
		}
	}
	return true;
}

/*
* @brief 逆置
* @param 无
* @return 逆置成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于逆置动态顺序表中的所有元素。
* 		函数思路：
* 			1. 首先进行合法性检查，判断动态顺序表是否已初始化，是否不为空，若未初始化或为空则逆置失败。
* 			2. 从第一个元素开始遍历，将第i个元素与第m_size-i个元素交换。
* 			3. 逆置成功返回true。
* 		注意：
* 			1. 顺序表的位序从1开始，而数组的下标从0开始，不要混淆。
* 			2. 逆置操作会改变动态顺序表的状态，所以不设置为常成员函数。
*			3. 如果顺序表的表长为偶数，则正好逆置一半的元素，如果表长为奇数，则中间的元素不需要移动，因为它是对称点。
*			4. 在c++中，整数的除法会向下取整，所以代码中的m_size/2会取整，例如m_size=5时，5/2=2，所以i的范围为[0,2)。
*			5. 交换元素位置时，需要一个临时变量temp来存储交换的中间值，将该变量写在for循环外面，可以减少内存的分配和释放次数，提高效率。
* 			6. 该逆置操作的时间复杂度为O(n)，空间复杂度为O(1)。
*/
template<class T>
bool DSeqList<T>::reverse()
{
	cout << endl << "[INFO] reverse()被调用" << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] 动态顺序表未初始化！" << endl;
		return false;
	}
	if (isEmpty())
	{
		cout << "[ERROR] 动态顺序表为空，逆置失败！" << endl;
		return false;
	}
	// 开始逆置
	T temp; // 将temp写在for循环外面，可以减少内存的分配和释放次数
	for (int i = 0; i < m_size / 2; i++)
	{
		temp = m_data[i];
		m_data[i] = m_data[m_size - i - 1];
		m_data[m_size - i - 1] = temp;
	}
	return true;
}


/*
* @brief 合并
* @param list 要合并的顺序表
* @return 合并成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于将两个有序的动态顺序表合并成一个有序的动态顺序表。
* 		函数思路：
*			1. 首先进行合法性检查，判断两个动态顺序表的数据域是否有效，若有一个无效（即m_data == NULL）则合并失败。
* 			2. 判断两个动态顺序表是否为空
			   若本顺序表为空，则将list合并到本顺序表中，若list为空，则不需要合并。
			   若两个顺序表都为空，则合并失败。
* 			3. 申请一片新的数组空间，数组长度为两个动态顺序表的长度之和。
*			4. 从第一个元素开始遍历，将两个动态顺序表中的元素依次比较，将较小的元素放入新的数组中。
* 			5. 若有一个动态顺序表的元素已经全部放入新数组中，则将另一个动态顺序表的剩余元素依次放入新数组中。
* 			6. 释放原来的数组空间，将新数组的地址赋值给数据域指针m_data。
* 			7. 修改动态顺序表的表长。
* 			8. 合并成功返回true。
* 		注意：
*			1. 顺序表的位序从1开始，而数组的下标从0开始，不要混淆。
* 			2. 合并操作会改变动态顺序表的状态，所以不设置为常成员函数。
* 			3. 该合并操作的时间复杂度为O(n)，空间复杂度为O(n)，其中n为两个动态顺序表的长度之和。
*			4. 与静态顺序表的合并相比，动态顺序表的合并操作更加灵活和通用，
			   因为动态顺序表的容量是可以动态调整的，而静态顺序表的容量是固定的，所以静态顺序表的合并操作需要考虑容量的问题。
*			5. 在合并算法中，需要维护三个指针，分别指向两个动态顺序表和新数组，以便于比较和插入操作。
*			6. 合并算法的局限性在于，只能合并两个有序的动态顺序表，如果两个动态顺序表是无序的，则需要先排序再合并。
*/
template<class T>
bool DSeqList<T>::merge(const DSeqList<T>& list)
{
	cout << endl << "[INFO] merge(const DSeqList<T>& list)被调用" << endl;
	if (NULL == m_data || NULL == list.m_data)
	{
		cout << "[ERROR] 两个动态顺序表中至少有一个未初始化，合并失败！" << endl;
		return false;
	}
	if (isEmpty())
	{
		if (list.isEmpty())
		{
			cout << "[ERROR] 两个动态顺序表都为空，合并失败！" << endl;
			return false;
		}
		cout << "[INFO] 本动态顺序表为空，将list合并到本动态顺序表中" << endl;
		m_data = new T[list.m_capacity];
		for (int i = 0; i < list.m_size; i++)
		{
			m_data[i] = list.m_data[i];
		}
		m_size = list.m_size;
		m_capacity = list.m_capacity;
		return true;
	}
	if (list.isEmpty())
	{
		cout << "[INFO] list为空，不需要合并" << endl;
		return true;
	}
	T* temp = new T[m_size + list.m_size];
	// 创建三个变量，分别记录本顺序表的元素位置、list顺序表的元素位置、新数组的元素位置
	int indexThis = 0, indexOther = 0, indexMerged = 0;
	while (indexThis < m_size && indexOther < list.m_size)
	{
		if (m_data[indexThis] < list.m_data[indexOther])
		{
			temp[indexMerged++] = m_data[indexThis++];
		}
		else
		{
			temp[indexMerged++] = list.m_data[indexOther++];
		}
	}
	while (indexThis < m_size)
	{
		temp[indexMerged++] = m_data[indexThis++];
	}
	while (indexOther < list.m_size)
	{
		temp[indexMerged++] = list.m_data[indexOther++];
	}
	delete[] m_data;
	m_data = temp;
	m_size = m_size + list.m_size;
	m_capacity = m_size;
	return true;
}

/*
* @brief 插入排序
* @param 无
* @return 排序成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于对动态顺序表中的元素进行插入排序。
* 		函数思路：
* 			1. 首先进行合法性检查，判断动态顺序表是否已初始化，是否为空，若未初始化则排序失败。
*			2. 判断动态顺序表是否为空，若为空则排序成功。
* 			3. 从第一个元素开始，该元素可以认为已经被排序。
			4. 取出下一个元素，记为temp，在已经排序的元素序列中从后向前扫描。
			5. 如果被扫描到的元素大于temp，则将该元素后移一位，空出一个位置。
			6. 重复步骤5，直到找到已排序的元素小于或者等于新元素的位置。
			7. 将新元素插入到该位置后。
			8. 重复步骤3-7，直到所有元素均排序完成。
* 		注意：
* 			1. 顺序表的位序从1开始，而数组的下标从0开始，不要混淆。
* 			2. 插入排序操作会改变动态顺序表的状态，所以不设置为常成员函数。
* 			3. 插入排序的核心思想是将一个元素插入到已经排好序的元素中，使得插入后的元素仍然有序。
*			4. 该插入排序操作的时间复杂度为O(n^2)，空间复杂度为O(1)。
* 			4. 插入排序是一种稳定的排序算法，即相同元素的相对位置不会发生变化。
* 			5. 插入排序是一种原地排序算法，即不需要额外的存储空间。
* 			6. 插入排序是一种简单的排序算法，适用于小规模的数据排序。
* 			7. 对于部分有序的数据，插入排序的效率较高，反之，插入排序的效率较低。
*			8. 代码中展示的是升序排序，若要降序排序，则需要将temp < m_data[j]改为temp > m_data[j]即可。
*/
template<class T>
bool DSeqList<T>::sortByInsert()
{
	cout << endl << "[INFO] sortByInsert()被调用" << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] 动态顺序表未初始化！" << endl;
		return false;
	}
	if (isEmpty())
	{
		cout << "[INFO] 动态顺序表为空，排序成功！" << endl;
		return true;
	}
	T temp;
	for (int i = 1; i < m_size; i++)
	{
		temp = m_data[i]; // 取出当前要排序的元素
		int j = i - 1;

		// 在已经排序的元素序列中从后向前扫描
		while (j >= 0 && temp < m_data[j])
		{
			m_data[j + 1] = m_data[j]; // 当当前元素大于temp时，将当前元素后移一位
			j--;
		}
		m_data[j + 1] = temp; // 将temp插入到合适的位置
	}
	return true;
}

/*
* @brief 元素交换
* @param i 第一个元素的位序
* @param j 第二个元素的位序
* @return 交换成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于交换动态顺序表中的两个元素，主要用于在快排算法中方便交换元素。
* 		函数思路：
* 			1. 首先进行合法性检查，判断动态顺序表是否已初始化，若未初始化则交换失败。
* 			2. 判断动态顺序表是否为空，若为空则交换失败。
* 			3. 判断i和j是否合法，即i和j的范围为[1,m_size]。
* 			4. 交换两个元素的位置。
* 			5. 交换成功返回true。
* 		注意：
* 			1. 顺序表的位序从1开始，而数组的下标从0开始，函数参数表中的i和j是元素的位序，而不是数组的下标，注意不要混淆。
* 			2. 交换操作会改变动态顺序表的状态，所以不设置为常成员函数。
* 			3. 该交换操作的时间复杂度为O(1)，空间复杂度为O(1)。
*/
template<class T>
bool DSeqList<T>::swap(int i, int j)
{
	cout << endl << "[INFO] swap(int " << i << ", int " << j << ")被调用" << endl;
	// 首先进行合法性检查
	if (NULL == m_data)
	{
		cout << "[ERROR] 动态顺序表未初始化！" << endl;
		return false;
	}
	// 判断动态顺序表是否为空
	if (isEmpty())
	{
		cout << "[ERROR] 动态顺序表为空，交换失败！" << endl;
		return false;
	}
	// 判断i和j是否合法
	 if (i < 1 || i > m_size || j < 1 || j > m_size)
	 {
		 cout << "[ERROR] 交换的元素位序不合法！" << endl;
		 return false;
	 }
	// test start
	cout << "[INFO] 交换前的顺序表为：";
	for (int i = 0; i < m_size; i++)
	{
		cout << m_data[i] << " ";
	}
	cout << endl;
	// test end
	T temp = m_data[i - 1];
	m_data[i - 1] = m_data[j - 1];
	m_data[j - 1] = temp;
	// test start
	cout << "[INFO] 交换后的顺序表为：";
	for (int i = 0; i < m_size; i++)
	{
		cout << m_data[i] << " ";
	}
	cout << endl;
	// test end
	return true;
}


/*
* @brief 快速排序
* @param left 待排序序列的左边界
* @param right 待排序序列的右边界，若right为-1，则表示对整个顺序表进行排序
* @return 排序成功返回true，否则返回false
* @note
* 		函数功能：
* 			本函数用于对动态顺序表中的元素进行快速排序。
* 		函数思路：
* 			1. 首先进行合法性检查，判断动态顺序表是否已初始化，若未初始化则排序失败。
* 			2. 判断动态顺序表是否为空，若为空则排序成功。
* 			3. 选择一个基准元素，通常选择第一个元素，用变量T pivot记录它。
* 			4. 从右向左找到第一个小于基准元素的元素，将其放到基准元素的位置。
* 			5. 从左向右找到第一个大于基准元素的元素，将其放到步骤4中空出的位置。
* 			6. 重复步骤4和5，直到左右指针相遇。
* 			7. 将基准元素放到最终的位置，此时基准元素左边的元素都小于它，右边的元素都大于它。
* 			8. 递归处理左右两个子序列，直到子序列的长度为1。
* 			9. 排序成功返回true。
* 		注意：
* 			1. 顺序表的位序从1开始，而数组的下标从0开始，函数参数表中的left和right是元素的位序，而不是数组的下标，注意不要混淆。
* 			2. 快速排序操作会改变动态顺序表的状态，所以不设置为常成员函数。
* 			3. 该快速排序操作的时间复杂度为O(nlogn)，空间复杂度为O(logn)。
* 			4. 快速排序是一种不稳定的排序算法，即相同元素的相对位置可能发生变化。
* 			5. 快速排序是一种递归的排序算法，递归的最大深度为logn，所以空间复杂度为O(logn)。
* 			6. 准确的说，快速排序是一种分治的排序算法，将一个大问题分解为两个小问题，然后递归解决。
* 			7. 快速排序是一种原地排序算法，即不需要额外的存储空间。
* 			8. 快速排序是一种高效的排序算法，适用于大规模数据的排序。
* 			9. 快速排序的效率取决于基准元素的选择，通常选择第一个元素，但是如果顺序表是有序的，则选择第一个元素作为基准元素会导致最坏情况的发生。
* 			10. 为了避免最坏情况的发生，可以随机选择基准元素，或者选择中间位置的元素作为基准元素。
* 			11. 该快速排序算法是升序排序，若要降序排序，则需要将两个while循环中的>=和<=对换位置即可。
*/
template<class T>
bool DSeqList<T>::sortByQuick(int left, int right)
{
	cout << endl << "[INFO] sortByQuick(int " << left << ", int " << right << ")被调用" << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] 动态顺序表未初始化！" << endl;
		return false;
	}
	if (isEmpty())
	{
		cout << "[INFO] 动态顺序表为空，排序成功！" << endl;
		return true;
	}
	// test start
	cout << "[INFO] 当前顺序表的内容为：";
	for (int i = 0; i < m_size; i++)
	{
		cout << m_data[i] << " ";
	}
	cout << endl;
	// test end
	// 若right为-1，则表示对整个顺序表进行排序
	if(right == -1)
	{
		right = m_size;
	}
	// 子序列的长度为1时，递归结束
	if (left >= right)
	{
		// test start
		cout << "[INFO] 当前left=" << left << ", right=" << right << "，子序列长度为1，递归结束" << endl;
		// test end
		return true; // 递归结束条件
	}
	T pivot = m_data[left-1]; // 选择基准元素
	int low = left, high = right;
	while (low < high)
	{
		while (low < high && m_data[high-1] >= pivot)
		{
			high--; // 从右向左找第一个小于pivot的元素
		}
		while (low < high && m_data[low - 1] <= pivot)
		{
			low++; // 从左向右找第一个大于pivot的元素
		}
		if (low < high)
		{
			swap(low, high); // 交换两个元素
		}
	}
	swap(left, low); // 将pivot元素放到最终的位置
	sortByQuick(left, low - 1); // 递归处理左边的子序列
	sortByQuick(low + 1, right); // 递归处理右边的子序列
	return true;
}

