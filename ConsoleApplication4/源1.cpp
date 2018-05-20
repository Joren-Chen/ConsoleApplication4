#include<iostream>
#include<string>
#include<Windows.h>
#include<conio.h>
using namespace std;
static char course[7][30] = { " ","高数","程序设计基础","大学英语","数字逻辑","大学写作","民族理论" };
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
	cout << "请输入学生姓名：";
	cin >> a;
	cout << "请输入密码：";
	cin >> b;
	p = new student(a, b);
	cout << "恭喜您注册成功，您的学号为：" << p->num << endl;
	cout << "请您谨记，这是您登陆的凭证，这很重要！！" << endl;
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
	cout << "按任意键回到主菜单！" << endl;
	_getch();
	mainMenu();
}
void student::delke(student *s)
{
	system("cls");
	cout << "********* 您现在正处于删课界面 *********" << endl;
	int Time = 4;
A:	cout << "您目前已选课情况为：" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << "." << course[s->knumber[i]] << endl;
	}
	cout << "请输入您要删除的课程序号：";
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
	cout << "删课成功。如需继续删除输入1，查询已选课程输入2，返回主菜单输入3。" << endl;
	int iiii;
	cin >> iiii;
	if (iiii == 1) goto A;
	if (iiii == 2) s->show(s);
	if (iiii == 3) s->smenu(s);
}
void student::smenu(student *s)//学生登陆界面
{
	system("cls");
	cout << "*********     登陆成功 " << s->name << " 同学    *********" << endl;
	cout << "********* 1.选课         *********" << endl;
	cout << "********* 2.查询选课结果 *********" << endl;
	cout << "********* 3.删除所选课程 *********" << endl;
	cout << "********* 4.修改密码     *********" << endl;
	cout << "********* 5.返回主界面   *********" << endl;
	cout << "********* 6.退出系统     *********" << endl;
	cout << "请输入操作序号：";
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
		cout << "请检查代码，重新输入!";
		Sleep(5000);
		s->smenu(s);
	}
}
void student::xuanke(student *s)
{
	system("cls");
	cout << "********* 您现在正处于选课界面 *********" << endl;
	cout << "当前的可选课程情况为：";
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
	A:		cout << "请输入您的第" << i + 1 << "个课程序号：";
		int b;
		cin >> b;
		for (int ii = 0; ii < i; ii++)
		{
			if (s->knumber[ii] == b)
			{
				cout << "您已经选过该课程，请重新输入" << endl;
				goto A;
			}
		}
		if (b > 7) { cout << "输入错误，请重新输入。" << endl; goto A; }
		else {
			s->knumber[i] = b;
			cout << "选课成功！" << endl;
		}
	}
	cout << "选课结束，5s后自动跳转至选课结果页面。" << endl;
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
	cout << "********* 您现在正处于查询界面 *********" << endl;
	cout << "您当前的选课情况为：" << endl;
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
		cout << "您目前尚有" << ii << "门课未选。" << endl;
	}
	cout << "按1返回学生菜单.按2前往选课，按3前往删课。" << endl;
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
	cout << "请输入学号：";
	string h;
	cin >> h;
	cout << "请输入密码：";
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
				cout << "您输入的账号或密码有误,3s后自动回到登陆界面。" << endl;
				for (int i = 0; i < 3; i++)
				{
					cout << i + 1;
					Sleep(1000);
				}
				slogin(s);
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
		system("cls");
		cout << "***************欢迎登录选课系统***************" << endl;
		cout << "**************您目前正处于学生端**************" << endl;
		cout << " ---------------  请选择功能  ---------------" << endl;
		cout << "                   1.登陆                   " << endl;
		cout << "                   2.注册                   " << endl;
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