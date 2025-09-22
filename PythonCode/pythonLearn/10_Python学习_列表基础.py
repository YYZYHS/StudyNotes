# fruits = ['apple', 'banana', 'cherry']
# fruits[0] = 'orange'  # 修改第一个元素
# print(fruits)         # 输出: ['orange', 'banana', 'cherry']

# append(): 在末尾添加元素
fruits = ['apple', 'banana']
fruits.append('orange')
print(fruits)

# insert(): 指定位置插入元素
fruits.insert(1, 'kiwi')  # ['apple', 'kiwi', 'banana', 'orange']
print(fruits)

# extend(): 合并另一个列表
fruits.extend(['grape', 'melon'])
print(fruits)


# remove(): 按值删除第一个匹配项
fruits.remove('banana')
print(fruits)

# pop(): 删除指定索引的元素并返回
last_fruit = fruits.pop()     # 删除并返回最后一个
second_fruit = fruits.pop(1)  # 删除索引1的元素
print(last_fruit, second_fruit)
print(fruits)

# del: 通过索引删除
del fruits[0]
print(fruits)

# clear(): 清空列表
fruits.clear()
print(fruits)