#pragma once
#include <iostream>
#include <assert.h>

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
	myString& append(const myString& str);
	myString& append(const myString& str, size_t pos, size_t n);
	myString& append(const char *s, size_t n);
	myString& append(const char *s);
	myString& append(size_t n, char c);

	//Iterators
	typedef char* iterator;
	typedef char* reverse_iterator;
	typedef const iterator const_iterator;
	typedef const reverse_iterator const_reverse_iterator;

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin()const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

private:
	char *_str;
	size_t _capacity;
	size_t _size;
};