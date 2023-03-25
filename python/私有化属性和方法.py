# class person:
#     __hobby = '跳舞'#类属性
#     #变成私有的就不可访问了
#     def __init__(self):
#         self.__name = '李四'#加两个下划线将此属性私有化 私有化之后就不能在外部直接访问了，在内部可以
#         self.age = 30
#         pass
#     def __str__(self):
#         return '名字是%s'%(self.__name)#可以访问
#     pass
# class student(person):
#     def printInfo(self):
#         #访问父类的私有属性 可以吗
#         print(self.printInfo())#错误，私有属性不可被继承
#     pass
# s = student()
# print(s.hobby)
# xl = person()
# # print(xl.__name) #是通过类对象在外部访问的
# print(xl)