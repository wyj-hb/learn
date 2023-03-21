#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
//8.2
//练习8.4:编写函数，以读模式打开一个文件，将其内容读入到一个 string 的vecto中，将每一行作为一个独立的元素存于 vector 中。
//int main()
//{
//	ifstream in("data");//打开in读的方式打开一个名为data的文件
//	if (!in)//判断是否打开成功
//	{
//		cerr << "无法打开输入文件" << endl;
//		return -1;
//	}
//	string line;
//	vector<string> words;
//	while (getline(in, line))//从in中读取内容到line
//	{
//		words.push_back(line);
//	}
//	in.close();//关闭流
//	for (vector<string>::iterator it = words.begin();it != words.end();it++)
//	{
//		cout << *it << endl;
//	}
//	return 0;
//}
//练习8.5 : 重写上面的程序，将每个单词作为一个独立的元素进行存储。
//int main()
//{
//	ifstream in("data");//打开in读的方式打开一个名为data的文件
//	if (!in)//判断是否打开成功
//	{
//		cerr << "无法打开输入文件" << endl;
//		return -1;
//	}
//	string line;
//	vector<string> words;
//	while(in>>line)//从in中读取内容到line
//	{
//		words.push_back(line);
//	}
//	in.close();//关闭流
//	for (vector<string>::iterator it = words.begin();it != words.end();it++)
//	{
//		cout << *it << endl;
//	}
//	return 0;
//}
////练习 8.6 : 重写 7.1.1 节的书店程序(第 229 页)，从一个文件中读取交易记录。将文化名作为一个参数传递给 main(参见 6.2.5 节，第 196页)。
//int main(int argc, char** argv)
//{
//	if (argc != 2)//出错
//	{
//		cerr << "请输出文件名" << endl;
//		return -1;
//	}
//	ifstream in(argv[1]);
//	if (!in)
//	{
//		//打开失败
//		cerr << "打开失败请重试" << endl;
//		return -1;
//	}
//	Sales_data total;
//	if (read(in, total))
//	{
//		Sales_data trans;
//		while (read(in, trans))
//		{
//			if (trans.isbn() == total.isbn())
//			{
//				total.combine(trans);
//			}//继续寻找下一个
//			else
//			{
//				print(cout, total);//输出信息
//				totol = trans;//帮助这个与前面不重复的trans寻找下一项是否一样
//			}
//		}
//		cout << total << endl;//读到末尾
//	}
//	else
//	{
//		cerr << "错误!" << endl;
//	}
//}
//习8.10 : 编写程序，将来自一个文件中的行保存在一个 vector<string>中。然使用一个istringstream从vector读取数据元素，每次读取一个单词。
//int main()
//{
//	//打开文件
//	ifstream in("data");
//	if (!in)
//	{
//		cerr << "打开流无效" << endl;
//	}
//	vector<string> v1;
//	string line;
//	while (getline(in, line))
//	{
//		v1.push_back(line);
//	}
//	in.close();
//	vector<string>::iterator it = v1.begin();
//	while (it != v1.end())
//	{
//		istringstream ifs(*it);//将一行绑定到ifs上
//		string word;
//		while (ifs>>word)
//		{
//			cout << word << " ";
//		}
//		cout << endl;
//		it++;
//	}
//	return 0;
//}
//练习8.11 : 本节的程序在外层 while 循环中定义了 istringstream 对象。如 record对象定义在循环之外，你需要对程序进行怎样的修改 ? 重写程序，将 record的定义移到 while 循环之外，
//验证你设想的修改方法是否正确。
//struct PersonInfo
//{
//	string name;//姓名
//	vector<string> phones;//电话，其中一个人可以有很多的电话
//};
//int main()
//{
//	string line, word;
//	istringstream record;
//	vector<PersonInfo> p1;
//	while (getline(cin, line))
//	{
//		PersonInfo info;
//		record.clear();//先将reword清空
//		record.str(line);//复制操作
//		record >> info.name;
//		while (record >> word)
//		{
//			info.phones.push_back(word);
//		}
//		p1.push_back(info);
//	}
//}
