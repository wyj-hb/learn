#文件的备份
f = open('test.txt','w')
f.write("jdadaslkasd")
f.close()
def copyFile():
    #接收用户输入的文件名
    old_file = input("请输入要备份的文件名:")
    file_list = old_file.split('.')#以.的形式分隔
    new_file = file_list[0] + '_备份.'+file_list[1]
    # old_f = open(old_file,'r')#以读的方式去打开旧文件
    # new_f = open(new_file,'w')#以写的方式去打开新文件，不存在则创建
    # content = old_f.read()#读取文件
    # new_f.write(content)#内容写入到备份文件中
    # new_f.close()
    # old_f.close()
    try:
        #监视要处理的逻辑
        with open(old_file,'r') as old_f,open(new_file,'w') as new_f:
            while True:
                content = old_f.read(1024)#一次读取1024个字符
                new_f.write(content)
                if len(content)<1024:
                    break
    except Exception as msg:
        print(msg)
        pass
    pass



    pass
copyFile()
