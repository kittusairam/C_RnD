/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>

char * get_last_word(char * str){
	if (str == NULL){
		return NULL;
	}
	int i = 0,p,q;
	if (str[i] == '\0'){
		return str;
	}
	while (str[i] != '\0'){
		p = i;
		while (str[i] != ' '&&str[i] != '\0'){
			i++;
		}
		q = i;
		while (str[i] == ' '&&str[i] != '\0'){
			i++;
		}

	}
	str[q] = '\0';
	return &str[p];
}
