#include "myVector.h"

template <class T>
myVector::myVector()
	:_start(nullptr)
	,_finish(nullptr)
	,endOfStorage(nullptr)
{}

template <class T>
myVector::myVector(size_t m, const T& value = T())
	:_start(nullptr)
	,_finish(nullptr)
	,endOfStorage(nullptr)
{
	Reserve(n);
	while (n--)
	{
		push_back(value);
	}
}

template <class T>
myVector::myVector(Iterator first, Iterator last)
{
	Reserve(last - first);
	while (first != last)
	{
		push_back(*first);
		first++;
	}
}

template <class T>
myVector::myVector(const myVector<T>& v)
{

}

template <class T>
myVector& myVector::operator =(myVector v)
{

}

template <class T>
myVector::~myVector()
{

}