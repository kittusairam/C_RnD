/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

int removeArrayDuplicates(int *Arr, int len)
{
	if (Arr == NULL || len <= 0){
		return -1;
	}
	for (int i = 0;i < len; i++){
		for (int j = i+1;j < len; j++){
			if (Arr[j] != -1&&Arr[i] == Arr[j]){
				Arr[j] = -1;
			}
		}
	}
	int *array = new int[50];
	int t = 0;
	for (int i = 0; i < len; i++){
		if (Arr[i] != -1){
			array[t++] = Arr[i];
		}
	}
	for (int i = 0; i < t; i++){
		Arr[i] = array[i];
	}
	return t;
}