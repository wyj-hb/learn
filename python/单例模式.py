#创建一个单例对象
class DataBaseClass:
    _instance = None
    def __new__(cls, *args, **kwargs):
        #cls._instance = cls.__new__(cls)不能调用自己的new方法
        if not hasattr(cls,'_instance'):
            cls._instance = super().__new__(cls, *args, **kwargs)
            pass
        return cls._instance
    pass
class c(DataBaseClass):
    pass
a = c()
b = c()
print(id(a))#子类会继承父类的new方法
print(id(b))

