/*

Problem Code : New York

Count the number of ways of reaching top left cell (0,0) to right bottom cell (n-1,m-1) of a 2d matrix.

You have to change the direction "exactly 'k' times", you can change to any direction top,down,left,right.

You can start with any direction (initially at (0,0) only right and down are possible).

For Example :
N = 3, m = 4 , k = 1
These are the two sequences , change in direction is indicated by *

(1,1) -->  (2,1) -->  (3,1) -->  (3,2)* -->  (3,3) --> (3,4)
(1,1) -->  (1,2) -->  (1,3) -->  (1,4) --> (2,4)* -->  (3,4)

N = 3, m = 4, k = 2

(1,1) --> (2,1) --> (2,2)* --> (2,3) -->  (2,4) -->  (3,4)*
(1,1) --> (1,2) -->  (2,2)* --> (3,2) -->  (3,3)* --> (3,4)
(1,1) --> (1,2) -->  (1,3) -->  (2,3)* -->  (3,3) -->  (3,4)*

Return 0 for invalid cases
*/

#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int* getLeaderIndex(int *arr, int len){
	if (arr == NULL || len <= 0){
		return 0;
	}
	int *t = new int[len]();
	int *res = new int[2]();
	for (int i = 0; i < len; i++){
		int p, c = 0;
		p = i + 1;
		int temp = arr[i];
		while (p < len){
			if (temp <= arr[p]){
				t[p]++;
				temp = arr[p];
				c++;
			}
			p++;
		}
		if (c == len - 1 && i == 0){
			res[0] = len - 1;
			res[1] = len - 1;
			return res;
		}
		if (c == 0 && i == 0){
			res[0] = 0;
			res[1] = 0;
			return res;
		}
	}
	int max = 0;
	for (int i = 0; i < len; i++){
		if (max < t[i]){
			res[0] = i;
			res[1] = t[i];
			max = t[i];
		}
	}
	return res;
}
int newyork_recur(int n, int m, int x, int y, int K, int dir) {
	
	int *res = new int[n];
	int c = 0;
	for (int i = 0; i < n; i++){
		
		int sum = 0;
		while (sum != 1 && c != 20){
			if (sum != 0)
				n = sum;
			sum = 0;
			while (n){
				int r = n % 10;
				n = n / 10;
				sum += (int)pow((double)r, 2);
			}
			c++;
		}
	}
	return c;
}

int NewYork(int n, int m, int k){
	return newyork_recur(n, m, 0, 0, k + 1, 0);
}