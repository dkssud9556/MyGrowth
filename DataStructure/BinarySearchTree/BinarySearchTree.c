#include "BinarySearchTree.h"
#include <stdio.h>

void BSTMakeAndInit(BTreeNode** pRoot) {
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst) {
	return GetData(bst);
}

BTreeNode* BSTInsert(BTreeNode* pRoot, BSTData data) {
	BTreeNode* newNode;
	if (pRoot == NULL) {
		newNode = MakeBTreeNode();
		SetData(newNode, data);
		return newNode;
	}

	if (pRoot->data < data) pRoot->right = BSTInsert(pRoot->right, data);
	else if (pRoot->data > data) pRoot->left = BSTInsert(pRoot->left, data);
	else printf("\nKey[%d] exists.\n", data);
	return pRoot;
}

//BTreeNode* BSTInsert(BTreeNode* pBST, BSTData data)
//{
//	BTreeNode* newNode;
//	if (pBST == NULL) {
//		newNode = MakeBTreeNode();
//		SetData(newNode, data);
//		return newNode;
//	}
//
//	if (pBST->data < data) pBST->right = BSTInsert(pBST->right, data);
//	else if (pBST->data > data) pBST->left = BSTInsert(pBST->left, data);
//	else printf("\nKey[%d] exists.\n", data);
//	return pBST;
//}

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target) {
	if (bst == NULL)
		return NULL;

	if (bst->data < target)
		return BSTSearch(bst->right, target);
	else if (bst->data > target)
		return BSTSearch(bst->left, target);
	else
		return bst;
}

BTreeNode* BSTRemove(BTreeNode* pRoot, BSTData target)
{
	BTreeNode* parent, *p, *succ, *succ_parent, *child;
	parent = NULL;
	p = pRoot;
	
	while ((p != NULL) && (p->data != target)) // 삭제할 값을 찾는
	{
		parent = p;
		if (p->data < target) p = p->right;
		else p = p->left;
	}
	if (p == NULL) // 삭제하려는 값이 존재하지 않을 때
	{
		printf("\nKey[%d] is not exist\n", target);
		return pRoot;
	}
	if (p->right == NULL && p->left == NULL) // 삭제할 노드의 자식이 없을 때
	{
		if (parent != NULL)
		{
			if (parent->right == p) parent->right = NULL;
			else parent->left = NULL;
		}
		else pRoot = NULL;
	}
	else if (p->right == NULL || p->left == NULL) // 삭제할 노드의 자식이 하나일 때
	{
		if (p->left != NULL) child = p->left;
		else child = p->right;

		if (parent != NULL)
		{
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		else pRoot = child;
	}
	else // 삭제할 노드의 자식이 2개일 때
	{
		child = p->left;
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL)
		{
			succ_parent = succ;
			succ = succ->right;
		}
		p->data = succ->data;
		if (succ->left != NULL) succ_parent->right = succ->left;
		else succ_parent->right = NULL;
		p = succ;
	}
	free(p);

	return pRoot;
}

void BSTShowAll(BTreeNode* bst, char* szTitle)
{
	printf("Inorder Traversal[%s] : ", szTitle);
	InorderTraverse(bst, ShowIntData);
	printf("\n\n");
}

void ShowIntData(int data)
{
	printf("%d ", data);
}