# #文件的操作
# #打开文件 open
# #默认的是中文编码gbk,最好在打开一个文件时指定一个编码类型
# fobj = open('./Test.txt','w',encoding='utf-8')#表示在当前文件夹下打开文件 该文件已存在就覆盖，不存在就创建
# #开始操作 读写
# fobj.write('xieshoushi')
# fobj.write("asja")
# fobj.close()#关闭后会自动更新到文件中

#以二进制的形式去写
# fobj = open('Test_1.txt','wb')#回到当前的文件夹下去找 写入转换为二进制形式
# fobj.write('像诗里翻飞的美丽章节'.encode('utf-8'))
# fobj.close()
#追加 a
# fobj = open('Test_1.txt','a',encoding='utf-8')#回到当前的文件夹下去找 写入转换为二进制形式
# fobj.write('你是我唯一想要的了解\r\n')
# fobj.write('heisi\r\n')
# fobj.close()

# f = open("test.txt",'a',encoding='utf-8')
# f.write("我爱你\n")
# f.write("再见\n")
# f.close()
#读数据 read
# f = open("test.txt",'r',encoding='utf-8')
# # print(f.read()) #从头读到尾 读取所有
# # print(f.read(2)) #n读的个数
# # print(f.readline())
# # print(f.readline())
# print(f.readlines(1))#返回的是一个列表对象
#以二进制形式去读
#with可以不必去使用close
# with open("test.txt",'r',encoding='utf-8') as f:
#     print(f.read())

