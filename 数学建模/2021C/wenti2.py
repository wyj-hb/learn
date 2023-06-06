from hanshu import *
import xlrd
import numpy
import openpyxl as op
#读取数据
file_location = "D:\Desktop\数学建模\初赛\CUMCM2021-C\附件1 近5年402家供应商的相关数据.xlsx"
data = xlrd.open_workbook(file_location)
sheet = data.sheet_by_index(1)
sheet2 = data.sheet_by_index(0)
data1 = [[sheet.cell_value(r, c) for c in range(sheet.ncols)] for r in range(sheet.nrows)]
data10 = [[sheet2.cell_value(r, c) for c in range(sheet2.ncols)] for r in range(sheet2.nrows)]
# 0.3%:240*28200*0.3%=20304 约束参数 这个我也不懂，凑合着用吧
list8 = numpy.zeros((402, 2))  # 240周总共的
for i in range(0, 402):#402家供应商240周总共的供应量
    sum = 0
    for j in range(0, 240):
        sum = sum + data1[i + 1][j + 2]
    list8[i][0] = sum
    list8[i][1] = i + 1

for i in range(0, 402):  # 排序
    for j in range(0, 401 - i):
        if list8[j][0] < list8[j + 1][0]:#上一行的数据和小于下一行，交换
            (list8[j][0], list8[j + 1][0]) = (list8[j + 1][0], list8[j][0])#交换总和
            (list8[j][1], list8[j + 1][1]) = (list8[j + 1][1], list8[j][1])#交换编号

qushu = 0#表示选取的供应商数目
#规定:供应商的均值小于20304被认为是可以剔除的数据
for i in range(0, 402):
    if list8[i][0] < 20304:
        qushu = i
        break

print('选取', qushu, '家供应商')
for i in range(0, qushu):
    print(list8[i][1])
    pass
#csdn上是错误的!我修改的的才是正确的，他多处理一个数据
filename2 = "D:\Desktop\数学建模\初赛\CUMCM2021-C\估计111.xlsx"
wenti2shaixuan(filename2,list8,qushu,data1,"Sheet1",26)
#对筛选出来的供应商数据进行保存，方便后续处理(其实不保存也没事)
filename1 = "D:\Desktop\数学建模\初赛\CUMCM2021-C\筛选后36供应商.xlsx"
wenti2shaixuan(filename1,list8,qushu,data1,"供货量",242)
wenti2shaixuan(filename1,list8,qushu,data10,"订货量",242)
#对excel表格进行操作，筛选出引有36家供应商的表格
data2 = xlrd.open_workbook(filename1)
sheet1 = data2.sheet_by_index(1)
data_d = [[sheet1.cell_value(r, c) for c in range(sheet1.ncols)] for r in range(sheet1.nrows)]

sheet2 = data2.sheet_by_index(0)
data_g = [[sheet2.cell_value(r, c) for c in range(sheet2.ncols)] for r in range(sheet2.nrows)]
list1 = numpy.zeros((36, 239, 4))  # 创建了一个3维数组,36代表36个商家，239代表每两周之间的差值，最终产生
#239组值，4代表每组值的有四个数，分别记录着差值的均值、周数、第一周的差值和第二周的差值
a = b = c = 0

for i in range(0, 36):#36个商家
    for j in range(0, 239):#238+2=240周
        a = data_g[i + 1][j + 2] - data_d[i + 1][j + 2]
        b = data_g[i + 1][j + 3] - data_d[i + 1][j + 3]
        list1[i][j][2] = a#第一周的差值
        list1[i][j][3] = b#第二周的差值
        #将差值归为正数，方便计算
        if a >= 0:
            a = a
        else:
            a = -a
        if b >= 0:
            b = b
        else:
            b = -b
        c = (a + b) / 2
        list1[i][j][0] = c  # 差值（除法）
        list1[i][j][1] = j + 1  # 周数
#进行排序
for k in range(0, 36):#共36个供应商
    for i in range(0, 239):#对每个供应商的239组值进行冒泡排序，共进行239次排序，每次将当前范围最大值移到最后
        for j in range(0, 238 - i):
            if list1[k][j][0] > list1[k][j + 1][0]:
                (list1[k][j][0], list1[k][j + 1][0]) = (list1[k][j + 1][0], list1[k][j][0])
                (list1[k][j][1], list1[k][j + 1][1]) = (list1[k][j + 1][1], list1[k][j][1])
                (list1[k][j][2], list1[k][j + 1][2]) = (list1[k][j + 1][2], list1[k][j][2])
                (list1[k][j][3], list1[k][j + 1][3]) = (list1[k][j + 1][3], list1[k][j][3])
list2 = numpy.zeros((36, 12, 3))
for i in range(0, 36):
    for j in range(0, 12):
        list2[i][j][0] = -2

for i in range(0, 36):
    # k=12
    k = 0
    for flag in range(0, 50):
        # for k in range(0,12):
        b = 0
        for j in range(0, 12):
            # if list1[i][12-k][1]==list2[i][j][0]+1:
            if list1[i][flag][1] == list2[i][j][0] + 1 or list1[i][flag][1] == list2[i][j][0] - 1:
                #不能与已经存入的数据发生冲突，即对应的序号之间应该至少差距为2，差距为1代表这两项数据之间存在重复周。
                b = 1
                break
        if b == 0:
            list2[i][k][0] = list1[i][flag][1]
            list2[i][k][1] = list1[i][flag][2]
            list2[i][k][2] = list1[i][flag][3]
            # list2[i][12-k][0]=list1[i][12-k][1]
            k = k + 1
        if k == 12:#每个供应商都只记录前12项数据，也就是24周的数据
            break
            pass
        pass
    pass
list3 = numpy.zeros((36,24))
#将对应的具体第几周的数据存放的列表list3中
for i in range(0,36):
    a=b=c=0
    for j in range (0,12):
        a=list2[i][j][0]#存放的是数据项的第一周
        # b=a+1#第二周
        c=int(a+1)#转化为整数,因为原值是浮点数 加二是因为前两列不是数据
        list3[i][j*2]=data_d[i+1][c]#两周两周的存放 加1是因为第一行不是数据
        k=k+1
        c=int(a+2)
        list3[i][j*2+1]=data_d[i+1][c]
        pass
    pass

wenti2gonghuo(filename2,list3)
data5 = xlrd.open_workbook(filename2)
sheet11 = data5.sheet_by_index(0)
data5 = [[sheet11.cell_value(r, c) for c in range(sheet11.ncols)] for r in range(sheet11.nrows)]
file100 = "D:\Desktop\数学建模\初赛\附件A 订购方案数据结果.xlsx"
shujudaoru(file100,data5,list8,242,"问题2的订购方案结果",24,36)

file10 = "D:\Desktop\数学建模\初赛\CUMCM2021-C\附件2 近5年8家转运商的相关数据.xlsx"
data2 = xlrd.open_workbook(file10)
sheet10 = data2.sheet_by_index(0)
data = [[sheet10.cell_value(r, c) for c in range(sheet10.ncols)] for r in range(sheet10.nrows)]
list = numpy.zeros((8,2))
#对损耗率表格进行处理 计算每个转运商所有周的总的转运率的均值，进行排名，靠前的优先进行选择
for i in range(0,8):
    sum0=0
    sum=0
    for j in range (0,240):
        if data[i+1][j+1]==0 :#第一行第一列不是数据所以跳过
           sum0=sum0+1
        else :
            sum=sum+data[i+1][j+1]
    sum=sum/(240-sum0)#减去没有运输的，计算平均的运输损失率
    list[i][0]=sum
    list[i][1]=i+1#转运商编号
for i in range (0,8):#按照运输损失率进行排序
    for j in range(0,7-i):
        if list[j][0]>list[j+1][0]:
            (list[j][0],list[j+1][0])=(list[j+1][0],list[j][0])
            (list[j][1],list[j+1][1])=(list[j+1][1],list[j][1])

for i in range(0,8):
    print(list[i][0],list[i][1])
    pass
#得到list数组，list数组中list[i][0]存的是转运商的ID
filename = "D:\Desktop\数学建模\初赛\附件B 转运方案数据结果.xlsx"
shurudaoru2(filename,data5,list,list8,"问题2的转运方案结果",36,2)
a=0
list4= numpy.zeros(24)
file_location = filename2
wenti2gonghuo(filename2,list3)
data_y = xlrd.open_workbook(file_location)
sheet = data_y.sheet_by_index(0)
data_y = [[sheet.cell_value(r, c) for c in range(sheet.ncols)] for r in range(sheet.nrows)]
for i in range(0,24):#列 共24周
    sum=0
    for j in range(0,36):#行 共36个供应商
        a = data_y[j+1][i+2]
        sum=sum+a
    list4[i]=sum
for i in range(0,24):#b代表的是需要选取转运商的家数
    b=list4[i]//6000
    if list4[i]%6000 != 0:
        b=b+1
        print("第%d周，需要转运商%d个"%(i+1,b))
        pass
    pass

