#include<iostream>
#include<string>
#include<Windows.h>
#include<conio.h>
using namespace std;
static char course[7][30] = { " ","����","������ƻ���","��ѧӢ��","�����߼�","��ѧд��","��������" };
static int d[4] = { NULL,NULL,NULL,NULL };
void mainMenu();
static int Snum = 171100001;
class student
{
private:
	string name;
	string pas;
	int knumber[4];
	string num;
	student *next;
public:
	student() {};
	student(string name, string pass)
	{
		this->name = name;
		this->pas = pass;
		this->next = NULL;
		this->num = std::to_string(Snum++);
		for (int i = 0; i < 4; i++)
		{
			this->knumber[i] = d[i];
		}
	}
	void smenu(student *s);
	void xuanke(student *s);
	void show(student *s);
	friend class teacher;
	friend void sRg(student *&head);
	void slogin(student *&head);
	void gaimi()
	void delke(student *s);
}; student *head = NULL;
void sRg(student *&head)
{
	system("cls");
	student *p, *p1;
	string a, b;
	cout << "������ѧ��������";
	cin >> a;
	cout << "���������룺";
	cin >> b;
	p = new student(a, b);
	cout << "��ϲ��ע��ɹ�������ѧ��Ϊ��" << p->num << endl;
	cout << "�������ǣ���������½��ƾ֤�������Ҫ����" << endl;
	p->next = 0;
	if (head)
	{
		p1 = head;
		while (p1->next)
		{
			p1 = p1->next;
		}
		p1->next = p;
	}
	else
	{
		head = p;
	}
	cout << "��������ص����˵���" << endl;
	_getch();
	mainMenu();
}
void student::delke(student *s)
{
	system("cls");
	cout << "********* ������������ɾ�ν��� *********" << endl;
	int Time = 4;
A:	cout << "��Ŀǰ��ѡ�����Ϊ��" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << "." << course[s->knumber[i]] << endl;
	}
	cout << "��������Ҫɾ���Ŀγ���ţ�";
	int deln;
	cin >> deln;
	deln--;
	s->knumber[deln] = NULL;
	for (int i = deln; i < Time; i++)
	{
		s->knumber[i] = s->knumber[i + 1];
	}
	Time--;
	s->knumber[Time] = NULL;
	cout << endl;
	cout << "ɾ�γɹ����������ɾ������1����ѯ��ѡ�γ�����2���������˵�����3��" << endl;
	int iiii;
	cin >> iiii;
	if (iiii == 1) goto A;
	if (iiii == 2) s->show(s);
	if (iiii == 3) s->smenu(s);
}
void student::smenu(student *s)//ѧ����½����
{
	system("cls");
	cout << "*********     ��½�ɹ� " << s->name << " ͬѧ    *********" << endl;
	cout << "********* 1.ѡ��         *********" << endl;
	cout << "********* 2.��ѯѡ�ν�� *********" << endl;
	cout << "********* 3.ɾ����ѡ�γ� *********" << endl;
	cout << "********* 4.�޸�����     *********" << endl;
	cout << "********* 5.����������   *********" << endl;
	cout << "********* 6.�˳�ϵͳ     *********" << endl;
	cout << "�����������ţ�";
	int a;
	cin >> a;
	if (a == 1)
		s->xuanke(s);
	if (a == 2)
		s->show(s);
	if (a == 3)
		s->delke(s);
	//if (a == 4)
	//s->gaimi(s);
	if (a == 5)
	{
		mainMenu();
	}
	if (a == 6)
		exit(0);
	if (a > 6)
	{
		cout << "������룬��������!";
		Sleep(5000);
		s->smenu(s);
	}
}
void student::xuanke(student *s)
{
	system("cls");
	cout << "********* ������������ѡ�ν��� *********" << endl;
	cout << "��ǰ�Ŀ�ѡ�γ����Ϊ��";
	int aaa = 0;
	for (int i = 1; i < 7; i++)
	{
		for (int ii = 0; ii < 4; ii++)
		{
			if (i == s->knumber[ii]) continue;
		}
		cout << i << "." << course[i] << endl;
	}
	for (int i = 0; i < 4; i++)
	{
		if (s->knumber[i] == NULL)
		{
			aaa = i;
			break;
		}
	}
	for (int i = aaa; i < 4; i++)
	{
	A:		cout << "���������ĵ�" << i + 1 << "���γ���ţ�";
		int b;
		cin >> b;
		for (int ii = 0; ii < i; ii++)
		{
			if (s->knumber[ii] == b)
			{
				cout << "���Ѿ�ѡ���ÿγ̣�����������" << endl;
				goto A;
			}
		}
		if (b > 7) { cout << "����������������롣" << endl; goto A; }
		else {
			s->knumber[i] = b;
			cout << "ѡ�γɹ���" << endl;
		}
	}
	cout << "ѡ�ν�����5s���Զ���ת��ѡ�ν��ҳ�档" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1;
		Sleep(1000);
	}
	student::show(s);
}
void student::show(student *s)
{
	system("cls");
	cout << "********* �����������ڲ�ѯ���� *********" << endl;
	cout << "����ǰ��ѡ�����Ϊ��" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << "." << course[s->knumber[i]] << endl;
	}
	int ii = 0;
	for (int i = 0; i < 4; i++)
	{
		if (s->knumber[i] == NULL)
			ii++;
	}
	if (ii != 0)
	{
		cout << "��Ŀǰ����" << ii << "�ſ�δѡ��" << endl;
	}
	cout << "��1����ѧ���˵�.��2ǰ��ѡ�Σ���3ǰ��ɾ�Ρ�" << endl;
	int iii;
	cin >> iii;
	if (iii == 1) s->smenu(s);
	if (iii == 2) s->xuanke(s);
	if (iii == 3) s->delke(s);
}
void student::slogin(student *&head)
{
	student *s = head;
	system("cls");
	cout << "������ѧ�ţ�";
	string h;
	cin >> h;
	cout << "���������룺";
	string j;
	cin >> j;
	cout << endl;
	for (s = head; s; s = s->next)
	{
		if (s->num == h)
		{
			if (s->pas == j)
			{
				s->smenu(s);
			}
			else
			{
				cout << "��������˺Ż���������,3s���Զ��ص���½���档" << endl;
				for (int i = 0; i < 3; i++)
				{
					cout << i + 1;
					Sleep(1000);
				}
				slogin(s);
			}
		}
	}
	cout << "��������˺Ż���������" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1;
		Sleep(1000);
	}
	slogin(s);

}
void mainMenu()
{

	string c, d;
	system("cls");
	cout << "***************��ӭ��¼ѡ��ϵͳ***************" << endl;
	cout << "--------------- ��ѡ���¼�˿� ---------------" << endl;
	cout << "                   1.ѧ����                   " << endl;
	cout << "                   2.��ʦ��                   " << endl;
	int n;
	cin >> n;
	if (n == 1)
	{
		system("cls");
		cout << "***************��ӭ��¼ѡ��ϵͳ***************" << endl;
		cout << "**************��Ŀǰ������ѧ����**************" << endl;
		cout << " ---------------  ��ѡ����  ---------------" << endl;
		cout << "                   1.��½                   " << endl;
		cout << "                   2.ע��                   " << endl;
		int mm;
		cin >> mm;
		if (mm == 1) { head->slogin(head); }
		if (mm == 2) { sRg(head); }
	}
	if (n == 2)
	{
		//tlogin();
	}
	else
	{
		cout << "�������󣬰�0�˳�����9���µ�¼��" << endl;
		int m;
		cin >> m;
		if (m == 9)
		{
			mainMenu();
		}
		else
		{
			exit(0);
		}
	}

}
int main()
{
	//t.password = 666666;
	mainMenu();
}