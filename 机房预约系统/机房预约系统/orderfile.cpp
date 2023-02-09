#include"orderFile.h"
//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE,ios::in);
	string date;
	string interval;
    string stuId;
	string stuName;
	string roomId;
	string status;
	this->m_size == 0;
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		string key;
		string value;
		map<string, string>m;
		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		/*将小map容器放入到大的map容器中*/
		this->m_order.insert(make_pair(this->m_size, m));
		this->m_size++;
	}
	ifs.close();
	//测试最大map容器
	/*for (map<int, map<string, string>>::iterator it = m_order.begin();it != m_order.end();it++)
	{
		cout << "条数为 " << it->first << "value= " << endl;
		for (map<string, string>::iterator mit = (*it).second.begin();mit != (*it).second.end();mit++)
		{
			cout << " key = " << mit->first << " value = " << mit->second<< " " ;
		}
		cout << endl;
	}*/
}
//更新预约
void OrderFile::updateOrder()
{
	if (this->m_size == 0)
	{
		return;//预约0条记录，直接return
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0;i < this->m_size;i++)
	{
		ofs << "data:" << this->m_order[i]["date"] << " ";
		ofs << "interval:" << this->m_order[i]["interval"] << " ";
		ofs << "stuId:" << this->m_order[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_order[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_order[i]["roomId"] << " ";
		ofs << "status:" << this->m_order[i]["status"] << " ";
	}
	ofs.close();
}