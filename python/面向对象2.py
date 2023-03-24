# class Animal:
#     def __init__(self,name):
#         self.name = name
#         print("这是构造初始化")
#         pass
#     def __del__(self):
#         print('这是析构方法')
#         pass
# cat = Animal('xia')
# # input("程序不能结束")#加上不会使用析构函数，等待用户输入过后才会析构
# # dog = Animal("柯基")
# # print()
# #使用关键字del手动删除对象 会执行__del__函数
# del cat
# class Animal:
#     def eat(self):
#         pass
#     def drink(self):
#         pass
#     pass
# class dog(Animal):
#     def wwj(self):
#         print("小猫喵喵叫")
#     pass
# class cat(Animal):
#     def mmj(self):
#         print("小狗汪汪叫")
#     pass
# c = cat()
# c.eat()
class shenxian:
    def fly(self):
        print("神仙会飞")
        pass
    pass
class Monkey:
    def chitao(self):
        print("猴子喜欢吃桃")
        pass
    pass
class sunwukong(shenxian,Monkey):
    pass
swk = sunwukong()
swk.chitao()
swk.fly()
class D(object):
    def eat(self):
        print('D,test')
        pass
    pass
class C(D):
    def eat(self):
        print("c.eat")
        pass
    pass
class B(D):
    pass
class A(B,C):
    pass
a = A()
a.eat()#先到A中找，再到B中找，再到C中找而不是D中找eat函数，最后去D中，未找到会报错 也是继承的顺序
print(A.__mro__)
#重写父类方法
class father:
    def eat(self):
        print("吃海鲜")
        pass
    pass
class son(father):
    def eat(self):
        print("吃水果")#方法覆盖
        pass
    pass
s = son()
print(s.eat())


