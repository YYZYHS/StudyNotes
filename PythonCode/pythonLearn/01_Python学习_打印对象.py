# python语法学习
# 打印字符串
print("Dad!")

# 打印进阶
# 一、多字符串拼接
print("Hello" + " World" + "!") # 输出结果：Hello World!
print("Hello" + "World") # 输出结果：HelloWorld
print("Hello" + " " + "World" + "!") # 输出结果：Hello World!

print("Hello world!" * 3)    # 输出结果：Hello world!Hello world!Hello world!

# 二、单双引号转义
# 正常情况下，单引号和双引号都可以用来表示字符串，
# 但是如果字符串中本身包含单双引号，则需要使用转义字符\来表示。
print("He said \"Let\'s go to the cinema!\"") # 输出结果：He said "Let's go to the cinema!"

# 三、换行
# 在字符串中加入\n可以实现换行，但是\n并不是一个真正的换行符，而是表示一个换行符的转义字符。
print("Hello\nWorld!") # 输出结果：Hello (换行) World!

# 四、三引号跨行字符串
# 三引号可以用来表示跨行字符串，即可以将多行内容作为一个整体来表示。
# 三引号可以是单引号或双引号，但是不能同时使用。
print('''This is a long string that
spans across multiple lines.''')
# 输出结果：This is a long string that spans across multiple lines.