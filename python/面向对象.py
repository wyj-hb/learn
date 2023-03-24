# class Person:
#     name = '小明'
#     age = 18
#     def eat(self):
#         print("大口的吃饭")
#         pass
#     pass
# xm = Person()
# xm.eat()
# print("%s的年龄是%d"%(xm.name,xm.age))
# class People:
#     def eat(self):
#         print("爱丽丝")
#         pass
#
# xq = People()
# #添加属性
# xq.name = "周杰伦"
# xq.sex = '女'
# xq.age = 18
# print(xq.name,xq.age,xq.sex)
#改进
class People:
    def __init__(self,name,age,food):#魔术方法，内置的,用于初始化实例属性
        #统一的声明实例属性
        self.name = name
        self.age = age
        self.food = food
        print('init---')
        pass
    def eat(self,food):
        print(self.name + "爱丽丝"+food)
        pass
    def __str__(self):
        return '%s的年龄是%d'%(self.name,self.age)
    pass
    def __new__(cls, *args, **kwargs):
        '''
        实例化对象的方法 在此显示调用,每次调用都会生成一个新的对象
        可以控制创建对象的一些限定属性,经常用来做单例模式的时候使用
        :param args:
        :param kwargs:
        '''
        print('----new----函数执行')
        return object.__new__(cls)#当前类的实例 cls
        pass
# xq = People()
# xq.name = "周杰伦"
# xq.sex = '女'
# xq.age = 18
# # print(xq.name,xq.age,xq.sex)
# # xm = People()#自动调用
# print(xm.name)#默认的属性 输出的是爱丽丝
zjl = People('周杰伦',18,"大米")
print(zjl.name)
zjl.eat("凉粉")
#_str_
print(zjl) #输出的是对象的地址
print(zjl) #输出的是格式化的内容