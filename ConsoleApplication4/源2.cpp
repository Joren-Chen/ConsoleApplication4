/*#include<iostream>
#include<string>
#include<cstring>
using namespace std;
struct student
{
	int id;
	char password[20];
	char people[20];
	char clsses[6][30];
	student *next;
};
struct course
{
	int kechenghao;
	char micheng[20];
	char jiaoshi[20];
	course *r;
};
void show(student * head);
int denglu(student *head, int id);
void personal(student *head);
void shanchu(student *&head);
void shanchu_(course *&m);
void add(course *&m);
void x(student *&, course *);
void all_course(course *m);
void stu_personal(student *head, int id);
void serect(student *&head, int id);
void add_student(student *&head);
void xuanke(student *&head, course *m, int id);
void course_show(student *head, int id);
void change_s(student *&head);
void change_c(course *&m);
void menu();
int main()
{
	student *head = new student, *p = new student, *q = new student, *s = new student;
	course *m = new course, *n = new course, *a = new course, *d = new course;
	int i, code = 0, choose = 0, id;
	m->kechenghao = 1; strcpy_s(m->jiaoshi, "zhangsan"), strcpy_s(m->micheng, "c++"); m
		->r = n;
	n->kechenghao = 2; strcpy_s(n->jiaoshi, "lisi"), strcpy_s(n->micheng, "大学英语"); n->r = a;
	a->kechenghao = 3; strcpy_s(a->jiaoshi, "wangwu"), strcpy_s(a->micheng, "高 等 数 学 "); a
		->r = d;
	d->kechenghao = 4; strcpy_s(d->jiaoshi, "xuliu"), strcpy_s(d->micheng, "数 字 逻 辑 "); d
		->r = NULL;
	head->id = 1; strcpy_s(head->password, "2233"); strcpy_s(head->people, "wang");
	for (i = 0; i<6; i++)
	{
		strcpy_s(head->clsses[i], "");
	}
	head->next = p;
	p->id = 2; strcpy_s(p->password, "1122"); strcpy_s(p->people, "zhang");
	for (i = 0; i<6; i++)
	{
		strcpy_s(p->clsses[i], "");
	}
	p->next = q;
	q->id = 3; strcpy_s(q->password, "5566"); strcpy_s(q->people, "peng");
	for (i = 0; i<6; i++)
	{
		strcpy_s(q->clsses[i], "");
	}
	q->next = s;
	s->id = 4; strcpy_s(s->password, "8899"); strcpy_s(s->people, "dong");
	for (i = 0; i<6; i++)
	{
		strcpy_s(s->clsses[i], "");
	}
	s->next = NULL;
	x(head, m);
}
void show(student *head)
{
	student *p;
	p = head;
	while (p)
	{
		cout << p->id << " " << p->people << " " << endl;
		p = p->next;
	}
}
void menu()
{
	cout << "|-----------------------------------|" << endl;
	cout << "| 学生管理系统： |" << endl;
	cout << "|-----------------------------------|" << endl;
	cout << "| |" << endl;
	cout << "| 0：退出系统 |" << endl;
	cout << "| 1：查询具体学生信息 |" << endl;
	cout << "| 2：查询全部学生信息 |" << endl;
	cout << "| 3：查看全部课程信息 |" << endl;
	cout << "| 4：增加课程 |" << endl;
	cout << "| 5：增加学生 |" << endl;
	cout << "| 6：删除学生 |" << endl;
	cout << "| 7：删除课程 |" << endl;
	cout << "| 8：修改学生信息 |" << endl;
	cout << "| 9：修改课程信息 |" << endl;
	cout << "| |" << endl;
	cout << "-------------------------------------" << endl;
}
void x(student *&head, course *m)
{
	int i, code = 0, choose = 0, id, n;
	cout << "*********************************" << endl;
	cout << " " << endl;
	cout << " 内蒙古大学教务系统登录窗口 " << endl;
	cout << " " << endl;
	cout << "*********************************" << endl;
	cout << " 请输入你的职工号或学号" << endl;
	cin >> id;
	code = denglu(head, id);
	system("cls");
	if (code == 1)
	{
		menu();
		cout << " 请输入具体操作 " << endl;
		while (cin >> choose)
		{
			if (choose == 0)
				break;
			else if (choose == 1)
				personal(head);
			else if (choose == 2)
				show(head);
			else if (choose == 3)
				all_course(m);
			else if (choose == 4)
				add(m);
			else if (choose == 5)
				add_student(head);
			else if (choose == 6)
				shanchu(head);
			else if (choose == 7)
				shanchu_(m);
			else if (choose == 8)
			{
				change_s(head);
				system("cls");
			}
			else if (choose == 9)
			{
				change_c(m);
				system("cls");
			}
			menu();
		}
	}
	else if (code == 2)
	{
		cout << "|-----------------------------------|" << endl;
		cout << "| 学生系统： |" << endl;
		cout << "|-----------------------------------|" << endl;
		cout << "| |" << endl;
		cout << "| 0：退出系统 |" << endl;
		cout << "| 1：查询学籍信息 |" << endl;
		cout << "| 2：查看全部课程信息 |" << endl;
		cout << "| 3：选课 |" << endl;
		cout << "| 4：选课状态查询 |" << endl;
		cout << "| 5：修改密码 |" << endl;
		cout << "| |" << endl;
		cout << "-------------------------------------" << endl;
		cout << " 请输入具体操作 " << endl;
		while (cin >> choose)
		{
			if (choose == 0)
				break;
			else if (choose == 1)
				stu_personal(head, id);
			else if (choose == 2)
				all_course(m);
			else if (choose == 3)
				xuanke(head, m, id);
			else if (choose == 4)
				course_show(head, id);
			else if (choose == 5)
				serect(head, id);
			cout << "注销输入 0" << endl;
		}
	}
	system("cls");
	cout << "退出请输入 0，登录新的账号请输入 8" << endl;
	while (cin >> n)
	{
		if (n == 0)
			break;
		else if (n == 8)
			system("cls");
		x(head, m);
	}
}
int denglu(student *head, int id)
{
	student *p = new student;
	string usercode;
	cout << " 请输入你的密码 " << endl;
	cin >> usercode;
	if (id>20 && usercode == "jiaoshi")
	{
		cout << "老师，您好！欢迎登陆内大教务系统！" << endl;
		return 1;
	}
	for (p = head; p; p = p->next)
	{
		if (id == p->id&&usercode == p->password)
		{
			cout << "你好" << p->people << "！欢迎光临内大教务系统！" << endl;
			return 2;
		}
	}
	if (p == NULL)
	{
		cout << "用户名或密码有误！" << endl << "请确认后重新输入用户名和密码
			"<<endl;
			cout << endl;
		cout << " 请输入你的职工号或学号 " << endl;
		cin >> id;
		return denglu(head, id);
	}
}
void shanchu(student *&head)
{
	system("cls");
	int num;
	cout << " 请输入所要删除学生的学号 " << endl;
	cin >> num;
	student *p = NULL, *q;
	if (num == head->id)
	{
		p = head;
		head = head->next;
		delete p;
	}
	else
	{
		for (q = head, p = q->next; p; q = p, p = p->next)
		{
			if (num == p->id)
			{
				q->next = p->next;
				delete p;
				break;
			}
		}
	}
	cout << " 该学生已从系统中删除 " << endl;
}
void personal(student *head)
{
	int id, i;
	student *p = NULL, *q = NULL;
	cout << "请输入学生学号：" << endl;
	cin >> id;
	for (p = head; p; p = p->next)
	{
		if (p->id == id)
		{
			cout << p->people << "具体信息如下：" << endl;
			cout << p->id << " " << endl << p->people << "已选课程： " << endl;
			for (i = 0; i<6; i++)
				cout << p->clsses[i] << endl;
			cout << endl;
			break;
		}
	}
}
void add(course *&m)
{
	system("cls");
	course *w = new course, *p = NULL;
	int kechenghao;
	char a[20];
	char b[20];
	cout << "----请输入你所要添加的课程信息----" << endl;
	cout << "输入添加课程的课程号" << endl;
	cin >> kechenghao;
	cout << "输入添加课程的任课教师的名字" << endl;
	cin >> a;
	cout << "输入添加课程的名称" << endl;
	cin >> b;
	w->kechenghao = kechenghao;
	strcpy_s(w->micheng, b);
	strcpy_s(w->jiaoshi, a);
	for (p = m; p->r; p = p->r);
	if (p->r == NULL)
		p->r = w;
	w->r = NULL;
}
void all_course(course *m)
{
	system("cls");
	course *p;
	p = m;
	while (p)
	{
		cout << "课程号：" << p->kechenghao << " " << "任课教师名称：" << p->jiaoshi << " " << "
			课程名称："<<" "<<p->micheng<<endl;
			p = p->r;
	}
}
void stu_personal(student *head, int id)
{
	student *p;
	for (p = head; p; p = p->next)
	{
		if (p->id == id)
		{
			cout << p->people << " " << p->id << " ";
			break;
		}
	}
}
void serect(student *&head, int id)
{
	system("cls");
	student *p;
	char name[20];
	char name1[20];
	cout << "请您输入新的密码" << endl;
	cin >> name;
	cout << "请再次输入新密码" << endl;
	cin >> name1;
	if (strcmp(name, name1) == 0)
	{
		for (p = head; p; p = p->next)
		{
			if (p->id == id)
			{
				strcpy(p->password, name);
				cout << "修改成功" << endl;
				break;
			}
		}
	}
	else
	{
		cout << "您两次输入的新密码有误，请您重新输入" << endl;
		serect(head, id);
	}
}
void add_student(student *&head)
{
	system("cls");
	student *w = new student, *p = NULL;
	int id, i;
	char people[20];
	char passworld[20];
	cout << "----请输入你所要添加的学生信息----" << endl;
	cout << "输入添加学生的学号" << endl;
	cin >> id;
	cout << "输入添加课程的学生的名字" << endl;
	cin >> people;
	cout << "输入添加学生的初始密码" << endl;
	cin >> passworld;
	w->id = id;
	strcpy_s(w->people, people);
	strcpy_s(w->password, passworld);
	for (i = 0; i<6; i++)
	{
		strcpy_s(w->clsses[i], "");
	}
	for (p = head; p->next; p = p->next);
	if (p->next == NULL)
		p->next = w;
	w->next = NULL;
}
void xuanke(student *&head, course *m, int id)
{
	system("cls");
	student *p;
	course *s;
	cout << "所有课程信息如下" << endl;
	all_course(m);
	int n = 0, b = 0, l = 0, h = 0, d = 0, y = 0, i, kechenghao;
	cout << "请输入你所要选的课程的课程号" << endl;
	cout << "退出选课请输入 0" << endl;
	while (cin >> kechenghao)
	{
		if (kechenghao == 0)
			break;
		else if (kechenghao == 1)
		{
			if (n == 1)
				cout << "不能重复选课" << endl;
			else
			{
				for (p = head; p; p = p->next)
					for (s = m; s; s = s->r)
					{
						if (p->id == id && s->kechenghao == kechenghao)
						{
							strcpy(p->clsses[0], s->micheng);
							n++;
							cout << "选课成功" << endl;
							cout << "退出选课请输入 0" << endl;
							break;
						}
					}
			}
		}
		else if (kechenghao == 2)
		{
			if (h == 1)
				cout << "不能重复选课" << endl;
			else
			{
				for (p = head; p; p = p->next)
					for (s = m; s; s = s->r)
					{
						if (p->id == id && s->kechenghao == kechenghao)
						{
							strcpy(p->clsses[1], s->micheng);
							h++;
							cout << "选课成功" << endl;
							cout << "退出选课请输入 0" << endl;
							break;
						}
					}
			}
		}
		else if (kechenghao == 3)
		{
			if (b == 1)
				cout << "不能重复选课" << endl;
			else
			{
				for (p = head; p; p = p->next)
					for (s = m; s; s = s->r)
					{
						if (p->id == id && s->kechenghao == kechenghao)
						{
							strcpy(p->clsses[2], s->micheng);
							b++;
							cout << "选课成功" << endl;
							cout << "退出选课请输入 0" << endl;
							break;
						}
					}
			}
		}
		else if (kechenghao == 4)
		{
			if (l == 1)
				cout << "不能重复选课" << endl;
			else
			{
				for (p = head; p; p = p->next)
					for (s = m; s; s = s->r)
					{
						if (p->id == id && s->kechenghao == kechenghao)
						{
							strcpy(p->clsses[3], s->micheng);
							l++;
							cout << "选课成功" << endl;
							cout << "退出选课请输入 0" << endl;
							break;
						}
					}
			}
		}
		else
			cout << "输入错误请重新选课" << endl;
	}
}
void course_show(student *head, int id)
{
	system("cls");
	student *p;
	for (p = head; p; p = p->next)
	{
		if (p->id == id)
		{
			cout << "姓名：" << p->people << " " << "学号：" << p->id << endl;
			cout << "已选课程如下" << endl;
			for (int i = 0; i<6; i++)
				cout << p->clsses[i] << endl;
			break;
		}
	}
}
void shanchu_(course *&m)
{
	system("cls");
	int num;
	cout << " 请输入所要删除课程的课程号课程号 " << endl;
	cin >> num;
	course *p = NULL, *q;
	if (num == m->kechenghao)
	{
		p = m;
		m = m->r;
		delete p;
	}
	else
	{
		for (q = m, p = q->r; p; q = p, p = p->r)
		{
			if (num == p->kechenghao)
			{
				q->r = p->r;
				delete p;
				break;
			}
		}
	}
	cout << " 该课程已从系统中删除 " << endl;
}
void change_s(student *&head)
{
	system("cls");
	student *p;
	int choose = 0, id, s;
	char name[20];
	cout << " 1:修改学生学号 " << endl;
	cout << " 2:修改学生姓名 " << endl;
	cout << " 0:退出 " << endl;
	cout << " 请输入具体操作 " << endl;
	while (cin >> choose)
	{
		if (choose == 0)
			break;
		else if (choose == 1)
		{
			cout << "输入所要修改的学生的学号" << endl;
			cin >> s;
			for (p = head; p; p = p->next)
			{
				if (p->id == s)
				{
					cout << "请输入学生的新的学号" << endl;
					cin >> id;
					p->id = id;
					cout << "修改成功" << endl;
					cout << "退出输入 0" << endl;
					break;
				}
			}
		}
		else if (choose == 2)
		{
			cout << "请输入所要修改的学生的学号" << endl;
			cin >> id;
			for (p = head; p; p = p->next)
			{
				if (p->id == id)
				{
					cout << "请输入学生的新的姓名" << endl;
					cin >> name;
					strcpy(p->password, name);
					cout << "修改成功" << endl;
					cout << "退出输入 0" << endl;
					break;
				}
			}
		}
	}
}
void change_c(course*&m)
{
	system("cls");
	course *p;
	int choose = 0, id, s;
	char name[20];
	cout << " 1：修改课程号 " << endl;
	cout << " 2：修改任课教师名称 " << endl;
	cout << " 3：修改课程名称 " << endl;
	cout << " 0：退出 " << endl;
	cout << " 请输入具体操作 " << endl;
	while (cin >> choose)
	{
		if (choose == 0)
			break;
		else if (choose == 1)
		{
			cout << "请输入所要修改的课程的课程号" << endl;
			cin >> s;
			for (p = m; p; p = p->r)
			{
				if (p->kechenghao == s)
				{
					cout << "请输入学生的新的课程号" << endl;
					cin >> id;
					p->kechenghao = id;
					cout << "修改成功" << endl;
					cout << "退出输入 0" << endl;
					break;
				}
			}
		}
		else if (choose == 2)
		{
			cout << "请输入所要修改的课程的课程号" << endl;
			cin >> s;
			cout << "请输入学生的新的任课教师" << endl;
			cin >> name;
			for (p = m; p; p = p->r)
			{
				if (p->kechenghao == s)
				{
					cout << "请输入学生的新的任课教师" << endl;
					cin >> name;
					strcpy(p->jiaoshi, name);
					cout << "修改成功" << endl;
					cout << "退出输入 0" << endl;
					break;
				}
			}
		}
		else if (choose == 3)
		{
			cout << "请输入所要修改的课程的课程号" << endl;
			cin >> id;
			cout << "请输入学生的新的课程名称" << endl;
			cin >> name;
			for (p = m; p; p = p->r)
			{
				if (p->kechenghao == id)
				{
					cout << "请输入学生的新的课程名称" << endl;
					cin >> name;
					strcpy(p->micheng, name);
					cout << "修改成功" << endl;
					cout << "退出输入 0" << endl;
					break;
				}
			}
		}
	}
}*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Person
{
	char Name[20];
	string pass[10];
	Person *next;
public:
	Person(char *Name, string pass[])
	{
		strcpy_s(this->Name, Name);
		int i;
		for (i = 0; i<10; i++) {
			this->pass[i] = pass[i];
		}
		next = NULL;
	}
	friend class teacher;
};
class teacher
{
private:
	Person * person;
	string id[3];
public:
	teacher()
	{
		person = NULL;
	}
	bool manage(string[3]);
	void Add();
	void Save();
	void show();
	void Cin();
};
void teacher::Cin()
{
	int i = 0;
	cin >> id[0] >> id[1];
	id[2] = "";
	char ch;
	cin >> id[2][0];
}
bool teacher::manage(string id[3])
{
	if (id[1] == this->id[1] && id[2] == this->id[2])
		return 1;
	else return 1;
}
void teacher::Add()
{
	Person *p, *p2; //新结点指针 
	string  pass[10] = { " "," "," "," "," "," "," "," "," "," " };
	string clas[8] = { " 高等数学 ","  程序设计基础  ","  小学英语  "," 数字逻辑  "," 大学体育  ","" ,"","" };
	char Name[20];
	int n;
	cout << "\n请输入信息 \n";
	cout << "输入学号:\t";
	cin >> pass[0];
	cout << "输入姓名:\t";
	cin >> Name;
	cout << endl;
	cout << "请输入密码";
	cin >> pass[1];
	cout << "请选课			" << endl << "0:高等数学   1：程序设计基础   2：小学英语  3：数字逻辑 4：大学体育  1024:退出 " << endl;
	while (cin >> n && n != 1024)
	{
		if (n < 8 && n >= 0)
		{
			pass[n + 2] = clas[n];
			cout << clas[n] << "选课成功 请继续" << endl;
		}
		else
			cout << "输入错误 请重新输入";
	}
	cout << "1 退课 2  退出";
	int ss;
	cin >> ss;
	if (ss == 1)
	{
		cout << "请退课			" << endl << "0:高等数学   1：程序设计基础   2：小学英语  3：数字逻辑 4：大学体育  1024:退出 " << endl;
		while (cin >> n && n != 1024)
		{
			if (n < 8 && n >= 0)
			{
				pass[n + 2] = "  ";
				cout << clas[n] << "退课成功 请继续" << endl;
			}
			else
				cout << "输入错误 请重新输入";
		}
	}
	p = new Person(Name, pass);
	p->next = 0;
	if (person)
	{
		p2 = person;
		while (p2->next)
		{
			p2 = p2->next;
		}
		p2->next = p;
	}
	else
	{
		person = p;
	}
}
void teacher::Save()
{
	ofstream oPerson;
	oPerson.open("Person.txt", ios::out);
	Person *p = person;
	while (p)
	{
		oPerson << p->pass[0] << " " << p->Name << " " << " " << p->pass[1] << " " << p->pass[2] << " " << p->pass[3] << " " << p->pass[4] << " " << p->pass[5] << " " << p->pass[6] << " " << p->pass[7] << " " << p->pass[8] << " " << p->pass[9];
		p = p->next;
	}
	oPerson.close();
}
void teacher::show()
{
	ifstream iPerson;
	iPerson.open("Person.txt", ios::in);
	Person *p = person;
	while (p)
	{
		iPerson >> p->pass[0] >> p->Name >> p->pass[1] >> p->pass[2] >> p->pass[3] >> p->pass[4] >> p->pass[5] >> p->pass[6] >> p->pass[7] >> p->pass[8] >> p->pass[9];
		cout << p->pass[0] << " " << p->Name << " " << p->pass[2] << " " << p->pass[3] << " " << p->pass[4] << " " << p->pass[5] << " " << p->pass[6] << " " << p->pass[7] << " " << p->pass[8] << " " << p->pass[9];
		p = p->next;
		cout << endl;
	}
	iPerson.close();
}
int main()
{
	teacher m;
	while (1)
	{
		int  shen;
		cout << " 1 学生 0 管理者 " << endl;
		cin >> shen;
		if (shen)
		{
			m.Add();
			cout << "选课完成 ";
			m.Save();
		}
		else
		{
		aa:
			string IDd[3];
			IDd[2] = "";

			cout << "请输入您的姓名  工号  密码";
			cin >> IDd[0] >> IDd[1] >> IDd[2];
			if (m.manage(IDd))
			{
				cout << "请选择服务        1 ：查询学生选课情况";
				int chos;
				cin >> chos;
				if (chos == 1)
				{
					m.show();
				}
			}
			else
			{
			c:
				cout << "密码错误 请重试 输入1 重新登录  输入1024退出";
				int  n;
				cin >> n;
				if (n == 1)
					goto aa;
				else if (n == 1024)
					goto en;
				else cout << "指令错误 请重新输入";
				goto c;
			}
		en:
			cout << endl << endl;
		}
	}
}
