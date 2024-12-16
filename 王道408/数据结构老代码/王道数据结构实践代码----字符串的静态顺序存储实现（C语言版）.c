/*
 *                        _oo0oo_
 *                       o8888888o
 *                       88" . "88
 *                       (| -_- |)
 *                       0\  =  /0
 *                     ___/`---'\___
 *                   .' \\|     |// '.
 *                  / \\|||  :  |||// \
 *                 / _||||| -:- |||||- \
 *                |   | \\\  - /// |   |
 *                | \_|  ''\---/''  |_/ |
 *                \  .-\__  '-'  ___/-. /
 *              ___'. .'  /--.--\  `. .'___
 *           ."" '<  `.___\_<|>_/___.' >' "".
 *          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *          \  \ `_.   \_ __\ /__ _/   .-` /  /
 *      =====`-.____`.___ \_____/___.-`___.-'=====
 *                        `=---='
 * 
 * 
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *            佛祖保佑       永不宕机     永无BUG
 * 
 * @Author       : YYZYHS
 * @Date         : 2021-11-20 18:03:33
 * @LastEditTime : 2021-11-20 20:54:41
 * @LastEditors  : YYZYHS
 * @Description  : 
 * @FilePath     : \C\SString.c
 * 自学之用,欢迎讨论.
 */

#include <stdio.h>
#include <stdlib.h>

#define bool char
#define true 1
#define false 0

#define MAXLEN 255  //预定义最大串长为255
//【0】定义数据结构和其初始化函数
//[1]顺序存储字符串的数据结构
typedef struct SString
{
    char ch[MAXLEN + 1];    /*char类型的数组，数组的每个分类存储一个字符*/
    char length;            /*串的实际长度*/
}SString;
//[2]顺序存储字符串的初始化
/**
 * @brief         顺序存储字符串的初始化
 * @param         str 类型:SString*,要进行初始化的字符串
 * @return        成功返回ture，否则返回false
 */
bool StrInit(SString* Str)
{
    Str->length = 0;
    return true;
}

//【1】顺序存储字符串的求串长、清空、判空操作
/**
 * @brief         顺序存储字符串的求串长
 * @param         Str 类型:SString,目标字符串
 * @return        返回一个int类型的值（即目标字符串的长度）
 */
int StrLength(SString Str)
{
    return Str.length;
}
/**
 * @brief         顺序存储字符串的清空操作
 * @param         Str 类型:SString*,目标字符串的指针
 * @return        成功返回ture，否则返回false
 */
bool StrClear(SString* Str)
{
    Str->length = 0;
    return true;
}
/**
 * @brief         顺序存储字符串的判空操作
 * @param         Str 类型:SString,目标字符串
 * @return        串空返回ture，否则返回false
 */
bool StrEmpty(SString Str)
{
    return !Str.length;
}
//【2】顺序存储字符串的赋值操作和输出操作
//[1]顺序存储字符串的赋值操作
/**
 * @brief         顺序存储字符串的赋值操作,把串src赋值为Dest
 * @param         Dest 类型:SString*,指向用于存储赋值内容的目标字符串的首地址
 * @param         *Src 类型:char,字符串Dest的数组要被赋值的内容
 * @return        赋值成功，返回true，同时Dest被赋给正确的值；否则返回false并报错
 */
bool StrAssign(SString* Dest,char *Src)
{
    if(!Src)
    {
        printf("StrAssign:Src is NULL!\n");
        return false;
    }
    int i = 1;
    for(i = 1;Src[i - 1] != '\0';i++)
    {
        if(i <= MAXLEN)
        {
            Dest->ch[i] = Src[i - 1];
        }
        else
        {
            break;
        }
    }
    Dest->length = i - 1;
    return true;
}
//[2]顺序存储字符串的输出操作
/**
 * @brief         顺序存储字符串的输出操作
 * @param         Str 类型:SString,目标字符串
 * @return        输出字符串的值和串长
 */
bool StrPrint(SString Str)
{
    if(StrEmpty(Str))
    {
        printf("StrPrint:The SString is an empty sstring or an error sstring\n");
        return false;
    }
    for(int i = 1;i <= Str.length;i++)
    {
        printf("%c",Str.ch[i]);
    }
    printf("\nLength = %d\n\n",StrLength(Str));
    return true;
}

//【3】顺序存储字符串的复制操作
/**
 * @brief         顺序存储字符串的复制操作,由串Src复制得到串Dest
 * @param         Dest 类型:SString*,用于存储要复制的字符串
 * @param         Src 类型:SString*,用于存储被复制的字符串
 * @return        复制成功，函数返回true，同时Dest的值变成Src的值，否则函数返回fales
 */
bool StrCopy(SString* Dest,SString* Src)
{
    if(StrEmpty(*Src))
    {
        printf("StrCopy:The copied sstring is an empty sstring!\n");
        return false;
    }
    for(int i = 1; i <= Src->length;i++)
    {
        Dest->ch[i] = Src->ch[i];
    }
    Dest->length = Src->length;
    return true;
}

//【4】顺序存储字符串的串联接
/**
 * @brief         顺序存储字符串的串联接。用Dest返回由Str1和Str2联接而成的
 * @param         Dest 类型:SString*,指向新串的首地址
 * @param         Str1 类型:SString,要联接的第一个字符串
 * @param         Str2 类型:SString,要联接的第二个字符串
 * @return        复制成功，函数返回true，同时Dest的待会新串的地址指针，否则函数返回fales
 */
bool StrConcat(SString* Dest,SString Str1,SString Str2)
{
    if(StrEmpty(Str1) || StrEmpty(Str2))
    {
        printf("StrConcat:At least one of the two sstrings is an empty sstring!\n");
        return false;
    }
    StrCopy(Dest,&Str1);
    for(int i = Dest->length + 1; 
        i <=(StrLength(Str1) + StrLength(Str2)) && i <= MAXLEN;
        i++)
    {
        Dest->ch[i] = Str2.ch[i - StrLength(*Dest)];
    }
    Dest->length = StrLength(Str1) + StrLength(Str2);
    return true;
}

//【5】顺序存储字符串的求字串操作
/**
 * @brief         顺序存储字符串的求子串，用Dest返回串Src的第pos个字符起长度为len的子串。
 * @param         Dest 类型:SString*,指向用于保存子串的存储空间
 * @param         Src 类型:SString,主串
 * @param         pos 类型:int,子串在主串中的位置
 * @param         len 类型:int,子串的长度
 * @return        若成功获得子串，函数返回true，同时Dest带回子串的指针，否则，函数返回false
 */
bool SubString(SString* Dest,SString Src,int pos,int len)
{
    if((pos + len -1) > StrLength(Src))
    {
        printf("SubString:The substring does not exist!\n");
        return false;
    }
    for(int i = pos;i <= pos + len -1;i++)
    {
        Dest->ch[i - pos + 1] = Src.ch[i];
    }
    Dest->length = len;
    return true;
}

//【7】顺序存储字符串的对比操作
/**
 * @brief         顺序存储字符串的对比操作
 * @param         Str1 类型:SString,
 * @param         Str2 类型:SString,
 * @return        返回一个int型的值，若Str1 > Str2，返回值>0;若Str1 == Str2，返回值=0；若Str1 < Str2，返回值<0；
 */
int StrCompare(SString Str1,SString Str2)
{
    for(int i = 1;i <= StrLength(Str1) && i <= StrLength(Str2);i++)
    {
        if(Str1.ch[i] != Str2.ch[i])
        return Str1.ch[i] - Str2.ch[i];
    }
    return StrLength(Str1) - StrLength(Str2);
}

//【8】顺序存储字符串的定位操作
/**
 * @brief         顺序存储字符串的定位操作
 * @param         MainStr 类型:SString,主串
 * @param         SubStr 类型:SString,子串
 * @return        若主串MainStr中存在与串SubStr值相同的子串，则返回它在主串MainStr中第一次出现的位置：否则函数值为-1.
 */
int StrIndex(SString MainStr,SString SubStr)
{
    if(StrEmpty(SubStr))
    {
        printf("StrIndex:The substring does not exist!\n");
    }
    int i = 1;
    SString sub;//临时存储子串的变量
    while (i <= StrLength(MainStr) - StrLength(SubStr) + 1)
    {
        SubString(&sub,MainStr,i,StrLength(SubStr));
        if(StrCompare(sub,SubStr) != 0) i++;
        else return i;
    }
    return -1;    
}

int main()
{
    SString str1,str2,str3;
    StrInit(&str1);
    StrInit(&str2);
    StrInit(&str3);
    StrAssign(&str1,"Str1:ABC");
    StrAssign(&str2,"Str2:HUAWEI MatePad pro?!!");
    StrAssign(&str3,"Str3:IPhone 13 Pro Plus 666!");
    // StrClear(&str1);
    StrPrint(str1);
    StrPrint(str2);
    StrPrint(str3);
    // StrCopy(&str1,&str3);
    // StrPrint(str1);
    SString str4,str5;
    StrInit(&str4);
    StrInit(&str5);
    StrConcat(&str4,str2,str3);
    StrPrint(str4);
    SubString(&str5,str1,3,4);
    StrPrint(str5);
    printf("StrCompare(str4,str4) = %d",StrCompare(str4,str4));
    printf("StrIndex(str1,str5) = %d",StrIndex(str1,str5));
    return 0;
}
