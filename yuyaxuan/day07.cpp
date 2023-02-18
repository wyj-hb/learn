//#include<iostream>
//#include<string>
//using namespace std;
////电脑组装
////抽象CPU类
//class CPU
//{
//public:
//	//抽象的计算函数
//	virtual void calculate() = 0;
//};
////抽象显卡类
//class VideoCard
//{
//public:
//	//抽象的显示函数
//	virtual void show() = 0;
//};
////抽象内存条类
//class Me
//{
//public:
//	//抽象的存储函数
//	virtual void M() = 0;
//};
////电脑类
//class computer
//{
//public:
//	computer(CPU* cpu, VideoCard* vc, Me* m)
//	{
//		m_cpu = cpu;
//		m_vc = vc;
//		m_m = m;
//	}
//	void work()
//	{
//		m_cpu->calculate();
//		m_vc->show();
//		m_m->M();
//	}
//	//提供析构函数 释放3个电脑零件
//	~computer()
//	{
//		if (m_cpu != NULL)
//		{
//			delete m_cpu;
//			m_cpu = NULL;
//		}
//		if (m_vc != NULL)
//		{
//			delete m_vc;
//			m_vc = NULL;
//		}
//		if (m_m != NULL)
//		{
//			delete m_m;
//			m_m = NULL;
//		}
//	}
//	CPU* m_cpu;
//	VideoCard* m_vc;
//	Me* m_m;
//};
////实现具体的厂商
//
//class IntelCPU :public CPU
//{
//public:
//	virtual void calculate()
//	{
//		cout << "这是Intel的CPU" << endl;
//	}
//};
//class IntelVideoCard :public VideoCard
//{
//public:
//	virtual void show()
//	{
//		cout << "这是Intel的videocard" << endl;
//	}
//};
//class IntelMe :public Me
//{
//public:
//	virtual void M()
//	{
//		cout << "这是Intel的Me" << endl;
//	}
//};
//class LenovoCPU :public CPU
//{
//public:
//	virtual void calculate()
//	{
//		cout << "这是Lenov0的CPU" << endl;
//	}
//};
//class LenovoVideoCard :public VideoCard
//{
//public:
//	virtual void show()
//	{
//		cout << "这是Lenovo的videocard" << endl;
//	}
//};
//class LenovoMe :public Me
//{
//public:
//	virtual void M()
//	{
//		cout << "这是Lenovo的Me" << endl;
//	}
//};
//void test01()
//{
//	//第一台电脑的零件
//	CPU* intelCPU = new IntelCPU;
//	VideoCard* IntelVideoCard = new LenovoVideoCard;
//	Me* intelMe = new IntelMe;
//	computer* c = new computer(intelCPU, IntelVideoCard, intelMe);
//	c->work();
//	delete c;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}