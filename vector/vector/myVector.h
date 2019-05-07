#pragma once
#include <iostream>

template <class T> 
class myVector{
public:
	typedef T* Iterator;
	typedef const T* constIterator;
	Iterator Begin();
	Iterator End();
	ConstIterator CBegin();
	ConstIterator CEnd();

	myVector();
	myVector(size_t m, const T& value = T());
	myVector(Iterator first, Iterator last);
	myVector(const myVector<T>& v);
	myVector& operator =(myVector v);
	~myVector();
	

	//capacity
	size_t size() const;
	size_t max_size() const;
	void resize(size_t n, T c = T());
	size_t capacity() const;
	bool empty() const;
	void Reserve(size_t n);

private:
	Iterator _start;
	Iterator _finsh;
	Iterator _endOfStorage;
};