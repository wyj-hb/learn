class student(object):
    def __init__(self):
        self.__age = 18
        pass
    # def get_age(self):
    #     return self.__age
    #     pass
    # def set_age(self,age):
    #     if self.__age<0:
    #         print("年龄不能小于0")
    #         pass
    #     else:
    #         self.__age = age
    #         pass
    # 实现方式一:定义一个类属性 实现通过直接访问属性的形式去访问私有的属性
    # age = property(get_age,set_age)
    #方式二:通过装饰器的方式去声明
    @property #使用装饰器去修饰，提供一个getter方法
    def age(self):
        return self.__age
    @age.setter #使用装饰器去修饰，提供一个setter方法
    def age(self,parms):
        if self.__age < 0:
            print("年龄不能小于0")
            pass
        else:
            self.__age = parms
            pass
    pass
p1 = student()
print(p1.age)
p1.age = 30
print(p1.age)#直接将两个方法映射过来
# p1.get_age()
# p1.set_age(18)