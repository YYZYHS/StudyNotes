fp = open("text.txt",'w')
print('人生苦短，我用Python',file=fp)
fp.close()

#  实战二：输出个人自我介绍
#  需求：使用input(函数从键盘输入姓名、年龄，座右铭，并使用print（）函数输出到控制台
name = input("请输入你的名字：")
age = input("请输入你的年龄：")
motto = input("请输入你的座右铭：")
print("我叫" + name + "，今年" + age + "岁，我的座右铭是" + motto)