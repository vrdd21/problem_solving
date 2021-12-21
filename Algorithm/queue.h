#pragma once
#include "List.h"

template<class T>
class Queue
{
private:
	List<T> list;
public:
	Queue();
	void enqueue(const T& data);
	T dequeue();
	bool empty();
	~Queue();
};

template<class T>
inline Queue<T>::Queue()
{
}

template<class T>
inline void Queue<T>::enqueue(const T& data)
{
	list.push_front(data);
}

template<class T>
inline T Queue<T>::dequeue()
{
	T ret = list.peek_back();
	list.remove_back();
	return ret;
}

template<class T>
inline bool Queue<T>::empty()
{
	return list.is_empty();
}

template<class T>
inline Queue<T>::~Queue()
{
}
