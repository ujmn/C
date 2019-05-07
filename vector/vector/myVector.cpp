#include "myVector.h"

template <class T>
Iterator myVector::Begin() { return _start; }

template <class T>
Iterator myVector::End() { return _finish; }

template <class T>
ConstIterator myVector::CBegin() { return _start; }

template <class T>
ConstIterator myVector::CEnd() { return _finish; }

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
		PushBack(value);
	}
}

template <class T>
myVector::myVector(Iterator first, Iterator last)
{
	Reserve(last - first);
	while (first != last)
	{
		PushBack(*first);
		first++;
	}
}

template <class T>
myVector::myVector(const myVector<T>& v)
{
	Reserve(capacity());
	iterator it = Begin();
	ConstIterator vit = v.CBegin();

	while (vit != v.CEnd())
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

template <class T>
size_t myVector::size() const { return _finish - _start; }

template <class T>
size_t myVector::max_size() const { return capacity(); }

template <class T>
void myVector::resize(size_t n, T value = T())
{
	size_t size = _start - _finish;
	if (n < size)
	{
		_finish = _start + n;
		return;
	}

	if (n > size)
	{
		Reserve(n);
	}

	Iterator it = _finish;
	_finish = _start + n;

	while (it != _finish)
	{
		*it++ = value;
	}
}

template <class T>
size_t myVector::capacity() const { return _endOfStorage - _start; }

template <class T>
bool myVector::empty() const { return (_start == _finish) ? true : false; }

template <class T>
void myVector::Reserve(size_t n)
{
	if (capacity < n)
	{
		size_t size = size();
		T* temp = new T[n];

		if (_start)
		{
			for (size_t i = 0; i < size; ++i)
			{
				temp[i] = _start[i];
			}
		}

		_start = temp;
		_finish = _start + size;
		_endOfStorage = _start + n;
	}
}