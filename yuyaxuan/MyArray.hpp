////自己的通用类
//#pragma once
//#include<iostream>
//using namespace std;
//template<class T>
//class MyArray
//{
//public:
//	//有参构造 参数 容量
//	MyArray(int capacity)
//	{
//		this->m_Capacity = capacity;
//		this->m_Size = 0;
//		this->pAddress = new T[this->m_Capacity];
//		//cout << "这是有参" << endl;
//	}
//	//拷贝构造
//	MyArray(const MyArray& arr)
//	{
//		this->m_Capacity = arr.m_Capacity;
//		this->m_Size = arr.m_Size;
//		//深拷贝
//		this->pAddress = new T[arr.m_Capacity];
//		//将arr中的数据都拷贝过来
//		for (int i = 0;i < this->m_Size;i++)
//		{
//			this->pAddress[i] = arr.pAddress[i];
//		}
//		//cout << "这是拷贝" << endl;
//	}
//	//operator=防治浅拷贝问题
//	MyArray& operator=(const MyArray& arr)
//	{
//		//先判断原来堆区是否有数据，如果有先释放
//		if (this->m_Capacity != NULL)
//		{
//			delete[] this->pAddress;
//			this->pAddress = NULL;
//			this->m_Capacity = 0;
//			this->m_Size = 0;
//		}
//		this->m_Capacity = arr.m_Capacity;
//		this->m_Size = arr.m_Size;
//		//深拷贝
//		this->pAddress = new T[arr.m_Capacity];
//		//将arr中的数据都拷贝过来
//		for (int i = 0;i < this->m_Size;i++)
//		{
//			this->pAddress[i] = arr.pAddress[i];
//		}
//		return *this;
//	}
//	//析构函数
//	~MyArray()
//	{
//		if (this->m_Capacity != NULL)
//		{
//			delete[] this->pAddress;
//			this->pAddress = NULL;
//		}
//		//cout << "这是析构" << endl;
//	}
//	//尾插法
//	void Push_Back(const T &val)
//	{
//		//判断是否已满
//		if (this->m_Capacity == this->m_Size)
//		{
//			cout << "数组已满" << endl;
//			return;
//		}
//		this->pAddress[this->m_Size] = val;
//		this->m_Size++;
//	}
//	//尾删法
//	void Pop_Back()
//	{
//		if (this->m_Size == 0)
//		{
//			return;
//		}
//		this->m_Size--;
//	}
//	//通过下标方式访问数据
//	//重载[]
//	T& operator[](int index)
//	{
//		return this->pAddress[index];
//	}
//	//返回数组容量
//	int getCapacity()
//	{
//		return this->m_Capacity;
//	}
//	//返回数组大小
//	int getSize()
//	{
//		return this->m_Size;
//	}
//private:
//	T* pAddress;//指针指向堆区开辟的真实数组
//	int m_Capacity;//数组容量
//	int m_Size;//数组大小
//};