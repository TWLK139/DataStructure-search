#include"search.h"

int main(void)
{
	BiTree T = nullptr;
	int order = 0, res = 0;

	//测试数据
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
		cout << "实验九：查找实验" << endl;
		cout << "*****************************************" << endl;
		cout << "*1，二分查找及其判定树。\t\t*" << endl;
		cout << "*2，创建一般二叉排序树。\t\t*" << endl;
		cout << "*3，二叉排序树查找结点。\t\t*" << endl;
		cout << "*4，二叉排序树删除结点。\t\t*" << endl;
		cout << "*5，创建平衡二叉排序树。\t\t*" << endl;
		cout << "*\t\t\t\t\t*" << endl;
		cout << "*0，退出程序。\t\t\t\t*" << endl;
		cout << "*****************************************" << endl;
		cout << "请输入菜单编号：\t";
		cin >> order;

		switch (order)
		{
		case 1:
			system("cls");
			cout << "\t【九.1】\t二分查找及其判定树" << endl << endl;
			//第一组测试**********************************************************
			cout << "第一组实验：" << endl;
			cout << "测试数据：\t";
			showSeqList(&data[0]);
			cout << endl << endl;
			cout << "创建的二分查找判定树作为解释如下：" << endl;
			creatJudgeTree(T, &data[0]);
			printBST(T);
			//**********一组一次**********//
			cout << "\t第一次查找（2）：" << endl;
			res = binarySearch(&data[0], 2); 
			if (res >= 0)cout << "查找成功，下标为：" << res;
			else cout << "查找失败";
			cout << endl;
			//**********一组二次**********//
			cout << "\t第二次查找（8）：" << endl;
			res = binarySearch(&data[0], 8);
			if (res >= 0)cout << "查找成功，下标为：" << res;
			else cout << "查找失败";
			cout << endl;
			//**********一组三次**********//
			cout << "\t第三次查找（20）：" << endl;
			res = binarySearch(&data[0], 20);
			if (res >= 0)cout << "查找成功，下标为：" << res;
			else cout << "查找失败";
			cout << endl;
			//**********一组四次**********//
			cout << "\t第四次查找（30）：" << endl;
			res = binarySearch(&data[0], 30);
			if (res >= 0)cout << "查找成功，下标为：" << res;
			else cout << "查找失败";
			cout << endl;
			//**********一组五次**********//
			cout << "\t第五次查找（50）：" << endl;
			res = binarySearch(&data[0], 50);
			if (res >= 0)cout << "查找成功，下标为：" << res;
			else cout << "查找失败";
			cout << endl;
			//**********一组六次**********//
			cout << "\t第六次查找（5）：" << endl;
			res = binarySearch(&data[0], 5);
			if (res >= 0)cout << "查找成功，下标为：" << res;
			else cout << "查找失败";
			cout << endl;
			//**********一组七次**********//
			cout << "\t第七次查找（15）：" << endl;
			res = binarySearch(&data[0], 15);
			if (res >= 0)cout << "查找成功，下标为：" << res;
			else cout << "查找失败";
			cout << endl;
			//**********一组八次**********//
			cout << "\t第八次查找（33）：" << endl;
			res = binarySearch(&data[0], 33);
			if (res >= 0)cout << "查找成功，下标为：" << res;
			else cout << "查找失败";
			cout << endl;
			//**********一组九次**********//
			cout << "\t第九次查找（100）：" << endl;
			res = binarySearch(&data[0], 100);
			if (res >= 0)cout << "查找成功，下标为：" << res;
			else cout << "查找失败";
			cout << endl;
			//第一次实验结束，销毁树
			if (destoryTree(T))cout << "销毁成功！" << endl;
			else cout << "销毁失败！" << endl;
			//********************************************************************
			cout << endl;
			//第二组测试**********************************************************
			cout << "第二组实验：" << endl;
			cout << "测试数据：\t";
			showSeqList(&data[1]);
			cout << endl << endl;
			cout << "创建的二分查找判定树作为解释如下：" << endl;
			creatJudgeTree(T, &data[1]);
			printBST(T);
			//**********二组一次**********//
			cout << "\t第一次查找（22）：" << endl;
			res = binarySearch(&data[1], 22);
			if (res >= 0)cout << "查找成功，下标为：" << res;
			else cout << "查找失败";
			cout << endl;
			//**********二组二次**********//
			cout << "\t第二次查找（8）：" << endl;
			res = binarySearch(&data[1], 8);
			if (res >= 0)cout << "查找成功，下标为：" << res;
			else cout << "查找失败";
			cout << endl;
			//**********二组三次**********//
			cout << "\t第三次查找（80）：" << endl;
			res = binarySearch(&data[1], 80);
			if (res >= 0)cout << "查找成功，下标为：" << res;
			else cout << "查找失败";
			cout << endl;
			//**********二组四次**********//
			cout << "\t第四次查找（3）：" << endl;
			res = binarySearch(&data[1], 3);
			if (res >= 0)cout << "查找成功，下标为：" << res;
			else cout << "查找失败";
			cout << endl;
			//**********二组五次**********//
			cout << "\t第五次查找（100）：" << endl;
			res = binarySearch(&data[1], 100);
			if (res >= 0)cout << "查找成功，下标为：" << res;
			else cout << "查找失败";
			cout << endl;
			//**********二组六次**********//
			cout << "\t第六次查找（1）：" << endl;
			res = binarySearch(&data[1], 1);
			if (res >= 0)cout << "查找成功，下标为：" << res;
			else cout << "查找失败";
			cout << endl;
			//**********二组七次**********//
			cout << "\t第七次查找（13）：" << endl;
			res = binarySearch(&data[1], 13);
			if (res >= 0)cout << "查找成功，下标为：" << res;
			else cout << "查找失败";
			cout << endl;
			//**********二组八次**********//
			cout << "\t第八次查找（120）：" << endl;
			res = binarySearch(&data[1], 120);
			if (res >= 0)cout << "查找成功，下标为：" << res;
			else cout << "查找失败";
			cout << endl;
			//第二次实验结束，销毁树
			if (destoryTree(T))cout << "销毁成功！" << endl;
			else cout << "销毁失败！" << endl;
			//********************************************************************
			cout << endl;
			break;
		case 2:
			system("cls");
			cout << "\t【九.2】\t构建非平衡二叉排序树" << endl << endl;
			//第一组测试**********************************************************
			cout << "第一组实验：" << endl;
			cout << "测试数据：\t";
			showSeqList(&data[2]);
			cout << endl << endl;
			creatBiSearchTree(T, &data[2]);
			cout << "打印创建的排序树如下：" << endl;
			printBST(T);
			cout << endl;
			//第一次实验结束，销毁树
			if (destoryTree(T))cout << "销毁成功！" << endl;
			else cout << "销毁失败！" << endl;
			//********************************************************************
			cout << endl;
			//第二组测试**********************************************************
			cout << "第二组实验：" << endl;
			cout << "测试数据：\t";
			showSeqList(&data[3]);
			cout << endl << endl;
			creatBiSearchTree(T, &data[3]);
			cout << "打印创建的排序树如下：" << endl;
			printBST(T);
			cout << endl;
			//第二次实验结束，销毁树
			if (destoryTree(T))cout << "销毁成功！" << endl;
			else cout << "销毁失败！" << endl;
			//********************************************************************
			cout << endl;
			break;
		case 3:
			system("cls");
			cout << "\t【九.3】\t二叉排序树查找结点" << endl << endl;
			//第一组测试**********************************************************
			cout << "第一组实验：" << endl;
			cout << "测试数据：\t";
			showSeqList(&data[2]);
			cout << endl << endl;
			creatBiSearchTree(T, &data[2]);
			cout << "打印创建的排序树如下：" << endl;
			printBST(T);
			//**********一组一次**********//
			cout << "\t第一次查找（150）：" << endl;
			searchBST(T, 150);
			cout << endl;
			//**********一组二次**********//
			cout << "\t第二次查找（70）：" << endl;
			searchBST(T, 70);
			cout << endl;
			//**********一组三次**********//
			cout << "\t第三次查找（160）：" << endl;
			searchBST(T, 160);
			cout << endl;
			//**********一组四次**********//
			cout << "\t第四次查找（190）：" << endl;
			searchBST(T, 190);
			cout << endl;
			//**********一组五次**********//
			cout << "\t第五次查找（10）：" << endl;
			searchBST(T, 10);
			cout << endl;
			//**********一组六次**********//
			cout << "\t第六次查找（55）：" << endl;
			searchBST(T, 55);
			cout << endl;
			//**********一组七次**********//
			cout << "\t第七次查找（175）：" << endl;
			searchBST(T, 175);
			cout << endl;
			//第一次实验结束，销毁树
			if (destoryTree(T))cout << "销毁成功！" << endl;
			else cout << "销毁失败！" << endl;
			//********************************************************************
			cout << endl;
			break;
		case 4:
			system("cls");
			cout << "\t【九.4】\t二叉排序树删除结点" << endl << endl;
			//第一组测试**********************************************************
			cout << "第一组实验：" << endl;
			cout << "测试数据：\t";
			showSeqList(&data[2]);
			cout << endl << endl;
			creatBiSearchTree(T, &data[2]);
			cout << "打印创建的排序树如下：" << endl;
			printBST(T);
			//**********一组一次**********//
			cout << "\t第一次删除（30）：" << endl;
			//creatBiSearchTree(T, &data[2]);
			deleteBSTNode(T, 30, false);
			printBST(T);
			if (destoryTree(T))cout << "销毁成功！" << endl;
			else cout << "销毁失败！" << endl;
			//**********一组二次**********//
			cout << "\t第二次删除（150）：" << endl;
			creatBiSearchTree(T, &data[2]);
			deleteBSTNode(T, 150, false);
			printBST(T);
			if (destoryTree(T))cout << "销毁成功！" << endl;
			else cout << "销毁失败！" << endl;
			//**********一组三次**********//
			cout << "\t第三次删除（100）：" << endl;
			creatBiSearchTree(T, &data[2]);
			deleteBSTNode(T, 100, false);
			printBST(T);
			if (destoryTree(T))cout << "销毁成功！" << endl;
			else cout << "销毁失败！" << endl;
			//********************************************************************
			cout << endl;
			break;
		case 5:
			system("cls");
			cout << "\t【九.5】\t创建平衡二叉排序树" << endl << endl;
			//第一组测试**********************************************************
			cout << "第一组实验：" << endl;
			cout << "测试数据：\t";
			showSeqList(&data[4]);
			cout << endl << endl;
			creatBiSearchTree(T, &data[4], true);
			cout << "打印创建的排序树如下：" << endl;
			printBST(T);
			cout << endl;
			//第一次实验结束，销毁树
			if (destoryTree(T))cout << "销毁成功！" << endl;
			else cout << "销毁失败！" << endl;
			//********************************************************************
			cout << endl;
			//第二组测试**********************************************************
			cout << "第二组实验：" << endl;
			cout << "测试数据：\t";
			showSeqList(&data[5]);
			cout << endl << endl;
			creatBiSearchTree(T, &data[5], true);
			cout << "打印创建的排序树如下：" << endl;
			printBST(T);
			cout << endl;
			//第二次实验结束，销毁树
			if (destoryTree(T))cout << "销毁成功！" << endl;
			else cout << "销毁失败！" << endl;
			//********************************************************************
			cout << endl;
			break;
		case 0:
			if (destoryTree(T))cout << "销毁成功！" << endl;
			else cout << "销毁失败！" << endl;
			cout << "退出程序！" << endl;
			return 0;
		default:
			system("cls");
			cout << "输入错误！" << endl;
			break;
		}
	}

	return 0;
}