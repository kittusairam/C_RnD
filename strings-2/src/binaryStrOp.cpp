/*

ProblemCODE : BINARYSTROP
Difficulty : Medium
Marks : 15

Given two binary numbers in form of strings and
a string representing "AND", "OR", "NOR" or "XOR". Return the output string which forms by doing the specified operation on those 2 strings .


Ex:	Input: "101", "111", op =  "OR"
Output: "111"


Ex:	Input: "10101", "1111", op =  "AND"
Output: "00101"

Ex:	Input: "0111", "1010", op =  "XOR"
Output: "0010"

Ex:	Input: "0011", "1010", op =  "NOR"
Output: "0100"

Note :
In the above representations ,Write those strings on a paper ,you will understand them better . [Align them to the Right]
If 1 string length is less than other ,you need to consider missing letters as 0's ie "1111" AND "1" is same as "1111" AND "0001".
Ie if a String is "" ,you should consider it as All 0's .This dosent not apply if String is NULL.

Reference : http://www.bristolwatch.com/pport/pics/logic_table.gif [For AND,OR,XOR]
For NOR : http://www.circuitstoday.com/wp-content/uploads/2010/04/2-Input-NOR-Gate-Truth-Table.jpg

Contraints :
String length < 50.
For 50% of TestCases ,only AND/OR operations will be given .

Difficulty : Medium

*/

#include <stdio.h>
#include <stdlib.h>
int len(char *c){
	if (c[0] != '\0')
	return len(&c[1]) + 1;
	return 0;
}

char *performOperation(char *str1, char *str2, char *operation){

	int i = len(str1)-1,j=len(str2)-1,k=0;
	k = i;
	if (i < j){
		k = j;
	}

	char *res = new char[1000];
	res[k + 1] = '\0';
	switch (operation[0]){
		case 'A':while (i>=0 && j>=0){
					res[k--] = ((str1[i--] - 48)&(str2[j--] - 48)) + 48;
				}
				 while (i>=0){
					 res[k--] = 48;
					 i--;
				 }
				 while (j>=0){
					 res[k--] = 48;
					 j--;
				 }
				 break;
		case 'O':while (i >= 0 && j >= 0){
					res[k--] = ((str1[i--] - 48)|(str2[j--] - 48)) + 48;
				}
				 while (i >= 0){
					 res[k--] = str1[i--];
				 }
				 while (j >= 0){
					 res[k--] = str2[j--];
				 }
				 break;
		case 'X':while (i >= 0 && j >= 0){
					res[k--] = ((str1[i--] - 48)^(str2[j--] - 48)) + 48;
					i++;
				}
				 while (i >= 0){
					 res[k--] = str1[i--];
				 }
				 while (j >= 0){
					 res[k--] = str2[j--];
				 }
				 break;
		case 'N':while (i >= 0 && j >= 0){
					int t = ((str1[i--] - 48) | (str2[j--] - 48));
					if (t == 0){
						res[k--] = 49;
					}
					else{
						res[k--] = 48;
					}
				 }
				 while (i >= 0){
					 if (str1[i--] == '0'){
						 res[k--] = 49;
					 }
					 else{
						 res[k--] = 48;
					 }
				 }
				 while (j >= 0){
					 if (str2[j--] == '0'){
						 res[k--] = 49;
					 }
					 else{
						 res[k--] = 48;
					 }
				 }
				 break;
	}
	return res;
}








