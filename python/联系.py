# 写函数，接收n个数字，求这些参数数字的和
# def qiuhe(*args):
#     sum = 0
#     for item in args:
#         sum+=item
#         pass
#     print("总和是%d"%(sum))
# qiuhe(1,2,3,4,5,6,7,8,9)
# 写函数，找出传入的列表或元组的奇数位对应的元素，并返回一个新的列表
# def jishu(con):
#     i = 0
#     li = []
#     for item in con:
#         i=i+1
#         if i%2 != 0:
#             li.append(item)
#         pass
#     pass
#     print(li)
# jishu(tuple(range(10,30)))
# 写函数，检查传入字典的每一个value的长度如果大于2，那么仅保留前两个长度的内容，并将新内容返回给调用者。PS:字典中的value只能是字符串或列表
# def jiancha(**kwargs):
#     result = {}
#     for key,value in kwargs.items():
#         if len(value)>2:
#             result[key] = value[0:2]
#         pass
#     return result
#     pass
# a = jiancha(name = "张ada",sex = "女diha")
# print(a)