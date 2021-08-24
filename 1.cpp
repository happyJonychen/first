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
	LinkList(T a[], int n);             //����n��Ԫ�صĵ�����
	~LinkList();                        //��������
	int Length();                       //��������
	T Get(int i);                       //��λ���ң����ҵ�i������Ԫ��ֵ
	int Located(T x);                   //��ֵ���ң�����ֵΪx��Ԫ��λ��
	void Insert(int i, T x);			//�����������i��λ�ò���ֵΪx�Ľ��
	T Delete(int i);					//ɾ��������ɾ����i�����
	void Empty();                       //�пղ���
	void PrintList();					//��ӡ����
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
//LinkList<typename T>::LinkList(T a[], int n)  //ͷ�巨
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
LinkList<typename T>::LinkList(T a[], int n)  //β�巨
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
		cout << "����λ�ô���" << endl;
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
		cout << "����λ�ô���!" << endl;
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
		cout << "ɾ��λ�ô���" << endl;
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
		cout << "������Ϊ�գ�" << endl;
	else
		cout << "������Ϊ�գ�" << endl;
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