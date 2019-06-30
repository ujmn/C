#include "RBTree.hpp"

void TestFunc()
{
	RBTree<int> t;
	int arr[10] = {0, 2, 9, 6, 1, 3, 5, 7, 8, 4};
	for (auto e : arr)
	{
		t.Insert(e);
	}

	t.InOrder();
	if (t.IsValidRBTree())
		cout << "该红黑树符合要求" << endl;
	else
		cout << "该红黑树不符合要求" << endl;
}

int main()
{
	TestFunc();
	return 0;
}