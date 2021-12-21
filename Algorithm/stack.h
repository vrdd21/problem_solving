#pragma once
#include "List.h"

template<class T>
class Stack
{
private:
	List<T> list; // similar with adapter pattern
public:
	Stack();
	void push(const T& data);
	T pop();
	bool empty() const;
	~Stack();
};

template<class T>
inline Stack<T>::Stack()
{
}

template<class T>
inline void Stack<T>::push(const T& data)
{
	list.push_back(data);
}

template<class T>
inline T Stack<T>::pop()
{
	T ret = list.peek_back();
	list.remove_back();
	return ret;
}

template<class T>
inline bool Stack<T>::empty() const
{
	return list.is_empty();
}

template<class T>
inline Stack<T>::~Stack()
{
}
