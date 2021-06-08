#include <iostream>
using namespace std;
#include <deque>
#include <vector>
#include <algorithm>

//选手类
class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name; //姓名
	int m_Score;  //平均分
};

//创建选手
void createPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];
		int score = 0;
		Person p(name, score);
		//将创建的person对象 放入到容器中
		v.push_back(p);
	}
}

//打分
void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//将评委的分数 放入到deque容器中
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;  // 随机数得分 60 ~ 100
			d.push_back(score);
		}
		//排序 从小到大
		sort(d.begin(), d.end());
		//去除最高和最低分
		d.pop_back();
		d.pop_front();
		//取平均分
		int sum = 0;//总分
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit; //累加每个评委的分数
		}
		int avg = sum / d.size();
		//将平均分 赋值给选手身上
		it->m_Score = avg;//(*it).m_Score
		cout << (*it).m_Score;
	}
}

//显示平均分
void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名： " << it->m_Name << " 平均分： " << it->m_Score << endl;
	}
}

int main18() {
	//随机数种子
	srand((unsigned int)time(NULL));
	//1、创建5名选手
	vector<Person>v;  //存放选手容器
	createPerson(v);
	//2、给5名选手打分
	setScore(v);
	//3、显示最后得分
	showScore(v);
	system("pause");
	return 0;
}