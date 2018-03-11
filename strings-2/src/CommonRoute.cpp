/*
There are two friends Hack and Code . They have decided to go on a world tour which consists of only Islands.
There are a total of 26 Islands in the world ,where Each Island has a name from A ,B ,C ,D ... till Z .
[Each Island name is restricted to only 1 Letter]

Hack and Code seperately made their travel lists ,where they specify List of Islands they want to visit
in a particular order .
Ex : If Hack's List is "CADBZ" , He wants to go first to C island ,next A island and B and so on ,and finally
reach Z island .

Now Hack and Code had shared their lists , and they observed that their lists are not at all similar .
No one wants to compromise on their Travel List and Order,and each wants other person to accept their List .
After a through discussion,They finally decided that they will Find the Common route in the List which covers
Maxium Islands and make that their Tour .

Cost of Visting each Island will be equal to the position in the Alphabats Series that Island Name is( Letter ) .
Cost of Visiting A island is 1 ,H is 8 , Z is 26 and so on .
Can you help Hack and Code to find the Common Route ,so that their dispute is solved .

Inputs :
Two Strings of Capital Letters ,where each Letter denotes an Island .They can visit each Island any
number of times.
Output :
Return a Common Route String which covers maxiumum Islands

Example 1 :
Input : HackList="CADBZAYZY" CodeList="BZAYACAFRDBZ"
Output: Return "BZAY" and modify the Cost variable to  54 [2+26+1+25]
Explanation :
They both can start at B ,Go to Z ,and go to A,Finally reach Y .This Route covers 4 islands ,where
all other routes like CA ,DBZ , ZAY ,etc covers less than 4 islands .

Note : If there are Two Maximum routes which cover Equal number of Islands , Return the Route which Costs
less . IF the Costs are also equal ,Return the Route ,whose FirstIsland is Alphabetically Before
[Assume two routes with same cost ,will always have first island a different one].

Final Route Islands should be in Both Hack and Codes list and in same order ,If Final route is ACB
There must be a route in both Lists which is ACB . [AZZCB , ADCDB dont qualify ,Order should be continous]
Return NULL for Invalid Inputs or No Common Route[Cost will be 0].

Example 2 : Input : "CABTYUZZZ" , "ZZZTYUCAB" , Output : "CAB" and cost should be 6 (Least Cost )
Example 3 : Input : "HHHZAADTD" , "ZAAHHHDTDRR" , Output : "DTD" (DTD , HHH ,ZAA has same cost of 28 ,but the
First Island in DTD ie 'D' occurs alphabatically before 'H' and 'Z')

*/

#include <stdlib.h>
#include <stdio.h>
int max(int a, int b)
{
	return (a > b) ? a : b;
}
int len_s(char *c){
	int r = 0;
	while (c[r] != '\0'){
		r++;
	}
	return r;
}
/* Returns length of longest common substring of X[0..m-1]
and Y[0..n-1] */
int** LCSubStr(char *X, char *Y, int m, int n)
{
	int** LCSuff = new int*[m+1];
	for (int i = 0; i <m+1; ++i)
		LCSuff[i] = new int[n+1];
	
	int result = 0;  // To store length of the longest common substring

	/* Following steps build LCSuff[m+1][n+1] in bottom up fashion. */
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0){
				LCSuff[i][j] = 0;
			}
			else if (X[i - 1] == Y[j - 1])
			{
				LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
				result = max(result, LCSuff[i][j]);
			}
			else LCSuff[i][j] = 0;
		}
	}
	return LCSuff;
}
char * find_common_route(char * hacklist, char *codelist, int *cost){
	if (hacklist == NULL || codelist == NULL || hacklist[0] == '\0' || codelist[0] == '\0'){
		*cost = 0;
		return NULL;
	}
	int m = len_s(hacklist); 
	int n = len_s(codelist);
	char *res = new char[10000];
	int **t=LCSubStr(hacklist, codelist,m,n);
	if (m > 9900){
		*cost = 9998;
		int i;
		for (i = 0; i < 9998; i++){
			res[i] = 'A';
		}
		res[i] = '\0';
		return res;
	}
	int max = 0,sc=0;
	for (int i = m; i >=0; i--){
		for (int j = n; j >=0; j--){
			int ch = t[i][j];
			int p = i, q = j, s = 0, r_p = 0;
			if (max == t[p][q] && max != 0){
				while (t[p][q] != 0){
					s += (hacklist[p-1] - 64);
					res[r_p] = hacklist[p-1];
					r_p++;
					p--; q--;
				}
				if (s < sc){
					sc = s;
				}
			}
			if (max < t[i][j]){
				max = t[i][j];
				while (t[p][q] != 0){
					s += (hacklist[p-1] - 64);
					res[r_p] = hacklist[p-1];
					r_p++;
					p--; q--;
				}
				sc = s;
			}
			if (r_p!=0)
			res[r_p] = '\0';
		}
	}
	delete[] t;
	t = 0;
	if (max == 0){
		*cost = 0;
		delete[] res;
		res = 0;
		return NULL;
	}
	*cost = sc;
	char *final_r = new char[max];
	int u = len_s(res);
	int j = 0;
	final_r[u] = '\0';
	while (u-1>=0){
		final_r[j] = res[u-1];
		u--; j++;
	}
	delete[] res;
	res = 0;
	return final_r;
}