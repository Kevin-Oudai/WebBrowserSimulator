#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stack>

template <typename T>
class Stack
{
private:
	std::stack<T> backward;
	std::stack<T> forward;

public:
	void push(const T& item);
	T pop();
	T popForward();
	bool isEmpty();
	bool isForwardEmpty();
};

#endif // !STACK_H

template<typename T>
inline void Stack<T>::push(const T& item)
{
	backward.push(item);
	while (!forward.empty())
	{
		forward.pop();
	}
}

template<typename T>
inline T Stack<T>::pop()
{
	T top = backward.top();
	backward.pop();
	forward.push(top);
	return top;
}

template<typename T>
inline T Stack<T>::popForward()
{
	T top = forward.top();
	forward.pop();
	backward.push(top);
	return top;
}

template<typename T>
inline bool Stack<T>::isEmpty()
{
	return backward.empty();
}

template<typename T>
inline bool Stack<T>::isForwardEmpty()
{
	return forward.empty();
}



