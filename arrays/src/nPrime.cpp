
/*
OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7] 

INPUTS: An Integer N

OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)

ERROR CASES: Return NULL for invalid inputs

Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}
NOTES:

Try to think of a optimized way , and avoid unnecessary comparisons.
*/

#include <stdio.h>
int* nPrime(int n)
{
	if (n <= 0){
		return NULL;
	}
	int *array = new int[50];
	int i,j,ct=0,t=0;
     for(i=2;i<=n;i++)
     {
             ct=0;
             for(j=2;j<i;j++)
             {
                     if(i%j==0)
                     {
                               ct=1;
                               break;
                     }
             }

             if(ct==0)
             {
				 array[t++] = i;
             }
     }
	return array;
}