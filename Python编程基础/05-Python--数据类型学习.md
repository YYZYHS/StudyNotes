# Python数据类型学习

## ▍ 基础数据类型

### 1. 整数型（int）
- Python基本数据类型
- 可表示整数、负整数、0
- 支持算术运算(`+`, `-`, `*`, `/`, `%`)、位运算(`&`, `|`, `^`, `~`, `<<`, `>>`)

```python
# 整数声明示例
intExp1 = 123
intExp2 = -456
intExp3 = 0

# 算术运算
intExp4 = 10 + 20        # 30
intExp5 = 30 - 10        # 20
intExp6 = 40 * 2         # 80
intExp7 = 50 / 2         # 25.0 (注意与C++区别)
intExp8 = 60 % 4         # 0

# 位运算
intExp9 = 10 & 3         # 2 (按位与)
intExp10 = 10 | 3        # 11 (按位或)
intExp11 = 10 ^ 3        # 9 (按位异或)
intExp12 = ~10           # -11 (取反)
intExp13 = 10 << 2       # 40 (左移)
intExp14 = 10 >> 2       # 2 (右移)
```

### 2. 浮点型（float）
- 用于表示小数
- 可表示小数、负数、0.0
- 支持四则运算
- `round()`函数进行四舍五入

```python
floatExp1 = 3.14
floatExp2 = -2.5
floatExp3 = 0.0

# 计算示例
floatExp4 = 1.5 + 2.5    # 4.0
floatExp5 = 3.5 - 1.5    # 2.0
floatExp6 = 4.5 * 2.5    # 11.25
floatExp7 = 5.5 / 2.5    # 2.2

# 四舍五入
floatExp8 = 3.1415926
floatExp9 = round(floatExp8, 2)  # 3.14(保留2位小数)
```

### 3. 字符串型（str）
- 用单/双引号包裹的文本
- 支持连接(`+`)、重复(`*`)
- 索引访问：`[索引]`（正数左起0，负数右起-1）
- 切片操作：`[start:end:step]`
- `len()`获取长度，`str()`转换其它类型

```python
strExp1 = 'Hello, world!'
strExp2 = "Python is awesome"

# 操作示例
strExp3 = strExp1 + ' ' + strExp2  # 字符串连接
strExp4 = 'Hello, ' * 3            # 'Hello, Hello, Hello, '

# 索引和切片
text = 'hello world'
print(text[0], text[-1])           # 'h' 'd'
print(text[0:5])                   # 'hello' 
print(text[::-1])                  # 'dlrow olleh'(反转)
print(len(text))                   # 11
```

### 4. 布尔型（bool）
- 仅有两个值：`True`/`False`（首字母大写）
- 支持逻辑运算：`and`, `or`, `not`
- 注意：不能直接使用1/0或true/false

```python
boolExp1 = True
boolExp2 = False

# 逻辑运算
boolExp3 = True and False  # False
boolExp4 = True or False   # True
boolExp5 = not True        # False
```

### 5. 空值类型（NoneType）
- 特殊值`None`表示空
- 非0/空字符串/False的独立类型

```python
noneExp1 = None
```

---

## ▍ 类型检测方法
使用`type()`函数获取变量类型

```python
print(type(123))          # <class 'int'>
print(type(3.14))         # <class 'float'>
print(type("text"))       # <class 'str'>
print(type(True))         # <class 'bool'>
print(type(None))         # <class 'NoneType'>
```

---

## ▍ 高级数据类型(后述)
1. 列表（list）
2. 元组（tuple）
3. 集合（set）
4. 字典（dict）
```

> **注意事项**：
> 1. Python整数除法(`/`)返回float类型（与C++不同）
> 2. 布尔值必须写作`True/False`（非true/false）
> 3. 字符串切片规则：`[start:end]`包含start，不包含end
> 4. `None`是独立类型，表示完全的"空"状态