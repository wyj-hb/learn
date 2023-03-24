# 求三组连续自然数的和:求出1到10 20到30和35到45的三个和
def sumrange(m,n):
    '''
    求从m到n连续自然数的总和
    :param m:
    :param n:
    :return:
    '''
    a = sum(range(m,n+1))
    return a
a = sumrange(1,10)
b = sumrange(20,30)
c = sumrange(35,45)
print(a,b,c)
# 100个和尚吃100个馒头，大和尚一人吃3个馒头，小和尚三人吃1个馒头。请问大小和尚各多少
def personcount():
    '''
    计算各有多少个和尚
    :return:
    '''
    for a in range(1,100):
        if a*3 + (100-a)/3 == 100:
            return a
        pass
    pass
a = personcount()
print(a)
# 指定一个列表，列表里含有唯一一个只出现过一次的数字。写程序找出这个“独一无二”的数字
li = [1,2,3,5,5,1,2,4,5,4,5,8]#3
set1 = set(li)#创建一个不重复的集合序列，去重
for i in set1:
    li.remove(i)#去除元素使得li中只剩下重复的元素
    pass
set2 = set(li)#再一次进行去重
for i in set1:
    if i not in set2:
        print(i)
        pass
    pass

