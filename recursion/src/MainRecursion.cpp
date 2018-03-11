/*
Author : Abhijith Ravuri
*/

#include "stdafx.h"
#include <stdlib.h>

#include "FunctionHeaders.h"

int main(){
	
	//Check NSnipers

	//Check CountPairs Sample Code 

	//Check Steps Sample Code

	//Check Spiral Sample Code

	//Check Maze Sample Code

	/*
	int maze[4][3] = {
		{ 0, 0, 1 },
		{ 1, 1, 1 },
		{ 1, 0, 1 },
		{ 1, 0, 1 }
	};

	int m = 4, n = 3;
	int x1 = 3, y1 = 0, x2 = 0, y2 = 2;

	int check=path_exists(&maze[0][0], m, n, x1, y1, x2, y2);
	printf("%d\n", check);
	*/
	int n = 4;
	int board[4][4];
	int i = 0, j = 0;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			board[i][j] = 0;
		}
	}

	int result = solve_nsnipers(&board[0][0], n);
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			printf("%d\t",board[i][j]);
		}
		printf("\n");
	}
	getchar();
	getchar();
	
	return 0;
}