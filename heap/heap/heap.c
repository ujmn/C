#include "heap.h"

int Less(HPDataType left, HPDataType right)
{
	return left < right;
}

int Greater(HPDataType left, HPDataType right)
{
	return left > right;
}

void CreateHeap(Heap* hp, HPDataType* array, int size, PFC pFC)
{
	//创建堆
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*size*2);
	assert(hp->_array);
	memcpy(hp->_array, array, sizeof(HPDataType)*size);
	hp->_capacity = size*2;
	hp->_size = size;
	hp->_pFC = pFC;

	//调整堆
	int root = (size - 2) / 2;
	while (root >= 0)
	{
		AdjustDownHeap(hp, root, size);
		--root;
	}	
}


void InsertHeap(Heap* hp, HPDataType data)
{
	if (hp->_size >= hp->_capacity)
	{
		int newSize = 2 * hp->_size*sizeof(HPDataType);
		HPDataType* temp = (HPDataType*)malloc(newSize);
		assert(temp);
		memcpy(temp, hp->_array, hp->_capacity*sizeof(HPDataType));
		HPDataType* dele = hp->_array;
		hp->_array = temp;
		free(dele);
		dele = NULL;
		hp->_capacity *= 2;
	}

	hp->_array[(hp->_size)++] = data;
	AdjustUpHeap(hp, hp->_size-1);
}

void EraseHeap(Heap* hp)
{
	if (NULL != hp && hp->_size > 0)
	{
		swap(&hp->_array[0], &hp->_array[--(hp->_size)]);
		AdjustDownHeap(hp, 0, hp->_size);
	}
}


HPDataType TopHeap(Heap* hp)
{
	assert(hp && hp->_array);
	return hp->_array[0];
}
int SizeHeap(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
int EmptyHeap(Heap* hp)
{
	assert(hp);
	if (0 == hp->_size)
		return 1;
	return 0;
}

void DestroyHeap(Heap* hp)
{
	assert(hp);
	free(hp->_array);
	hp->_array = NULL;
	hp->_size = 0;
	hp->_capacity = 0;
	hp->_pFC = NULL;
}

void swap(HPDataType* left, HPDataType* right)
{
	HPDataType temp = *left;
	*left = *right;
	*right = temp;
}

void AdjustDownHeap(Heap* hp, int root, int size)
{
	int parent = root;
	int child = 2 * root + 1;
	while (child < size)
	{
		//找出左孩子和右孩子中的较大者或较小者
		if (child + 1 < size && hp->_pFC(hp->_array[child+1], hp->_array[child]))
		{
			++child;
		}
		if (hp->_pFC(hp->_array[child], hp->_array[parent]))
		{
			swap(&hp->_array[parent], &hp->_array[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

void AdjustUpHeap(Heap* hp, int child)
{
	int parent = (child - 1) >> 1;
	while (parent >= 0)
	{
		if (hp->_pFC(hp->_array[parent], hp->_array[child]))
		{
			swap(&hp->_array[parent], &hp->_array[child]);
			child = parent;
			parent = (child - 1) >> 1;
		}	
		else
			break;
	}
}

void HeapSort(Heap* hp)
{
	int size = hp->_size-1;
	while (size >= 0)
	{
		swap(&hp->_array[0], &hp->_array[size]);
		AdjustDownHeap(hp, 0, size);
		--size;
	}
}

void TopK(Heap* hp, HPDataType* array, int arrSize, int k, PFC pFC)
{
	CreateHeap(hp, array, k, pFC);
	HeapSort(hp);
	int i = k;
	while (i < arrSize)
	{
		if (pFC(array[i], hp->_array[0]))
		{
			hp->_array[0] = array[i];
			int parent = 0;
			int child = 2 * 0 + 1;
			while (child < k)
			{
				//找出左孩子和右孩子中的较大者或较小者
				if (child + 1 < k && hp->_pFC(hp->_array[child], hp->_array[child+1]))
				{
					++child;
				}
				if (hp->_pFC(hp->_array[parent], hp->_array[child]))
				{
					swap(&hp->_array[parent], &hp->_array[child]);
					parent = child;
					child = 2 * parent + 1;
				}
				else
					break;
			}
		}	
		++i;
	}
}