//【1】预编译部分
#include <stdio.h>
#include <stdlib.h>
//【2】宏定义部分
#define bool char
#define true 1
#define false 0
//【3】自定义变量部分
#define MaxSize 50      //定义栈中元素的最大个数
//【4】顺序栈的数据结构
typedef int Elemtype;   //自定义顺序栈的数据元素类型
typedef struct SqStack
{
    Elemtype data[MaxSize];
    int top;            //栈顶指针
}SqStack;
//【5】顺序栈的初始化
bool Initstack(SqStack *S)
{
    S->top = -1;        //初始化栈顶指针（判空条件S->top = -1;）
}
//【6】判栈空
bool StackEmpty(SqStack S)
{
    if(S.top == -1)     return true;        //栈空
    else                return false;       //栈不空
}
//【7】进栈（压栈）
bool Push(SqStack *S,Elemtype e)
{
    if(S->top == MaxSize - 1)     return false;     //栈满，报错
    S->data[++S->top] = e;                  //指针先加1，再入栈
    return  true;
}
//【8】出栈
bool Pop(SqStack *s,Elemtype *e)
{
    if(StackEmpty(*s))      return false;   //栈空报错
    *e = s->data[s->top--];                 //先出栈，指针再减一
    return true;
}
//【9】读栈顶元素
bool GetTop(SqStack S,Elemtype *e)
{
    if(StackEmpty(S))      return false;   //栈空报错
    *e = S.data[S.top];
    return true;
}
//【10】main函数验证
int main()
{
    SqStack S;
    Initstack(&S);
    Push(&S,1);
    Push(&S,2);
    Push(&S,3);
    Push(&S,4);
    Push(&S,5);
    Push(&S,6);

    Elemtype X; //用与保存出栈和读栈顶元素返回的变量的值
    int count = S.top;
    for(int i = 0;i <= count;i++)
    {
        printf("i = %d\n",i);
        GetTop(S,&X);
        printf("GetTop X = %d\n",X);
        Pop(&S,&X);
        printf("GetTop X = %d\n",X);
    }

    return 0;
}
