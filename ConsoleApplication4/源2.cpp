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
	n->kechenghao = 2; strcpy_s(n->jiaoshi, "lisi"), strcpy_s(n->micheng, "��ѧӢ��"); n->r = a;
	a->kechenghao = 3; strcpy_s(a->jiaoshi, "wangwu"), strcpy_s(a->micheng, "�� �� �� ѧ "); a
		->r = d;
	d->kechenghao = 4; strcpy_s(d->jiaoshi, "xuliu"), strcpy_s(d->micheng, "�� �� �� �� "); d
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
	cout << "| ѧ������ϵͳ�� |" << endl;
	cout << "|-----------------------------------|" << endl;
	cout << "| |" << endl;
	cout << "| 0���˳�ϵͳ |" << endl;
	cout << "| 1����ѯ����ѧ����Ϣ |" << endl;
	cout << "| 2����ѯȫ��ѧ����Ϣ |" << endl;
	cout << "| 3���鿴ȫ���γ���Ϣ |" << endl;
	cout << "| 4�����ӿγ� |" << endl;
	cout << "| 5������ѧ�� |" << endl;
	cout << "| 6��ɾ��ѧ�� |" << endl;
	cout << "| 7��ɾ���γ� |" << endl;
	cout << "| 8���޸�ѧ����Ϣ |" << endl;
	cout << "| 9���޸Ŀγ���Ϣ |" << endl;
	cout << "| |" << endl;
	cout << "-------------------------------------" << endl;
}
void x(student *&head, course *m)
{
	int i, code = 0, choose = 0, id, n;
	cout << "*********************************" << endl;
	cout << " " << endl;
	cout << " ���ɹŴ�ѧ����ϵͳ��¼���� " << endl;
	cout << " " << endl;
	cout << "*********************************" << endl;
	cout << " ���������ְ���Ż�ѧ��" << endl;
	cin >> id;
	code = denglu(head, id);
	system("cls");
	if (code == 1)
	{
		menu();
		cout << " ������������ " << endl;
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
		cout << "| ѧ��ϵͳ�� |" << endl;
		cout << "|-----------------------------------|" << endl;
		cout << "| |" << endl;
		cout << "| 0���˳�ϵͳ |" << endl;
		cout << "| 1����ѯѧ����Ϣ |" << endl;
		cout << "| 2���鿴ȫ���γ���Ϣ |" << endl;
		cout << "| 3��ѡ�� |" << endl;
		cout << "| 4��ѡ��״̬��ѯ |" << endl;
		cout << "| 5���޸����� |" << endl;
		cout << "| |" << endl;
		cout << "-------------------------------------" << endl;
		cout << " ������������ " << endl;
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
			cout << "ע������ 0" << endl;
		}
	}
	system("cls");
	cout << "�˳������� 0����¼�µ��˺������� 8" << endl;
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
	cout << " ������������� " << endl;
	cin >> usercode;
	if (id>20 && usercode == "jiaoshi")
	{
		cout << "��ʦ�����ã���ӭ��½�ڴ����ϵͳ��" << endl;
		return 1;
	}
	for (p = head; p; p = p->next)
	{
		if (id == p->id&&usercode == p->password)
		{
			cout << "���" << p->people << "����ӭ�����ڴ����ϵͳ��" << endl;
			return 2;
		}
	}
	if (p == NULL)
	{
		cout << "�û�������������" << endl << "��ȷ�Ϻ����������û���������
			"<<endl;
			cout << endl;
		cout << " ���������ְ���Ż�ѧ�� " << endl;
		cin >> id;
		return denglu(head, id);
	}
}
void shanchu(student *&head)
{
	system("cls");
	int num;
	cout << " ��������Ҫɾ��ѧ����ѧ�� " << endl;
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
	cout << " ��ѧ���Ѵ�ϵͳ��ɾ�� " << endl;
}
void personal(student *head)
{
	int id, i;
	student *p = NULL, *q = NULL;
	cout << "������ѧ��ѧ�ţ�" << endl;
	cin >> id;
	for (p = head; p; p = p->next)
	{
		if (p->id == id)
		{
			cout << p->people << "������Ϣ���£�" << endl;
			cout << p->id << " " << endl << p->people << "��ѡ�γ̣� " << endl;
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
	cout << "----����������Ҫ��ӵĿγ���Ϣ----" << endl;
	cout << "������ӿγ̵Ŀγ̺�" << endl;
	cin >> kechenghao;
	cout << "������ӿγ̵��ον�ʦ������" << endl;
	cin >> a;
	cout << "������ӿγ̵�����" << endl;
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
		cout << "�γ̺ţ�" << p->kechenghao << " " << "�ον�ʦ���ƣ�" << p->jiaoshi << " " << "
			�γ����ƣ�"<<" "<<p->micheng<<endl;
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
	cout << "���������µ�����" << endl;
	cin >> name;
	cout << "���ٴ�����������" << endl;
	cin >> name1;
	if (strcmp(name, name1) == 0)
	{
		for (p = head; p; p = p->next)
		{
			if (p->id == id)
			{
				strcpy(p->password, name);
				cout << "�޸ĳɹ�" << endl;
				break;
			}
		}
	}
	else
	{
		cout << "���������������������������������" << endl;
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
	cout << "----����������Ҫ��ӵ�ѧ����Ϣ----" << endl;
	cout << "�������ѧ����ѧ��" << endl;
	cin >> id;
	cout << "������ӿγ̵�ѧ��������" << endl;
	cin >> people;
	cout << "�������ѧ���ĳ�ʼ����" << endl;
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
	cout << "���пγ���Ϣ����" << endl;
	all_course(m);
	int n = 0, b = 0, l = 0, h = 0, d = 0, y = 0, i, kechenghao;
	cout << "����������Ҫѡ�Ŀγ̵Ŀγ̺�" << endl;
	cout << "�˳�ѡ�������� 0" << endl;
	while (cin >> kechenghao)
	{
		if (kechenghao == 0)
			break;
		else if (kechenghao == 1)
		{
			if (n == 1)
				cout << "�����ظ�ѡ��" << endl;
			else
			{
				for (p = head; p; p = p->next)
					for (s = m; s; s = s->r)
					{
						if (p->id == id && s->kechenghao == kechenghao)
						{
							strcpy(p->clsses[0], s->micheng);
							n++;
							cout << "ѡ�γɹ�" << endl;
							cout << "�˳�ѡ�������� 0" << endl;
							break;
						}
					}
			}
		}
		else if (kechenghao == 2)
		{
			if (h == 1)
				cout << "�����ظ�ѡ��" << endl;
			else
			{
				for (p = head; p; p = p->next)
					for (s = m; s; s = s->r)
					{
						if (p->id == id && s->kechenghao == kechenghao)
						{
							strcpy(p->clsses[1], s->micheng);
							h++;
							cout << "ѡ�γɹ�" << endl;
							cout << "�˳�ѡ�������� 0" << endl;
							break;
						}
					}
			}
		}
		else if (kechenghao == 3)
		{
			if (b == 1)
				cout << "�����ظ�ѡ��" << endl;
			else
			{
				for (p = head; p; p = p->next)
					for (s = m; s; s = s->r)
					{
						if (p->id == id && s->kechenghao == kechenghao)
						{
							strcpy(p->clsses[2], s->micheng);
							b++;
							cout << "ѡ�γɹ�" << endl;
							cout << "�˳�ѡ�������� 0" << endl;
							break;
						}
					}
			}
		}
		else if (kechenghao == 4)
		{
			if (l == 1)
				cout << "�����ظ�ѡ��" << endl;
			else
			{
				for (p = head; p; p = p->next)
					for (s = m; s; s = s->r)
					{
						if (p->id == id && s->kechenghao == kechenghao)
						{
							strcpy(p->clsses[3], s->micheng);
							l++;
							cout << "ѡ�γɹ�" << endl;
							cout << "�˳�ѡ�������� 0" << endl;
							break;
						}
					}
			}
		}
		else
			cout << "�������������ѡ��" << endl;
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
			cout << "������" << p->people << " " << "ѧ�ţ�" << p->id << endl;
			cout << "��ѡ�γ�����" << endl;
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
	cout << " ��������Ҫɾ���γ̵Ŀγ̺ſγ̺� " << endl;
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
	cout << " �ÿγ��Ѵ�ϵͳ��ɾ�� " << endl;
}
void change_s(student *&head)
{
	system("cls");
	student *p;
	int choose = 0, id, s;
	char name[20];
	cout << " 1:�޸�ѧ��ѧ�� " << endl;
	cout << " 2:�޸�ѧ������ " << endl;
	cout << " 0:�˳� " << endl;
	cout << " ������������ " << endl;
	while (cin >> choose)
	{
		if (choose == 0)
			break;
		else if (choose == 1)
		{
			cout << "������Ҫ�޸ĵ�ѧ����ѧ��" << endl;
			cin >> s;
			for (p = head; p; p = p->next)
			{
				if (p->id == s)
				{
					cout << "������ѧ�����µ�ѧ��" << endl;
					cin >> id;
					p->id = id;
					cout << "�޸ĳɹ�" << endl;
					cout << "�˳����� 0" << endl;
					break;
				}
			}
		}
		else if (choose == 2)
		{
			cout << "��������Ҫ�޸ĵ�ѧ����ѧ��" << endl;
			cin >> id;
			for (p = head; p; p = p->next)
			{
				if (p->id == id)
				{
					cout << "������ѧ�����µ�����" << endl;
					cin >> name;
					strcpy(p->password, name);
					cout << "�޸ĳɹ�" << endl;
					cout << "�˳����� 0" << endl;
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
	cout << " 1���޸Ŀγ̺� " << endl;
	cout << " 2���޸��ον�ʦ���� " << endl;
	cout << " 3���޸Ŀγ����� " << endl;
	cout << " 0���˳� " << endl;
	cout << " ������������ " << endl;
	while (cin >> choose)
	{
		if (choose == 0)
			break;
		else if (choose == 1)
		{
			cout << "��������Ҫ�޸ĵĿγ̵Ŀγ̺�" << endl;
			cin >> s;
			for (p = m; p; p = p->r)
			{
				if (p->kechenghao == s)
				{
					cout << "������ѧ�����µĿγ̺�" << endl;
					cin >> id;
					p->kechenghao = id;
					cout << "�޸ĳɹ�" << endl;
					cout << "�˳����� 0" << endl;
					break;
				}
			}
		}
		else if (choose == 2)
		{
			cout << "��������Ҫ�޸ĵĿγ̵Ŀγ̺�" << endl;
			cin >> s;
			cout << "������ѧ�����µ��ον�ʦ" << endl;
			cin >> name;
			for (p = m; p; p = p->r)
			{
				if (p->kechenghao == s)
				{
					cout << "������ѧ�����µ��ον�ʦ" << endl;
					cin >> name;
					strcpy(p->jiaoshi, name);
					cout << "�޸ĳɹ�" << endl;
					cout << "�˳����� 0" << endl;
					break;
				}
			}
		}
		else if (choose == 3)
		{
			cout << "��������Ҫ�޸ĵĿγ̵Ŀγ̺�" << endl;
			cin >> id;
			cout << "������ѧ�����µĿγ�����" << endl;
			cin >> name;
			for (p = m; p; p = p->r)
			{
				if (p->kechenghao == id)
				{
					cout << "������ѧ�����µĿγ�����" << endl;
					cin >> name;
					strcpy(p->micheng, name);
					cout << "�޸ĳɹ�" << endl;
					cout << "�˳����� 0" << endl;
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
	Person *p, *p2; //�½��ָ�� 
	string  pass[10] = { " "," "," "," "," "," "," "," "," "," " };
	string clas[8] = { " �ߵ���ѧ ","  ������ƻ���  ","  СѧӢ��  "," �����߼�  "," ��ѧ����  ","" ,"","" };
	char Name[20];
	int n;
	cout << "\n��������Ϣ \n";
	cout << "����ѧ��:\t";
	cin >> pass[0];
	cout << "��������:\t";
	cin >> Name;
	cout << endl;
	cout << "����������";
	cin >> pass[1];
	cout << "��ѡ��			" << endl << "0:�ߵ���ѧ   1��������ƻ���   2��СѧӢ��  3�������߼� 4����ѧ����  1024:�˳� " << endl;
	while (cin >> n && n != 1024)
	{
		if (n < 8 && n >= 0)
		{
			pass[n + 2] = clas[n];
			cout << clas[n] << "ѡ�γɹ� �����" << endl;
		}
		else
			cout << "������� ����������";
	}
	cout << "1 �˿� 2  �˳�";
	int ss;
	cin >> ss;
	if (ss == 1)
	{
		cout << "���˿�			" << endl << "0:�ߵ���ѧ   1��������ƻ���   2��СѧӢ��  3�������߼� 4����ѧ����  1024:�˳� " << endl;
		while (cin >> n && n != 1024)
		{
			if (n < 8 && n >= 0)
			{
				pass[n + 2] = "  ";
				cout << clas[n] << "�˿γɹ� �����" << endl;
			}
			else
				cout << "������� ����������";
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
		cout << " 1 ѧ�� 0 ������ " << endl;
		cin >> shen;
		if (shen)
		{
			m.Add();
			cout << "ѡ����� ";
			m.Save();
		}
		else
		{
		aa:
			string IDd[3];
			IDd[2] = "";

			cout << "��������������  ����  ����";
			cin >> IDd[0] >> IDd[1] >> IDd[2];
			if (m.manage(IDd))
			{
				cout << "��ѡ�����        1 ����ѯѧ��ѡ�����";
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
				cout << "������� ������ ����1 ���µ�¼  ����1024�˳�";
				int  n;
				cin >> n;
				if (n == 1)
					goto aa;
				else if (n == 1024)
					goto en;
				else cout << "ָ����� ����������";
				goto c;
			}
		en:
			cout << endl << endl;
		}
	}
}
