# Python输入函数笔记
# 模块: 输入输出函数
# 主题: input()函数详解

##############################################################################
# 1. 函数基本语法
"""
input([prompt]) -> str
功能: 从标准输入读取一行文本
参数: 
    prompt (可选): 字符串，作为输入前的提示信息
返回值:
    用户输入的内容(字符串类型)，不包含末尾的换行符
"""

##############################################################################
# 2. 基础使用示例

# 示例1: 基本输入
name = input("请输入姓名: ")
print("输入的用户名:", name)

# 示例2: 数值输入处理
age = input("请输入年龄: ")  # 返回字符串
print("原始输入类型:", type(age))  # <class 'str'>
age_int = int(age)  # 需要显式转换
print("转换后类型:", type(age_int))  # <class 'int'>

##############################################################################
# 3. 类型转换技巧

# 数值转换
weight = float(input("输入体重(kg): ").strip())

# 布尔转换
is_active = input("是否激活(y/n): ").lower() == 'y'

# 列表转换
numbers = list(map(int, input("输入数字序列(空格分隔): ").split()))

##############################################################################
# 4. 高级输入处理

# 4.1 多变量同时输入
x, y = map(float, input("输入坐标(x y): ").split())


# 4.2 输入验证
def get_valid_input(prompt, type_func):
    while True:
        try:
            return type_func(input(prompt))
        except ValueError as e:
            print(f"输入无效，请重新输入({e})")


# 使用示例
valid_age = get_valid_input("请输入您的年龄: ", int)

##############################################################################
# 5. 安全注意事项

"""
1. 密码输入应使用getpass模块而非input()，避免回显
2. 处理外部输入时应始终考虑异常情况
3. 数值转换前应验证数据有效性
4. 大量输入数据时考虑使用文件读取而非交互式输入
"""

##############################################################################
# 6. 常用配套函数

# 6.1 字符串处理
user_input = input().strip()  # 去除首尾空白
user_input2 = input().upper()  # 转为大写

# 6.2 分隔处理
data_list = input("输入多个值(逗号分隔): ").split(',')
data_list = [item.strip() for item in data_list]  # 列表推导式清理数据

##############################################################################
# 7. 实际案例

# 案例: 用户注册系统
import getpass

print("=== 用户注册系统 ===")
username = input("设置用户名: ").strip()
while not username:
    print("用户名不能为空!")
    username = input("设置用户名: ").strip()

print("即将输入密码(输入时不会显示文字)...")
password = getpass.getpass("设置密码: ")
age = get_valid_input("请输入年龄: ", int)

print(f"\n注册成功!\n用户名: {username}\n年龄: {age}")

"""
注意：由于pyCharm对getpass模块的支持不好，所以该案例推荐使用Windows的命令行运行。
"""


##############################################################################
# 8. 知识扩展

"""
1. 文件输入替代方案: 
    with open('data.txt') as f:
        for line in f:
            process(line)

2. 格式化输入建议:
   使用format或f-string格式化提示信息
   name = input(f"这是第{i}次输入，请输入名称: ")

3. 多语言输入处理:
   注意编码问题，建议统一使用UTF-8
"""
