#include "heap.h"

int main()
{
	int arr[] = { 9, 2, 4, 1, 0, 5, 8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Heap hp1;
	CreateHeap(&hp1, arr, len, Less);
	InsertHeap(&hp1, 10);
	EraseHeap(&hp1);
	HPDataType tmp = TopHeap(&hp1);
	HeapSort(&hp1);
	Heap hp2;
	TopK(&hp2, arr, len, 3, Greater);
	DestroyHeap(&hp1);
	DestroyHeap(&hp2);
	return 0;
}