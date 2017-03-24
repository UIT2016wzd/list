#include"iostream"
#include"string"
using namespace std;

struct Node//定义链表结构体
{
	int Data;
	Node * next;
};

class list//设立链表类
{
	Node*head;
	public:
		list()
		{
			head = NULL;
		}
		void insertlist(int aData, int bData);//链表节点的插入
		void Deletelist(int aData);//链表节点的删除
		void Outputlist();//链表节点的输出
			Node*Gethead()
			{
				return head; 
			}
};

void list::Outputlist()//链表输出函数
{
	Node*current = head;
	while (current != NULL)
	{
		cout << current->Data << " ";
		current = current->next;
	}
	cout << endl;
}

void list::insertlist(int aData, int bData)//链表插入函数（两个节点中的数据）
{
	Node *p, *q, *s;//p指向节点a，q指向节点a_k,s指向节点b
	q = NULL;
	s = (Node*)new(Node);//动态分配一个新节点
	s->Data = bData;//设b为此新节点
	p = head;
	if (head == NULL)//若是空表，使b作为第一个节点
	{
		head = s;
		s->next = NULL;
	}
	else
	{
		if (p->Data == aData)//若a是第一个节点
		{
			s->next = p;
			head = s;
		}
		else
		{
			while (p->Data != aData&&p->next != NULL)//查找节点a
			{
				q = p;
				p = p->next;
			}
			if (p->Data == aData)//若有节点a
			{
				q->next = s;
				s->next = p;
			}
			else//若没有节点a
			{
				p->next = s;
				s->next = NULL;
			}
		}
	}
}

void list::Deletelist(int aData)//设aData是要删除的节点a中的数据成员
{
	Node*p, *q;//p用于指向a，q用于指向节点a的前一个节点
	p = head;
	q = NULL;
	if (p == NULL)//若是空表
	{
		return;
	}
	if (p->Data == aData)//若a是第一个节点
	{
		head = p->next;
		delete p;
	}
	else
	{
		while (p->Data != aData&&p->next != NULL)//查找节点a
		{
			q = p;
			p = p->next;
		}
		if (p->Data == aData)
		{
			q->next = p->next;
			delete p;
		}
	}
}