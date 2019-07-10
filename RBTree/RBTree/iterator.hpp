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
		//1.右子树存在
		
		if (_pNode->_pRight)
		{
			//寻找右子树最左端结点
			_pNode = _pNode->_pRight;
			while (_pNode->_pLeft)
			{
				_pNode = _pNode->_pLeft;
			}
		}
		//2.右子树不存在
		else
		{
			//寻找上一个结点
			Node* pParent = _pNode->_pParent;

			while (_pNode == pParent->_pRight)
			{
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}

			//特殊情况：根节点没有右子树
			if (_pNode->_pRight != pParent)
				_pNode = pParent;
		}
	}

	void Decreasemen()
	{
		//0._pNode在head位置，将_pNode放到最大结点
		if (_pNode->_pParent->_pParent = _pNode && _pNode->_color == RED)
			_pNode = _pNode->_pRight;
		//1.左子树存在
		else if (_pNode->_pLeft)
		{
			//找左子树的最右端结点
			_pNode = _pNode->_pLeft;
			while (_pNode->_pRight)
			{
				_pNode = _pNode->_pRight;
			}
		}
		//2.左子树不存在
		else
		{
			//寻找上一个结点
			Node* pParent = _pNode->_pParent;
			if (_pNode == pParent->_pLeft)
			{
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}

			//特殊情况：根节点没有左子树
			if (_pNode->_pLeft != pParent)
				_pNode = pParent;
		}
	}

private:
	Node* _pNode;
};