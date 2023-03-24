import random
age = random.randint(10,20)
x = False
while True:
    for i in range(3):
        a = input("请输入您要猜的年龄:")
        if age == a:
            x = True
            print("恭喜您猜对了，正确年龄是%d"%(age))
            break
        else:
            print("很遗憾没有猜对")
            continue
            pass
    if(x == True):
        break
        pass
    a = input("请问是否继续输入: y:继续 n:结束")
    if(a == 'n'):
        break
    pass
