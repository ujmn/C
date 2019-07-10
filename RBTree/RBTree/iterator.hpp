#include "RBTree.hpp"
using namespace std;

template<class v>
class RBTreeIterator
{
	typedef RBTreeIterator<v> Iterator;
	typedef RBTreeNode Node;
public:
	Iterator()
		:_pNode(nullptr)
	{}

	Node& operator*()
	{
		return _pNode->val;
	}

	Node* operator->()
	{
		return &(*_pNode);
	}

	Iterator& operator++()
	{
		Increasement();
		return *this;
	}

	Iterator operator++(int)
	{
		Iterator temp(*this);
		Increasement();
		return temp;
	}

	Iterator& operator--()
	{
		Decreasement();
		return *this;
	}

	Iterator operator--(int)
	{
		Iterator temp(*this);
		Decreasement();
		return temp;
	}

private:
	void Increasement()
	{
		//1.����������
		
		if (_pNode->_pRight)
		{
			//Ѱ������������˽��
			_pNode = _pNode->_pRight;
			while (_pNode->_pLeft)
			{
				_pNode = _pNode->_pLeft;
			}
		}
		//2.������������
		else
		{
			//Ѱ����һ�����
			Node* pParent = _pNode->_pParent;

			while (_pNode == pParent->_pRight)
			{
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}

			//������������ڵ�û��������
			if (_pNode->_pRight != pParent)
				_pNode = pParent;
		}
	}

	void Decreasemen()
	{
		//0._pNode��headλ�ã���_pNode�ŵ������
		if (_pNode->_pParent->_pParent = _pNode && _pNode->_color == RED)
			_pNode = _pNode->_pRight;
		//1.����������
		else if (_pNode->_pLeft)
		{
			//�������������Ҷ˽��
			_pNode = _pNode->_pLeft;
			while (_pNode->_pRight)
			{
				_pNode = _pNode->_pRight;
			}
		}
		//2.������������
		else
		{
			//Ѱ����һ�����
			Node* pParent = _pNode->_pParent;
			if (_pNode == pParent->_pLeft)
			{
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}

			//������������ڵ�û��������
			if (_pNode->_pLeft != pParent)
				_pNode = pParent;
		}
	}

private:
	Node* _pNode;
};