/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for 
  octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.

2)Write a function which takes a fractional octal number as input and returns the hexadecimal number for 
octalToHexadecimalFraction() until precision two
E.g.: octalToHexadecimal(6.01) returns 6.04

INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>
#include<math.h>
int octalToHexadecimal(int num)
{
	if (num <= 0){
		return 0;
	}
	long int res = 0,result[32],top=-1;
	int i = 0;
	while (num){
		res += (num % 10)*(long int)pow(8.0, i++);
		num /= 10;
	}
	while (res){
		result[++top] = res % 16;
		res /= 16;
	}
	i = 0;
	while(i!=top+1){
		res +=(result[i]*(int)pow(10.0, i));
		i++;
	}
	return res;
}

float octalToHexadecimalFraction(float num)
{
	return 0.0;
}