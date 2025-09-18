# Python学习笔记：条件判断整理

## 条件判断结构
Python中使用`if`、`elif`、`else`关键字实现条件判断：
```python
if 条件1:
    执行语句块1
elif 条件2:
    执行语句块2
else:
    执行语句块3
```

## 核心注意事项
1. 冒号(`:`)必须放在每个条件判断语句结尾
2. 语句块缩进必须一致（推荐4个空格）
3. 条件表达式不需要用括号包裹
4. 避免将赋值运算符(`=`)与比较运算符(`==`)混淆

---

## 基础判断示例
### 1. 基础if判断
```python
age = 18
if age >= 18:
    print("你已成年")
else:
    print("你还未成年")
```

### 2. 多条件elif判断
```python
score = 85
if score >= 90:
    print("优秀")
elif 80 <= score < 90:
    print("良好")
elif 60 <= score < 80:
    print("及格")
else:
    print("不及格")
```

---

## 嵌套条件判断
嵌套if可以处理更复杂的逻辑：
```python
num = 15
if num > 0:
    print("数字是正数")
    if num % 2 == 0:
        print("而且是偶数")
    else:
        print("而且是奇数")
else:
    print("数字是非正数")
```

### 多层嵌套示例（用户登录验证）
```python
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
```

### 嵌套注意事项
1. 嵌套层级不宜过多（建议不超过3层）
2. 多重嵌套可考虑重构为函数或用逻辑运算符简化
3. 保持一致的标准缩进格式

---

## elif优先级特性
1. `elif`实现同级条件判断
2. Python从上到下依次判断条件
3. 满足第一个条件后跳过后续判断
4. `elif`数量无限制
5. 同级条件同时满足时只执行第一个匹配块

### 示例：同级条件判断
```python
score = 85
if score >= 90:
    print("优秀")
elif score >= 80:  # 满足此条件
    print("良好")   # 执行此语句后跳过后续判断
elif score >= 60:
    print("及格")
else:
    print("不及格")
```

---

## 比较运算符
| 运算符 | 描述     | 示例     |
| ------ | -------- | -------- |
| `==`   | 等于     | `a == b` |
| `!=`   | 不等于   | `a != b` |
| `>`    | 大于     | `a > b`  |
| `<`    | 小于     | `a < b`  |
| `>=`   | 大于等于 | `a >= b` |
| `<=`   | 小于等于 | `a <= b` |

### 运算符使用示例
```python
a, b = 10, 20
print(a == b)  # False
print(a != b)  # True
print(a > b)   # False
print(a < b)   # True
```

---

## 常见错误避免
```python
# 错误写法（使用赋值运算符=）
# if x = 5: 
#    print("x等于5")

# 正确写法（使用比较运算符==）
x = 5
if x == 5:
    print("x等于5")
```

> **重点提示**：Python条件判断中，`=`是赋值操作符，`==`才是值比较操作符，两者不可混淆使用。