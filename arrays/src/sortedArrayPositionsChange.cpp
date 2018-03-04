/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

Problem Code :SAP
*/

#include <stdio.h>

void poschange(int *Arr, int len);
void swap(int *Arr, int pos1, int pos2){
	int temp = Arr[pos1];
	Arr[pos1] = Arr[pos2];
	Arr[pos2] = temp;
}
void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr == NULL || len < 2)
		return NULL;
	else
	{
		poschange(Arr, len);

		return Arr;
	}
}

void poschange(int *Arr, int len){
	int pos1 = -1, pos2 = -1;
	int flag1 = 0, flag2 = 0, i;
	for (i = 0; i < len - 1; i++){
		if (Arr[i + 1] < Arr[i] && flag1 != 1){

			pos1 = i;
			flag1 = 1;
		}
		else if (Arr[i + 1] < Arr[i] && flag2 != 1 && flag1 == 1){

			pos2 = i + 1;
			flag2 = 1;
		}
	}

	if (flag2 == 0){
		pos2 = pos1 + 1;
		flag2 = 1;
	}
	if (flag1 && flag2){
		swap(Arr, pos1, pos2);
	}
}