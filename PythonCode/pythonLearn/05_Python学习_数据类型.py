# Python数据类型学习

# 基础数据类型有以下几种：
# 1. 整数型（int）
# 整数型是Python中最基本的数据类型。
# 整数型特点：可以表示整数、负整数、0。
intExp1 = 123
intExp2 = -456
intExp3 = 0
print("intExp1 = " + str(intExp1))
print("intExp2 = " + str(intExp2))
print("intExp3 = " + str(intExp3))
# 整数型也可以用加号（+）、减号（-）、乘号（*）、除号（/）、取模（%）来进行运算。
intExp4 = 10 + 20
intExp5 = 30 - 10
intExp6 = 40 * 2
intExp7 = 50 / 2 # 结果为25.0，即python和C++的浮点数计算方式不同，C++的结果为25
intExp8 = 60 % 4
print("intExp4 = " + str(intExp4))
print("intExp5 = " + str(intExp5))
print("intExp6 = " + str(intExp6))
print("intExp7 = " + str(intExp7))
print("intExp8 = " + str(intExp8))
# 整数型也可以用位运算符（&、|、^、~、<<、>>）来进行位运算。
#     &：按位与运算
#     |：按位或运算
#     ^：按位异或运算
#     ~：按位取反运算
#     <<：左移运算
#     >>：右移运算
intExp9 = 10 & 3
intExp10 = 10 | 3
intExp11 = 10 ^ 3
intExp12 = ~10
intExp13 = 10 << 2
intExp14 = 10 >> 2
print("intExp9 = " + str(intExp9))
print("intExp10 = " + str(intExp10))
print("intExp11 = " + str(intExp11))
print("intExp12 = " + str(intExp12))
print("intExp13 = " + str(intExp13))
print("intExp14 = " + str(intExp14))
# 2. 浮点型（float）
# 浮点型是Python中用来表示小数的一种数据类型。
# 浮点型特点：可以表示小数、负数、0。
floatExp1 = 3.14
floatExp2 = -2.5
floatExp3 = 0.0
print("floatExp1 = " + str(floatExp1))
print("floatExp2 = " + str(floatExp2))
print("floatExp3 = " + str(floatExp3))
# 浮点型也可以用加号（+）、减号（-）、乘号（*）、除号（/）来进行运算。
floatExp4 = 1.5 + 2.5
floatExp5 = 3.5 - 1.5
floatExp6 = 4.5 * 2.5
floatExp7 = 5.5 / 2.5
print("floatExp4 = " + str(floatExp4))
print("floatExp5 = " + str(floatExp5))
print("floatExp6 = " + str(floatExp6))
print("floatExp7 = " + str(floatExp7))
# 浮点型也可以用内置函数round()来四舍五入。
floatExp8 = 3.1415926
floatExp9 = round(floatExp8, 2)
print("floatExp8 = " + str(floatExp8))
print("floatExp9 = " + str(floatExp9))

# 3. 字符串型（str）
# 字符串型是Python中最常用的一种数据类型。
# 字符串型特点：可以用单引号或双引号括起来的任意文本。
strExp1 = 'Hello, world!'
strExp2 = "Python is awesome"
print("strExp1 = " + strExp1)
print("strExp2 = " + strExp2)
# 字符串型可以用加号（+）来连接两个字符串型。
strExp3 = strExp1 +' ' + strExp2
print("strExp3 = " + strExp3)
# 字符串型也可以用乘号（*）来重复一个字符串型。
strExp4 = 'Hello, '
strExp5 = strExp4 * 3
print("strExp5 = " + strExp5)
# 字符串型也可以用切片（[start:end:step]）来提取子字符串。
#     start：起始索引（包含在内）
#     end：结束索引（不包含在内）
#     step：步长（默认为1）
#     例如：'hello'[0:3:1] = 'hel'，'hello'[1:4:2] = 'el'
strExp6 = 'hello world'
print("strExp6[0:5:1] = " + strExp6[0:5:1])
print("strExp6[6:11:1] = " + strExp6[6:11:1])
print("strExp6[::-1] = " + strExp6[::-1])
print("strExp6 + '!' = " + strExp6 + '!')
# 字符串型也可以用索引（[index]）来获取字符串中的单个字符。
#     索引为正数时，从左往右数，从0开始。
#     索引为负数时，从右往左数，从-1开始。
#     例如：'hello'[0] = 'h'，'hello'[-1] = 'o'
strExp7 = 'hello world'
print("strExp7[0] = " + strExp7[0])
print("strExp7[-1] = " + strExp7[-1])
print("strExp7[5] = " + strExp7[5])
print("strExp7[-6] = " + strExp7[-6])
# 字符串型也可以用内置函数len()来获取字符串的长度。
strExp8 = 'hello world'
print("len(strExp8) = " + str(len(strExp8)))
# 字符串型也可以用内置函数str()来将其他数据类型转换为字符串型。
# 将整数型转换为字符串型
intTemp = 123
strExp9 = str(intTemp)
print("strExp9 = " + strExp9)

# 4. 布尔型（bool）
# 布尔型是Python中用来表示真值和假值的一种数据类型。
# 布尔型只有True和False两个值。T和F要大写。
boolExp1 = True
boolExp2 = False
# boolExp3 = 1 # 错误，不能将整数型转换为布尔型
# boolExp4 = true # 错误，true不是关键字，应为True
# boolExp5 = False # 错误，False应为小写
print("boolExp1 = " + str(boolExp1))
print("boolExp2 = " + str(boolExp2))
# 布尔型也可以用逻辑运算符（and、or、not）来进行逻辑运算。
# 注意：与C++的逻辑运算符不同，Python的逻辑运算符是以关键字的形式出现的。
boolExp3 = True and False
boolExp4 = True or False
boolExp5 = not True
print("boolExp3 = " + str(boolExp3))
print("boolExp4 = " + str(boolExp4))
print("boolExp5 = " + str(boolExp5))

# 5. 空值类型（NoneType）
# 空值类型是Python中用来表示空值的一种数据类型。
# 空值类型只有一个值None。
# None不是0，也不是空字符串，也不是False，而是一个特殊的空值。
noneExp1 = None
print("noneExp1 = " + str(noneExp1))

# type()函数可以用来获取变量的类型。
print("type(intExp1) = " + str(type(intExp1)))
print("type(floatExp1) = " + str(type(floatExp1)))
print("type(strExp1) = " + str(type(strExp1)))
print("type(boolExp1) = " + str(type(boolExp1)))
print("type(noneExp1) = " + str(type(noneExp1)))

# 高级数据类型有以下几种：(在后面的章节中会详细介绍)
# 1. 列表（list）
# 2. 元组（tuple）
# 3. 集合（set）
# 4. 字典（dict）
