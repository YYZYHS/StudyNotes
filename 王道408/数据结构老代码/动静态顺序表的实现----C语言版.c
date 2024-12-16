//[1]定义顺序表最大长度和动态数组初始默认的最大容量
#define MaxSize 10      //静态顺序表的最大长度
#define InitSize 10     //动态顺序表的初始最大长度
//需要包含的头文件
#include <stdio.h>
#include <stdlib.h>
//C语言自定义bool变量
#define bool char
#define true 1
#define false 0
//自定义数据元素的数据类型
typedef int Elemtype;

//顺序表数据元素结构体(静态分配)
typedef struct SqList
{
    //[1]用静态的“数组”存放数据元素
    Elemtype data[MaxSize];
    //[2]顺序表的当前长度
    int length;
}SqList;//顺序表的类型定义（静态分配方式）

//顺序表数据元素结构体(动态分配)
typedef struct SeqList
{
    //[1]指示动态分配数组的指针
    Elemtype *data;
    //[2]顺序表的当前长度
    int length;
    //[3]顺序表的最大容量
    int maxsize;
}SeqList;//顺序表的类型定义（动态分配方式）

//基本操作----初始化一个静态顺序表
bool InitsqList(SqList *L)
{
    //[1]将所有数据元素设为默认初始值
    for(int i = 0; i < MaxSize; i++)
    {
        L->data[i] = 0;
    }
    /*
    1.本步骤其实可以省略
    2.之所以赋初值是因为内存中会有遗留的"脏数据"
    3.但是常规操作下,用户无法访问大于
      当前表长的数据元素,所以可以在需要时再赋值
    */

    //[2]顺序表初始长度设为0
    L->length = 0;

    return true;
}

//基本操作----初始化一个动态顺序表
bool InitseqList(SeqList *L)
{
    //[1]用malloc函数申请一片连续的存储空间
    L->data = (Elemtype *)malloc(sizeof(Elemtype) * InitSize);
    //[2]表长和默认最大长度初始化
    L->length = 0;
    L->maxsize = InitSize;

    return true;
}

//动态顺序表的加长
bool IncreaseSize(SeqList *L,int len)
{
    //[1]生成指向原来顺序表存储位置的指针
    int *p = L->data;
    //[2]为顺序表开辟一片比原来更大的空间
    L->data = (Elemtype *)malloc((L->maxsize + len) * sizeof(Elemtype));
    //[3]转移数据
    for (int i = 0; i < L->length; i++)
    {
        L->data[i] = p[i];
    }
    //[4]修改顺序表的最大长度,为其增加len
    L->maxsize = L->maxsize + len;
    //[5]释放原来的存储空间
    free(p);

    return true;
}

//基本操作----顺序表的插入
//[1]静态顺序表的插入
bool SqListInsert(SqList *L,int i,Elemtype e)
{
    //[1]判断i的合法性
    if(i < 1 || i > L->length + 1)
    {
        printf("The position of the element to be inserted is invalid!\n");
        return false;
    }
    if(L->length >= MaxSize)
    {
        printf("This sequence table is full!\n");
        return false;
    }

    //[2]将第i个元素及之后的元素都后移
    for(int j = L->length; j >= i; j--)
    {
        L->data[j] = L->data[j-1];      //第i个元素对应数组下标为i-1的数组元素 
    }
    //[3]在正确的位置插入新元素
    L->data[i-1] = e;
    //[4]顺序表长+1(注意:顺序表的最大长度不变)
    L->length++;
    //[5]插入成功,返回成功信号
    return true;
}
//[2]动态顺序表的插入
bool SeqListInsert(SeqList *L,int i,Elemtype e)
{
    //[1]判断i的合法性
    if(i < 1 || i > L->length + 1)
    {
        printf("The position of the element to be inserted is invalid!\n");
        return false;
    }
    if(L->length >= L->maxsize)
    {
        printf("This sequence table is full!\n");
        return false;
    }

    //[2]将第i个元素及之后的元素都后移
    for(int j = L->length; j >= i; j--)
    {
        L->data[j] = L->data[j+1];      //第i个元素对应数组下标为i-1的数组元素 
    }
    //[3]在正确的位置插入新元素
    L->data[i-1] = e;
    //[4]顺序表长+1(注意:顺序表的最大长度不变)
    L->length++;
    //[5]插入成功,返回成功信号
    return true;
}

//基本操作----顺序表的元素删除
//[1]静态顺序表的元素删除
bool SqListDelete(SqList *L, int i, Elemtype *e)
{
    //[1]判断i的合法性
    if(i < 1 || i > L->length + 1)
    {
        printf("The position of the element to be delected is invalid!\n");
        return false;
    }
    if(L->length <= 0)
    {
        printf("This sequence table is empty!\n");
        return false;
    }
    //[2]将被删除的元素值赋给e
    *e = L->data[i-1];
    //[3]将第i个元素及之后的元素都前移
    for(int j = i; j <= L->length; j++)
    {
        L->data[j-1] = L->data[j];      //第i个元素对应数组下标为i-1的数组元素 
    }
    //[4]顺序表长-1(注意:顺序表的最大长度不变)
    L->length--;
    //[5]插入成功,返回成功信号
    return true;
}
//[2]动态顺序表的元素删除
bool SeqListDelete(SeqList *L,int i,Elemtype *e)
{
        //[1]判断i的合法性
    if(i < 1 || i > L->length + 1)
    {
        printf("The position of the element to be delected is invalid!\n");
        return false;
    }
    if(L->length <= 0)
    {
        printf("This sequence table is empty!\n");
        return false;
    }
    //[2]将被删除的元素值赋给e
    *e = L->data[i-1];
    //[3]将第i个元素及之后的元素都前移
    for(int j = i; j <= L->length; j++)
    {
        L->data[j-1] = L->data[j];      //第i个元素对应数组下标为i-1的数组元素 
    }
    //[4]顺序表长-1(注意:顺序表的最大长度不变)
    L->length--;
    //[5]插入成功,返回成功信号
    return true;
}

//基本操作----按值查找
//[1]静态顺序表的按值查找
int SqListLocateElem(SqList L, Elemtype e)
{
    int i;
    for(i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i+1;
        }
    }
    return 0;
}
//[2]动态顺序表的按值查找
int SeqListLocateElem(SeqList L, Elemtype e)
{
    int i;
    for(i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i+1;
        }
    }
    return 0;
}

//额外操作----顺序表的打印
//[1]静态顺序表的输出
bool SqListPrint(SqList L)
{
    //[1]判空
    if(L.length == 0)
    {
        printf("This sequence table is empty!\n");
        return false;
    }
    //[2]输出
    printf("SqList:\n");
    for(int i = 0;i < L.length;i++)
    {
        printf("%d-->",L.data[i]);
    }
    printf("end\n");
}
//[2]动态顺序表的输出
bool SeqListPrint(SeqList L)
{
    //[1]判空
    if(L.length == 0)
    {
        printf("This sequence table is empty!\n");
        return false;
    }
    //[2]输出
    printf("SeqList:\n");
    for(int i = 0;i < L.length;i++)
    {
        printf("%d-->",L.data[i]);
    }
    printf("end\n");
}


int main()
{
    /*【1】生成顺序表*/
    //[1]静态分配的顺序表L1
    SqList L1;
    //[2]动态分配的顺序表L2
    SeqList L2;

    /*【2】顺序表的初始化*/
    //[1]静态顺序表L1的初始化
    InitsqList(&L1);
    //[2]动态顺序表L2的初始化
    InitseqList(&L2);

    /*【3】顺序表插入新元素*/
    int e;
    SqListInsert(&L1,1,1);
    SqListInsert(&L1,2,2);
    SqListInsert(&L1,3,3);
    SqListInsert(&L1,4,4);
    SqListInsert(&L1,5,5);
    SqListDelete(&L1,3,&e);
    SqListInsert(&L1,5,6);

    SeqListInsert(&L2,1,1);
    SeqListInsert(&L2,2,2);
    SeqListInsert(&L2,3,3);
    SeqListInsert(&L2,4,4);
    SeqListInsert(&L2,5,5);
    SeqListDelete(&L2,2,&e);
    SeqListInsert(&L2,5,6);
    IncreaseSize(&L2,5);

    SqListPrint(L1);
    SeqListPrint(L2);

    printf("%d\n",L2.maxsize);
    printf("SqListLocateElem(4) = %d\n",SqListLocateElem(L1,4));
    printf("SeqListLocateElem(6) = %d\n",SeqListLocateElem(L2,6));

    return 0;
}
