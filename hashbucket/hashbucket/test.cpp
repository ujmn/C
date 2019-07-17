#include "hashbucket.hpp"
#include <iostream>

using namespace std;

void TestFunc()
{
	HashBucket<int> ht;
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 ,1, 2, 12, 32};
	for (auto e : arr)
	{
		ht.Insert(e);
	}
}

int main()
{
	TestFunc();
	return 0;
}