#pragma once

#include <iostream>

using std::cout;
using std::endl;

template <class T>
class ListNode
{
private:
	T data;
	ListNode<T>* next;
public:
	ListNode();
	ListNode<T>* GetNext() const;
	void SetNext(ListNode<T>* node);

	T GetData() const;
	void SetData(const T& data);
	~ListNode();
};

template <class T>
class List
{
private:
	ListNode<T>* head;
	ListNode<T>* tail;
	int cnt;
public:
	List();
	void push_front(const T& data);
	void push_back(const T& data);
	T peek_front() const;
	T peek_back() const;
	void remove_front();
	void remove_back();
	ListNode<T>* create_node(const T& data) const;
	bool is_empty() const;
	~List();
};

template<class T>
inline ListNode<T>::ListNode()
{
	next = nullptr;
}

template<class T>
inline ListNode<T>* ListNode<T>::GetNext() const
{
	return next;
}

template<class T>
inline void ListNode<T>::SetNext(ListNode<T>* node)
{
	next = node;
}

template<class T>
inline T ListNode<T>::GetData() const
{
	return data;
}

template<class T>
inline void ListNode<T>::SetData(const T& data)
{
	this->data = data;
}

template<class T>
inline ListNode<T>::~ListNode()
{
}

template<class T>
inline List<T>::List()
{
	head = nullptr;
	tail = nullptr;
	cnt = 0;
}

template<class T>
inline void List<T>::push_front(const T& data)
{
	ListNode<T>* node = create_node(data);

	if (is_empty())
	{
		head = node;
		tail = node;
	}
	else
	{
		node->SetNext(head);
		head = node;
	}
	cnt++;
}

template<class T>
inline void List<T>::push_back(const T& data)
{
	ListNode<T>* node = create_node(data);

	if (is_empty())
	{
		head = node;
		tail = node;
	}
	else
	{
		tail->SetNext(node);
		tail = node;
	}
	cnt++;
}

template<class T>
inline T List<T>::peek_front() const
{
	if (is_empty())
	{
		cout << "empty state" << endl;
		exit(1);
	}

	return head->GetData();
}

template<class T>
inline T List<T>::peek_back() const
{
	if (is_empty())
	{
		cout << "empty state" << endl;
		exit(1);
	}
	return tail->GetData();
}

template<class T>
inline void List<T>::remove_front()
{
	if (is_empty())
	{
		cout << "empty state" << endl;
		exit(1);
	}
	else if (head == tail)
	{
		ListNode<T>* p = head;
		head = nullptr;
		tail = nullptr;
		delete p;
	}
	else
	{
		ListNode<T>* p = head;
		head = head->GetNext();
		delete p;
	}

	cnt--;
}

template<class T>
inline void List<T>::remove_back()
{
	if (is_empty())
	{
		cout << "empty state" << endl;
		exit(1);
	}
	else if (head == tail)
	{
		ListNode<T>* p = head;
		head = nullptr;
		tail = nullptr;
		delete p;
	}
	else
	{
		ListNode<T>* p = head;
		while (p->GetNext() != tail)
		{
			p = p->GetNext();
		}
		tail = p;
		delete p->GetNext();
		p->SetNext(nullptr);
	}

	cnt--;
}

template<class T>
inline ListNode<T>* List<T>::create_node(const T& data) const
{
	ListNode<T>* node;

	if (!(node = new ListNode<T>()))
	{
		cout << "memory allocation failed" << endl;
		exit(1);
	}

	node->SetData(data);

	return node;
}

template<class T>
inline bool List<T>::is_empty() const
{
	if (head == nullptr && tail == nullptr) return true;
	else if ((head == nullptr && tail != nullptr) || (head != nullptr && tail == nullptr))
	{
		cout << "wrong state" << endl;
		exit(1);
	}

	return false;
}

template<class T>
inline List<T>::~List()
{
	ListNode<T>* p = head;
	ListNode<T>* tmp;

	while (p != nullptr)
	{
		tmp = p->GetNext();
		delete p;
		p = tmp;
	}
}