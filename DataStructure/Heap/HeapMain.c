#include <stdio.h>
#include <math.h>
#include "Heap.h"

int Square(int d1, int d2) {
	if (d2 == 0)
		return 1;
	int a = 1;
	for (int i = 0; i < d2; i++)
		a *= d1;
	return a;
}

int DataPriorityComp(int ch1, int ch2)
{
	//return ch2-ch1;		// Min Heap
	return ch1 - ch2;			// Max Heap
}

/* 힙을 인덱스 순서로 선형으로 출력하는 함수*/
void PrintHeap(Heap* heap, char* szTitle)
{
	printf("================================\n%s\n================================\n ", szTitle);
	int heapLen = heap->numOfData;
	int i;
	for (i = 1; i <= heapLen; i++)
		printf("%d ", heap->heapArr[i]);
	puts("");
}

double logN(double x, double base) {
	return log(x) / log(base);
}

int getHTree(int n) {
	return (int)logN((double)n, 2.0);
}

/* 힙을 트리모양으로 출력하는 함수*/
void PrintHeapTree(Heap* heap, char* szTitle)
{
	int height = getHTree(heap->numOfData) + 1, count = 1;
	for (int i = height, l = 0; i > 0; i--, l++) {
		int gaesu = Square(2, l);
		for (int k = 0; k < gaesu; k++) {
			if (heap->numOfData < count) {
				puts("");
				return;
			}
			for (int j = Square(2, i - 1) - 1; j > 0; j--) {
				printf("  ");
			}
			if (k != 0) {
				for (int j = Square(2, i - 1); j > 0; j--) {
					printf("  ");
				}
			}
			printf("%2d", heap->heapArr[count++]);
		}
		puts("");
	}
}

int main(void)
{
	Heap heap;
	int i, nSizeItemList = 0;

	//int ItemList[] = { 24, 17, 29, 22, 20, 31, 27, 18, 21 };	
	//int ItemList[] = { 4, 16, 57, 9, 32, 45, 20, 19 };	
	int ItemList[] = { 50, 40, 30, 25, 30, 20, 10, 5, 15, 20 };	
	//int ItemList[] = { 50, 40, 30, 25, 30 };

	nSizeItemList = sizeof(ItemList) / sizeof(int);

	HeapInit(&heap, DataPriorityComp);

	for (i = 0; i < nSizeItemList; i++)
	{
		HInsert(&heap, ItemList[i]);
	}

	PrintHeap(&heap, "삽입후");
	PrintHeapTree(&heap, "트리의 모양");

	HInsert(&heap, 45);
	HInsert(&heap, 60);
	PrintHeap(&heap, "데이타 40, 60 삽입후");
	PrintHeapTree(&heap, "트리의 모양");


	HDelete(&heap);
	PrintHeap(&heap, "데이타 1개 삭제후");
	PrintHeapTree(&heap, "트리의 모양");

	return 0;
}