class Animal:
    def speak(self):
        print("我是动物")
        pass
    pass
class Duck(Animal):
    #重写
    def speak(self):
        print("我是一只鸭子")
    pass
class Dog(Animal):
    def speak(self):
        print("我是小狗")
        pass
    pass
class Cat(Animal):
    def speak(self):
        print("我是小猫")
        pass
    pass
def commomInvoke(obj):
    #统一调用方法
    obj.speak()
    pass
listobj = [Duck(),Dog(),Cat()]
for item in listobj:
    commomInvoke(item)
    pass