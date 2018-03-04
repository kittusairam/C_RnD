/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};



int com_dates(char *date1, char* date2){
	int y1 = ((date1[6] - '0') * 1000 + (date1[7] - '0') * 100 + (date1[8] - '0') * 10 + (date1[9] - '0'));
	int y2 = ((date2[6] - '0') * 1000 + (date2[7] - '0') * 100 + (date2[8] - '0') * 10 + (date2[9] - '0'));
	return y1 - y2;
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	struct transaction * mergeTrans = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));
	int i = 0, j = 0, res = 0;
	while (i<ALen&&j<BLen)
	{
		int cmp = com_dates(A[i].date, B[j].date);
		if (cmp<0){
			mergeTrans[res] = A[i];
			i++;
			res++;
		}
		else if (cmp>0){
			mergeTrans[res] = B[j];
			j++;
			res++;
		}
		else
		{
			mergeTrans[res] = A[i];
			i++;
			res++;
			mergeTrans[res] = B[j];
			j++;
			res++;
		}
	}
	while (i < ALen)
	{
		mergeTrans[res] = A[i];
		i++;
		res++;
	}
	while (j<BLen)
	{
		mergeTrans[res] = B[j];
		j++;
		res++;
	}
	return mergeTrans;
}