#pragma once
#include <iostream>

class Sort
{
public:
	Sort(int *arr);
	Sort(Sort& arr);
	Sort& operator =(Sort arr);
	~Sort();
private:
	int *m_arr;
};