#pragma once
#include <vector>

using namespace std;

template <class T>
struct HashBucketNode
{
	HashBucketNode(const T& value = T())
		:_pNext(nullptr)
		,_data(value)
	{}

	HashBucketNode<T>* _pNext;
	T _data;
};

template <class T>
class HashBucket
{
	typedef HashBucketNode<T> Node;
	typedef Node* pNode;

public:
	HashBucket(size_t capacity = 10)
		:_ht(capacity)
		,_size(0)
	{}

	void Insert(const T& value)
	{
		//À©ÈÝ
		if (_size >= _ht.capacity())
		{
			size_t oldSize = _ht.capacity();
			HashBucket ht(oldSize*2);

			//Ìæ»»
			pNode pCur = nullptr;
			for (int i = 0; i < oldSize; ++i)
			{
				pCur = _ht[i];
				while (pCur)
				{
					ht.Insert(pCur->_data);
					pCur = pCur->_pNext;
				}
			}

			Swap(ht);
		}


		size_t bucketNO = _FindBucketNO(value);

		//¼ì²âÔªËØÊÇ·ñÒÑ¾­´æÔÚ
		pNode pCur = _ht[bucketNO];
		while (pCur)
		{
			if (value == pCur->_data)
				return;
			pCur = pCur->_pNext;
		}

		pCur = new Node(value);
		pCur->_pNext = _ht[bucketNO];
		_ht[bucketNO] = pCur;
		++_size;
	}

private:
	size_t _FindBucketNO(const T& value)
	{
		return value % _ht.capacity();
	}

	void Swap(HashBucket ht)
	{
		swap(_ht, ht._ht);
		swap(_size, ht._size);
	}

private:
	vector<pNode> _ht;
	size_t _size;
};
