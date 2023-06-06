# -*- coding: utf-8 -*-
#一定要边debug边看代码!!!
#一定要边debug边看代码!!!
#一定要边debug边看代码!!!
#PS:这部分代码其实我们小组认为还是可以继续优化的，因为240周有的周其实是并没有太大的参考价值的，但是我们却令每周的排名具有相同的权值，显然可以处理的更合理
#可以计算402家240周总的供应量，再计算每周的供应量，相除的得到每周的权值，与排名相乘即可。如果你想试试的话可以搞搞，但我保证你电脑会崩。
from hanshu import *#导入自己编写的函数
import xlrd
file_location = "D:\Desktop\数学建模\初赛\CUMCM2021-C\附件1 近5年402家供应商的相关数据.xlsx"
data = xlrd.open_workbook(file_location)
#获取excel表中的两个sheet表，分别命名为sheet和sheet2
sheet = data.sheet_by_index(1)#供应商的供货量表
sheet2 = data.sheet_by_index(0)#企业的订货量表
#读取sheet表中的数据(供货量)
data1 = [[sheet.cell_value(r, c) for c in range(sheet.ncols)] for r in range(sheet.nrows)]
# 排名
import numpy
#创建一个402行，240列的矩阵,sheet表中第一行、前两列不需要数据记录,因此为403-1=402行，242-2=240列
#该矩阵用来记录排序后的对应位置，当进行数据交换时，要记录交换后供应商的位置
num_list = numpy.zeros((402, 240))
for i in range(0, 402):
    for j in range(0, 240):
        num_list[i][j] = i + 1#初始化为对应的供应商id号，例如第一行数据全部为1，因为他们对应位置为供应商1在240周的每周的供应量
#把数据按每周进行排序
#判断数据大小时，不仅要考虑数值，还要考虑它属于何种材料，A类的1肯定比B类的1价值大，应该排在前面，产能表因此而生!
#根据判断A、B、C赋予不同的权值，数据比较时比较产能表的值即可。
filename = "D:\Desktop\数学建模\初赛\CUMCM2021-C\产能表.xlsx"
channengbiao(filename,data1,'Sheet1')
#使用的是冒泡排序
#读入新创建的产能表
data2 = xlrd.open_workbook(filename)
sheet20 = data2.sheet_by_index(0)
data3 = [[sheet20.cell_value(r, c) for c in range(sheet.ncols)] for r in range(sheet.nrows)]
for k in range(240):#当前正在排序的是第几周，共240周因此为240
    for i in range(0, 402):#冒泡排序的轮数,一共要排402轮(其实401次也可以吧)，每次把当前范围中的最小数放到当前范围最后的位置
        for j in range(0, 401 - i):#每次排序交换401-i次，例如第一次交换401次可将402个数据中最小的数据移动到最后
            #解释为什么k+2，j+1:因为操纵的是data数据，而data数据的第1行不是数据，前两列不是数据，
            if data3[j + 1][k + 2] < data3[j + 2][k + 2]:#如果上一行数据小于下一行
                (data3[j + 1][k + 2], data3[j + 2][k + 2]) = (data3[j + 2][k + 2], data3[j + 1][k + 2])
                (num_list[j][k], num_list[j + 1][k]) = (num_list[j + 1][k], num_list[j][k])
                pass
            pass
        pass

y = numpy.zeros((402, 240))
for i in range(0, 240):#240列，需要排240次
    a = 1
    y[0][i] = 1#每一列的第一名直接设置为1
    n = 1
    for j in range(0, 401):
        if data3[j + 1][i + 2] == data3[j + 2][i + 2]:#如果该行的数据与上一行数据大小相等
            y[j + 1][i] = y[j][i]
            n = n + 1#表示连续相同排名出现的值
        else:#不相等
            y[j + 1][i] = a + n#a表示重复值出现前的排名，如果没有重复值a+n即为下一个数的排名
            a = a + n#更新
            n = 1#n值归1

# 计算每家供应商每周排名的平均值
#第一个代表的是供应商的平均排名,第二个值代表的是供应商编号,
list = numpy.zeros((402, 2))
for k in range(1, 403):#操纵行,从供应商1开始
    sum = 0.0
    for i in range(0, 402):
        for j in range(0, 240):
            #遍历查找位置矩阵中属于原位置矩阵的位置
            if num_list[i][j] == k:
                sum = sum + y[i][j]#加上排名
    sum = sum / 240#排名均值
    list[k - 1][0] = sum
    list[k - 1][1] = k

# 对每周排名的平均值进行排序
for i in range(0, 402):
    for j in range(0, 401 - i):
        if list[j][0] > list[j + 1][0]:
            #将排名最大的(排名最靠后的)排在最后面
            (list[j][0], list[j + 1][0]) = (list[j + 1][0], list[j][0])
            (list[j][1], list[j + 1][1]) = (list[j + 1][1], list[j][1])
# 输出结果
for i in range(0, 50):
    print(list[i][1])#输出对应的供应商编号
filename5 = "D:\Desktop\数学建模\初赛\CUMCM2021-C\重要50家供应商数据.xlsx"#数据存取
wushijia(filename5,data1,"Sheet1",list)