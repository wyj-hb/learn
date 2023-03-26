#tell
# with open('test.txt','r') as f:
#     print(f.read(3))
#     print(f.tell())
#     pass
#truncate 对源文件进行截取操作
# f = open('test.txt','r')
# print(f.read())
# f.close()
# e = open('test.txt','r+')
# e.truncate(5)
# print(e.read())#源文件会被修改,保留前5个字符
# e.close()
#seek()设置当前指针的位置
# with open('test.txt','rb') as f:
#     f.seek(4,0)#表示光标从0位置开始向右移动四个私服
#     data = f.read(2)
#     print(data.decode('gbk'))
#     f.seek(-2,1)#设置光标的位置 1表示当前位置，-2使得光标回到0的位置 2表示设置为末尾位置
#     data = f.read(3)
#     print(data.decode('gbk'))
#     pass
#对读取的位置有选择性的开始读，应该使用二进制的方式去读