/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int grater_or_not(char *a, char *b ){
	int y1, y2, d1, d2, m1, m2;
	y1 = (a[6] - '0')*1000 + (a[7] - '0')*100 + (a[8] - '0')*10 + a[9] - '0';
	y2 = (b[6] - '0') * 1000 + (b[7] - '0') * 100 + (b[8] - '0') * 10 + b[9] - '0';
	m1 = (a[3] - '0') * 10 + (a[4] - '0');
	m2 = (b[3] - '0') * 10 + (b[4] - '0');
	d1 = (a[0] - '0') * 10 + (a[1] - '0');
	d2 = (b[0] - '0') * 10 + (b[1] - '0');
	if (y1 > y2){
		return 1;
	}
	else {
		if (y1 == y2){
			if (m1 > m2){
				return 1;
			}
			else{
				if (m1 == m2){
					if (d1 > d2){
						return 1;
					}
					else{
						if (d1 == d2){
							return 0;
						}
						return 2;
					}
				}
				return 2;
			}
		}
		return 2;
	}
}
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int count = 0;
	for (int i = 0; i < len; i++){
		if (grater_or_not(Arr[i].date, date) == 1){
			count++;
		}
	}
	return count;
}
