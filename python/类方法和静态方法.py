# class People:
#     country = 'china'
#     @classmethod#标示为类方法
#     def get_country(cls):
#         return cls.country#访问类属性
#         pass
#     @classmethod
#     def chang_country(cls,data):
#         cls.country = data#修改类属性的值
#         pass
#     @staticmethod #静态方法
#     def getData():#参数可传可不传
#         return People.country
#         pass
#     pass
# print(People.get_country())#通过类对象直接去引用
# #实例对象也可以访问类方法
# People.chang_country('英国')
# print(People.get_country())
# print(People.getData())#实例对象可以访问但是没有必要，一般不使用
# import time
# class TimeTest:#返回当前的系统时间
#     def __init__(self,hour,min,second):
#         self.hour = hour
#         self.min = min
#         self.second = second
#     @staticmethod
#     def show_time():
#         return time.strftime("%H:%M:%S",time.localtime())#小时分钟秒
#         pass
#     pass
# print(TimeTest.show_time())#该方法是独立的，不需要去实例化对象
# t = TimeTest(2,10,15)
# print(t.show_time())