# 逻辑运算.py

# 1. 基本逻辑运算符
"""
Python中的逻辑运算符用于组合多个条件判断，返回布尔值(True/False)
主要有三种：
- and (逻辑与)
- or (逻辑或)
- not (逻辑非)
"""

# 2. 逻辑与(and)
"""
只有当所有表达式都为True时，结果才为True
只要有一个为False，结果就为False
"""


def example_and():
    print(True and True)  # True
    print(True and False)  # False
    print(False and True)  # False
    print(False and False)  # False


# 3. 逻辑或(or)
"""
只要有一个表达式为True，结果就为True
只有全部为False时，结果才为False
"""


def example_or():
    print(True or True)  # True
    print(True or False)  # True
    print(False or True)  # True
    print(False or False)  # False


# 4. 逻辑非(not)
"""
对布尔值取反
True变False，False变True
"""


def example_not():
    print(not True)  # False
    print(not False)  # True


# 5. 运算符优先级
"""
1. not 优先级最高
2. and 次之
3. or 最低
可以通过括号改变运算顺序
"""


def example_priority():
    print(True or False and True)  # True (先算and再算or)
    print((True or False) and True)  # True (括号优先)


# 6. 短路求值特性
"""
Python中的逻辑运算具有短路求值特性：
- and: 遇到False时停止计算
- or: 遇到True时停止计算
"""


def example_short_circuit():
    def func():
        print("函数被调用")
        return True

    print(False and func())  # False (func不会被调用)
    print(True or func())  # True (func不会被调用)


# 7. 非布尔类型的逻辑运算
"""
对于非布尔类型的值，and和or会返回其中一个操作数的值，具体规则如下：
- a and b: 如果a为假，返回a，否则返回b
- a or b: 如果a为真，返回a，否则返回b
"""


def example_non_bool():
    print(0 and 5)  # 0 (0被认为是False)
    print(2 and 3)  # 3 (2被认为是True)
    print(0 or 5)  # 5 (0被认为是False)
    print(2 or 3)  # 2 (2被认为是True)


# 8. 使用建议
"""
1. 合理使用括号使表达式更清晰
2. 利用短路特性减少不必要的计算
3. 注意优先级顺序
4. 对于多条件判断，可拆分成多行增加可读性
"""