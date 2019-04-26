#pragma once
#include <iostream>

template <class T> 
class myVector{
public:
	typedef T* Iterator;
	typedef const T* constIterator;

	myVector();
	myVector(size_t m, const T& value = T());
	myVector(Iterator begin, Iterator end);
	myVector(const myVector& v);
	myVector& operator =(myVector v);
	~myVector();

private:
	Iterator _start;
	Iterator _finsh;
	Iterator _endOfStorage;
};