# Python 列表基础笔记

## 1. 列表的写法（声明、定义）
- 列表使用方括号 `[]` 定义
- 元素间用逗号分隔

```python
# 空列表
empty_list = []

# 包含元素的列表
numbers = [1, 2, 3, 4, 5]
fruits = ['apple', 'banana', 'cherry']
mixed = [1, 'apple', True, 3.14]

# 列表嵌套
nested_list = [[1, 2, 3], ['a', 'b', 'c']]
```

## 2. 列表的可变性
### 列表是可变对象
- 可以修改列表内容而不创建新对象
- 可以通过索引或方法修改列表

```python
fruits = ['apple', 'banana', 'cherry']
fruits[0] = 'orange'  # 修改第一个元素
print(fruits)         # 输出: ['orange', 'banana', 'cherry']
```

### 不可变类型的对比
- 字符串、整数、浮点数、布尔类型是**不可变对象**
- 修改时创建新对象，原始对象不变

```python
s = "hello"
s[0] = 'H'  # TypeError: 字符串不可修改

num = 5
num = num + 1  # 不是修改值，而是创建新对象
```

## 3. 列表的增删改查方法

### 增加元素
```python
# append(): 在末尾添加元素
fruits = ['apple', 'banana']
fruits.append('orange')

# insert(): 指定位置插入元素
fruits.insert(1, 'kiwi')  # ['apple', 'kiwi', 'banana', 'orange']

# extend(): 合并另一个列表
fruits.extend(['grape', 'melon']) 
```

### 删除元素
```python
# remove(): 按值删除第一个匹配项
fruits.remove('banana')

# pop(): 删除指定索引的元素并返回
last_fruit = fruits.pop()     # 删除并返回最后一个
second_fruit = fruits.pop(1)  # 删除索引1的元素

# del: 通过索引删除
del fruits[0]

# clear(): 清空列表
fruits.clear()
```

### 修改元素
```python
fruits = ['apple', 'banana', 'cherry']
fruits[1] = 'blueberry'  # 直接赋值
fruits[0:2] = ['kiwi', 'mango']  # 切片赋值
```

### 查找元素
```python
# 索引访问
first = fruits[0]       # 第一个元素
last = fruits[-1]       # 最后一个元素

# 切片操作
subset = fruits[1:3]    # 索引1到2的元素
every_other = fruits[::2]  # 每隔1个取元素

# 成员检测
if 'apple' in fruits:
    print("苹果在列表中")
  
if 'pear' not in fruits:
    print("梨不在列表中")
  
# 索引位置查找
index = fruits.index('banana')  # 返回位置索引
```

## 4. Python支持不同类型的数据
- Python列表可以包含不同类型的元素
- 这与其他静态类型语言不同

```python
# 包含多种数据类型的列表
mixed_list = [42, "hello", True, 3.14, [1, 2, 3]]

# 访问不同类型元素
number = mixed_list[0]        # 整数
text = mixed_list[1]          # 字符串
flag = mixed_list[2]          # 布尔
pi = mixed_list[3]            # 浮点数
nested = mixed_list[4]        # 子列表

print(f"数值: {number}, 文本: {text}, 布尔值: {flag}")
```

## 5. 常用函数

### 最大值和最小值
```python
numbers = [42, 18, 99, 37, 21]

max_value = max(numbers)
min_value = min(numbers)

print(f"最大值: {max_value}, 最小值: {min_value}")
```

### 排序函数
```python
# 使用sorted()函数 - 返回新列表
sorted_numbers = sorted(numbers)
print("排序后:", sorted_numbers)  # 默认升序
print("原始列表不变:", numbers)

# 使用sort()方法 - 原地排序
numbers.sort()
print("原地排序后:", numbers)  # 原列表改变

# 降序排序
numbers.sort(reverse=True)
print("降序排序后:", numbers)

# sorted()函数实现降序
reverse_sorted = sorted(numbers, reverse=True)
```

### 其他常用函数
```python
# 列表长度
length = len(numbers)

# 元素出现的次数
count_of_5 = [1, 5, 3, 5, 2].count(5)  # 2

# 列表反转
numbers.reverse()  # 或使用切片 reversed = numbers[::-1]

# 列表拷贝
shallow_copy = numbers.copy()  # 浅拷贝
```