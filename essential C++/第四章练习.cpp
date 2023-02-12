#include"stack.h"
//bool stack::pop(string &elem)//返回要压出栈的元素
//{
//	if (empty())
//	{
//		return false;
//	}
//	elem = _stack.back();
//	_stack.pop_back();
//	return true;
//}
//bool stack::peek(string& elem)//返回栈顶元素
//{
//	if (empty())
//	{
//		return false;
//	}
//	elem = _stack.back();
//	return true;
//}
//bool stack::push(const string& elem)
//{
//	if (full())
//	{
//		return false;
//	}
//	_stack.push_back(elem);
//	return true;
//}
//bool stack::find(const string& elem)const
//{
//	vector<string>::const_iterator it = _stack.end();
//	return std::find(_stack.begin(),it,elem) != it;
//}
//int stack::count(const string& elem)const
//{
//	return ::count(_stack.begin(), _stack.end(),elem);
//}
//int main()
//{
//	stack st;
//	string str;
//	cout << "请输入字符串" << endl;
//	
//	while (!st.full() && cin >> str)
//	{
//		st.push(str);
//		if (cin.get() == '\n')
//		{
//			break;
//		}
//	}
//	if (st.empty())
//	{
//		cout << '\n' << "Oops:no strings were read -- bailing out\n";
//		return 0;
//	}
//	st.peek(str);
//	cout << st.size() << endl;
//	if (st.size() == 1 && str.empty())
//	{
//		cout << '\n' << "Oops:no strings were read -- bailling out\n";
//		return 0;
//	}
//	cout << '\n' << "Read in " << st.size() << " strings!\n";
//	cin.clear();//清除end-of-file的设定
//	cout << "what word to search for?" << endl;
//	cin >> str;
//	bool found = st.find(str);
//	int count = found ? st.count(str) : 0;
//	cout << str << (found ? "is" : "isn\'t") << "in the stack.";
//	if (found)
//	{
//		cout << "It occurs " << count << "times\n";
	/*}*/
	/*cout << '\n' << "read in" << st.size() << "strings!\n" << "The strings,in reverse order:\n";
	while (st.size())
	{
		if (st.pop(str))
		{
			cout << str << " ";
		}
	}
	cout << '\n' << "there are now" << st.size() << "elements in the stack!\n";*/
//}
//class globalWrapper
//{
//public:
//	static int tests_passed() { return _tests_passed; };
//	static int tests_run() { return _tests_run; };
//	static int version_number() { return _version_number; };
//	static string version_stamp() { return _version_stamp; };
//	static string program_name() { return _program_name; };
//	static void tests_passed(int nval) { _tests_passed = nval; }
//	static void tests_run(int nval) { _tests_run = nval; }
//	static void version_number(int nval) { _version_number = nval; };
//	static void version_stamp(const string& nstamp)
//	{
//		_version_stamp = nstamp;
//	}
//	static void program_name(const string& npn)
//	{
//		_program_name = npn;
//	}
//private:
//	static string _program_name;
//	static string _version_stamp;
//	static int _version_number;
//	static int _tests_run;
//	static int _tests_passed;
//};
//class UserProfile
//{
//public:
//	enum uLevel { Beginner, Intermediate, Advanced, Guru };
//	UserProfile(string login, uLevel = Beginner);
//	UserProfile();
//	bool operator==(const UserProfile&);
//	bool operator!=(const UserProfile& rhs);
//	//读取数据
//	string login() const { return _login; };
//	string user_name()const { return _user_name; };
//	int login_count()const { return _times_logged; };
//	int guess_count()const { return _guesses; };
//	int guess_correct()const { return _correct_guesses; };
//	double guess_average()const;
//	string level()const;
//	//写入数据
//	void reset_login(const string& val) { _login = val; };
//	void user_name(const string& val){_user_name = val;};//实际姓名
//	void reset_level(const string&);
//	void reset_level(uLevel newlevel) { _user_level = newlevel; }//等级
//	void resst_login_count(int val) { _times_logged = val; };//登入次数
//	void reset_guess_count(int val) { _guesses = val; };//猜过次数
//	void reset_guess_correct(int val) { _correct_guesses = val; };//猜对次数
//	void bump_login_count(int cnt = 1) { _times_logged += cnt; };//
//	void bump_guess_count(int cnt = 1) { _guesses += cnt; };
//	void bump_guess_correct(int cnt = 1) { _correct_guesses += cnt; };
//private:
//	string _login;
//	string _user_name;
//	int _times_logged;
//	int _guesses;
//	int _correct_guesses;
//	uLevel _user_level;
//	static map<string, uLevel>_level_map;
//	static void init_level_map();
//	static string guest_login();
//};
//inline double UserProfile::guess_average()const
//{
//	return _guesses ? double(_correct_guesses) / double(_guesses) * 100 : 0.0;//不为0则计算其百分比
//}
//inline UserProfile::UserProfile(string login, uLevel level) :_login(login), _user_level(level), _times_logged(1), _guesses(0), _correct_guesses(0) {};
//#include<cstdlib>
//inline UserProfile::UserProfile()
//	:_login("guest"), _user_level(Beginner), _times_logged(1), _guesses(0), _correct_guesses(0) 
//{
//	static int id = 0;
//	char buffer[16];
//	_itoa_s(id++, buffer, 10);//将整数转换为对应的ASCLL字符串形式
//	_login += buffer;//会话符id
//};
//inline bool UserProfile::operator==(const UserProfile& rhs)
//{
//	if (_login == rhs._login && _user_name == rhs._user_name)
//	{
//		return true;
//	}
//	return false;
//}
//inline bool UserProfile:: operator!=(const UserProfile& rhs)
//{
//	return *this == rhs;
//}
//inline string UserProfile::level()const
//{
//	static string _level_table[] = {
//		"Beginner","Intermediate","Advanced","Guru" };
//	return _level_table[_user_level];
//}
//ostream& operator<<(ostream& os, const UserProfile& rhs)
//{
//	os << rhs.login() << " " << rhs.level() << " " << rhs.login_count() << " " << rhs.guess_count() << " " << rhs.guess_correct() << " " << rhs.guess_average() << endl;
//	return os;
//}
//map<string, UserProfile::uLevel> UserProfile::_level_map;
//void UserProfile::init_level_map()
//{
//	_level_map["Beginner"] = Beginner;
//	_level_map["Intermediate"] = Intermediate;
//	_level_map["Advanced"] = Advanced;
//	_level_map["Guru"] = Guru;
//}
//inline void UserProfile::reset_level(const string& val)
//{
//	map<string, uLevel>::iterator it;
//	if (_level_map.empty())
//	{
//		init_level_map;
//	}
//	_user_level = ((it = _level_map.find(val)) != _level_map.end()) ? it->second : Beginner;//保证等级独一无二，如果重复则设为默认值Beginner
//}
//istream& operator>>(istream &is, UserProfile& rhs)
//{
//	string login, level;
//	is >> login >> level;
//	int lcount, gcount, gcorrect;
//	is >> lcount >> gcount >> gcorrect;
//	//赋值
//	rhs.reset_login(login);
//	rhs.reset_level(level);
//	rhs.resst_login_count(lcount);
//	rhs.reset_guess_count(gcount);
//	rhs.reset_guess_correct(gcorrect);
//	return is;
//}
//int main()
//{
//	UserProfile anon;
//	cout << anon;//测试output运算符
//	UserProfile anon_too;//鉴别是否取得一份独一无二的标识符
//	cout << anon_too;
//	UserProfile anna("AnnaL", UserProfile::Guru);
//	cout << anna;
//	anna.bump_guess_count(27);
//	anna.bump_guess_correct(27);
//	anna.bump_login_count();
//	cout << anna;
//	cin >> anon;
//	cout << anon;
//}
typedef float elemType;
class Matrix
{
	friend Matrix operator+(const Matrix&, const Matrix&);
	friend Matrix operator*(const Matrix&, const Matrix&);
public:
	Matrix(const elemType*);
	Matrix(elemType = 0., elemType = 0., elemType = 0., elemType = 0.,
		elemType = 0., elemType = 0., elemType = 0., elemType = 0.,
		elemType = 0., elemType = 0., elemType = 0., elemType = 0.,
		elemType = 0., elemType = 0., elemType = 0., elemType = 0.);//矩阵
	int rows() const 
	{
		return 4;};
	int cols() const { return 4;};
	ostream& print(ostream&)const;
	void operator+=(const Matrix&);
	elemType operator()(int row, int column)const
	{
		return _matrix[row][column];
	}
	elemType& operator()(int row, int column)
	{
		return _matrix[row][column];
	}
private:
	elemType _matrix[4][4];
};
inline ostream& operator<<(ostream& os, const Matrix& m)
{
	return m.print(os);
}
Matrix operator+(const Matrix& m1, const Matrix& m2)
{
	Matrix result(m1);
	result += m2;
	return result;
}
Matrix operator*(const Matrix& m1, const Matrix& m2)
{
	Matrix result;
	for (int i = 0;i < m1.rows();i++)
	{
		for (int j = 0;j < m1.cols();j++)
		{
			result(i, j) = 0;
			for (int k = 0;k < m1.cols();k++)
			{
				result(i, j) += m1(i, k) * m2(k, j);
			}
		}
	}
	return result;
}
void Matrix::operator+=(const Matrix& m)
{
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			_matrix[i][j] += m._matrix[i][j];
		}
	}
}
ostream& Matrix::print(ostream& os)const
{
	int cnt = 0;
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++,cnt++)
		{
			if (cnt && !(cnt % 8))
			{
				os << endl;
			}
			os << _matrix[i][j] << " ";
		}
	}
	os << endl;
	return os;
}
Matrix::Matrix(const elemType* array)
{
	int array_index = 0;
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			_matrix[i][j] = array[array_index++];
		}
	}
}
Matrix::Matrix(elemType a11, elemType a12, elemType a13, elemType a14,
	elemType a21, elemType a22, elemType a23, elemType a24,
	elemType a31, elemType a32, elemType a33, elemType a34,
	elemType a41, elemType a42, elemType a43, elemType a44)
{
	_matrix[0][0] = a11;_matrix[0][1] = a12;
	_matrix[0][3] = a13;_matrix[0][3] = a14;
	_matrix[1][0] = a21;_matrix[1][1] = a22;
	_matrix[1][2] = a23;_matrix[1][3] = a24;
	_matrix[2][0] = a31;_matrix[2][1] = a32;
	_matrix[2][2] = a33;_matrix[2][3] = a34;
	_matrix[3][0] = a41;_matrix[3][1] = a42;
	_matrix[3][2] = a43;_matrix[3][3] = a44;
}
int main()
{
	Matrix m;
	cout << m << endl;
	elemType ar[16] = { 1., 0., 0., 0., 0., 1., 0.,0.,
		0., 0., 1., 0., 0., 0., 0., 1. };
	Matrix id(ar);
	cout << id << endl;
	Matrix m2(id);
	m = id;
	cout << m2 << endl;
	cout << m << endl;
	elemType ar2[16] = { 1.3,0.4,2.6,8.2,6.2,1.7,1.3,8.3,
	4.2,7.4,2.7,1.9,6.3,8.1,5.6,6.6 };
	Matrix m3(ar2);
	cout << m3 << endl;
	Matrix m4 = m3 * id;cout << m4 << endl;
	Matrix m5 = m3 + m4;cout << m5 << endl;
	m3 += m4;
	cout << m3 << endl;
}