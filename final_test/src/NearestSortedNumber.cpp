/*
	problemCode : NearestSortedNumber
	score : 15

	A Sorted Number is a number in which all its digits are in non-decending order.
	for example "129" , "222", "345", "999" are all Sorted Numbers.
	Where as the numbers "110" , "1000", "143" are not Sorted Numbers.

	You are given an integer N in the form of a string.
	
	Your task is to find the the last Sorted Number in the range [1,N]

	Sorted Numbers = [1,2,3,4,5,6,7,8,9,  11,12,13,...19,  22,23,24,.... INF]

	Sample Cases : 
	N = 10, result = 9
	N = 12, result = 12
	N = 19, result = 19
	N = 21, result = 19

	Note : 
	1) if there is no answer or the input is invalid , return NULL
	2) Input consists of no leading zeros, and output should not consist of leading zeros
	returning "0002" instead of "2" is considered as a wrong answer.

	Constraints : 
	1 <= len <= 100000 (i.e 100000 digits not integer 100000)
*/


#include<stdio.h>
#include<malloc.h>

char * NearestSortedNumber(char *N, int len){
	if (N == NULL || len < 0){
		return NULL;
	}
	if (N[len / 2]<'0' || N[len / 2]>'9'){
		return NULL;
	}
	char *res = new char[len+1];
	int i = 0;
	while (i != len&&N[i] == '0'){
		i++;
	}
	int t = i;
	for (;i!=len; i++){
		res[i] = N[i];
	}
	res[len] = '\0';
	i = t;
	while (i<len&&N[i] < N[i + 1]){
		i++;
	}
	if (i == len-1){
		return res;
	}
	i++;
	res[i - 1] = N[i - 1] - 1;
	while (i<len){
		res[i] = '9';
		i++;
	}
	
	return res;
	
}

