//异质对象数组
//edited by sunshine  2016-06-02
#define NUM 50 //参数为记录数开的大小
#include<iostream>
using namespace std;
//以下为主类
class Person {
private:
	int ID;
	char Name[10], Sex[5], Birth[10];
public:
	int ShowID()
	{
		return ID;
	}
	void Print()
	{
		cout << "ID:" << ID << endl;
		cout << "Name:" << Name << endl;
		cout << "Birth:" << Birth << endl;
		cout << "Sex:" << Sex << endl;
	}
	void SetID(int n)
	{
		ID = n;
	}
	void SetName(char ch[])
	{
		strcpy(Name, ch);
	}
	void SetBirth(char ch[])
	{
		strcpy(Birth, ch);
	}
	void SetSex(char ch[])
	{
		strcpy(Sex, ch);
	}

};
//以下开始派生类
class Student :public Person {
private:
	int Point;
public:
	void sPrint()
	{
		Print();
		cout << "grade_point:" << Point << endl << endl;
	}
	void SetPoint(int n)
	{
		Point = n;
	}
};
class Staff :public Person {
private:
	char Dept[10];
public:
	void sPrint()
	{
		Print();
		cout << "dept:" << Dept << endl << endl;
	}
	void SetDept(char ch[])
	{
		strcpy(Dept, ch);
	}
};
class Teacher :public Person {
private:
	int Fund;
public:
	void sPrint()
	{
		Print();
		cout << "fund:" << Fund << endl << endl;
	}
	void SetFund(int n)
	{
		Fund = n;
	}
};

//下面开记录数组和全局变量
Student student[NUM] = {};
Staff staff[NUM] = {};
Teacher teacher[NUM] = {};
int N, Now = 0, Type = 1;//N代表读入的指令，Now代表当前数组位置，Type代表当前数组对象类型

//下面为处理函数
void Deal(int n)//对应n.操作类型
{
	int temp1, temp5;//temp5在student表示学分，在teacher表示科研经费
	char temp2[10], temp3[10], temp4[5],temp6[10];//temp6为了staff里的部门
	if (n == 1)
	{
		if (Type == 1)
			student[Now].sPrint();//调用派生类输出
		else if (Type == 2)
			staff[Now].sPrint();
		else if (Type == 3)
			teacher[Now].sPrint();
	}
	else if (n == 2)//添加一条记录
	{
		while (1)
		{
			cout << "请输入对应序号1.学生 2.职工 3.教师" << endl;
			cin >> Type;
			if (Type > 0 && Type < 4)
				break;
			else
				continue;
		}
		if (Type == 1)//类型1为student
		{
			for (int n1 = 0; n1 < NUM; n1++)
			{
				if (student[n1].ShowID() == 0)
				{
					Now = n1;//调整当前操作位置
					break;
				}
			}
			cout << "请输入" << endl << "*证件号，姓名（英文），出生年月，性别（M/W），学分*" << endl << "每输入一个回车键继续" << endl;
			cin >> temp1 >> temp2 >> temp3 >> temp4 >> temp5;
			student[Now].SetID(temp1);
			student[Now].SetName(temp2);
			student[Now].SetBirth(temp3);
			student[Now].SetSex(temp4);
			student[Now].SetPoint(temp5);
			cout << "记录添加完成" << endl << endl;
		}
		else if (Type == 2)//类型2为staff
		{
			for (int n1 = 0; n1 < NUM; n1++)
			{
				if (staff[n1].ShowID() == 0)
				{
					Now = n1;
					break;
				}
			}
			cout << "请输入" << endl << "*证件号，姓名（英文），出生年月，性别（M/W），部门*" << endl << "每输入一个回车键继续" << endl;
			cin >> temp1 >> temp2 >> temp3 >> temp4 >> temp6;
			staff[Now].SetID(temp1);
			staff[Now].SetName(temp2);
			staff[Now].SetBirth(temp3);
			staff[Now].SetSex(temp4);
			staff[Now].SetDept(temp6);
			cout << "记录添加完成" << endl << endl;
		}
		else if (Type == 3)//类型3为teaacher
		{
			for (int n1 = 0; n1 < NUM; n1++)
			{
				if (teacher[n1].ShowID() == 0)
				{
					Now = n1;
					break;
				}
			}
			cout << "请输入" << endl << "*证件号，姓名，出生年月，性别，科研经费*" << endl << "每输入一个回车键继续" << endl;
			cin >> temp1 >> temp2 >> temp3 >> temp4 >> temp5;
			teacher[Now].SetID(temp1);
			teacher[Now].SetName(temp2);
			teacher[Now].SetBirth(temp3);
			teacher[Now].SetSex(temp4);
			teacher[Now].SetFund(temp5);
			cout << "记录添加完成" << endl << endl;
		}
	}
	else if (n == 3)//删除对象，并重置当前元素
	{
		if (Type == 1)
		{
			student[Now].SetID(0);
			student[Now].SetName("");
			student[Now].SetBirth("");
			student[Now].SetSex("");
			student[Now].SetPoint(0);
			cout << "记录删除成功" << endl << endl;
		}
		else if (Type == 2)
		{
			staff[Now].SetID(0);
			staff[Now].SetName("");
			staff[Now].SetBirth("");
			staff[Now].SetSex("");
			staff[Now].SetDept("");
			cout << "记录删除成功" << endl << endl;
		}
		else if (Type == 3)
		{
			teacher[Now].SetID(0);
			teacher[Now].SetName("");
			teacher[Now].SetBirth("");
			teacher[Now].SetSex("");
			teacher[Now].SetFund(0);
			cout << "记录删除成功" << endl << endl;
		}
	}
	else if (n == 4)//输入一个证件号，查找相应的元素。若找到，则将该节点设为当前元素
		{
			int found = 0, id = -1;
			cout << "请输入要查询的ID号：" << endl;
			cin >> id;
			if (found == 0)
				for (int n1 = 0; n1 < NUM; n1++)
				{
					if (student[n1].ShowID() == id)
					{
						Type = 1;
						Now = n1;
						found = 1;
						student[n1].sPrint();
						break;
					}
				}
			if(found == 0)
				for (int n1 = 0; n1 < NUM; n1++)
				{
					if (staff[n1].ShowID() == id)
					{
						Type = 2;
						Now = n1;
						found = 1;
						staff[n1].sPrint();
						break;
					}
				}
			if (found == 0)
				for (int n1 = 0; n1 < NUM; n1++)
				{
					if (teacher[n1].ShowID() == id)
					{
						Type = 3;
						Now = n1;
						found = 1;
						teacher[n1].sPrint();
						break;
					}
				}
			if (found == 0)
				cout << "没有搜索到想关信息" << endl << endl;
		}
	else if (n == 5)//显示所有记录
		{
			for (int n1 = 0; n1 < NUM; n1++)
				if (student[n1].ShowID() != 0)
					student[n1].sPrint();
			for (int n1 = 0; n1 < NUM; n1++)
				if (staff[n1].ShowID() != 0)
					staff[n1].sPrint();
			for (int n1 = 0; n1 < NUM; n1++)
				if (teacher[n1].ShowID() != 0)
					teacher[n1].sPrint();
			cout << "已经输出了所有信息" << endl;
		}
}

//主函数
int main()
{
	//int N, Now = 0, Type = 0; 已经开到全局里面，照顾返回值不够
	while (1)
	{
		cout << "**************************************************************************" << endl;
		cout << "* 1.显示当前元素信息                 ";
		cout << "2.插入一个元素                      *" << endl;
		cout << "* 3.删除当前元素，并重置当前元素     ";
		cout << "4.查找并设置对象                    *" << endl;
		cout << "* 5.输出所有信息                     ";
		cout << "0.退出                              *" << endl;
		cout << "**************************************************************************" << endl;
		cout << endl;

		cin >> N;
		if (N > 0 && N < 6)
			Deal(N);
		else if (N == 0)
			break;
		else
		{
			cout << "你的输入不正确，请重新输入" << endl;
			cout << endl;
			continue;
		}
	}
}