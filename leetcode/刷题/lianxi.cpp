//#include<iostream>
//#include<vector>
//using namespace std;
//class node
//{
//public:
//	node* left;
//	node* right;
//	int data;
//	node() { this->left = NULL;this->right = NULL;data = 0;
//	}
//};
//void gouzao(node* n)
//{
//	cout << "请输入数据" << endl;
//	int data;
//	cin >> data;
//	if (data == 55)
//	{
//		n = NULL;
//		return;
//	}
//	else
//	{
//		n = new node();
//		n->data = data;
//		gouzao(n->left);
//		gouzao(n->right);
//	}
//}
//bool chazhao(node* n, int k)
//{
//	//在树中查找k
//	if (n->data == k)
//	{
//		return true;
//	}
//	else if(n->data < k)
//	{
//		chazhao(n->left,k);
//	}
//	else
//	{
//		chazhao(n->right, k);
//	}
//	return false;
//}
//int main()
//{
//	node* n = new node();
//	gouzao(n);
//	cout << n->data << endl;
//	int k = 5;
//	auto b = chazhao(n, k);
//	cout << b << endl;
//}