#pragma once
#include <iostream>

class myString
{
public:
	myString(char* str);

#if 0
	//传统经典写法
	myString(const myString& s);

	myString& operator =(myString& s);

#endif

#if 1

	//现代写法
	myString(const myString& s);

	myString& operator =(myString s);

#endif

	~myString();
	void test(myString s);
	void swap(myString& sleft, myString& sright);
	void swap(size_t left, size_t right);

	//capacity
	size_t size()const;
	size_t length()const;
	void resize(size_t n, char c);
	void resize(size_t n);
	size_t capacity()const;
	void reserve(size_t res_arg = 0);
	void clear();
	bool empty()const;
	friend std::ostream& operator <<(std::ostream& cout, myString& s);

	//modifiers
	myString& operator +=(const myString &s);
	myString& operator +=(char c);
	myString& operator +=(const char* s);

private:
	char *_str;
	size_t _capacity;
	size_t _size;
};