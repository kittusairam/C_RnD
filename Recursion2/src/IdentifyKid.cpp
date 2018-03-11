/*

Problem Code: IdentifyKid

There are three types of Guys,
'A' - Ambitious Boy 
'B' - Brilliant Boy
'C' - Creative Boy

The first generation guy is 'A'
each guy will have 3 kids 'A','B','C' , but the order will be different

'A' children will be  A ,B, C
'B' children will be  B ,C, A
'C' children will be  C ,A, B    ( rotations of “ABC”)


So basically , if it was represented in the form of a tree


1st  Generation -	                                   A
Index -                                                1
                                 /                     |                   \
2nd Generation -	            A                      B                    C
Index -			                1                      2                    3
                           /    |    \            /    |    \           /   |   \
3rd Generation -          A     B     C          B     C     A         C    A    B
Index-                    1     2     3          4     5     6         7    8     9

Given the N,K which represents the Nth generation and Kth index
You need to identify the type of the kid present there.

Note : If there is No Guy present there, return '\0'

*/

#include<stdio.h>
#include<string.h>
int isMove(int i, int j, int n, int m) {
	if (i >= 0 && i < m && j >= 0 && j < n)
		return 1;
	return 0;
}

int find_solution(int n, int k){
	if (n == 0){
		return k;
	}
	n = (n + 1) % k;
	return find_solution(n / k, n);
}
char identifyKid(int N, int K) {
	if (N <= 0||K<=0){
		return '\0';
	}
	return find_solution(N, K);
}