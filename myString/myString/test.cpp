#include <iostream>

class myString
{
public:
	myString(char* str = "")
	{
		if (nullptr == str)
			str = "";
		size_t size = strlen(str);
		_str = new char[size + 1];
		memcpy(_str, str, size);
		_str[size] = '\0';
	}

#if 1
	//传统经典写法
	myString(const myString& s)
	{
			size_t size = strlen(s._str);
			_str = new char[size + 1];
			memcpy(_str, s._str, size);
			_str[size] = '\0';
	}

	myString& operator =(myString& s)
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

	void test(myString s)
	{}

#if 0

	//现代写法
	myString(const myString& s)
		:_str(nullptr)
	{
		myString sTemp(s._str);
		swap(*this, sTemp);
	}

	myString& operator =(myString s)
	{
		swap(*this, s);
		return *this;
	}

#endif

	~myString()
	{
		if (nullptr != _str)
		{
			delete[] _str;
		}
	}

	void swap(myString& sleft, myString& sright)
	{
		char *temp = sleft._str;
		sleft._str = sright._str;
		sright._str = temp;
	}

private:
	char *_str;
};

int main()
{
	myString s1("hello world!");
	myString s2(s1);
	myString s3(nullptr);
	s1.test(s2);
	s3 = s2;
	return 0;
}