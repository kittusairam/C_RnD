/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<stdio.h>
char KthIndexFromEnd(char *str, int K) {

	if (K < 0 || str == NULL || str == '\0')
		return '\0';
	int length = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		length++;
	}
	if (length == 0 || K>length)
		return '\0';
	int count = 0;
	for (int i = length - 1; i >= 0; i--)
	{

		if (K == count)
			return str[i];
		count++;

	}
}