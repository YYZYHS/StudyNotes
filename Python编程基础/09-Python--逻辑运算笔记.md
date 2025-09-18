# Python 逻辑运算笔记

## 1. 基本逻辑运算符
Python 中的逻辑运算符用于组合多个条件判断，返回布尔值 (`True/False`)
- `and` (逻辑与)
- `or` (逻辑或)
- `not` (逻辑非)

## 2. 逻辑与 (and)
- 所有表达式为 `True` 时，结果才为 `True`
- 任意一个表达式为 `False`，结果即为 `False`

```python
print(True and True)   # True
print(True and False)  # False
print(False and True)  # False
print(False and False) # False
```

## 3. 逻辑或 (or)
- 任意一个表达式为 `True` 时，结果即为 `True`
- 所有表达式为 `False` 时，结果才为 `False`

```python
print(True or True)   # True
print(True or False)  # True
print(False or True)  # True
print(False or False) # False
```

## 4. 逻辑非 (not)
- 对布尔值取反
- `True` 变 `False`，`False` 变 `True`

```python
print(not True)   # False
print(not False)  # True
```

## 5. 运算符优先级
1. `not` 优先级最高
2. `and` 次之
3. `or` 最低
（可通过括号改变运算顺序）

```python
# 默认优先级：and > or
print(True or False and True)  # True (等价于 True or (False and True))
print((True or False) and True) # True (括号改变顺序)
```

## 6. 短路求值特性
- `and`: 遇到 `False` 时停止计算
- `or`: 遇到 `True` 时停止计算

```python
def func():
    print("函数被调用")
    return True

# 短路示例
print(False and func())  # False (func未调用)
print(True or func())    # True (func未调用)
```

## 7. 非布尔类型的逻辑运算
- `a and b`: 如果 `a` 为假返回 `a`，否则返回 `b`
- `a or b`: 如果 `a` 为真返回 `a`，否则返回 `b`

```python
print(0 and 5)  # 0 (0 视为 False)
print(2 and 3)  # 3 (2 视为 True)
print(0 or 5)   # 5 (0 视为 False)
print(2 or 3)   # 2 (2 视为 True)
```

## 8. 使用建议
1. 使用括号增强表达式可读性
2. 利用短路特性优化性能
3. 注意运算符优先级
4. 复杂逻辑拆分成多行提高可读性

