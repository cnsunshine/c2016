//���ʶ�������
//edited by sunshine  2016-06-02
#define NUM 50 //����Ϊ��¼�����Ĵ�С
#include<iostream>
using namespace std;
//����Ϊ����
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
//���¿�ʼ������
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

//���濪��¼�����ȫ�ֱ���
Student student[NUM] = {};
Staff staff[NUM] = {};
Teacher teacher[NUM] = {};
int N, Now = 0, Type = 1;//N��������ָ�Now����ǰ����λ�ã�Type����ǰ�����������

//����Ϊ������
void Deal(int n)//��Ӧn.��������
{
	int temp1, temp5;//temp5��student��ʾѧ�֣���teacher��ʾ���о���
	char temp2[10], temp3[10], temp4[5],temp6[10];//temp6Ϊ��staff��Ĳ���
	if (n == 1)
	{
		if (Type == 1)
			student[Now].sPrint();//�������������
		else if (Type == 2)
			staff[Now].sPrint();
		else if (Type == 3)
			teacher[Now].sPrint();
	}
	else if (n == 2)//���һ����¼
	{
		while (1)
		{
			cout << "�������Ӧ���1.ѧ�� 2.ְ�� 3.��ʦ" << endl;
			cin >> Type;
			if (Type > 0 && Type < 4)
				break;
			else
				continue;
		}
		if (Type == 1)//����1Ϊstudent
		{
			for (int n1 = 0; n1 < NUM; n1++)
			{
				if (student[n1].ShowID() == 0)
				{
					Now = n1;//������ǰ����λ��
					break;
				}
			}
			cout << "������" << endl << "*֤���ţ�������Ӣ�ģ����������£��Ա�M/W����ѧ��*" << endl << "ÿ����һ���س�������" << endl;
			cin >> temp1 >> temp2 >> temp3 >> temp4 >> temp5;
			student[Now].SetID(temp1);
			student[Now].SetName(temp2);
			student[Now].SetBirth(temp3);
			student[Now].SetSex(temp4);
			student[Now].SetPoint(temp5);
			cout << "��¼������" << endl << endl;
		}
		else if (Type == 2)//����2Ϊstaff
		{
			for (int n1 = 0; n1 < NUM; n1++)
			{
				if (staff[n1].ShowID() == 0)
				{
					Now = n1;
					break;
				}
			}
			cout << "������" << endl << "*֤���ţ�������Ӣ�ģ����������£��Ա�M/W��������*" << endl << "ÿ����һ���س�������" << endl;
			cin >> temp1 >> temp2 >> temp3 >> temp4 >> temp6;
			staff[Now].SetID(temp1);
			staff[Now].SetName(temp2);
			staff[Now].SetBirth(temp3);
			staff[Now].SetSex(temp4);
			staff[Now].SetDept(temp6);
			cout << "��¼������" << endl << endl;
		}
		else if (Type == 3)//����3Ϊteaacher
		{
			for (int n1 = 0; n1 < NUM; n1++)
			{
				if (teacher[n1].ShowID() == 0)
				{
					Now = n1;
					break;
				}
			}
			cout << "������" << endl << "*֤���ţ��������������£��Ա𣬿��о���*" << endl << "ÿ����һ���س�������" << endl;
			cin >> temp1 >> temp2 >> temp3 >> temp4 >> temp5;
			teacher[Now].SetID(temp1);
			teacher[Now].SetName(temp2);
			teacher[Now].SetBirth(temp3);
			teacher[Now].SetSex(temp4);
			teacher[Now].SetFund(temp5);
			cout << "��¼������" << endl << endl;
		}
	}
	else if (n == 3)//ɾ�����󣬲����õ�ǰԪ��
	{
		if (Type == 1)
		{
			student[Now].SetID(0);
			student[Now].SetName("");
			student[Now].SetBirth("");
			student[Now].SetSex("");
			student[Now].SetPoint(0);
			cout << "��¼ɾ���ɹ�" << endl << endl;
		}
		else if (Type == 2)
		{
			staff[Now].SetID(0);
			staff[Now].SetName("");
			staff[Now].SetBirth("");
			staff[Now].SetSex("");
			staff[Now].SetDept("");
			cout << "��¼ɾ���ɹ�" << endl << endl;
		}
		else if (Type == 3)
		{
			teacher[Now].SetID(0);
			teacher[Now].SetName("");
			teacher[Now].SetBirth("");
			teacher[Now].SetSex("");
			teacher[Now].SetFund(0);
			cout << "��¼ɾ���ɹ�" << endl << endl;
		}
	}
	else if (n == 4)//����һ��֤���ţ�������Ӧ��Ԫ�ء����ҵ����򽫸ýڵ���Ϊ��ǰԪ��
		{
			int found = 0, id = -1;
			cout << "������Ҫ��ѯ��ID�ţ�" << endl;
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
				cout << "û�������������Ϣ" << endl << endl;
		}
	else if (n == 5)//��ʾ���м�¼
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
			cout << "�Ѿ������������Ϣ" << endl;
		}
}

//������
int main()
{
	//int N, Now = 0, Type = 0; �Ѿ�����ȫ�����棬�չ˷���ֵ����
	while (1)
	{
		cout << "**************************************************************************" << endl;
		cout << "* 1.��ʾ��ǰԪ����Ϣ                 ";
		cout << "2.����һ��Ԫ��                      *" << endl;
		cout << "* 3.ɾ����ǰԪ�أ������õ�ǰԪ��     ";
		cout << "4.���Ҳ����ö���                    *" << endl;
		cout << "* 5.���������Ϣ                     ";
		cout << "0.�˳�                              *" << endl;
		cout << "**************************************************************************" << endl;
		cout << endl;

		cin >> N;
		if (N > 0 && N < 6)
			Deal(N);
		else if (N == 0)
			break;
		else
		{
			cout << "������벻��ȷ������������" << endl;
			cout << endl;
			continue;
		}
	}
}