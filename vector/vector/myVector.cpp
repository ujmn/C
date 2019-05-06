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
	Reserve(capacity());
	iterator it = Begin();
	ConstIterator vit = v.CBegin();

	while (it != v.cend())
	{
		*it++ = *vit++;
	}

	_finish = _start + v.size();
	_endOfStorage = _start + v.Capacity();
}

template <class T>
myVector& myVector::operator =(myVector<T> v)
{
	swap(v);

	return *this;
}

template <class T>
myVector::~myVector()
{
	if (_start != nullptr)
	{
		delete[] _start;
		_start = nullptr;
		_finish = nullptr;
		_endOfStorage = nullptr;
	}
}