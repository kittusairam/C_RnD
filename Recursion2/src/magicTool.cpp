/*

	Given a matrix nxn and a starting point (p,q), 
	Output all the points in the matrix which are identical to the starting point in the fashion similar to magic tool in Adobe photoshop.
	Eg:
	(p,q) : (0,3)
	1 2 3 3
	3 2 3 3
	5 3 3 3
	4 5 1 4
	o/p : [ (0,2) (0,3) (1,2) (1,3) (2,2) (2,3) (2,1) ]

	Use 2 structures provided to solve the problem.
	
	struct point -> contains x, y corresponding to point on matrix.
	struct result -> contains 3 fields
						1. selected -> contains all the final points after the selecting process.
						2. size -> number of the selected points.
						3. visited -> utility variable to note the visited points on matrix during recursion.
	
	In error cases return a emply structures
		size = 0;
		selected = {};
		visited = {};

NOTE : Donot use any Global Variables
*/
#include <malloc.h>

struct Point {
	int x;
	int y;
};


struct result {
	Point* selected;
	bool *visited;
	int size;
};


void select(char *pixels, int m, int n, struct Point pivot, struct result* res, struct Point current) {
	// feel free to change this function parameters
	if (res->visited[pivot.x + pivot.y] != true){
		for (int i = 0; i < n; i++){
			int count = 1;
			for (int j = 0; j < n; j++){
				if (pixels[i] == pixels[j])
					count++;
			}
			if (count == 2)
				return;
		}
	}
}

struct result select_wrapper(char* pixels, int m, int n, struct Point pivot) {
	struct result res;
	if (pixels==nullptr|| m < 0 || n < 0 ){
		res.size = 0;
		return res;
	}
	select(pixels, m, n, pivot, &res, pivot);
	res.size = 0;
	return res;
}
