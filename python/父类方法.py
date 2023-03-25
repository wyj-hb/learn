# class Dog:
#     def __init__(self,name,color):
#         self.name = name
#         self.color = color
#     def bark(self):
#         print("汪汪叫")
#         pass
#     pass
# class kj(Dog):
#     def __init__(self,name,color):#重写父类的构造函数
#         #调用父类的构造函数
#         # Dog.__init__(self,name,color)# 手动的调用,显示的调用父类的方法 之后会具备name和color属性
#         super().__init__(name,color)#通过super自动的去找父类，进而调用方法,假如继承的是多个父类,逐个的去找
#         #扩展其他属性
#         self.height = 90
#         self.weight = 20
#         pass
#     def __str__(self):
#         return '%s的身高是%s,体重是%s'%(self.name,self.height,self.weight)
#     def bark(self):#重写父类的方法
#         super().bark()#调用父类的方法
#         print("哈哈小")
#         pass
#     pass
# li = kj('keji','hongse')
# print(li)
# print(li.bark())
