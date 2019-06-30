#include "HashTable.hpp"
#include <iostream>

using namespace std;

void TestFunc()
{
	int arr[] = { 2, 33, 4, 18, 44 };
	HashTable<int> ht;
	for (auto e : arr)
	{
		ht.Insert(e);
	}
	ht.Erase(44);
	ht.Erase(18);

	int arr1[] = { 9, 10, 55, 78 };
	for (auto e : arr1)
	{
		ht.Insert(e);
	}
}

int main()
{
	TestFunc();
	return 0;
}