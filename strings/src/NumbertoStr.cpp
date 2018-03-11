/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>


void number_to_str(float f, char *str, int ad){

	int  i = 0;
	char str2[100];

	int k;
	if (f<0)
	{
		str[0] = '-';
		k = 1;
		f = -(f);
	}
	else
		k = 0;
	int num = (int)f;
	float ans = (float)f - num;
	for (int m = 0; m < ad; m++)
	{
		ans = ans * 10;
	}
	int num2 = (int)ans;
	while (num != 0)
	{
		int rem = num % 10;
		str2[i] = rem + '0';
		i++;
		num = num / 10;
	}

	str2[i] = '\0';

	for (int j = i - 1; j >= 0; j--)
	{
		str[k] = str2[j];
		k++;
	}


	if (num2 != 0)
	{
		str[k] = '.';
		k++;
	}
	i = 0; char str3[100];
	while (num2 != 0)
	{

		int rem = num2 % 10;
		str3[i] = rem + '0';
		i++;
		num2 = num2 / 10;
	}
	str3[i] = '\0';
	for (int j = i - 1; j >= 0; j--)
	{
		str[k] = str3[j];
		k++;
	}
	str[k] = '\0';



}