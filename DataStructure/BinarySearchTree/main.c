#include <stdio.h>
#include "BinarySearchTree.h"


int main(void)
{

	BTreeNode* bstRoot;
	BTreeNode* sNode;    // search */

	BSTData insertKey[] = { 9,1,6,2,8,4,3,5,7,7,5 };   //교재에 나와있는 데이타 삽입 순서 뒤 7, 5 는 삽입실패를 위한 임의값으로 추가해넣었음. 
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
			printf("탐색 성공^*^ Key[%d] \n", searchKey[i]);
		else
			printf("탐색 실패  -_- Key[%d] \n", searchKey[i]);
	}


	//중위순회
	BSTShowAll(bstRoot, "삽입후 이진탐색트리 중위순회 결과");

	/* 노드 삭제*/
	for (i = 0; i < sizeof(searchKey) / sizeof(BSTData); i++) {
		BSTShowAll(bstRoot, "삭제전");
		bstRoot = BSTRemove(bstRoot, searchKey[i]);
		BSTShowAll(bstRoot, "삭제후");
	}

	return 0;
}