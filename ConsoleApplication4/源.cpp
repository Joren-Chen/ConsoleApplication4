#include<iostream>
#include<string>
#include<Windows.h>
#include<conio.h>
using namespace std;
static char course[6][30] = { "高数","程序设计基础","大学英语","数字逻辑","大学写作","民族理论" };
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
void sRegister(student *head)//（注册学生）
{
	student *s;
	student *p=head;
	student *q;
	s = new student;
	cout << "输入学生姓名：";
	string a, b, c;
	cin >> a;
	cout << endl;
	s->name = a;
	snum++;
	s->num = std::to_string(snum);
	cout << "输入学生密码：";
	cin >> b;
	cout << endl;
	s->pas = b;
	cout << "学生学号为：" << s->num << endl;
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
	cout << "注册成功，即将返回主界面。";
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1;
		Sleep(1000);
	}
	mainMenu();
}
void student::smenu(student *s)//学生登陆界面
{
	system("cls");
	cout << "*********     登陆成功   *********" << endl;
	cout << "********* 1.选课         *********" << endl;
	cout << "********* 2.查询选课结果 *********" << endl;
	cout << "********* 3.返回主界面   *********" << endl;
	cout << "********* 4.退出系统     *********" << endl;
	cout << "请输入操作序号：";
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
		cout << "请检查代码，重新输入!";
		Sleep(5000);
		s->smenu(s);
	}
}
void student::xuanke(student *s)
{
	system("cls");
	cout << "********* 您现在正处于选课界面 *********" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << i + 1 << "." << course[i] << endl;
	}
	for (int i = 0; i < 4; i++)
	{
	A:cout << "请输入您的第" << i + 1 << "个课程序号：";
		int b;
		cin >> b;
		for (int ii = 0; ii < i; ii++)
		{
			if (s->knumber[ii] == b - 1)
			{
				cout << "您已经选过该课程，请重新输入" << endl;
				goto A;
			}
		}
		if (b > 6) { cout << "输入错误，请重新输入。" << endl; goto A; }
		else {
			b--;
			s->knumber[i] = b;
			cout << "选课成功！" << endl;
		}
	}
	cout << "选课结束，即将自动跳转至选课结果页面。";
	Sleep(5000);
	student::show(s);
}
void student::show(student *s)
{
	cout << "您当前的选课情况为：" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << "." << course[s->knumber[i]] << endl;
	}
	Sleep(2000);
	cout << "按任意键返回主界面。";
	_getch();
	smenu(s);
}
void slogin(student *s)
{
	system("cls");
	cout << "请输入学号：";
	string h;
	cin >> h;
	cout << "请输入密码：";
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
				cout << "您输入的账号或密码有误。" << endl; Sleep(3000); slogin(s);
			}
		}
	}
	cout << "您输入的账号或密码有误" << endl;
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
	cout << "***************欢迎登录选课系统***************" << endl;
	cout << "--------------- 请选择登录端口 ---------------" << endl;
	cout << "                   1.学生端                   " << endl;
	cout << "                   2.教师端                   " << endl;
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << "                   1.登陆                   " << endl;
		cout << "                   2.注册                   " << endl;
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
		cout << "输入有误，按0退出，按9重新登录：" << endl;
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