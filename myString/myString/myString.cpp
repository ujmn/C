#include "myString.h"

myString::myString(char* str = "")
{
	if (nullptr == str)
		str = "";
	_size = strlen(str);
	_capacity = _size + 1;
	_str = new char[_capacity];
	memcpy(_str, str, _size);
	_str[_size] = '\0';
}

#if 0
//传统经典写法
myString::myString(const myString& s)
{
	size_t size = strlen(s._str);
	_str = new char[size + 1];
	memcpy(_str, s._str, size);
	_str[size] = '\0';
}

myString& myString::operator =(myString& s)
{
	if (nullptr != _str)
		delete[] _str;

	size_t size = strlen(s._str);
	_str = new char[size + 1];
	memcpy(_str, s._str, size);
	_str[size] = '\0';

	return *this;
}

#endif

void myString::test(myString s)
{}

#if 1

//现代写法
myString::myString(const myString& s)
	:_str(nullptr)
{
	myString sTemp(s._str);
	swap(*this, sTemp);
}

myString& myString::operator =(myString s)
{
	swap(*this, s);
	return *this;
}

#endif

myString::~myString()
{
	if (nullptr != _str)
	{
		delete[] _str;
	}
}

void myString::swap(myString& sleft, myString& sright)
{
	char *temp = sleft._str;
	sleft._str = sright._str;
	sright._str = temp;
	swap(sleft._capacity, sright._capacity);
	swap(sleft._size, sright._size);
}

void myString::swap(size_t left, size_t right)
{
	size_t temp = left;
	left = right;
	right = temp;
}

size_t myString::size()const
{
	return _size;
}

size_t myString::length()const
{
	return _size;
}

void myString::resize(size_t n, char c)
{
	if (n < _size)
	{
		_str[n] = '\0';
	}
	else
	{
		char *temp = new char[n+1];
		memcpy(temp, _str, _size);
		memset(temp+_size, c, n-_size);
		temp[n] = '\0';
		delete[] _str;
		_str = temp;
		_capacity = n + 1;
		_size = n;
	}
}
void myString::resize(size_t n)
{
	if (n < _size)
	{
		_str[n] = '\0';
	}
	else
	{
		char *temp = new char[n + 1];
		memcpy(temp, _str, _size);
		memset(temp + _size, 0, n - _size);
		temp[n] = '\0';
		delete[] _str;
		_str = temp;
		_capacity = n + 1;
		_size = n;
	}
}
size_t myString::capacity()const
{
	return _capacity;
}
void myString::reserve(size_t res_arg)
{
	if (_capacity < res_arg)
	{
		char *temp = new char[res_arg];
		memcpy(temp, _str, _size+1);
		delete[] _str;
		_str = temp;
		_capacity = res_arg;
	}
}
void myString::clear()
{
	_str[0] = '\0';
	_size = 0;
}
bool myString::empty()const
{
	if (0 == _size)
		return 1;
	else
		return 0;
}
std::ostream& operator <<(std::ostream& cout, myString& s)
{
	std::cout << "myString " << s._str << " " << s._capacity 
		<< " " << s._size;
	return cout;
}

myString& myString::operator +=(const myString &s)
{
	size_t size = s._size + _size;
	if (size + 1 > _capacity)
	{
		char* temp = new char[size + 1];
		memcpy(temp, _str, _size);
		delete[] _str;
		_str = temp;
		temp = nullptr;
		_capacity = size + 1;
	}
	memcpy(_str + _size, s._str, s._size);
	_size = size;
	_str[_size] = '\0';

	return *this;
}

myString& myString::operator +=(char c)
{
	if (_size + 1 > _capacity)
	{
		char *temp = new char[_capacity * 2];
		memcpy(temp, _str, _size);
		delete[] _str;
		_str = temp;
		_capacity *= 2;
	}
	_str[_size++] = c;
	_str[_size] = '\0';
	return *this;
}
myString& myString::operator +=(const char* s)
{
	size_t size = _size + strlen(s);
	if (size+1 > _capacity)
	{
		char *temp = new char[size + 1];
		memcpy(temp, _str, _size);
		delete[] _str;
		_str = temp;
		temp = nullptr;
		_capacity = size + 1;
	}

	memcpy(_str + _size, s, strlen(s));
	_str[size] = '\0';
	_size = size;
	return *this;
}

myString& myString::append(const myString& str)
{
	size_t size = _size + str._size;
	if (size >= _capacity)
	{
		char *temp = new char[size*2];
		memcpy(temp, _str, _size);
		delete[] _str;
		_str = temp;
		temp = nullptr;
		_capacity = size * 2;
	}

	memcpy(_str + _size, str._str, str._size);
	_size = size;
	_str[_size] = '\0';

	return *this;
}

myString& myString::append(const myString& str, size_t pos, size_t n)
{
	if (0 == n)
		return *this;

	assert(pos > str._size);

	if (pos + n > str._size)
	{
		n = str._size - pos;
	}

	size_t newSize = _size + n;
	if (newSize >= _capacity)
	{
		char *temp = new char[newSize * 2];
		memcpy(temp, _str, _size);
		delete[] _str;
		_str = temp;
		temp = nullptr;
		_capacity = newSize * 2;
	}

	memcpy(_str + _size, str._str + pos, n);
	_size = newSize;
	_str[_size] = '\0';

	return *this;
}

myString& myString::append(const char *s, size_t n)
{
	if (0 == n)
		return *this;

	if (n > strlen(s))
	{
		n = strlen(s);
	}

	size_t newSize = _size + n;
	if (newSize >= _capacity)
	{
		char *temp = new char[newSize * 2];
		memcpy(temp, _str, _size);
		delete[] _str;
		_str = temp;
		temp = nullptr;
		_capacity = newSize * 2;
	}

	memcpy(_str + _size, s, n);
	_size += n;
	_str[_size] = '\0';

	return *this;
}

myString& myString::append(const char *s)
{
	size_t n = strlen(s);
	if (0 == s)
		return *this;
	size_t newSize = _size + n;
	if (newSize >= _capacity)
	{
		char *temp = new char[newSize * 2];
		memcpy(temp, _str, _size);
		delete[] _str;
		_str = temp;
		temp = nullptr;
		_capacity = newSize * 2;
	}

	memcpy(_str + _size, s, n);
	_size += n;
	_str[_size] = '\0';

	return *this;
}

myString& myString::append(size_t n, char c)
{
	if (0 == n)
		return *this;

	size_t newSize = _size + n;
	if (newSize >= _capacity)
	{
		char *temp = new char[newSize * 2];
		memcpy(temp, _str, _size);
		delete[] _str;
		_str = temp;
		temp = nullptr;
		_capacity = newSize * 2;
	}

	memset(_str + _size, c, n);
	_size = newSize;
	_str[_size] = '\0';

	return *this;
}


///////////////////////////////////////////////////////////
//Iterator
myString::iterator myString::begin()
{
	assert(_str);
	return &_str[0];
}

myString::const_iterator myString::begin() const
{
	assert(_str);
	return &_str[0];
}

myString::iterator myString::end()
{
	assert(_str);
	return &_str[_size-1];
}

myString::const_iterator myString::end() const
{
	assert(_str);
	return &_str[_size - 1];
}

myString::reverse_iterator myString::rbegin()
{
	assert(_str);
	return &_str[_size-1];
}

myString::const_reverse_iterator myString::rbegin()const
{
	assert(_str);
	return &_str[_size - 1];
}

myString::reverse_iterator myString::rend()
{
	assert(_str);
	return &_str[0];
}

myString::const_reverse_iterator myString::rend() const
{
	assert(_str);
	return &_str[0];
}