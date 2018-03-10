/*
Problem Statement :

Check if a DOM (string format) is valid or not.
Take string as a input and validate if every opening tag end with closing tag.
valid tags are html, head, body, p.

consider the following priority for tags  [ html > head == body > p ]

Return false if you encounter a invalid tags.
For all invalid cases return -1; other wise 1

Eg: <html><head><body></body></head></html>  o/p : 1
<body><p></p></body> o/p : 1
<html><head></body></head></html> o/p: -1
<head><html></html></head> o/p: -1

In case of
- empty string return -1
- no tag return 1

NOTE : Donot use any Global Variables

Marks : 15
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int isStringValidDom(char* input) {
	if (input == NULL){
		return -1;
	}
	int len = strlen(input);
	int i = 0, j = len - 1;
	while (i < j){
		if (input[i] == input[j] || input[i] == '>'){
			if (input[i] == '>'&&input[j] != '/'){
				return -1;
			}
		}
		if (input[i] == '>'&&input[j] == '/'){
			i++;
			j = j - 2;
		}
		i++; j--;
	}
	return 1;
}