#include <stdio.h>
#include "BinarySearchTree.h"


int main(void)
{

	BTreeNode* bstRoot;
	BTreeNode* sNode;    // search */

	BSTData insertKey[] = { 9,1,6,2,8,4,3,5,7,7,5 };   //���翡 �����ִ� ����Ÿ ���� ���� �� 7, 5 �� ���Խ��и� ���� ���ǰ����� �߰��س־���. 
	BSTData searchKey[] = { 9,3, 3,1,6,2,13,8,4,3,5,7,10 };

	//BSTData insertKey[] = { 13, 20, 3, 6, 7, 4, 18, 22, 32, 1 };
	//BSTData searchKey[] = { 20 };

	//BSTData insertKey[] = {20, 15, 35, 12, 18, 70, 37 };
	//BSTData searchKey[] = {20 }; 


	int i = 0;
	char szDesc[64];

	BSTMakeAndInit(&bstRoot);

	bstRoot = BSTInsert(bstRoot, insertKey[i]);
	for (i = 1; i < sizeof(insertKey) / sizeof(BSTData); i++)
		BSTInsert(bstRoot, insertKey[i]);

	for (i = 0; i < sizeof(searchKey) / sizeof(BSTData); i++) {
		if (sNode = BSTSearch(bstRoot, searchKey[i]))
			printf("Ž�� ����^*^ Key[%d] \n", searchKey[i]);
		else
			printf("Ž�� ����  -_- Key[%d] \n", searchKey[i]);
	}


	//������ȸ
	BSTShowAll(bstRoot, "������ ����Ž��Ʈ�� ������ȸ ���");

	/* ��� ����*/
	for (i = 0; i < sizeof(searchKey) / sizeof(BSTData); i++) {
		BSTShowAll(bstRoot, "������");
		bstRoot = BSTRemove(bstRoot, searchKey[i]);
		BSTShowAll(bstRoot, "������");
	}

	return 0;
}