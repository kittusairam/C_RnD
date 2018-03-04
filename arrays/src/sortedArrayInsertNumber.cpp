/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use memory allocation techniques to allocate memory.

ProblemCode :SAIN
*/

#include <stdio.h>
#include <malloc.h>

#include <stdio.h>
#include <malloc.h>

int findPos(int *Arr, int len, int num);
int * insertNum(int * Arr, int, int, int);

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (Arr == NULL || len < 0)
		return NULL;
	else
	{
		Arr = (int *)realloc(Arr, (len + 1)*sizeof(int));
		return insertNum(Arr, len, num, findPos(Arr, len, num));
	}
}

int findPos(int *Arr, int len, int num){
	int counter;
	if (Arr[0]>num)
		return 0;
	else if (Arr[len - 1]<num){
		return len;
	}
	else
	{
		for (counter = 1; counter < len; counter++){
			if (Arr[counter - 1]<num && Arr[counter]>num)
				return counter;
		}

	}
}

int * insertNum(int *Arr, int len, int num, int pos){
	int counter = len;
	while (counter > pos){
		Arr[counter] = Arr[counter - 1];
		counter--;
	}
	Arr[pos] = num;
	len++;
	return Arr;
}