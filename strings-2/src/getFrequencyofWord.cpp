/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>

int string_length(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}

int count_word_in_str_way_1(char *str, char *word){

	int i, j, word_len = string_length(word);
	int str_len = string_length(str);
	int count = 0, flag;
	for (i = 0; i <= str_len - word_len; i++)
	{
		flag = 1;
		for (j = i; j < i + word_len; j++)
		{
			if (str[j] != word[j - i])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			count++;
	}
	return count;
}
bool substring_compare(char *str, char *word, int i, int j)
{
	int k;
	bool flag = true;
	for (k = i; k <= j; k++)
	{
		if (str[k] != word[k - i])
		{
			flag = false;
			break;
		}
	}
	return flag;
}
void recur_count(char *str, char *word, int i, int j, int *count)
{

	if (i < string_length(str) - (j - i) + 1)
	{
		if (substring_compare(str, word, i, j))
			*count = *count + 1;
		i++;
		j++;
		recur_count(str, word, i, j, count);
	}
}


int count_word_int_str_way_2_recursion(char *str, char *word)
{
	int count = 0;
	recur_count(str, word, 0, string_length(word) - 1, &count);
	return count;

}
