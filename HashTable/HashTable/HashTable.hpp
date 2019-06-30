#pragma once
#include <vector>

const int npos = -1;

enum State {EMPTY, EXIST, DELETE};

template <class T>
struct Elem
{
	T _value;
	State _state;
};

template <typename T>
class HashTable
{
public:
	HashTable(size_t capacity = 10)
		:_ht(capacity)
		,_size(0)
	{
		for (size_t i = 0; i < capacity; ++i)
		{
			_ht[i]._state = EMPTY;
		}
	}

	bool Insert(T& val)
	{
		//¼ì²é¿Õ¼ä
		if (_size * 10 / _ht.capacity() > 7)
		{
			CheckCapacity();
		}
		
		size_t hashAddr = _FindAddr(val);

		while (_ht[hashAddr]._state != EMPTY)
		{
			if (_ht[hashAddr]._state == DELETE)
				break;

			if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._value == val)
				return false;

			++hashAddr;

			if (hashAddr == _ht.capacity())
				hashAddr = 0;
		}

		_ht[hashAddr]._value = val;
		_ht[hashAddr]._state = EXIST;
		++_size;

		return true;
	}

	int Find(T& val)
	{
		size_t hashAddr = _FindAddr(val);
		while (_ht[hashAddr]._state != EMPTY)
		{
			if (_ht[hashAddr]._value == val)
				return hashAddr;

			++hashAddr;

			if (hashAddr == _ht.capacity())
				hashAddr = 0;
		}

		return npos;
	}


	bool Erase(T val)
	{
		size_t hashAddr = Find(val);
		if (hashAddr != -1)
		{
			_ht[hashAddr]._state = DELETE;
			--_size;
			return true;
		}

		return false;
	}

	size_t size()
	{
		return _size;
	}

	bool Empty()
	{
		return (_size == 0);
	}

	void Swap(HashTable<T> ht)
	{
		swap(_ht, ht._ht);
		swap(_size, ht._size);
	}

	void CheckCapacity()
	{
		size_t newSize = _ht.capacity() * 2;
		HashTable temp(newSize);

		for (size_t i = 0; i < newSize; ++i)
		{
			temp._ht[i]._state = EMPTY;
		}

		for (size_t i = 0; i < _ht.capacity(); ++i)
		{
			if (_ht[i]._state == EXIST)
				temp.Insert(_ht[i]._value);
		}

		Swap(temp);
	}

private:
	size_t _FindAddr(const T& val)
	{
		size_t hashAddr = val % _ht.capacity();
		return hashAddr;
	}

private:
	std::vector<Elem<T>> _ht;
	size_t _size;
};