#include<iostream>
using namespace std;
//(6) 假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素结点 （注意：不
//设头指针）， 试编写相应的置空队列、判断队列是否为空、入队和出队等算法。
#include<time.h>
//typedef int QElemType;
//typedef int Status;
//
//typedef struct QNode//创建队列
//{
//    QElemType data;
//    struct QNode* rear;
//    struct QNode* next;
//}QNode, * LinkQueue;
////队列的初始化
//Status init(LinkQueue& L)
//{
//    L = new QNode;
//    if (L == NULL)
//    {
//        cout << "内存分配失败" << endl;
//        return 0;
//    }
//    L->rear = L;
//    return 1;
//}
////链式队列的建立
//Status create(LinkQueue& L, int n)//n为链表的长度
//{
//    srand((unsigned int)time(NULL));
//    LinkQueue p;
//    for (int i = 0;i < n;i++)
//    {
//        p = new QNode;
//        p->data = rand() % 100;//100以内的随机数
//        L->rear->next = p;
//        L->rear = p;
//       
//    }
//    p->next = L;
//    return 1;
//}
////入队
//Status rudui(LinkQueue& L, int e)
//{
//    LinkQueue q = new QNode;
//    q->data = e;
//    q->next = L;
//    L->rear->next = q;
//    L->rear = q;
//    return 1;
//}
////出队
//Status chudui(LinkQueue& L, int& e)
//{
//    //判断是否为空
//    if (!L->rear->data)
//    {
//        return 0;
//    }
//    LinkQueue temp;
//    e = L->rear->data;
//    temp = L->next;
//    L->next = L->next->next;
//    delete temp;
//    return 1;
//
//}
////输出
//void print(LinkQueue& L)
//{
//    LinkQueue q;
//    q = L->next;
//    while (q!=L)
//    {
//        cout << "元素为:" << q->data << " ";
//        q = q->next;
//    }
//    cout << endl;
//    system("pause");
//    return;
//}
//int main()
//{
//    LinkQueue L;
//    int ElemNumber;
//    QElemType EnElem, DeElem;
//    init(L);
//    cout<<"请输入元素个数：\n";
//    cin >> ElemNumber;
//    create(L, ElemNumber);
//    print(L);
//    cout<<"请输入入队元素：\n";
//    cin >> EnElem;
//    rudui(L, EnElem);
//    print(L);
//    cout<<"出队操作，并返回出队元素：\n";
//    chudui(L, DeElem);
//    cout<<"出队元素为\n"<<DeElem<<endl;
//    print(L);
//    return 0;
//}
//(7) 假设以数组Q[m]存放循环队列中的元素，同时设置一个标志ta$, 以tag = 0 和tag = 1
//来区别在队头指针(front) 和队尾指针(rear) 相等时，队列状态为 “空
//” 还是 “满＂。试编写与此结构相应的插入(enqueue) 和删除(dequeue) 算法。
//#define MAXSIZE 1000
//typedef int Status;
//typedef int QElemType;
//typedef struct
//{
//    QElemType* base;
//    int front;
//    int rear;
//    int tag;
//} SqQueue;
//Status init(SqQueue &S)
//{
//    S.base = new QElemType[MAXSIZE];
//    if (!S.base)//内存分配空间失败
//        exit(OVERFLOW);
//    S.front = S.rear = 0;
//    S.tag = 0; // 循环队列空的标志
//    return 1;
//}
//Status QueueEmpty(SqQueue Q)//判断是否为空
//{
//    if (Q.front == Q.rear && Q.tag == 0)
//        return 1;
//    return 0;
//}
//
//Status QueueFull(SqQueue Q)
//{
//    if (Q.front == Q.rear && Q.tag == 1)
//        return 1;
//    return 0;
//}
//Status EnQueue(SqQueue& Q, QElemType e)//入队
//{
//    if (QueueFull(Q))
//        return 0;//队已满，无法入队
//    Q.base[Q.rear] = e;
//    Q.rear = (Q.rear + 1) % MAXSIZE;
//    if (Q.front == Q.rear && Q.tag == 0)
//        Q.tag = 1;
//    return 1;
//}
//
//Status DeQueue(SqQueue& Q, QElemType& e)//出队
//{
//    if (QueueEmpty(Q))
//        return 0;
//    e = Q.base[Q.front];
//    Q.front = (Q.front + 1) % MAXSIZE;
//    if (Q.front == Q.rear && Q.tag == 1)
//        Q.tag = 0;
//    return 1;
//}
//int main(void)
//{
//    SqQueue Q;
//    cout<<"初始化循环队列Q中.....\n";
//    init(Q);
//    cout<<"准备入队...\n将1 2 3 4 5入队中...\n";
//    for (int i = 1; i <= 5; i++)
//        EnQueue(Q, i) ? cout<<"元素"<<i<<"入队成功"<<endl : cout<<"入队失败";
//    cout << "入队完毕.\n";
//    cout<<"准备出队...\n";
//    cout<<"将 1 2 出队中...\n";
//    QElemType e;
//    DeQueue(Q, e) ? printf("元素%d成功出队\n", e) : printf("出队失败..\n");
//    DeQueue(Q, e) ? printf("元素%d成功出队\n", e) : printf("出队失败..\n");
//    printf("元素 1 2 出队之后判断循环队列是否为空：");
//    QueueEmpty(Q) ? printf("Yes\n") : printf("No\n");
//    printf("将 6 7 入队...\n");
//    EnQueue(Q, 6);
//    EnQueue(Q, 7);
//    printf("元素 6 7 入队之后判断是否为满：");
//    QueueFull(Q) ? printf("Yes\n") : printf("No\n");
//    printf("将循环队列中的元素全部出队...\n");
//    for (int i = 0; i < 5; i++)
//        DeQueue(Q, e) ? printf("元素%d成功出队\n", e) : printf("出队失败..\n");
//    printf("全部元素出队之后判断是否为空：");
//    QueueEmpty(Q) ? printf("Yes\n") : printf("No\n");
//
//    delete Q.base;
//    return 0;
//}
//(8)如果允许在循环队列的两端都可以进行插入和删除操作。要求：心 写出循环队列的类型定义；
//＠写出 “从队尾删除“ 和“从队头插入＂ 的算法。
//#define maxsize 1000
//typedef struct {
//	int data[maxsize];
//	int front;// 队首指针
//	int rear;// 队尾指针
//} SqQueue;
////初始化队列
//void initQueue(SqQueue& qu) {
//	qu.front = qu.rear = 0;// 队首和队尾指针重合并指向0
//}
//
///* 入队（从队头插入） */
//int enQueue(SqQueue& qu, int x) 
//{
//	if (qu.rear == (qu.front - 1 + maxsize) % maxsize) {
//		//判断是否对满
//		return 0;
//	}
//	else {
//		/* 注意：这里是先入队，再修改指针 */
//		qu.data[qu.front] = x;
//		qu.front = (qu.front - 1 + maxsize) % maxsize;
//		return 1;
//	}
//}
//
///* 出队（从队尾出队）
///* &qu指的是要出队的队列；&x指的是要存储出队元素的值 */
//int deQueue(SqQueue& qu, int& x) {
//	if (qu.rear == qu.front) { // 如果队空，就不能出队了
//		return 0;
//	}
//	else {
//		/* 注意：这里是先入队，再修改指针 */
//		x = qu.data[qu.rear];
//		qu.rear = (qu.rear - 1 + maxsize) % maxsize;
//		return 1;
//	}
//}
//
///* 打印队列 */
//void printQueue(SqQueue qu) {
//	printf("\n");
//	while (qu.rear != qu.front) 
//	{
//		//打印输出，直到队列为空
//		qu.front = (qu.front + 1) % maxsize;
//		cout << qu.data[qu.front] << endl;
//	}
//	cout << endl;
//}
//
//int main() {
//	SqQueue qu;
//	initQueue(qu);
//	int nums[] = { 1,2,3,4,5,6 };
//	int n = 6;
//	for (int i = 0; i < n; i++) {
//		int m = enQueue(qu, nums[i]);// 将数组中的元素入队
//	}
//	printQueue(qu);// 打印队列
//	int x;
//	deQueue(qu, x);// 将元素1出队
//	printQueue(qu);// 打印队列
//	cout << x << endl;
//	//将队列变成了先进先出
//	return 0;
//}
//(9) 已知Ackermann 函数定义如下：//n + l 当m = O时Ack(m, n) = �Ack(m - 1, 1) 当m "'F-0,n=O时
//Ack(m - 1, Ack(m, n - 1))当m - ct:-0, n - ct : -0时
//心写出计算Ack(m, n)的递归算法，并根据此算法给出Ack(2, 1)的计算过程。
//＠写出计算Ack(m, n)的非递归算法。
//int Ack(int m,int n)
//{
//	if (m == 0)
//	{
//		return n + 1;
//	}
//	else if (m != 0 && n == 0)
//	{
//		return Ack(m - 1, 1);
//	}
//	else
//	{
//		return Ack(m - 1, Ack(m, n - 1));
//	}
//}
//（10）已知f为单链表的表头指针, 链表中存储的都是整型数据，试写出实现下列运算的递归算法：
//① 求链表中的最大整数；
//② 求链表的结点个数；
//③ 求所有整数的平均值。
class ListNode { //链表结点类
	friend class List;
public:
	int data; //结点数据
	ListNode* link; //结点指针
	ListNode(const int item) : data(item), link(NULL) { } //构造函数,初始化链表
};
class List { //链表类
private:
	ListNode* first;
	ListNode* current;
	int Max(ListNode* f);//求链表中的最大整数;
	int Num(ListNode* f);//求链表的结点个数;
	float Avg(ListNode* f, int& n);//求所有整数的平均值。
public:
	int n;
	List() : first(NULL), current(NULL) { } //构造函数
	~List() { } //析构函数
	ListNode* NewNode(const int item); //创建链表结点, 其值为item
	void NewList(const int retvalue); //建立链表, 以输入retvalue结束
	void PrintList(); //输出链表所有结点数据
	int GetMax() { return Max(first); } //求链表所有数据的最大值
	int GetNum() { return Num(first); } //求链表中数据个数
	float GetAvg() { return Avg(first,n); } //求链表所有数据的平均值
};
ListNode* List::NewNode(const int item) { //创建新链表结点,数据为item
	ListNode* newnode = new ListNode(item);
	return newnode;
}
void List::NewList(const int retvalue) 
{ //建立链表, 以输入retvalue结束
	first = NULL;  int value;  ListNode* q;
	cout << "Input your data:\n"; //提示
	cin >> value; //输入

	while (value != retvalue) { //输入有效
		q = NewNode(value); //建立包含value的新结点
		if (first == NULL) first = current = q; //空表时, 新结点成为链表第一个结点
		else { current->link = q;  current = q; } //非空表时, 新结点链入链尾
		cin >> value; //再输入
	}
	current->link = NULL; //链尾封闭
}
void List::PrintList() { //输出链表
	cout << "\nThe List is : \n";
	ListNode* p = first;
	while (p != NULL) {
		cout << p->data << " ";
	p = p->link; }
	cout << '\n';
}

int List::Max(ListNode* f) { //递归算法 : 求链表中的最大值
	if (f->link == NULL) return f->data;
	int temp = Max(f->link); 
	if (f->data > temp) return f->data; 
	else return temp; 
}
int List::Num(ListNode* f) { //递归算法 : 求链表中结点个数
	if (f == NULL) return 0; //空表, 返回0
	return 1 + Num(f->link); //否则, 返回后继链表结点个数加1
}
float List::Avg(ListNode* f, int& n) { //递归算法 : 求链表中所有元素的平均值
	if (f->link == NULL) //链表中只有一个结点, 递归结束条件
	{
		n = 1;  return (float)(f->data);
	}
	else 
	{ 
		float Sum = Avg(f->link, n) * n;  
		n++; 
		return (f->data + Sum) / n; }
}
int main() {

	List test;   int finished;

	cout << "输入建表结束标志数据:"<<endl;

	cin >> finished; //输入建表结束标志数据

	test.NewList(finished); //建立链表

	test.PrintList(); //打印链表

	cout << "\nThe Max is : " << test.GetMax();

	cout << "\nThe Num is : " << test.GetNum();

	cout << "\nThe Ave is : " << test.GetAvg() << '\n';

	printf("Hello World!\n");

	return 0;

}