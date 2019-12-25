#pragma once
#ifndef SEARCH_H

#define SEARCH_H

#define DEBUG

#include<iostream>
#include<math.h>

using namespace std;

#define elementType int
#define MAXLEN 100


//***********************˳���ṹ*************************//
typedef struct sList										//
{															//
	elementType data[MAXLEN];								//
	int listLen;											//
}seqList, * seqP;			//���������͡����ָ������	//
//**********************************************************//

//*********************�������ṹ����***********************//
typedef struct lBNode										//
{															//
	elementType data;										//
	struct lBNode* lChild, * rChild;						//
}BiNode, * BiTree;											//
//**********************************************************//

//**********************���������нṹ**********************//
//�����н��ṹ											//
typedef struct LNode										//
{															//
	BiTree point;					//����ַ���			//
	struct LNode* next;										//
}queueNode;													//
															//
//�����нṹ												//
typedef struct LNodes										//
{															//
	queueNode* front;				//��ͷָ��				//
	queueNode* rear;				//��βָ��				//
	bool flag = false;				//������ڴ�ӡ������	//
}linkQueue, * lQP;											//
//**********************************************************//


//************************************************��������******************************************************//
//���к�������																									//
bool initialQueue(lQP& Q);													//�����г�ʼ��						//
bool enQueue(lQP Q, BiTree data);											//���������						//
bool outQueue(lQP Q, BiTree& data);											//�����г���						//
//˳���������																								//
void showSeqList(seqP L);													//��ӡ˳���						//
int binarySearch(seqP L, elementType data);									//���ֲ���Ԫ��						//
//������ͨ�ú�������																							//
bool addTreeNode(BiTree& T, elementType x);									//�����������½��					//
int getTreeHeight(BiTree T);												//��������߶�						//
void getNodeFloor(BiTree T, elementType x, int floor, int& res);			//������������					//
int getNodeFloor(BiTree T, elementType x);									//������������					//
void printBST(BiTree T);													//��ӡ������						//
void destoryTreeNode(BiTree T);												//���ٶ�����						//
bool destoryTree(BiTree& T);												//���ٶ�����						//
//���ֲ�������������																							//
void creatJudgeTree(BiTree& T, seqP L, int min, int max);					//�������ֲ�����					//
bool creatJudgeTree(BiTree& T, seqP L);										//�������ֲ�����					//
//������������������																							//
void insertBiSearchTree(BiTree& T, elementType x);							//��������������ڵ�				//
bool creatBiSearchTree(BiTree& T, seqP L, bool AVL = false);				//����ƽ�⻯����������				//
BiTree searchBST(BiTree T, elementType data);								//�ڶ����������в���ָ��ֵ���		//
bool deleteBSTNode(BiTree& T, elementType data, bool AVL = true);			//����������ɾ�����				//
//ƽ���������������																							//
void LLAdjust(BiTree& T);													//LL��ƽ�⻯						//
void LRAdjust(BiTree& T);													//LR��ƽ�⻯						//
void RRAdjust(BiTree& T);													//RR��ƽ�⻯						//
void RLAdjust(BiTree& T);													//RL��ƽ�⻯						//
void adjust(BiTree& T);														//����ƽ����ƽ�⻯					//
//**************************************************************************************************************//

#endif // !SEARCH_H



//*********************************************************��������*********************************************************//

//******************************************************�����к�������******************************************************//

//���������������г�ʼ��
//���룺����ָ��
//���أ��ɹ�����true��ʧ�ܷ���false
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
		cout << "��ǰָ����ռ�ã����г�ʼ��ʧ�ܣ�" << endl;

		return false;
	}
}


//�������������������
//���룺����ָ�룬���ָ��
//���أ��ɹ�����true��ʧ�ܷ���false
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
		cout << "��ǰ����δ��ʼ�������ʧ�ܣ�" << endl;

		return false;
	}
}


//���������������г���
//���룺����ָ�룬����ָ��
//���أ��ɹ�����true��ʧ�ܷ���false
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
		cout << "��ǰ����δ��ʼ��������ʧ�ܣ�" << endl;

		return false;
	}
}


//******************************************************˳���������******************************************************//

//������������ӡ˳���
//���룺˳���ָ��
//��ӡ�������ڴ�ӡ˳�����Ԫ��
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


//ʵ���.����.1�����ֲ���Ԫ��
//���룺˳�������Ԫ��
//���أ����ҳɹ����ؽ���±꣬����ʧ�ܷ���-1
int binarySearch(seqP L, elementType data)
{
	int min = 0, max = L->listLen - 1, mid = 0;

	mid = (min + max) / 2;
#ifdef DEBUG
	cout << "����Ԫ��ֵ" << data << "\t���αȽ�Ԫ��Ϊ��\t";
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


//****************************************************������ͨ�ú�������****************************************************//

//���������������������½��
//���룺������ָ�룬˳���
//���أ��ɹ�����true��ʧ�ܷ���false
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
		cout << "��ǰ�����ռ�ã�" << endl;

		return false;
	}
}


//������������������ĸ߶�
//���룺������ָ�� 
//���أ��������߶�
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


//����������������������
//���룺���ֲ�����ָ�룬����Ԫ�أ���ǰ�㼶���ش�������ַ
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


//����������������������
//���룺���ֲ�����ָ�룬����Ԫ�أ���ǰ�㼶���ش�������ַ
//���أ����ҳɹ����ز�Σ�ʧ�ܷ���-1
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
		cout << "������δ������" << endl;

		return -1;
	}
}


//������������ӡ����������
//���룺���ֲ�����ָ�룬˳���
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


//�������������ٶ�����
//���룺���������ڵ�
void destoryTreeNode(BiTree T)
{
	if (T)
	{
		destoryTreeNode(T->lChild);
		destoryTreeNode(T->rChild);
		delete(T);
	}
}


//�������������ٶ�����
//���룺���������ڵ�
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


//****************************************************���ֲ�������������****************************************************//

//�����������������ֲ�����
//���룺���ֲ�����ָ�룬˳������ޣ�����
void creatJudgeTree(BiTree& T, seqP L, int min, int max)
{
	if (min <= max)
	{
		addTreeNode(T, L->data[(min + max) / 2]);

		creatJudgeTree(T->lChild, L, min, ((min + max) / 2 - 1));
		creatJudgeTree(T->rChild, L, ((min + max) / 2 + 1), max);
	}
}


//�����������������ֲ�����
//���룺���ֲ�����ָ�룬˳���
//���أ��ɹ�����true��ʧ�ܷ���false
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


//****************************************************������������������****************************************************//

//ʵ���.����.2�������������в�����
//���룺������ָ�룬����Ԫ��ֵ
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


//ʵ���.����.2������ƽ�⻯����������
//���룺������ָ�룬˳����Ƿ񴴽�ƽ������������true������false������������Ĭ��Ϊfalse��
//���أ��ɹ�����true��ʧ�ܷ���false
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
		cout << "��ǰָ����ռ�ã�" << endl;

		return false;
	}
}


//ʵ���.����.3���ڶ����������в���ָ��ֵ���
//���룺������ָ�룬����Ԫ��ֵ
//���أ��ɹ����ؽ��ָ�룬ʧ�ܷ���nullptr
BiTree searchBST(BiTree T, elementType data)
{
	while (T)
	{
#ifdef DEBUG
		cout << "��ǰ�ȽϽ��Ϊ��" << T->data << endl;
#endif // DEBUG

		if (T->data > data)
		{
			T = T->lChild;
		}
		else if(T->data == data)
		{
#ifdef DEBUG
			cout << "���ҳɹ���" << endl;
#endif // DEBUG

			return T;
		}
		else
		{
			T = T->rChild;
		}
	}
#ifdef DEBUG
	cout << "����ʧ�ܣ�" << endl;
#endif // DEBUG
	return nullptr;
}


//ʵ���.����.4������������ɾ�����
//���룺������ָ�룬ɾ��Ԫ��ֵ���Ƿ����Ϊƽ������������true������false������������Ĭ��Ϊtrue��
//���أ��ɹ�����true��ʧ�ܷ���false
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
		else									//�����Ϊɾ�����Ϊ�������ĸ��ڵ�
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
	cout << "δ�ҵ���ӦԪ�أ�" << endl;

	return false;
}


//****************************************************ƽ���������������****************************************************//

//����������LL�͵���
//���룺��������������ڵ�
void LLAdjust(BiTree& T)
{
	BiTree save = nullptr;

	save = T;
	T = save->lChild;
	save->lChild = T->rChild;
	T->rChild = save;
}


//����������LR�͵���
//���룺��������������ڵ�
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


//����������RR�͵���
//���룺��������������ڵ�
void RRAdjust(BiTree& T)
{
	BiTree save = nullptr;

	save = T;
	T = save->rChild;
	save->rChild = T->lChild;
	T->lChild = save;
}


//����������RL�͵���
//���룺��������������ڵ�
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


//��������������ƽ��������
//���룺������������ڵ�
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