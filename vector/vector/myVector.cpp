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
myVector::myVector(Iterator begin, Iterator end)
{

}

template <class T>
myVector::myVector(const myVector& v)
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