# class Animal:#默认继承于object类
#     def __init__(self):
#         self.color = '红色'
#         pass
#     #在python如果不重写new方法，默认结构如下
#     def __new__(cls, *args, **kwargs):
#         return super().__new__(cls,*args,**kwargs)#默认的结构
#     pass
# tiger = Animal()