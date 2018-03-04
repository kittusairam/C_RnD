/*
Well Done for completing the first part of the C Course ,If you didnt finish
Do complete them and come here again .

Use MainArrays2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.s

Objectives of C-Arrays-2 Lesson:

->Handling Arrays of Structures
->Sorting Arrays
->Learning Complexities of your Algorithm

*/
#include <stdio.h>
#include "FunctionHeadersArrays2.h"

int main(){
	int arr[100000] = { 0 };
	int len = 100000;
	int i = 0;
	int totalElems = 0;
	for (i = 0; i < len; i++){
		arr[i] = i;
	}

	int expectedAns[2] = { len - 1, len - 1 };

	int *ans = getLeaderIndex(arr, len);
	for (int i = 0; i < 2; i++){
		printf("%d\t", ans[i]);
	}
	//Test findSingleOccurenceNumber

	//Test mergeSortedArray

	//Test sortedArraysCommonElements

	//Test others
	getchar();
	return 0;
}