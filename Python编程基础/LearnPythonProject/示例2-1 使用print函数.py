a = 100  # 变量a赋值为100
b = 200  # 变量b赋值为200
print(99)  # 输出99
print(a)  # 输出变量a的值
print(a + b)  # 输出变量a和b的运算结果

# 输出字符串示例,用不同的符号输出字符串
print("Hello World!")  # 输出字符串,用双引号
print('Hello World!')  # 输出字符串,用单引号
print('''Hello World!''')  # 输出字符串,用三个单引号
print("""Hello World!""")  # 输出字符串,用三个双引号

# 不换行一次输出多个数据
# 一次输出多个数据,用逗号隔开,输出结果每个数据之间用空格隔开
print(a, b, 99, "Hello World!")

i = 100  # 变量i赋值为100
# chr()函数原型
chr(i)  # 返回一个整数i对应的Unicode字符

c = chr(65)  # 变量c赋值为字符A
# ord()函数原型
ord(c)  # 返回一个字符c对应的Unicode编码

# 通过ASCII码输出字符,用chr()函数
print(chr(65))  # 输出字符A
print(chr(97))  # 输出字符a
print(chr(91))  # 输出字符[
#  中文编码范围是0x4E00-0x9FA5
print(chr(0x4E00))  # 输出中文字符一
print(chr(0x9FA5))  # 输出中文字符龥
#  通过字符输出ASCII码,用ord()函数
print(ord('A'))  # 输出字符A的ASCII码
print(ord('杨'))  # 输出字符杨的ASCII码

#  将数据输出到文件,用file参数,用内置函数open()打开文件
fp = open("test.txt", "w")  # 打开文件
print("Hello World!", file=fp)  # 输出到文件
fp.close()  # 关闭文件

#  使用print()函数输出复杂的数据,用sep参数和end参数
#  函数原型:print(*objects, sep=' ', end='\n', file=sys.stdout, flush=False)
print("Hello", "World!", "hhh", sep="***", end="\n")  # 输出Hello***World!***hhh

#  多行print函数,输出到同一行
print("Hello", end="-->")  # 输出Hello-->
print("World!")  # 输出World!
