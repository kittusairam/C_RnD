/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>

bool isSafe(int **maze, int x, int y,int m,int n)
{
	if (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 1)
		return true;

	return false;
}
int find_path(int **arr, int rows, int columns, int x1, int y1, int x2, int y2){
	// if (x,y is goal) return true
	if (x1 == x2 && y1 == y2)
	{
		//arr[x1][y1] = 1;
		return 1;
	}

	// Check if maze[x][y] is valid
	if (isSafe(arr, x1, y1, rows, columns) == true)
	{
		// mark x,y as part of solution path
		//arr[x1][y1] = 1;

		/* Move forward in x direction */
		if (find_path(arr, rows, columns, x1 + 1, y1, x2, y2) == 1)
			return 1;

		/* If moving in x direction doesn't give solution then
		Move down in y direction  */
		if (find_path(arr, rows, columns, x1, y1 + 1, x2, y2) == 1)
			return 1;
		/* If none of the above movements work then BACKTRACK:
		unmark x,y as part of solution path */
		//return 0;
	}
	return 0;
}
int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (rows <= 0 || columns <= 0){
		return 0;
	}
	int **arr = new int*[rows];
	int k = 0;
	for (int i = 0; i < rows; i++){
		arr[i] = new int[columns];
	}
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			arr[i][j] = maze[k++];
		}
	}
	if (arr[x2][y2] == 1){
		return find_path(arr, rows, columns, x1, y1, x2, y2);
	}
	else{
		return 0;
	}
	
}
