
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:

Problem Code :SC
*/

#include <stdio.h>

int binarySearch(int *, int, int, int);

void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {

	int index;

	if (Arr != NULL&&len > 0){ //check for invalid

		index = binarySearch(Arr, score, 0, len - 1);

		if (index != -1)
		{
			int count, count1 = 0;
			for (count = 0; Arr[count] == score; count++)
				count1++;
			if (count1 == len){
				*lessCount = 0;
				*moreCount = 0;
				return 0;
			}
			*lessCount = index;
			*moreCount = len - index - 1;
			return 0;
		}
		else
		{
			int count;

			for (count = 0; count < len; count++) {
				if (Arr[count]>score)
					break;
			}

			*lessCount = count;
			*moreCount = len - count;
		}
	}
	return NULL;
}

int binarySearch(int *Arr, int searchEle, int start, int last){
	int middle = (start + last) / 2;
	if (start <= last){

		if (Arr[middle] == searchEle)
		{
			return middle;
		}

		else if (Arr[middle] > searchEle){
			last = middle - 1;
		}
		else
		{
			start = middle + 1;
		}
		return binarySearch(Arr, searchEle, start, last);
	}
	else
		return -1;
}
