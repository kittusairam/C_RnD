/*

Use Strings2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.s

Objectives of C-Strings-2 Lesson:

->Using malloc to create new strings
->New ways of Handling Strings

Solve CommonRoute , Concat4Strings keeping complexity in Mind , BruteForce solutions take
long time to pass ,and will eventually fail when we run on our side with Timeouts .

Make Sure The Each Individual Test cases for Large inputs dosent take more than
2Seconds. (ie Real20_CommonRoute TestCase in CommonRouteSpec)
*/

#include "FunctionHeadersStrings2.h"
#include<stdio.h>
#include<malloc.h>

int main(){

	int len = 10000;
	char *hacklist = (char *)malloc(sizeof(char)*len);
	char *codelist = (char *)malloc(sizeof(char)*len);
	char *ans = (char *)malloc(sizeof(char)*len);;
	hacklist[0] = 'Z';
	codelist[0] = 'T';
	int k = 0;
	for (int i = 1; i < len - 1; i++){
		hacklist[i] = 'A';
		codelist[i] = 'A';
		ans[k] = 'A';
		k++;
	}
	hacklist[len - 1] = '\0';
	codelist[len - 1] = '\0';
	int p=0;
	char *t = find_common_route(hacklist, codelist, &p);

	//Test getFrequencyofWord

	//Test getSubstring

	//Test getLastWord

	//Test others
	getchar();
	return 0;
}