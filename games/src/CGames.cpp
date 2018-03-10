#define _CRT_SECURE_NO_WARNINGS

//Helper Utils
#include "C15BoardUtils.h"
#include "C15UserUtils.h"
#include "C15MovesUtils.h"

#include "C15Puzzle.cpp"

#include "ReversiBoardUtils.h"
#include "ReversiMovesUtils.h"

#include "CReversi.cpp"

int main(){

	/*
		Read The Description in C15Puzzle.h
	*/

	//c15Puzzle_main();
	int rows = 4, cols = 4;
	ReversiGame *game = createNewGame(rows, cols, "praveen", "abhijith");
	char table1[4][5] =
	{
		"    ",
		" wb ",
		" bw ",
		"    "
	};

	initializeReversiGame(game, (char *)table1, rows, cols, 1);
	int t = isValidMove(game, createMove(1,3));
	/*
		Read The Description in Reversi.h
	*/

	//Reversi_main();
	system("pause");
	return 0;
}
