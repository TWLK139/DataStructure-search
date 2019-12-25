#pragma once
#ifndef SEARCH_H

#define SEARCH_H

#define DEBUG

#include<iostream>
#include<math.h>

using namespace std;

#define elementType int
#define MAXLEN 100


//***********************顺序表结构*************************//
typedef struct sList										//
{															//
	elementType data[MAXLEN];								//
	int listLen;											//
}seqList, * seqP;			//定义结点类型、结点指针类型	//
//**********************************************************//

//*********************二叉树结构定义***********************//
typedef struct lBNode										//
{															//
	elementType data;										//
	struct lBNode* lChild, * rChild;						//
}BiNode, * BiTree;											//
//**********************************************************//

//**********************数据链队列结构**********************//
//链队列结点结构											//
typedef struct LNode										//
{															//
	BiTree point;					//结点地址存放			//
	struct LNode* next;										//
}queueNode;													//
															//
//链队列结构												//
typedef struct LNodes										//
{															//
	queueNode* front;				//队头指针				//
	queueNode* rear;				//队尾指针				//
	bool flag = false;				//标记用于打印二叉树	//
}linkQueue, * lQP;											//
//**********************************************************//


//************************************************函数声明******************************************************//
//队列函数声明																									//
bool initialQueue(lQP& Q);													//链队列初始化						//
bool enQueue(lQP Q, BiTree data);											//链队列入队						//
bool outQueue(lQP Q, BiTree& data);											//链队列出队						//
//顺序表函数声明																								//
void showSeqList(seqP L);													//打印顺序表						//
int binarySearch(seqP L, elementType data);									//二分查找元素						//
//二叉树通用函数声明																							//
bool addTreeNode(BiTree& T, elementType x);									//二叉树创建新结点					//
int getTreeHeight(BiTree T);												//求二叉树高度						//
void getNodeFloor(BiTree T, elementType x, int floor, int& res);			//求二叉树结点层次					//
int getNodeFloor(BiTree T, elementType x);									//求二叉树结点层次					//
void printBST(BiTree T);													//打印二叉树						//
void destoryTreeNode(BiTree T);												//销毁二叉树						//
bool destoryTree(BiTree& T);												//销毁二叉树						//
//二分查找树函数声明																							//
void creatJudgeTree(BiTree& T, seqP L, int min, int max);					//创建二分查找树					//
bool creatJudgeTree(BiTree& T, seqP L);										//创建二分查找树					//
//二分排序树函数声明																							//
void insertBiSearchTree(BiTree& T, elementType x);							//二叉排序树插入节点				//
bool creatBiSearchTree(BiTree& T, seqP L, bool AVL = false);				//创建平衡化二叉排序树				//
BiTree searchBST(BiTree T, elementType data);								//在二叉排序树中查找指定值结点		//
bool deleteBSTNode(BiTree& T, elementType data, bool AVL = true);			//二叉排序树删除结点				//
//平衡二叉树函数声明																							//
void LLAdjust(BiTree& T);													//LL型平衡化						//
void LRAdjust(BiTree& T);													//LR型平衡化						//
void RRAdjust(BiTree& T);													//RR型平衡化						//
void RLAdjust(BiTree& T);													//RL型平衡化						//
void adjust(BiTree& T);														//二叉平衡树平衡化					//
//**************************************************************************************************************//

#endif // !SEARCH_H



//*********************************************************函数定义*********************************************************//

//******************************************************链队列函数定义******************************************************//

//辅助函数：链队列初始化
//输入：队列指针
//返回：成功返回true，失败返回false
bool initialQueue(lQP& Q)
{
	if (Q == nullptr)
	{
		Q = new linkQueue;
		Q->front = new queueNode;
		Q->rear = Q->front;
		Q->front->next = nullptr;

		return true;
	}
	else
	{
		cout << "当前指针已占用，队列初始化失败！" << endl;

		return false;
	}
}


//辅助函数：链队列入队
//输入：队列指针，入队指针
//返回：成功返回true，失败返回false
bool enQueue(lQP Q, BiTree data)
{
	if (Q != nullptr)
	{
		Q->rear->next = new queueNode;
		Q->rear = Q->rear->next;
		Q->rear->point = data;
		Q->rear->next = nullptr;

		return true;
	}
	else
	{
		cout << "当前队列未初始化，入队失败！" << endl;

		return false;
	}
}


//辅助函数：链队列出队
//输入：队列指针，出队指针
//返回：成功返回true，失败返回false
bool outQueue(lQP Q, BiTree& data)
{
	queueNode* dp = nullptr;

	if (Q != nullptr)
	{
		if (Q->front != Q->rear)
		{
			dp = Q->front->next;
			data = dp->point;
			Q->front->next = dp->next;
			delete(dp);
			if (Q->front->next == nullptr)
			{
				Q->rear = Q->front;
			}

			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		cout << "当前队列未初始化，出队失败！" << endl;

		return false;
	}
}


//******************************************************顺序表函数定义******************************************************//

//辅助函数：打印顺序表
//输入：顺序表指针
//打印：函数内打印顺序表结点元素
void showSeqList(seqP L)
{
	int i = 0;
	while (i < L->listLen)
	{
		cout << L->data[i] << "\t";
		i++;
	}
	cout << endl;
}


//实验九.查找.1：二分查找元素
//输入：顺序表，查找元素
//返回：查找成功返回结点下标，查找失败返回-1
int binarySearch(seqP L, elementType data)
{
	int min = 0, max = L->listLen - 1, mid = 0;

	mid = (min + max) / 2;
#ifdef DEBUG
	cout << "查找元素值" << data << "\t依次比较元素为：\t";
#endif // DEBUG


	while (min <= max)
	{
#ifdef DEBUG
		cout << "[" << mid << "]" << ":" << L->data[mid] << "\t";
#endif // DEBUG

		if (data < L->data[mid])
		{
			max = mid - 1;
		}
		else if(data == L->data[mid])
		{
			return mid;
		}
		else
		{
			min = mid + 1;
		}
		mid = (min + max) / 2;
	}

	return -1;
}


//****************************************************二叉树通用函数声明****************************************************//

//辅助函数：二叉树创建新结点
//输入：二叉树指针，顺序表
//返回：成功返回true，失败返回false
bool addTreeNode(BiTree& T, elementType x)
{
	if (T == nullptr)
	{
		T = new BiNode;
		T->data = x;
		T->lChild = nullptr;
		T->rChild = nullptr;

		return true;
	}
	else
	{
		cout << "当前结点已占用！" << endl;

		return false;
	}
}


//辅助函数：求二叉树的高度
//输入：二叉树指针 
//返回：二叉树高度
int getTreeHeight(BiTree T)
{
	int lh = 0, rh = 0;

	if (!T)
	{
		return 0;
	}
	else
	{
		lh = 1 + getTreeHeight(T->lChild);
		rh = 1 + getTreeHeight(T->rChild);

		return lh > rh ? lh : rh;
	}
}


//辅助函数：求二叉树结点层次
//输入：二分查找树指针，查找元素，当前层级，回传参数地址
void getNodeFloor(BiTree T, elementType x, int floor, int& res)
{
	if (T)
	{
		if (T->data == x)
		{
			res = floor;
			return;
		}
		getNodeFloor(T->lChild, x, floor + 1, res);
		getNodeFloor(T->rChild, x, floor + 1, res);
	}
}


//辅助函数：求二叉树结点层次
//输入：二分查找树指针，查找元素，当前层级，回传参数地址
//返回：查找成功返回层次，失败返回-1
int getNodeFloor(BiTree T, elementType x)
{
	int res = -1;

	if (T != nullptr)
	{
		getNodeFloor(T, x, 1, res);

		return res;
	}
	else
	{
		cout << "二叉树未创建！" << endl;

		return -1;
	}
}


//辅助函数：打印二叉排序树
//输入：二分查找树指针，顺序表
void printBST(BiTree T)
{
	int i = 0;
	int nowHeight = 1, height = 0;
	BiTree nowT = nullptr;
	lQP SQF = nullptr, SQS = nullptr, SQC = nullptr;

	height = getTreeHeight(T);

	initialQueue(SQF);
	initialQueue(SQS);
	enQueue(SQF, T);
	if (T)
	{
		SQF->flag = true;
	}
	while (SQF->flag)
	{
		while (outQueue(SQF, nowT))
		{
			cout << " ";
			for (i = 0; i < (int)(pow(2, height - nowHeight) - 1); i++)
			{
				cout << " ";
			}
			if (nowT)
			{
				cout << nowT->data;
			}
			else
			{
				cout << "_";
			}
			for (i = 0; i < (int)(pow(2, height - nowHeight) - 1); i++)
			{
				cout << " ";
			}

			if (nowT)
			{
				enQueue(SQS, nowT->lChild);
				enQueue(SQS, nowT->rChild);
				if (nowT->lChild || nowT->rChild)
				{
					SQS->flag = true;
				}
			}
			else
			{
				enQueue(SQS, nullptr);
				enQueue(SQS, nullptr);
			}
		}
		cout << endl;
		nowHeight++;
		SQF->flag = false;
		SQC = SQF;
		SQF = SQS;
		SQS = SQC;
	}

	cout << endl;
}


//辅助函数：销毁二叉树
//输入：二叉树根节点
void destoryTreeNode(BiTree T)
{
	if (T)
	{
		destoryTreeNode(T->lChild);
		destoryTreeNode(T->rChild);
		delete(T);
	}
}


//辅助函数：销毁二叉树
//输入：二叉树根节点
bool destoryTree(BiTree& T)
{
	if (T)
	{
		destoryTreeNode(T);
		T = nullptr;
	}

	if (T == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//****************************************************二分查找树函数声明****************************************************//

//辅助函数：创建二分查找树
//输入：二分查找树指针，顺序表，下限，上限
void creatJudgeTree(BiTree& T, seqP L, int min, int max)
{
	if (min <= max)
	{
		addTreeNode(T, L->data[(min + max) / 2]);

		creatJudgeTree(T->lChild, L, min, ((min + max) / 2 - 1));
		creatJudgeTree(T->rChild, L, ((min + max) / 2 + 1), max);
	}
}


//辅助函数：创建二分查找树
//输入：二分查找树指针，顺序表
//返回：成功返回true，失败返回false
bool creatJudgeTree(BiTree& T, seqP L)
{
	if (T != nullptr)
	{
		return false;
	}
	else
	{
		creatJudgeTree(T, L, 0, L->listLen - 1);

		return true;
	}
}


//****************************************************二分排序树函数声明****************************************************//

//实验九.查找.2：二叉排序树中插入结点
//输入：二叉树指针，插入元素值
void insertBiSearchTree(BiTree& T, elementType x)
{
	if (T == nullptr)
	{
		addTreeNode(T, x);
	}
	else if (T->data > x)
	{
		insertBiSearchTree(T->lChild, x);
	}
	else
	{
		insertBiSearchTree(T->rChild, x);
	}
}


//实验九.查找.2：创建平衡化二叉排序树
//输入：二叉树指针，顺序表，是否创建平衡树（是则传入true，否传入false，若不传入则默认为false）
//返回：成功返回true，失败返回false
bool creatBiSearchTree(BiTree& T, seqP L, bool AVL)
{
	int i = 0;

	if (!T)
	{
		for (i = 0; i < L->listLen; i++)
		{
			insertBiSearchTree(T, L->data[i]);
			if (AVL)
			{
				adjust(T);
			}
		}

		return true;
	}
	else
	{
		cout << "当前指针已占用！" << endl;

		return false;
	}
}


//实验九.查找.3：在二叉排序树中查找指定值结点
//输入：二叉树指针，查找元素值
//返回：成功返回结点指针，失败返回nullptr
BiTree searchBST(BiTree T, elementType data)
{
	while (T)
	{
#ifdef DEBUG
		cout << "当前比较结点为：" << T->data << endl;
#endif // DEBUG

		if (T->data > data)
		{
			T = T->lChild;
		}
		else if(T->data == data)
		{
#ifdef DEBUG
			cout << "查找成功！" << endl;
#endif // DEBUG

			return T;
		}
		else
		{
			T = T->rChild;
		}
	}
#ifdef DEBUG
	cout << "查找失败！" << endl;
#endif // DEBUG
	return nullptr;
}


//实验九.查找.4：二叉排序树删除结点
//输入：二叉树指针，删除元素值，是否调整为平衡树（是则传入true，否传入false，若不传入则默认为true）
//返回：成功返回true，失败返回false
bool deleteBSTNode(BiTree& T, elementType data, bool AVL)
{
	BiTree deleteP = nullptr, moveP = T;

	while (T)
	{
		if (moveP->data > data)
		{
			if (moveP->lChild && moveP->lChild->data == data)
			{
				deleteP = moveP->lChild;
				if (!deleteP->lChild)
				{
					moveP->lChild = deleteP->rChild;
					delete(deleteP);
				}
				else if (!deleteP->rChild)
				{
					moveP->lChild = deleteP->lChild;
					delete(deleteP);
				}
				else
				{
					moveP->lChild = deleteP->rChild;
					while (moveP->lChild)
					{
						moveP = T->lChild;
					}
					moveP->lChild = deleteP->lChild;
					delete(deleteP);
				}
				if (AVL)
				{
					adjust(T);
				}

				return true;
			}
			else
			{
				moveP = moveP->lChild;
			}
		}
		else if (moveP->data < data)
		{
			if (moveP->rChild && moveP->rChild->data == data)
			{
				deleteP = moveP->rChild;
				if (!deleteP->lChild)
				{
					moveP->rChild = deleteP->rChild;
					delete(deleteP);
				}
				else if (!deleteP->rChild)
				{
					moveP->rChild = deleteP->lChild;
					delete(deleteP);
				}
				else
				{
					moveP->rChild = deleteP->lChild;
					while (moveP->rChild)
					{
						moveP = moveP->rChild;
					}
					moveP->rChild = deleteP->rChild;
					delete(deleteP);
				}
				if (AVL)
				{
					adjust(T);
				}

				return true;
			}
			else
			{
				moveP = moveP->rChild;
			}
		}
		else									//该情况为删除结点为整棵树的根节点
		{
			deleteP = T;
			T = T->lChild;
			moveP = T;
			while (moveP->lChild)
			{
				moveP = moveP->lChild;
			}
			moveP->lChild = deleteP->rChild;
			delete(deleteP);
			if (AVL)
			{
				adjust(T);
			}

			return true;
		}
	}
	cout << "未找到对应元素！" << endl;

	return false;
}


//****************************************************平衡二叉树函数声明****************************************************//

//辅助函数：LL型调整
//输入：需调整的子树根节点
void LLAdjust(BiTree& T)
{
	BiTree save = nullptr;

	save = T;
	T = save->lChild;
	save->lChild = T->rChild;
	T->rChild = save;
}


//辅助函数：LR型调整
//输入：需调整的子树根节点
void LRAdjust(BiTree& T)
{
	BiTree save = nullptr;

	save = T;
	T = save->lChild->rChild;
	save->lChild->rChild = T->lChild;
	T->lChild = save->lChild;
	save->lChild = T->rChild;
	T->rChild = save;
}


//辅助函数：RR型调整
//输入：需调整的子树根节点
void RRAdjust(BiTree& T)
{
	BiTree save = nullptr;

	save = T;
	T = save->rChild;
	save->rChild = T->lChild;
	T->lChild = save;
}


//辅助函数：RL型调整
//输入：需调整的子树根节点
void RLAdjust(BiTree& T)
{
	BiTree save;

	save = T;
	T = save->rChild->lChild;
	save->rChild->lChild = T->rChild;
	T->rChild = save->rChild;
	save->rChild = T->lChild;
	T->lChild = save;
}


//辅助函数：二叉平衡树调整
//输入：需调整的树根节点
void adjust(BiTree& T)
{
	int lH = 0, rH = 0;

	if (T)
	{
		adjust(T->lChild);
		adjust(T->rChild);
		lH = getTreeHeight(T->lChild);
		rH = getTreeHeight(T->rChild);
		if ((lH - rH) >= 2)
		{
			lH = getTreeHeight(T->lChild->lChild);
			rH = getTreeHeight(T->lChild->rChild);
			if (lH >= rH)
			{
				LLAdjust(T);
			}
			else
			{
				LRAdjust(T);
			}
		}
		else if ((lH - rH) <= -2)
		{
			lH = getTreeHeight(T->rChild->lChild);
			rH = getTreeHeight(T->rChild->rChild);
			if (lH >= rH)
			{
				RLAdjust(T);
			}
			else
			{
				RRAdjust(T);
			}
		}
	}
}