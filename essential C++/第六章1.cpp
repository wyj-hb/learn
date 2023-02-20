#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
//template<typename elemType>
//class example
//{
//public:
//	example(const elemType& min, const elemType& max);
//	example(const elemType* array, int size);
//	elemType& operator[](int index);
//	bool operator==(const example&)const;
//	bool insert(const elemtype&)const;
//	bool insert(const elemtype*,int)const;
//	elemType min()consy(return _min);
//	elemType max()consy(return _max);
//	void min(const elemType&);
//	void max(const elemType&);
//	int count(const elemType& value)const;
//private:
//	int size;
//	elemType* parray;
//	elemType min;
//	elemType max;
//};
template <typename elemType>
class Matrix
{
	friend Matrix<elemType> operator+(const Matrix<elemType>&, const Matrix<elemType>&);
	friend Matrix<elemType> operator*(const Matrix<elemType>&, const Matrix<elemType>&);
public:
	Matrix(int rows, int columns) :_rows(rows), _cols(columns) {
		int size = _rows * _cols;
		_matrix = new elemType[size];
		for (int ix = 0;ix < size;ix++)
		{
			_matrix[ix] = elemType();
		}
	}
	Matrix(const Matrix& m) : _rows(m.rows()), _cols(m.cols())
	{
		int size = _rows * _cols;
		_matrix = new elemType[size];
		for (int ix = 0;ix < size;ix++)
		{
			_matrix[ix] = m._matrix[ix];
		}
	}
	~Matrix() {};
	Matrix<elemType>& operator=(const Matrix& m)
	{
		if (this != m)
		{
			_rows = m._rows;
			_cols = m._cols;
			int size = _rows * _cols;
			delete[] _matrix;
			_matrix = new elemType[size];
			for (int ix = 0;ix < size;ix++)
			{
				_matrix[ix] = m._matrix[ix];
			}
		}
		return *this;
	}
	void operator+=(const Matrix&);
	elemType& operator()(int row, int column) { return _matrix[row * cols() + column]; };
	const elemType& operator()(int row, int column)const { return _matrix[row * cols() + column]; };
	bool same_size(const Matrix& m)const { return rows() == m._rows() && cols() == m._cols; };
	bool comfortable(const Matrix& m)const { return (cols() == m.rows()); };
	int cols()  { return _cols; };
	int rows()  { return _rows; };
	ostream& print(ostream&);
private:
	int _cols;
	int _rows;
	elemType* _matrix;
};
template<typename elemType>
inline ostream& operator << (ostream & os, Matrix<elemType> &m) { return m.print(os); };
template<typename elemType>
Matrix<elemType> operator+(const Matrix<elemType>& m1, const Matrix<elemType>& m2)
{
	//
	Matrix<elemType> result(m1);//将m1的值赋给result
	result += m2;
	return result;
}
template<typename elemType>
Matrix<elemType> operator*(const Matrix<elemType>&m1, const Matrix<elemType>&m2)
{
	Matrix<elemType> result(m1.rows(), m2.cols());
	for (int ix = 0;ix < m1.rows();ix++)
	{
		for (int jx = 0;jx < m1.cols();jx++)
		{
			result(ix, jx) = 0;
			for (int kx = 0;kx < m1.cols();kx++)
			{
				result(ix, jx) += m1(ix, kx) * m2(kx, jx);
			}
		}
	}
	return result;
}
template<typename elemType>
void Matrix<elemType>::operator+=(const Matrix& m)
{
	int matrix_size = cols() * rows();
	for (int ix = 0;ix < matrix_size;++ix)
	{
		(*(_matrix + ix)) += (*(m._matrix + ix));
	}
}
template<typename elemType>
ostream& Matrix<elemType>::print(ostream& os)
{
	int col = cols();
	int matrix_size = col * rows();
	for (int ix = 0;ix < matrix_size;++ix)
	{
		if (ix % col == 0)//到了末尾输入换行符
		{
			os << endl;
		}
		os << (*(_matrix + ix)) << ' ';
	}
	os << endl;
	return os;
}
int main()//测试
{
	ofstream log("D:\C++\C++\C++\odd.txt");
	if (!log)//文件不存在
	{
		cerr << "can not find" << endl;
		return 0;
	}
	Matrix<float> identity(4, 4);
	log <<identity;
	return 0;
}