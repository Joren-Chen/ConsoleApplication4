#include<iostream>
#include<string>
#include<Windows.h>
#include<conio.h>
using namespace std;
static char course[6][30] = { "����","������ƻ���","��ѧӢ��","�����߼�","��ѧд��","��������" };
static int d[4] = { NULL,NULL,NULL,NULL };
void mainMenu();
class student
{
private:
	string name;
	string pas;
	student *next;
	int knumber[4];
	string num;
public:
	student() {};
	student(string a, string b, string c);
	void smenu(student *s);
	void xuanke(student *s);
	void show(student *s);
	friend void sRegister(student *head);//finsh
	friend void slogin(student *s);
	friend void mainMenu();
};
static int snum = 171100000;
student::student(string a, string b, string c)
{
	this->name = a;
	this->num = b;
	this->pas = c;
	for (int i = 0; i < 4; i++)
	{
		this->knumber[i] = d[i];
	}
	this->next = NULL;
};
void sRegister(student *head)//��ע��ѧ����
{
	student *s;
	student *p=head;
	student *q;
	s = new student;
	cout << "����ѧ��������";
	string a, b, c;
	cin >> a;
	cout << endl;
	s->name = a;
	snum++;
	s->num = std::to_string(snum);
	cout << "����ѧ�����룺";
	cin >> b;
	cout << endl;
	s->pas = b;
	cout << "ѧ��ѧ��Ϊ��" << s->num << endl;
	s->next = NULL;
	if (head == NULL)
	{
		head = s;
	}
	else
	{
		while (p = NULL)
		{
			q = p;
			p = p->next;
		}
		q->next = s;
	}
	cout << "ע��ɹ����������������档";
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1;
		Sleep(1000);
	}
	mainMenu();
}
void student::smenu(student *s)//ѧ����½����
{
	system("cls");
	cout << "*********     ��½�ɹ�   *********" << endl;
	cout << "********* 1.ѡ��         *********" << endl;
	cout << "********* 2.��ѯѡ�ν�� *********" << endl;
	cout << "********* 3.����������   *********" << endl;
	cout << "********* 4.�˳�ϵͳ     *********" << endl;
	cout << "�����������ţ�";
	int a;
	cin >> a;
	if (a == 1)
		s->xuanke(s);
	if (a == 2)
		s->show(s);
	if (a == 3)
		mainMenu();
	if (a == 4)
		exit(0);
	if (a > 5)
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
	for (int i = 0; i < 6; i++)
	{
		cout << i + 1 << "." << course[i] << endl;
	}
	for (int i = 0; i < 4; i++)
	{
	A:cout << "���������ĵ�" << i + 1 << "���γ���ţ�";
		int b;
		cin >> b;
		for (int ii = 0; ii < i; ii++)
		{
			if (s->knumber[ii] == b - 1)
			{
				cout << "���Ѿ�ѡ���ÿγ̣�����������" << endl;
				goto A;
			}
		}
		if (b > 6) { cout << "����������������롣" << endl; goto A; }
		else {
			b--;
			s->knumber[i] = b;
			cout << "ѡ�γɹ���" << endl;
		}
	}
	cout << "ѡ�ν����������Զ���ת��ѡ�ν��ҳ�档";
	Sleep(5000);
	student::show(s);
}
void student::show(student *s)
{
	cout << "����ǰ��ѡ�����Ϊ��" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << "." << course[s->knumber[i]] << endl;
	}
	Sleep(2000);
	cout << "����������������档";
	_getch();
	smenu(s);
}
void slogin(student *s)
{
	system("cls");
	cout << "������ѧ�ţ�";
	string h;
	cin >> h;
	cout << "���������룺";
	string j;
	cin >> j;
	cout << endl;
	student *head = NULL;
	for(s=head;s;s=s->next)
	{
		if (s->num == h)
		{
			if (s->pas == j)
			{
				s->smenu(s);
			}
			else {
				cout << "��������˺Ż���������" << endl; Sleep(3000); slogin(s);
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
	student *head = NULL;
	student *p = NULL;
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
		cout << "                   1.��½                   " << endl;
		cout << "                   2.ע��                   " << endl;
		int mm;
		cin >> mm;
		if (mm == 1) { slogin(p); }
		if (mm == 2) { sRegister(head); }
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