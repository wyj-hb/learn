#include"speechManger.h"
int main()
{
	srand((unsigned int)time(NULL));
	//创建管理类对象
	SpeechManger sm;
	int choice = 0;
	while (true)
	{
		sm.menu();
		cout << "请输入您的选择" << endl;
	    cin >> choice;
		switch (choice)
		{
		case 1://开始比赛
			sm.startSpeech();
			break;
		case 2://查看往届比赛记录
			sm.showrecord();
			break;
		case 3://情况比赛记录
			sm.clearrecord();
			break;
		case 0://退出系统
			sm.exitsys();
			break;
		default:
			system("cls");//清屏
		}
	}
	system("pause");
	return 0;
}