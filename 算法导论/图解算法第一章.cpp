#include<iostream>
using namespace std;
int output[1000] = { 0 };
//int fin(int n)
//{
//	int result;
//	result = output[n];
//	if (result == 0)
//	{
//		//说明此时并未递归到该值
//		if (n == 0)
//		{
//			return 0;
//		}
//		if (n == 1)
//		{
//			return 1;
//		}
//		else
//		{
//			//继续递归
//			return (fin(n - 1) + fin(n - 2));
//		}
//		output[n] = result;//记录有值得情况
//	}
//	return result;//此时说明该值被计算过,直接返回即可
//}
//int main()
//{
//	int a = fin(4);
//	cout << a << endl;
//}
//老鼠走迷宫游戏
//该问题利用堆栈,走到的每一个都使用堆栈记录，此时堆栈的指针的指向便是老鼠的当前位置,如果该位置四个方向均不可走，则将该位置标记并且出栈，退回到上一个元素继续进行选择
//typedef struct list
//{
//	int x, y;//x,y代表坐标
//	struct list* next;//指向
//}Lnode,*linklist;
//linklist push(linklist stack,int x,int y)//此例中stack相当于栈顶指针，永远指向栈顶元素，也就是最后加入的元素
//{
//	linklist neonode;
//	neonode = new Lnode;//开辟一段新的空间
//	if (!neonode)
//	{
//		//开辟失败
//		cerr << "内存分配失败" << endl;
//		return NULL;
//	}
//	neonode->x = x;
//	neonode->y = y;//入栈
//	neonode->next = stack;
//	stack = neonode;
//	return stack;
//}
//linklist pop(linklist stack, int &x1, int &y1)
//{
//	linklist top;
//	if (stack != NULL)
//	{
//		top = stack;
//		stack = stack->next;
//		x1 = top->x;//保存元素坐标
//		y1 = top->y;
//		free(top);//释放掉该空间
//		return stack;
//	}
//	else
//	{
//		x1 = -1;
//		return stack;
//	}
//}
//int MAZE[10][12] = { 2,1,1,1,1,0,0,0,1,1,1,1,
//					1,0,0,0,1,1,1,1,1,1,1,1,
//					1,1,1,0,1 ,1,0,0,0,0,1,1,
//					1,1,1,0,1,1,0,1,1,0,1,1,
//					1,1,1,0,0,0,0,1,1,0,1,1,
//					1,1 ,1,0,1,1,0,1 ,1,0,1,1,
//					1,1 ,1,0,1,1,0,1,1,0,1,1,
//					1 ,1 ,1,0,1 ,1,0,0,1,0,1,1,
//					1,1,0,0,0,0,0,0,0,0,0,1,
//					1,1,1,1,1,1 ,1,1,1,1,1,3 };//创建迷宫
//#define Exitx 8
//#define Exity 10//出口并不意味着是最后一个位置,应该是本题中出口的左上角元素
//#define EAST MAZE[x][y+1]
//#define WEST MAZE[x][y-1]
//#define NORTH MAZE[x-1][y]
//#define SORTH MAZE[x+1][y]
//int cheExit(int x, int y, int ex, int ey)//检查是否已经到了出口
//{
//	if (x == ex && y == ey)
//	{
//		return 1;
//	}
//}
////x,y的坐标都是从1开始的
//int main()
//{
//	linklist path = NULL;
//	int i, j;
//	cout << "迷宫初始化为:"<<endl;
//	int x = 1;
//	int y = 1;//设置老鼠此时的位置为(1,1),此位置是真实的老鼠开始走迷宫的位置
//	for (int i = 0;i < 10;i++)
//	{
//		for (int j = 0;j < 12;j++)
//		{
//			cout << MAZE[i][j] << " ";
//		}
//		cout << endl;
//	}
//	while (x <= Exitx && y <= Exity)
//	{
//		MAZE[x][y] = 6;//该点的值等于6，说明老鼠来过该点
//		if (NORTH == 0)
//		{
//			//NORTH有路可走
//			x -= 1;
//			path = push(path, x, y);//将该位置存入链表中,退出本次for循环并设置该点的位置为6，代表来过
//		}
//		else if (SORTH == 0)
//		{
//			x += 1;
//			path = push(path, x, y);
//		}
//		else if (EAST == 0)
//		{
//			y += 1;
//			path = push(path, x, y);
//		}
//		else if (WEST == 0)
//		{
//			y -= 1;
//			path = push(path, x, y);
//		}
//		else if (cheExit(x, y, Exitx, Exity) == 1)
//		{
//			break;
//		}
//		//注意，在上述的循环中，如果下一个位置(除了他来的那个位置)以外都是0，那么他只能返回到上一个位置,执行
//		else
//		{
//			//说明本位置没有其他位置可走，退回到上一步
//			MAZE[x][y] == 2;//该点等于2，表示该点无法在此访问，并且是个死胡同
//			pop(path, x, y);
//		}
//	}
//	cout << "遍历后" << endl;
//	for (int i = 0;i < 10;i++)
//	{
//		for (int j = 0;j < 12;j++)
//		{
//			cout << MAZE[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//int qiuhe(int x)
//{
//	int sum = 1;
//	if (x >= 1)
//	{
//		for (int i = 0;i < x;i++)
//		{
//			sum *= x;
//		}
//		return sum;
//	}
//	else
//	{
//		return x;
//	}
//	
//}
//int main()
//{
//	int x = 5;
//	int z = qiuhe(x);
//	cout << z << endl;
//}
void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}
void maopao(int arr[],int size)
{
	for (int i = size - 1;i > 0;i--)
	{
		for (int j = 0;j < i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void xuanze(int arr[],int size)
{
	
	
	for (int i = 0;i < size - 1;i++)
	{
		for (int j = i + 1;j < size;j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}
void shuchu(int arr[],int size)
{
	for (int i = 0;i < size;i++)
	{
		cout << arr[i] << " ";
		
	}
	cout << endl;
}
void charu(int arr[],int size)
{
	for (int i = 1;i < size;i++)//比较长度减去一次
	{
		int tmp = arr[i];//存放我们新插入的值,因为如果新添加的值较小，可能会覆盖掉原本位置上的值，因此使用一个临时变量tmp来保存数据
		int j = i - 1;
		while (j >= 0 && arr[j] > tmp)
		{
			//此时插入的元素要小，让出i所占据的大位置
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = tmp;
	}
}
void xier(int arr[], int size)
{
	int jmp = size / 2;
	while (jmp != 0)
	{
		for (int i = jmp;i < size;i++)
		{
			int tmp = arr[i];
			int j = i - jmp;
			while (j >= 0 && arr[j] > tmp)
			{
				arr[j + jmp] = arr[j];
				j = j - jmp;
			}
			arr[j + jmp] = tmp;
		}
		jmp = jmp / 2;
	}
	
}
int main()
{
	int arr[] = { 16,25,39,27,12,8,45,63 };
	int size = sizeof(arr) / sizeof(arr[0]);
	/*maopao(arr,size);*/
	///*xuanze(arr, size);*/
	//charu(arr, size);
	xier(arr, size);
	shuchu(arr,size);
}