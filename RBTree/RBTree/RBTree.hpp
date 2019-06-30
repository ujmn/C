#pragma once

#include <iostream>

using namespace std;

enum Color
{
	RED,
	BLACK
};


template <class v>
struct RBTreeNode
{
	RBTreeNode(v value = v(), Color color = RED)
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_pParent(nullptr)
		,val(value)
		,_color(color)
	{}


	RBTreeNode<v>* _pLeft;
	RBTreeNode<v>* _pRight;
	RBTreeNode<v>* _pParent;
	v val;
	Color _color;
};

template <class v>
class RBTree
{
	typedef RBTreeNode<v> Node;

public:
	RBTree()
		:_pHead(new Node)
	{
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
		_pHead->_pParent = nullptr;
	}

	bool Insert(const v& value)
	{
		Node* pRoot = GetRoot();
		if (pRoot == nullptr)
		{
			pRoot = new Node(value, BLACK);
			pRoot->_pParent = _pHead;
			_pHead->_pParent = pRoot;
		}
		else
		{
			//找到结点待插入位置
			Node* pCur = pRoot;
			Node* pParent = nullptr;

			while (pCur)
			{
				pParent = pCur;
				if (value < pCur->val)
					pCur = pCur->_pLeft;
				else if (value > pCur->val)
					pCur = pCur->_pRight;
				else
					return false;
			}

			pCur = new Node(value);
			if (value < pParent->val)
			{
				pParent->_pLeft = pCur;
			}
			else
			{
				pParent->_pRight = pCur;
			}

			pCur->_pParent = pParent;

			//检测红黑树结构有没有被破坏
			//如果被破坏 则修复

			while (pParent && pParent->_color == RED && pParent->_pParent != pCur)
			{
				Node* grandFather = pParent->_pParent;

				if (pParent == grandFather->_pLeft)
				{
					Node* uncle = grandFather->_pRight;

					if (uncle && uncle->_color == RED)
					{
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						grandFather->_color = RED;
						pCur = grandFather;
						pParent = pCur->_pParent;
					}

					else
					{
						if (pCur == pParent->_pRight)
						{
							_RotateLeft(pParent);
							swap(pCur, pParent);
						}

						grandFather->_color = RED;
						pParent->_color = BLACK;
						_RotateRight(grandFather);
					}
				}

				else
				{
					Node* uncle = grandFather->_pLeft;

					if (uncle && RED == uncle->_color)
					{
						uncle->_color = BLACK;
						pParent->_color = BLACK;
						grandFather->_color = RED;
						pCur = grandFather;
						pParent = pCur->_pParent;
					}
					else
					{
						if (pCur == pParent->_pLeft)
						{
							_RotateRight(pParent);
							swap(pCur, pParent);
						}

						grandFather->_color = RED;
						pParent->_color = BLACK;
						_RotateLeft(grandFather);
					}
				}

				pRoot = GetRoot();
			}//while

		}//else

		

		pRoot->_color = BLACK;
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		return true;
	}

	void InOrder()
	{
		Node* pRoot = GetRoot();
		_InOrder(pRoot);
		cout << endl;
	}

	bool IsValidRBTree()
	{
		Node* pRoot = GetRoot();

		if (nullptr == pRoot)
			return true;

		if (BLACK != pRoot->_color)
		{
			cout << "违反性质一：根节点颜色为黑色" << endl;
			return false;
		}
			
		//随便统计一条路径上的黑色结点数
		Node* pCur = pRoot;
		int k = 0;
		while (pCur)
		{
			if (pCur && BLACK == pCur->_color)
			{
				++k;
			}

			pCur = pCur->_pLeft;
		}

		return _IsValidRBTree(pRoot, 0, k);
	}

private:
	Node* GetRoot()
	{
		return _pHead->_pParent;
	}

	Node* LeftMost()
	{
		Node* pCur = GetRoot();

		if (nullptr == pCur)
		{
			return _pHead;
		}

		while (pCur->_pLeft)
		{
			pCur = pCur->_pLeft;
		}

		return pCur;
	}

	Node* RightMost()
	{
		Node* pCur = GetRoot();

		if (nullptr == pCur)
		{
			return _pHead;
		}

		while (pCur->_pRight)
		{
			pCur = pCur->_pRight;
		}

		return pCur;
	}

	void _RotateRight(Node*& pCur)
	{
		if (nullptr == pCur)
			return;

		Node* pLeft = pCur->_pLeft;
		pCur->_pLeft = pLeft->_pRight;
		pLeft->_pParent = pCur->_pParent;
		if (pCur->_pParent != _pHead)
		{
			if (pCur == pCur->_pParent->_pLeft)
			{
				pCur->_pParent->_pLeft = pLeft;
			}
			else
			{
				pCur->_pParent->_pRight = pLeft;
			}
		}
		else
		{
			_pHead->_pParent = pLeft;
		}

		pLeft->_pRight = pCur;
		pCur->_pParent = pLeft;
	}

	void _RotateLeft(Node*& pCur)
	{
		if (nullptr == pCur)
			return;

		Node* pRight = pCur->_pRight;
		pCur->_pRight = pRight->_pLeft;
		pRight->_pParent = pCur->_pParent;
		if (pCur->_pParent != _pHead)
		{
			if (pCur == pCur->_pParent->_pLeft)
			{
				pCur->_pParent->_pLeft = pRight;
			}
			else
			{
				pCur->_pParent->_pRight = pRight;
			}
		}
		else
		{
			_pHead->_pParent = pRight;
		}

		pRight->_pLeft = pCur;
		pCur->_pParent = pRight;
	}

	void _InOrder(Node*& pCur)
	{
		if (nullptr == pCur)
			return;
		_InOrder(pCur->_pLeft);
		cout << pCur->val << " ";
		_InOrder(pCur->_pRight);
	}

	bool _IsValidRBTree(Node* pRoot, int k, int blackCount)
	{
		if (nullptr == pRoot)
			return true;

		if (BLACK == pRoot->_color)
			++k;

		Node* pParent = pRoot->_pParent;
		if (pParent && RED == pParent->_color && RED == pRoot->_color)
		{
			cout << "违反性质三：没有连在一起的红色结点" << endl;
			return false;
		}

		if (nullptr == pRoot->_pLeft && nullptr == pRoot->_pRight)
		{
			if (k != blackCount)
			{
				cout << "违反性质四：每条路径上的黑色结点个数相同" << endl;
				return false;
			}

			return true;
		}

		return _IsValidRBTree(pRoot->_pLeft, k, blackCount) &&
				_IsValidRBTree(pRoot->_pRight, k, blackCount);
	}

private:
	Node* _pHead;
};