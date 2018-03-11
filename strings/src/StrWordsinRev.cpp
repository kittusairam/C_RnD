/*
OVERVIEW: Given a string, reverse all the words not the string.
E.g.: Input: "i like coding". Output: "coding like i"
INPUTS: A string.
OUTPUT: Modify the string according to the logic.
NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void str_words_in_rev(char *input, int len){
	char str[100];
	int j = 0, i, k;
	for (i = len; i >= 0; i--)
	{
		if (input[i - 1] == ' ' || i == 0)
		{
			for (k = i; input[k] != ' '&&k<len; k++)
			{

				str[j] = input[k];
				j++;


			}

			str[j] = ' ';
			j++;
		}

	}
	str[j] = '\0';

	for (int i = 0; i<j; i++)
	{
		input[i] = str[i];
		// printf("%c",str[i]);
		//printf("%c", input[i]);
	}


}