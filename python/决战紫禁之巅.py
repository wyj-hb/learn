#两个任务 西门吹雪 和 叶孤城
#属性:name blood血量
#方法:tong()捅一刀 掉10滴血
#kanren()砍一刀 掉15滴血
#chiyao()吃一个颗药 补血10滴
#__str__打印玩家的状态
import time
class Role:
    def __init__(self,name,hp):#hp是血量
        self.name = name
        self.hp = hp
        pass
    def tong(self,enemy):
        enemy.hp = enemy.hp - 10
        info = '%s捅了%s一刀，掉了10滴血'%(self.name,enemy.name)
        print(info)
        pass
    def kanren(self,enemy):
        enemy.hp = enemy.hp - 15
        info = '%s砍了%s一刀，掉了15滴血' % (self.name, enemy.name)
        print(info)
        pass
    def chiyao(self):
        self.hp+=10
        info = '%s吃了补血药，补了10滴血'%(self.name)
        print(info)
        pass
    def __str__(self):
        return '%s的血量是%d'%(self.name,self.hp)
    pass
xmcx = Role("西门吹雪",100)
ygc = Role("叶孤城",100)
while True:
    if xmcx.hp<=0 or ygc.hp<=0:
        break;
    xmcx.tong(ygc)
    print(ygc)
    print(xmcx)
    ygc.chiyao()
    print(ygc)
    xmcx.tong(ygc)
    print(ygc)
    print(xmcx)
    xmcx.tong(ygc)
    print(ygc)
    print(xmcx)
    time.sleep(0.5)

