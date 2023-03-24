# # li = [2,45,67,23,10]
# # # li.sort() #list的排序方法，只能用于list,在原始对象上排序 默认从小到大
# # # print(li)
# # v = sorted(li)
# # x = sorted(li,reverse = True)#降序排列
# # print(li)
# # print(v)#在新的对象上排序
# # print(x)
# #range 创建一个整数列表
# #zip()用于打包,压缩对象 将对象以元组的形式打包，然后返回由这些元组所构成的列表
# s1 = [1,2,3,4,5]
# s2 = ['你','好','吗']
# s3 = ['as','as']
# print(zip(s1,s2))#打印地址
# print(list(zip(s1,s3))) #以最少打包数输出
# def printInfo():
#     books = []#存储所有的图书信息
#     bookid = input("请输入图书的编号:每个项以空格分隔")
#     bookname = input("请输入图书的名字:")
#     idlist = bookid.split(' ') #以空格分隔
#     booknamelist = bookname.split(' ') #以空格分隔
#     booklist = zip(booknamelist,idlist);
#     for bookitem in booklist:
#         '''
#         遍历图书信息进行存储
#         '''
#         dictInfo = {"编号":bookitem[1],'书名':bookitem[0]}
#         print(bookitem)
#         books.append(dictInfo)
#         pass
#     for items in books:
#         print(items)
#         pass
#     pass
# printInfo()
#enumerate函数 用于将一个可以遍历的数据对象(如列表、元组或字符串)组合为一个索引序列,痛死列出数据和数据下标
#一般用在for循环中
# listObj = ['a','b','c']
# for item in enumerate(listObj):#自动为数据添加上下标 以元组的类型
#     print(item)
#     pass
# for index,item in enumerate(listObj,5):#显示的打印出其索引,默认从0开始
#     print(index,item)
#     pass
# #遍历字典
# dicobj = {}
# dicobj['name'] = "李明"
# dicobj['age'] = 18
# for index,item in enumerate(dicobj):
#     # print(index,item)#打印出key值
#     print(item[0:])
#     pass
#集合 set() 无序且不重复 不支持索引和切片
#类似于字典，但只有键
#创建
set1={1,2,3}
print(type(set1))
#添加操作
set1.add(15)
print(set1)
#清空操作
# set1.clear()
# print(set1)
#取差集 difference
# set2= {1,2,5}
# a = set1.difference(set2)#只要set1中存在，若a中元素在b中也存在，则不会输出
# print(a)
# #取交集 intersection
# #取并集 union
# #pop移除数据
# set1.pop()
# print(set1) #拿出去了第一个数
# d = set1.pop()
# print(d)#2
# #discard指定移除
# #更新 update
# set1.update(set2)
# print(set1)#相当于取并集，是在原set上操作的
