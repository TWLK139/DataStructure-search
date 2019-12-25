#include"search.h"

int main(void)
{
	BiTree T = nullptr;
	int order = 0, res = 0;

	//��������
	seqList data[6] = {
		{
			{1,2,3,4,6,7,8,9,10,11,12,13,17,18,19,20,24,25,26,30,35,40,45,50,100},
			25
		},
		{
			{2,3,5,7,8,10,12,15,18,20,22,25,30,35,40,45,50,55,60,80,100},
			21
		},
		{
			{100,150,120,50,70,60,80,170,180,160,110,30,40,35,175},
			15
		},
		{
			{100,70,60,80,150,120,50,160,30,40,170,180,175,35},
			14
		},
		{
			{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26},
			26
		},
		{
			{1,3,6,10,15,21,28,36,45,55,66,78,91,105,120,136,153,171,190,210,231,253,277,302,328},
			25
		}
	};

	while (1)
	{
		cout << "ʵ��ţ�����ʵ��" << endl;
		cout << "*****************************************" << endl;
		cout << "*1�����ֲ��Ҽ����ж�����\t\t*" << endl;
		cout << "*2������һ�������������\t\t*" << endl;
		cout << "*3���������������ҽ�㡣\t\t*" << endl;
		cout << "*4������������ɾ����㡣\t\t*" << endl;
		cout << "*5������ƽ�������������\t\t*" << endl;
		cout << "*\t\t\t\t\t*" << endl;
		cout << "*0���˳�����\t\t\t\t*" << endl;
		cout << "*****************************************" << endl;
		cout << "������˵���ţ�\t";
		cin >> order;

		switch (order)
		{
		case 1:
			system("cls");
			cout << "\t����.1��\t���ֲ��Ҽ����ж���" << endl << endl;
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飺" << endl;
			cout << "�������ݣ�\t";
			showSeqList(&data[0]);
			cout << endl << endl;
			cout << "�����Ķ��ֲ����ж�����Ϊ�������£�" << endl;
			creatJudgeTree(T, &data[0]);
			printBST(T);
			//**********һ��һ��**********//
			cout << "\t��һ�β��ң�2����" << endl;
			res = binarySearch(&data[0], 2); 
			if (res >= 0)cout << "���ҳɹ����±�Ϊ��" << res;
			else cout << "����ʧ��";
			cout << endl;
			//**********һ�����**********//
			cout << "\t�ڶ��β��ң�8����" << endl;
			res = binarySearch(&data[0], 8);
			if (res >= 0)cout << "���ҳɹ����±�Ϊ��" << res;
			else cout << "����ʧ��";
			cout << endl;
			//**********һ������**********//
			cout << "\t�����β��ң�20����" << endl;
			res = binarySearch(&data[0], 20);
			if (res >= 0)cout << "���ҳɹ����±�Ϊ��" << res;
			else cout << "����ʧ��";
			cout << endl;
			//**********һ���Ĵ�**********//
			cout << "\t���Ĵβ��ң�30����" << endl;
			res = binarySearch(&data[0], 30);
			if (res >= 0)cout << "���ҳɹ����±�Ϊ��" << res;
			else cout << "����ʧ��";
			cout << endl;
			//**********һ�����**********//
			cout << "\t����β��ң�50����" << endl;
			res = binarySearch(&data[0], 50);
			if (res >= 0)cout << "���ҳɹ����±�Ϊ��" << res;
			else cout << "����ʧ��";
			cout << endl;
			//**********һ������**********//
			cout << "\t�����β��ң�5����" << endl;
			res = binarySearch(&data[0], 5);
			if (res >= 0)cout << "���ҳɹ����±�Ϊ��" << res;
			else cout << "����ʧ��";
			cout << endl;
			//**********һ���ߴ�**********//
			cout << "\t���ߴβ��ң�15����" << endl;
			res = binarySearch(&data[0], 15);
			if (res >= 0)cout << "���ҳɹ����±�Ϊ��" << res;
			else cout << "����ʧ��";
			cout << endl;
			//**********һ��˴�**********//
			cout << "\t�ڰ˴β��ң�33����" << endl;
			res = binarySearch(&data[0], 33);
			if (res >= 0)cout << "���ҳɹ����±�Ϊ��" << res;
			else cout << "����ʧ��";
			cout << endl;
			//**********һ��Ŵ�**********//
			cout << "\t�ھŴβ��ң�100����" << endl;
			res = binarySearch(&data[0], 100);
			if (res >= 0)cout << "���ҳɹ����±�Ϊ��" << res;
			else cout << "����ʧ��";
			cout << endl;
			//��һ��ʵ�������������
			if (destoryTree(T))cout << "���ٳɹ���" << endl;
			else cout << "����ʧ�ܣ�" << endl;
			//********************************************************************
			cout << endl;
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飺" << endl;
			cout << "�������ݣ�\t";
			showSeqList(&data[1]);
			cout << endl << endl;
			cout << "�����Ķ��ֲ����ж�����Ϊ�������£�" << endl;
			creatJudgeTree(T, &data[1]);
			printBST(T);
			//**********����һ��**********//
			cout << "\t��һ�β��ң�22����" << endl;
			res = binarySearch(&data[1], 22);
			if (res >= 0)cout << "���ҳɹ����±�Ϊ��" << res;
			else cout << "����ʧ��";
			cout << endl;
			//**********�������**********//
			cout << "\t�ڶ��β��ң�8����" << endl;
			res = binarySearch(&data[1], 8);
			if (res >= 0)cout << "���ҳɹ����±�Ϊ��" << res;
			else cout << "����ʧ��";
			cout << endl;
			//**********��������**********//
			cout << "\t�����β��ң�80����" << endl;
			res = binarySearch(&data[1], 80);
			if (res >= 0)cout << "���ҳɹ����±�Ϊ��" << res;
			else cout << "����ʧ��";
			cout << endl;
			//**********�����Ĵ�**********//
			cout << "\t���Ĵβ��ң�3����" << endl;
			res = binarySearch(&data[1], 3);
			if (res >= 0)cout << "���ҳɹ����±�Ϊ��" << res;
			else cout << "����ʧ��";
			cout << endl;
			//**********�������**********//
			cout << "\t����β��ң�100����" << endl;
			res = binarySearch(&data[1], 100);
			if (res >= 0)cout << "���ҳɹ����±�Ϊ��" << res;
			else cout << "����ʧ��";
			cout << endl;
			//**********��������**********//
			cout << "\t�����β��ң�1����" << endl;
			res = binarySearch(&data[1], 1);
			if (res >= 0)cout << "���ҳɹ����±�Ϊ��" << res;
			else cout << "����ʧ��";
			cout << endl;
			//**********�����ߴ�**********//
			cout << "\t���ߴβ��ң�13����" << endl;
			res = binarySearch(&data[1], 13);
			if (res >= 0)cout << "���ҳɹ����±�Ϊ��" << res;
			else cout << "����ʧ��";
			cout << endl;
			//**********����˴�**********//
			cout << "\t�ڰ˴β��ң�120����" << endl;
			res = binarySearch(&data[1], 120);
			if (res >= 0)cout << "���ҳɹ����±�Ϊ��" << res;
			else cout << "����ʧ��";
			cout << endl;
			//�ڶ���ʵ�������������
			if (destoryTree(T))cout << "���ٳɹ���" << endl;
			else cout << "����ʧ�ܣ�" << endl;
			//********************************************************************
			cout << endl;
			break;
		case 2:
			system("cls");
			cout << "\t����.2��\t������ƽ�����������" << endl << endl;
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飺" << endl;
			cout << "�������ݣ�\t";
			showSeqList(&data[2]);
			cout << endl << endl;
			creatBiSearchTree(T, &data[2]);
			cout << "��ӡ���������������£�" << endl;
			printBST(T);
			cout << endl;
			//��һ��ʵ�������������
			if (destoryTree(T))cout << "���ٳɹ���" << endl;
			else cout << "����ʧ�ܣ�" << endl;
			//********************************************************************
			cout << endl;
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飺" << endl;
			cout << "�������ݣ�\t";
			showSeqList(&data[3]);
			cout << endl << endl;
			creatBiSearchTree(T, &data[3]);
			cout << "��ӡ���������������£�" << endl;
			printBST(T);
			cout << endl;
			//�ڶ���ʵ�������������
			if (destoryTree(T))cout << "���ٳɹ���" << endl;
			else cout << "����ʧ�ܣ�" << endl;
			//********************************************************************
			cout << endl;
			break;
		case 3:
			system("cls");
			cout << "\t����.3��\t�������������ҽ��" << endl << endl;
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飺" << endl;
			cout << "�������ݣ�\t";
			showSeqList(&data[2]);
			cout << endl << endl;
			creatBiSearchTree(T, &data[2]);
			cout << "��ӡ���������������£�" << endl;
			printBST(T);
			//**********һ��һ��**********//
			cout << "\t��һ�β��ң�150����" << endl;
			searchBST(T, 150);
			cout << endl;
			//**********һ�����**********//
			cout << "\t�ڶ��β��ң�70����" << endl;
			searchBST(T, 70);
			cout << endl;
			//**********һ������**********//
			cout << "\t�����β��ң�160����" << endl;
			searchBST(T, 160);
			cout << endl;
			//**********һ���Ĵ�**********//
			cout << "\t���Ĵβ��ң�190����" << endl;
			searchBST(T, 190);
			cout << endl;
			//**********һ�����**********//
			cout << "\t����β��ң�10����" << endl;
			searchBST(T, 10);
			cout << endl;
			//**********һ������**********//
			cout << "\t�����β��ң�55����" << endl;
			searchBST(T, 55);
			cout << endl;
			//**********һ���ߴ�**********//
			cout << "\t���ߴβ��ң�175����" << endl;
			searchBST(T, 175);
			cout << endl;
			//��һ��ʵ�������������
			if (destoryTree(T))cout << "���ٳɹ���" << endl;
			else cout << "����ʧ�ܣ�" << endl;
			//********************************************************************
			cout << endl;
			break;
		case 4:
			system("cls");
			cout << "\t����.4��\t����������ɾ�����" << endl << endl;
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飺" << endl;
			cout << "�������ݣ�\t";
			showSeqList(&data[2]);
			cout << endl << endl;
			creatBiSearchTree(T, &data[2]);
			cout << "��ӡ���������������£�" << endl;
			printBST(T);
			//**********һ��һ��**********//
			cout << "\t��һ��ɾ����30����" << endl;
			//creatBiSearchTree(T, &data[2]);
			deleteBSTNode(T, 30, false);
			printBST(T);
			if (destoryTree(T))cout << "���ٳɹ���" << endl;
			else cout << "����ʧ�ܣ�" << endl;
			//**********һ�����**********//
			cout << "\t�ڶ���ɾ����150����" << endl;
			creatBiSearchTree(T, &data[2]);
			deleteBSTNode(T, 150, false);
			printBST(T);
			if (destoryTree(T))cout << "���ٳɹ���" << endl;
			else cout << "����ʧ�ܣ�" << endl;
			//**********һ������**********//
			cout << "\t������ɾ����100����" << endl;
			creatBiSearchTree(T, &data[2]);
			deleteBSTNode(T, 100, false);
			printBST(T);
			if (destoryTree(T))cout << "���ٳɹ���" << endl;
			else cout << "����ʧ�ܣ�" << endl;
			//********************************************************************
			cout << endl;
			break;
		case 5:
			system("cls");
			cout << "\t����.5��\t����ƽ�����������" << endl << endl;
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飺" << endl;
			cout << "�������ݣ�\t";
			showSeqList(&data[4]);
			cout << endl << endl;
			creatBiSearchTree(T, &data[4], true);
			cout << "��ӡ���������������£�" << endl;
			printBST(T);
			cout << endl;
			//��һ��ʵ�������������
			if (destoryTree(T))cout << "���ٳɹ���" << endl;
			else cout << "����ʧ�ܣ�" << endl;
			//********************************************************************
			cout << endl;
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飺" << endl;
			cout << "�������ݣ�\t";
			showSeqList(&data[5]);
			cout << endl << endl;
			creatBiSearchTree(T, &data[5], true);
			cout << "��ӡ���������������£�" << endl;
			printBST(T);
			cout << endl;
			//�ڶ���ʵ�������������
			if (destoryTree(T))cout << "���ٳɹ���" << endl;
			else cout << "����ʧ�ܣ�" << endl;
			//********************************************************************
			cout << endl;
			break;
		case 0:
			if (destoryTree(T))cout << "���ٳɹ���" << endl;
			else cout << "����ʧ�ܣ�" << endl;
			cout << "�˳�����" << endl;
			return 0;
		default:
			system("cls");
			cout << "�������" << endl;
			break;
		}
	}

	return 0;
}