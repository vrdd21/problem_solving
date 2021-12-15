#pragma once

template <class T>
class ListNode
{
private:
	T data;
	ListNode* next;
};

template <class T>
class List abstract
{
public:
	virtual bool Search(const T& data) const = 0;
	virtual void Insert(const T& data) = 0;
	virtual void Delete(const T& data) = 0;
};

template <class T>
class QueueList : public List
{
private:
	ListNode* head;
	ListNode* tail;

public:
	QueueList();
	bool Search(const T& data) const;
	void Insert(const T& data);
	void Delete(const T& data);
	~QueueList();
};

template <class T>
class StackList : public List
{
private:
	ListNode* top;

public:
	StackList();
	bool Search(const T& data) const;
	void Insert(const T& data);
	void Delete(const T& data);
	~StackList();
};

