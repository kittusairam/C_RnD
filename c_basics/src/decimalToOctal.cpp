/*
OVERVIEW: 
1)Write a function which takes a decimal number as input and returns the octal number for decimalToOctal().
E.g.: decimalToOctal(10) returns 12.

2)Write a function which takes a fractional decimal number as input and returns the octal number for decimalToOctalFraction()
until precision two
E.g.: decimalToOctal(6.06) returns 6.03

INPUTS: Single decimal number num;

OUTPUT: Octal value of the Decimal Number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>
#include<math.h>
int decimalToOctal(int num)
{
	if (num<0){
		return 0;
	}
	int res = 0,j=0;
	while (num){
		res += (num % 8) * (int)pow(10.0, j++);
		num /= 8;
	}
	return res;
}

float decimalToOctalFraction(float num)
{
	return 0.0;
}

