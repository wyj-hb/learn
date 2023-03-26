import os
import shutil
# os.rename('test.txt','hyals.txt')#文件的重命名
# os.remove('testUpload.py')#删除文件
# os.mkdir('TestCj')#创建文件夹
# os.rmdir('TestCj')#删除文件夹
# os.mkdir('d:/python111')#在d盘创建文件夹 不允许创建多级目录
# //os.makedirs('d:/zjl/ailisi')#创建多级目录
#rmdir只能删除空的目录
#删除非空目录需调用 shutil
#shutil.rmtree('d:/zjl')#删除非空文件夹

#获取当前的目录
# print(os.getcwd())
#路径的拼接
# print(os.path)
# print(os.path.join(os.getcwd(),'venv'))
#获取python中的目录列表
# list = os.listdir('c:/') #老版本的写法 返回的是一个列表
# print(list)
#现代版的 返回的是迭代器对象
# with os.scandir('d:/') as a:
#     for entry in a:
#         print(entry.name)
# rs = os.scandir('d:/')
# print(rs)
# basebath = 'd:/'
# for entry in os.listdir(basebath):
#     if os.path.isfile(os.path.join(basebath,entry)):#只打印文件
#         print(entry)