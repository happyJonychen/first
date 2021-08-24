#include<iostream>
using namespace std;
template<typename T>
struct Node
{
	T data;
	Node<T>* next;
}; 
template<typename T>
class LinkList
{
public:
	LinkList();
	LinkList(T a[], int n);             //建立n个元素的单链表
	~LinkList();                        //析构函数
	int Length();                       //求单链表长度
	T Get(int i);                       //按位查找，查找第i个结点的元素值
	int Located(T x);                   //按值查找，查找值为x的元素位置
	void Insert(int i, T x);			//插入操作，第i个位置插入值为x的结点
	T Delete(int i);					//删除操作，删除第i个结点
	void Empty();                       //判空操作
	void PrintList();					//打印操作
private:
	 Node<T>* first;
};

template<typename T>
LinkList<T>::LinkList()
{
	first = new Node<T>;
	first->next = NULL;
}

//template<typename T>
//LinkList<typename T>::LinkList(T a[], int n)  //头插法
//{
//	first = new Node < T >;
//	first->next = NULL;
//	for (int i = 0; i < n; i++)
//	{
//		Node<T>* s = NULL;
//		s = new Node<T>;
//		s->data = a[i];
//		s->next = first->next;
//		first->next = s;
//	}
//}

template<typename T>
LinkList<typename T>::LinkList(T a[], int n)  //尾插法
{
	first = new Node<T>;
	Node<T>* p = first, * s = NULL;
	for (int i = 0; i < n; i++)
	{
		s = new Node<T>;
		s->data = a[i];
		p->next = s;
		p = s;
	}
	p->next = NULL;
}

template<typename T>
LinkList<T>::~LinkList()
{
	Node<T>* p = first;
	while (first)
	{
		first = first->next;
		delete p;
		p = first;
	}
}

template<typename T>
int LinkList<T>::Length()
{
	Node<T>* p = first;
	int count = 0;
	while (p)
	{
		p = p->next;
		count++;
	}
	return count;
}

template<typename T>
T LinkList<T>::Get(int i)
{ 
	Node<T>* p = first->next;
	int count = 1;
	while (p&&count<i)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)
		cout << "查找位置错误！" << endl;
	else	return p->data;
}

template<typename T>
int LinkList<T>::Located(T x)
{
	Node<T>* p = first->next;
	int count = 1;
	while (p)
	{
		if (p->data == x)
			return count;
		p = p->next;
		count++;
	}
	return 0;
}

template<typename T>
void LinkList<T>::Insert(int i, T x)
{
	Node<T>* p = first, * s = NULL;
	int count = 0;
	while (p && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)
		cout << "插入位置错误!" << endl;
	else
	{
		s = new Node<T>;
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
}

template<typename T>
T LinkList<T>::Delete(int i)
{
	T x;
	Node<T>* p = first, * q = NULL;
	int count = 0;
	while (p&&count<i-1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL || p->next == NULL||i==0)
		cout << "删除位置错误！" << endl;
	else
	{
		q = p->next;
		x = q->data;
		p->next = q->next;
		delete q;
		return x;
	}
}


template<typename T>
void LinkList<T>::Empty()
{
	if (first->next == NULL)
		cout << "该链表为空！" << endl;
	else
		cout << "该链表不为空！" << endl;
}

template<typename T>
void LinkList<T>::PrintList()
{
	Node<T>* p = first->next;
	while (p)
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	int a[5] = { 5,8,9,11,4 };
	LinkList<int>L(a, 5);
	//L.Delete(5);
	//L.Empty();
	//L.Insert(6, 2);
	L.Insert(6, 99);
	L.PrintList();
	//cout << endl;
	//cout << L.Located(5);

	return 0;
}