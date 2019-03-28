#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int HPDataType;
typedef int(*PFC)(HPDataType left, HPDataType right);

typedef struct Heap
{
	HPDataType* _array;
	int _capacity;
	int _size; // ������ЧԪ�ظ��� 
	PFC _pFC;
}Heap;

int Less(HPDataType left, HPDataType right);
int Greater(HPDataType left, HPDataType right);

void CreateHeap(Heap* hp, HPDataType* array, int size, PFC pFC);
void InsertHeap(Heap* hp, HPDataType data);
void EraseHeap(Heap* hp); // ɾ���Ѷ�Ԫ�� 
HPDataType TopHeap(Heap* hp);
int SizeHeap(Heap* hp);
int EmptyHeap(Heap* hp);
void DestroyHeap(Heap* hp);
void AdjustDownHeap(Heap* hp, int root, int size);
void swap(HPDataType*, HPDataType*);
void AdjustUpHeap(Heap* hp, int child);
void HeapSort(Heap* hp);
void TopK(Heap* hp, HPDataType* array, int arrSize, int k, PFC pFC);