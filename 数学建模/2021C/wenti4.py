# -*- coding: utf-8 -*-
import numpy
import xlrd
from hanshu import *
file_location = "D:\Desktop\数学建模\初赛\CUMCM2021-C\附件1 近5年402家供应商的相关数据.xlsx"
data = xlrd.open_workbook(file_location)
sheet = data.sheet_by_index(1)
sheet2 = data.sheet_by_index(0)
data = [[sheet.cell_value(r, c) for c in range(sheet.ncols)] for r in range(sheet.nrows)]
data1 = [[sheet.cell_value(r, c) for c in range(sheet.ncols)] for r in range(sheet.nrows)]#供应量
data_d = [[sheet2.cell_value(r, c) for c in range(sheet2.ncols)] for r in range(sheet2.nrows)]#订货量

list3 = numpy.zeros((240, 3))  # 分类看类看每周的总值
#计算每周A类供应的均值
for j in range(0, 240):
    sum = 0
    for i in range(0, 402):
        if data1[i + 1][1] == 'A':
            sum = sum + data_d[i + 1][j + 2]
    list3[j][0] = sum
#计算每周B类供应的均值
for j in range(0, 240):
    sum = 0
    for i in range(0, 402):
        if data1[i + 1][1] == 'B':
            sum = sum + data_d[i + 1][j + 2]
    list3[j][1] = sum
#计算每周C类供应的均值
for j in range(0, 240):
    sum = 0
    for i in range(0, 402):
        if data1[i + 1][1] == 'C':
            sum = sum + data_d[i + 1][j + 2]
    list3[j][2] = sum
#分别的出A类、B类、C类每周的均值
#将数据分为5年，分别计算出每年的A、B、C三类的产能
for i in range(1, 6):
    sumA = sumB = sumC = 0
    print("第%d年每周的产生均值为:"%i)
    for j in range((i - 1) * 48, i * 48):
        sumA = sumA + list3[j][0]
        sumB = sumB + list3[j][1]
        sumC = sumC + list3[j][2]
    sumA = sumA / 48
    sumB = sumB / 48
    sumC = sumC / 48
    # print(sumA)
    # print(sumB)
    # print(sumC)
    print(sumA / 0.6 + sumB / 0.66 + sumC / 0.72)

# 第四问的402家
list4_1 = numpy.zeros((402, 239, 4))  # 第三和第四是每个的差值（有正负那种）
a = b = c = 0
for i in range(0, 402):
    for j in range(0, 239):
        a = data1[i + 1][j + 2] - data_d[i + 1][j + 2]
        b = data1[i + 1][j + 3] - data_d[i + 1][j + 3]
        list4_1[i][j][2] = a
        list4_1[i][j][3] = b
        if a >= 0:
            a = a
        else:
            a = -a
        if b >= 0:
            b = b
        else:
            b = -b
        c = (a + b) / 2
        list4_1[i][j][0] = c  # 差值（除法）
        list4_1[i][j][1] = j + 1  # 周数

for k in range(0, 402):
    for i in range(0, 239):
        for j in range(0, 238 - i):
            if list4_1[k][j][0] > list4_1[k][j + 1][0]:
                (list4_1[k][j][0], list4_1[k][j + 1][0]) = (list4_1[k][j + 1][0], list4_1[k][j][0])
                (list4_1[k][j][1], list4_1[k][j + 1][1]) = (list4_1[k][j + 1][1], list4_1[k][j][1])
                (list4_1[k][j][2], list4_1[k][j + 1][2]) = (list4_1[k][j + 1][2], list4_1[k][j][2])
                (list4_1[k][j][3], list4_1[k][j + 1][3]) = (list4_1[k][j + 1][3], list4_1[k][j][3])

                # 第四问的        2
list4_2 = numpy.zeros((402, 12, 3))
for i in range(0, 402):
    for j in range(0, 12):
        list4_2[i][j][0] = -2

for i in range(0, 402):
    # k=12
    k = 0
    for flag in range(0, 50):
        # for k in range(0,12):
        b = 0
        for j in range(0, 12):
            # if list1[i][12-k][1]==list2[i][j][0]+1:
            if list4_1[i][flag][1] == list4_2[i][j][0] + 1 or list4_1[i][flag][1] == list4_2[i][j][0] - 1:
                b = 1
                break
        if b == 0:
            list4_2[i][k][0] = list4_1[i][flag][1]
            list4_2[i][k][1] = list4_1[i][flag][2]
            list4_2[i][k][2] = list4_1[i][flag][3]
            # print(list4_2[i][k][0])

            # list2[i][12-k][0]=list1[i][12-k][1]
            k = k + 1
        if k == 12:
            break

# 第四问的
list4_3 = numpy.zeros((403, 24))

for i in range(0, 402):
    a = b = c = 0
    for j in range(0, 12):
        a = list4_2[i][j][0]
        #b = a + 1
        c = int(a + 1)
        # print(c)
        list4_3[i][j * 2] = data_d[i + 1][c]
        k = k + 1
        c = int(a + 2)
        # print(c)
        list4_3[i][j * 2 + 1] = data_d[i + 1][c]
        pass
file_location = "D:\Desktop\数学建模\初赛\CUMCM2021-C\附件2 近5年8家转运商的相关数据.xlsx"
data = xlrd.open_workbook(file_location)
sheet = data.sheet_by_index(0)
data = [[sheet.cell_value(r,c) for c in range(sheet.ncols)] for r in range(sheet.nrows)]
#与问题2相同，选择损耗率最小的转运商
list = numpy.zeros((8, 2))
for i in range(0, 8):
    sum0 = 0
    sum = 0
    for j in range(0, 240):
        if data[i + 1][j + 1] == 0:
            sum0 = sum0 + 1
        else:
            sum = sum + data[i + 1][j + 1]
    sum = sum / (240 - sum0)
    list[i][0] = sum
    list[i][1] = i + 1
for i in range(0, 8):
    for j in range(0, 7 - i):
        if list[j][0] > list[j + 1][0]:
            (list[j][0], list[j + 1][0]) = (list[j + 1][0], list[j][0])
            (list[j][1], list[j + 1][1]) = (list[j + 1][1], list[j][1])

filename11 = "D:\Desktop\数学建模\初赛\CUMCM2021-C\第四问商家选取.xlsx"
wenti4shaixuan(filename11,402,data_d,"Sheet1",26)
wenti2gonghuo(filename11,list4_3)
data222 = xlrd.open_workbook(filename11)
sheet = data222.sheet_by_index(0)
data1 = [[sheet.cell_value(r,c) for c in range(sheet.ncols)] for r in range(sheet.nrows)]
file100 = "D:\Desktop\数学建模\初赛\附件A 订购方案数据结果.xlsx"
shujudaoru3(file100,data1,402,"问题4的订购方案结果",24,402)
filename = "D:\Desktop\数学建模\初赛\附件B 转运方案数据结果.xlsx"
shurudaoru4(filename,data1,list,"问题4的转运方案结果",402)
