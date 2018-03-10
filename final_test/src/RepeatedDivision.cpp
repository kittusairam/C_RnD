/*

problemCode : RepeatedDivision
score : 10

Repeated 2 Division.

Given a Number N, your task is to find a number in the range [1,N]
such that the number is most divisible reptedly by 2

Example :
N = 6

x   -    DivisibleCount
1   -    0
2   -    1
3   -    0
4   -    2
5   -    0
6   -    1

Hence the answer is 4 since it can be repetedly divisible 2 times.

CONSTRAINTS : 
	1 <= N < 2^32

*/

#include<math.h>
int RepeatedDivision(int N){
	int count = 0,i=0;
	if (N <= 0||N>pow(2.0,32)){
		return -1;
	}
	while ((int)pow(2.0, i)<N){
		i += 1;
	}
	return (int)pow(2.0,i-1);
}

