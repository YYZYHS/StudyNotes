# Python学习笔记 - 条件判断

# --- 条件判断结构 ---
"""
Python中使用if、elif、else关键字来实现条件判断
基本语法结构：
if 条件1:
    执行语句块1
elif 条件2:
    执行语句块2
else:
    执行语句块3
"""
# --- 注意点 ---
"""
1. 冒号(:)是必须的，表示代码块的开始
2. 缩进必须一致，推荐使用4个空格
3. 条件表达式不需要用括号包裹
4. 避免将赋值运算符(=)与比较运算符(==)混淆
"""

# 示例1: 基础if判断
age = 18
if age >= 18:
    print("你已成年")
else:
    print("你还未成年")

# 示例2: 多条件判断
score = 85
if score >= 90:
    print("优秀")
elif 80 <= score < 90:
    print("良好")
elif 60 <= score < 80:
    print("及格")
else:
    print("不及格")

# 示例3: 嵌套if判断（嵌套条件语句）
"""
嵌套if是指在if、elif或else代码块中再包含if语句
可以实现更复杂的条件判断逻辑
"""

# 示例3-1: 简单嵌套判断
num = 15
if num > 0:
    print("数字是正数")
    if num % 2 == 0:
        print("而且是偶数")
    else:
        print("而且是奇数")
else:
    print("数字是非正数")

# 示例3-2: 多重嵌套判断（用户登录验证）
username = "admin"
password = "123456"
captcha = "ABCD"

if username == "admin":
    if password == "123456":
        if captcha == "ABCD":
            print("登录成功")
        else:
            print("验证码错误")
    else:
        print("密码错误")
else:
    print("用户名不存在")

"""
注意事项：
1. 嵌套层级不宜过多，一般不超过3层
2. 多层嵌套时可考虑重构为函数或使用逻辑运算符简化
3. 嵌套时需要保持一致的缩进格式
"""

# --- elif 同级条件判断 ---
"""
相比较于if-else结构，elif可以实现同级条件判断
if 条件一:
    执行语句块1
elif 条件二:
    执行语句块2
elif 条件三:
    执行语句块3
else:
    执行语句块4
    
Python会从上到下依次判断条件，如果满足某个条件，则执行对应的语句块。
如果所有条件都不满足，则执行else语句块。
elif的数量没有限制，可以根据实际情况增加或减少。
由于Python是从上到下判断，所以多个条件可以同时满足，但只会执行第一个满足的条件。
"""
# 示例4: 同级条件判断
score = 85
if score >= 90:
    print("优秀")
elif score >= 80:
    print("良好")
elif score >= 60:
    print("及格")
else:
    print("不及格")


# --- 比较运算符 ---
"""
常用比较运算符：
== 等于 
!= 不等于
>  大于
<  小于
>= 大于等于
<= 小于等于
"""

# 示例3: 比较运算符使用
a, b = 10, 20
print(a == b)  # False
print(a != b)  # True
print(a > b)   # False
print(a < b)   # True

# 示例4: 常见错误避免
x = 5
if x == 5:  # 正确写法
    print("x等于5")

# if x = 5:  # 错误写法，会报语法错误
#    print("x等于5")