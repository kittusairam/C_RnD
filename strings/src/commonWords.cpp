/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31

char ** commonWords(char *str1, char *str2) {

	if (str1 == NULL &&str2 == NULL)
		return NULL;

	int i, j, k = 0, l = 0, x;
	int count = 0;
	int check = 0;
	char *p;
	char **temp;
	p = NULL;
	if (str1 == NULL&&str2 == NULL){
		return NULL;
	}
	temp = (char**)malloc(sizeof(char*) * 10);


	for (i = 0; str1[i] != '\0'; i++){
		for (j = 0; str2[j] != '\0'; j++){
			if (str1[i] == str2[j] && str1[i] != ' '&& str1[i + 1] == str2[j + 1] && str1[i + 1] != '\0' && str2[j + 1] != '\0')
			{

				count = 0;
				x = 0;
				while (str1[i] == str2[j] && str1[i] != ' '&& str1[i] != '\0'&&str2[j] != '\0'&&str1[i] != 32)
				{

					i++;
					j++;
					count++;
					check++;
				}
				temp[l] = (char*)malloc(sizeof(char)* count);

				for (k = i - count; k <i; k++)
				{
					temp[l][x] = str1[k];
					x++;

				}
				temp[l][x] = '\0';
				l++;
			}

		}
	}
	if (check != 0){
		return temp;
	}
	else{
		return NULL;
	}
}