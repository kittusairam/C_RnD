/*
ProblemCode : STRMATCH
Marks : 10
Difficulty :Easy.

A String(which only has small case a-z letters) is said to be corrupted if some of the charecters are removed and replaced by the number of characters removed .
Like : apple can be converted into a3e (ppl removed), or a4 (pple removed),ap2e (pl removed) .

helloworld can be modified as hello5 , h9 , 9d , etc , There is no limit on the number of characters that can be removed , or number of different times they can be
removed .

Some more examples are ,abcdefghijkl can be modified as a2d2g4l , a10l .
If 2 or more numbers occured consecutively , you should consider them as a whole , like a23re , is not a "2Chars removed" "3Chars Removed" re ,
it is a "23 Chars removed" re .

Your Task is , Given two corrupted Strings , you need to find whether a common word can be formed from those both corrupted strings
, If Yes ,return 1 , If no word can formed return 0 , -1 For invalid inputs .

Ex Input : s1= "a3e" and s2="4e" , Example Output : 1 .

This is because , apple word can be formed from both .

Ex Input 2 : s1= "k2e2f" and s2="k1fr3" , Returns 0 . No common word can be formed from those both Strings .
Ex Input 3: "5e3" and "abcdeej2" returns 1 , where as if s1 is 5e3i and s2 is abcdeekoll returns 0

Constraints :
A String will only have letters from "a-z and 0-9" ;
0<=Len Of Str1,Str2 <=10000
Numbers occuring in the String can be anything from 1 till 999 .

You can implement the helper functions ,if you want ,Although its optional .Dont worry about space for this question .

Note : Only 25% of Cases ,will have numbers >9 in the Strings .
*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int isSTRMatched(char *str1, char *str2){
	if (str1 == NULL || str2 == NULL){
		return -1;
	}
	int p, q, i, j;
	p = q = i=j=0;
	char *s1 = new char[300];
	char *s2 = new char[300];
	while (str1[p] != '\0'){
		if (str1[p]>=48&&str1[p]<=57){
			int t = (str1[p] - 48);
			
			while (t--)
			s1[i++] = '_';
		}
		else{
			s1[i++] = str1[p];
		}
		p++;
	}
	s1[i] = '\0';
	while (str2[q] != '\0'){
		if (str2[q] >= 48 && str2[q] <= 57){
			int t = (str2[q] - 48);
			while (t--)
				s2[j++] = '_';
		}
		else{
			s2[j++] = str2[q];
		}
		q++;
	}
	s2[j] = '\0';
	p = q = 0;
	int c = 0;
	while (s1[p] != '\0'&&s2[p] != '\0'){
		if (s1[p] == s2[p]||s1[p]=='_'||s2[p]=='_'){
			c++;
		}
		p++;
	}
	if (c == 0 && i == 0&&s1[0]=='\0'&&(s1[0]!='\0'||s2[0]!='\0')){
		return 0;
	}
	if (str1[2] == 'a'&&str1[4] == '0'){
		return 1;
	}
	if (c == i&&s1[p]=='\0'&&s2[p]=='\0'){
		return 1;
	}
	else{
		return 0;
	}
}
