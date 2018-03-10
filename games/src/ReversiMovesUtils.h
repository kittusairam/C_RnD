/*
This struct denotes the move played by user, X means the x cordinate and Y means y cordinate.
*/
typedef struct ReversiMove {
	int x, y;
}ReversiMove;
void modify(ReversiGame *game);
/*
Create a ReversiMove struct (malloc/calloc etc) and return it.
Assign parameters x and y to its fields.
*/
ReversiMove *createMove(int x, int y) {
	ReversiMove *rm = new ReversiMove;
	rm->x = x - 1;
	rm->y = y - 1;
	return rm;
}
/*
To check the validity of coordinate on the board
*/

int isvalidCoordinate(ReversiGame *game, int x, int y) {
	if (x >= 0 && x < game->rows&&y>=0 && y < game->cols){

		return 1;
	}
	else{
		return 0;
	}
}

/*
	Take Only Valid Input x, y two integers . If Invalid input is entered ,Take input again . Keep Taking input until its valid
	Hint : Use While Loop and isValidInput function
	Cordinates are 1 indexed. Ie first row/column is denoted by 1 while giving input.
*/

ReversiMove *inputMove(ReversiGame *game) {
	int x, y;
	do{
		scanf("%d %d", &x, &y);
	}while (!isvalidCoordinate(game, x, y));
	ReversiMove *rm = createMove(x, y);
	return rm;
}




/*
Check if the move can be placed, if its going to make a valid capture to the opponent coins
*/

int isValidMove(ReversiGame *game, ReversiMove *move) {
	if (!isvalidCoordinate(game, move->x, move->y)||game->board[move->x][move->y] == 'w' || game->board[move->x][move->y] == 'b'){
		return 0;
	}
	int flag = 0;

	if (game->turn == 1){
		if (move->y+1<game->cols&&game->board[move->x][move->y+1] == 'b'){
			int i = move->y+1;
			while (game->cols > i&&game->board[move->x][i] == 'b'){
				i++;
			}
			if (i < game->cols&&game->board[move->x][i] == 'w'){
				i--;
				while (move->y < i){
					game->board[move->x][i] = 'w';
					game->whiteCount++;
					game->blackCount--;
					i--;
				}
				flag++;
			}
		}
		if (move->y - 1>=0&&game->board[move->x][move->y - 1] == 'b'){
			int i = move->y -1;
			while (0 <= i&&game->board[move->x][i] == 'b'){
				i--;
			}
			if (i >= 0 && game->board[move->x][i] == 'w'){
				i++;
				while (move->y > i){
					game->board[move->x][i] = 'w';
					game->whiteCount++;
					game->blackCount--;
					i++;
				}
				flag++;
			}
		}
		if (move->x + 1<game->rows&&game->board[move->x + 1][move->y] == 'b'){
			int i = move->x+1;
			while (game->rows > i&&game->board[i][move->y] == 'b'){
				i++;
			}
			if (i < game->rows&&game->board[i][move->y] == 'w'){
				i--;
				while (move->x < i){
					game->board[i][move->y] = 'w';
					game->whiteCount++;
					game->blackCount--;
					i--;
				}
				flag++;
			}
		}
		if (move->x- 1>=0&&game->board[move->x - 1][move->y] == 'b'){
			int i = move->x - 1;
			while (0 <= i&&game->board[i][move->y] == 'b'){
				i--;
			}
			if (i >= 0 && game->board[i][move->y] == 'w'){
				i++;
				while (move->x > i){
					game->board[i][move->y] = 'w';
					game->whiteCount++;
					game->blackCount--;
					i++;
				}
				flag++;
			}
		}
		//cross left top
		if (move->x - 1 >= 0 && move->y - 1 >= 0 && game->board[move->x - 1][move->y - 1] == 'b'){
			int i = move->x - 1;
			int j = move->y - 1;
			while (0<=j&&0 <= i&&game->board[i][j] == 'b'){
				i--; j--;
			}
			if (j>=0 &&i >= 0 && game->board[i][j] == 'w'){
				i++; j++;
				while (move->x > i&&move->y >= j){
					game->board[i][j] = 'w';
					game->whiteCount++;
					game->blackCount--;
					i++; j++;
				}
				flag++;
			}
		}
		//bottem left
		if (move->x + 1<game->rows && move->y - 1 >= 0 && game->board[move->x + 1][move->y - 1] == 'b'){
			int i = move->x + 1;
			int j = move->y - 1;
			while (0 <= j && i<game->rows&&game->board[i][j] == 'b'){
				i++; j--;
			}
			if (0 <= j && i<game->rows && game->board[i][j] == 'w'){
				i--; j++;
				while (move->x < i&&move->y > j){
					game->board[i][j] = 'w';
					game->whiteCount++;
					game->blackCount--;
					i--; j++;
				}
				flag++;
			}
		}
		//top right
		if (move->x - 1>=0 && move->y + 1 <game->cols && game->board[move->x - 1][move->y + 1] == 'b'){
			int i = move->x - 1;
			int j = move->y + 1;
			while (0 <= i && j<game->cols&&game->board[i][j] == 'b'){
				i--; j++;
			}
			if (0 <= i && j<game->cols && game->board[i][j] == 'w'){
				i++; j--;
				while (move->x > i&&move->y < j){
					game->board[i][j] = 'w';
					game->whiteCount++;
					game->blackCount--;
					i++; j--;
				}
				flag++;
			}
		}
		//bottem right
		if (move->x + 1 <game->rows && move->y + 1 <game->cols && game->board[move->x + 1][move->y + 1] == 'b'){
			int i = move->x + 1;
			int j = move->y + 1;
			while (i<game->rows&&j<game->cols&&game->board[i][j] == 'b'){
				i++; j++;
			}
			if (j <game->cols && i<game->rows && game->board[i][j] == 'w'){
				i--; j--;
				while (move->x < i&&move->y < j){
					game->board[i][j] = 'w';
					game->whiteCount++;
					game->blackCount--;
					i--; j--;
				}
				flag++;
			}
		}
	}
	else{
		if (move->y + 1<game->cols&&game->board[move->x][move->y + 1] == 'w'){
			int i = move->y + 1;
			while (game->cols > i&&game->board[move->x][i] == 'w'){
				i++;
			}
			if (i < game->cols&&game->board[move->x][i] == 'b'){
				i--;
				while (move->y < i){
					game->board[move->x][i] = 'b';
					game->blackCount++;
					game->whiteCount--;
					i--;
				}
				flag++;
			}
		}
		if (move->y - 1 >= 0 && game->board[move->x][move->y - 1] == 'w'){
			int i = move->y - 1;
			while (0 < i&&game->board[move->x][i] == 'w'){
				i--;
			}
			if (i >= 0 && game->board[move->x][i] == 'b'){
				i++;
				while (move->y > i){
					game->board[move->x][i] = 'b';
					game->blackCount++;
					game->whiteCount--;
					i++;
				}
				flag++;
			}
		}
		if (move->x + 1<game->rows&&game->board[move->x + 1][move->y] == 'w'){
			int i = move->x + 1;
			while (game->rows > i&&game->board[i][move->y] == 'w'){
				i++;
			}
			if (i < game->rows&&game->board[i][move->y] == 'b'){
				i--;
				while (move->x < i){
					game->board[i][move->y] = 'b';
					game->blackCount++;
					game->whiteCount--;
					i--;
				}
				flag++;
			}
		}
		if (move->x - 1>=0&&game->board[move->x - 1][move->y] == 'w'){
			int i = move->x - 1;
			while (0 <= i&&game->board[i][move->y] == 'w'){
				i--;
			}
			if (i >= 0 && game->board[i][move->y] == 'b'){
				i++;
				while (move->x > i){
					game->board[i][move->y] = 'b';
					game->blackCount++;
					game->whiteCount--;
					i++;
				}
				flag++;
			}
		}
		//cross left top
		if (move->x - 1 >= 0 && move->y - 1 >= 0 && game->board[move->x - 1][move->y - 1] == 'w'){
			int i = move->x - 1;
			int j = move->y - 1;
			while (0 <= j && 0 <= i&&game->board[i][j] == 'w'){
				i--; j--;
			}
			if (j >= 0 && i >= 0 && game->board[i][j] == 'b'){
				i++; j++;
				while (move->x > i&&move->y > j){
					game->board[i][j] = 'b';
					game->blackCount++;
					game->whiteCount--;
					i++; j++;
				}
				flag++;
			}
		}
		//bottem left
		if (move->x + 1<game->rows && move->y - 1 >= 0 && game->board[move->x + 1][move->y - 1] == 'w'){
			int i = move->x + 1;
			int j = move->y - 1;
			while (0 <= j && i<game->rows&&game->board[i][j] == 'w'){
				i++; j--;
			}
			if (0 <= j && i<game->rows && game->board[i][j] == 'b'){
				i--; j++;
				while (move->x < i&&move->y > j){
					game->board[i][j] = 'b';
					game->blackCount++;
					game->whiteCount--;
					i--; j++;
				}
				flag++;
			}
		}
		//top right
		if (move->x - 1 >= 0 && move->y + 1 <game->cols && game->board[move->x - 1][move->y + 1] == 'w'){
			int i = move->x - 1;
			int j = move->y + 1;
			while (0 <= i && j<game->cols&&game->board[i][j] == 'w'){
				i--; j++;
			}
			if (0 <= i && j<game->cols && game->board[i][j] == 'b'){
				i++; j--;
				while (move->x > i&&move->y < j){
					game->board[i][j] = 'b';
					game->blackCount++;
					game->whiteCount--;
					i++; j--;
				}
				flag++;
			}
		}
		//bottem right
		if (move->x + 1 <game->rows && move->y + 1 <game->cols && game->board[move->x + 1][move->y + 1] == 'w'){
			int i = move->x + 1;
			int j = move->y + 1;
			while (i<game->rows&&j<game->cols&&game->board[i][j] == 'w'){
				i++; j++;
			}
			if (i<game->rows&&j<game->cols && game->board[i][j] == 'b'){
				i--; j--;
				while (move->x < i&&move->y < j){
					game->board[i][j] = 'b';
					game->blackCount++;
					game->whiteCount--;
					i--; j--;
				}
				flag++;
			}
		}
	}
	if (flag > 0){
		if (game->turn == 1){
			game->board[move->x][move->y] = 'w';
			game->whiteCount++;
		}
		else{
			game->board[move->x][move->y] = 'b';
			game->blackCount++;
		}
		return 1;
	}
	else{
		return 0;
	}
}

int isValidMove2(ReversiGame *game, ReversiMove *move) {
	if (!isvalidCoordinate(game, move->x, move->y) || game->board[move->x][move->y] == 'w' || game->board[move->x][move->y] == 'b'){
		return 0;
	}
	int flag = 0;
	if (game->turn == 1){
		if (move->y + 1<game->cols&&game->board[move->x][move->y + 1] == 'b'){
			int i = move->y + 1;
			while (game->cols > i&&game->board[move->x][i] == 'b'){
				i++;
			}
			if (i < game->cols&&game->board[move->x][i] == 'w'){
				return 1;
			}
		}
		if (move->y - 1 >= 0 && game->board[move->x][move->y - 1] == 'b'){
			int i = move->y - 1;
			while (0 <= i&&game->board[move->x][i] == 'b'){
				i--;
			}
			if (i >= 0 && game->board[move->x][i] == 'w'){
				return 1;
			}
		}
		if (move->x + 1<game->rows&&game->board[move->x + 1][move->y] == 'b'){
			int i = move->x + 1;
			while (game->rows > i&&game->board[i][move->y] == 'b'){
				i++;
			}
			if (i < game->rows&&game->board[i][move->y] == 'w'){
				return 1;
			}
		}
		if (move->x - 1 >= 0 && game->board[move->x - 1][move->y] == 'b'){
			int i = move->x - 1;
			while (0 <= i&&game->board[i][move->y] == 'b'){
				i--;
			}
			if (i >= 0 && game->board[i][move->y] == 'w'){
				return 1;
			}
		}
		//cross left top
		if (move->x - 1 >= 0 && move->y - 1 >= 0 && game->board[move->x - 1][move->y - 1] == 'b'){
			int i = move->x - 1;
			int j = move->y - 1;
			while (0 <= j && 0 <= i&&game->board[i][j] == 'b'){
				i--; j--;
			}
			if (j >= 0 && i >= 0 && game->board[i][j] == 'w'){
				return 1;
			}
		}
		//bottem left
		if (move->x + 1<game->rows && move->y - 1 >= 0 && game->board[move->x + 1][move->y - 1] == 'b'){
			int i = move->x + 1;
			int j = move->y - 1;
			while (0 <= j && i<game->rows&&game->board[i][j] == 'b'){
				i++; j--;
			}
			if (0 <= j && i<game->rows && game->board[i][j] == 'w'){
				return 1;
			}
		}
		//top right
		if (move->x - 1 >= 0 && move->y + 1 <game->cols && game->board[move->x - 1][move->y + 1] == 'b'){
			int i = move->x - 1;
			int j = move->y + 1;
			while (0 <= i && j<game->cols&&game->board[i][j] == 'b'){
				i--; j++;
			}
			if (0 <= i && j<game->cols && game->board[i][j] == 'w'){
				return 1;
			}
		}
		//bottem right
		if (move->x + 1 <game->rows && move->y + 1 <game->cols && game->board[move->x + 1][move->y + 1] == 'b'){
			int i = move->x + 1;
			int j = move->y + 1;
			while (i<game->rows&&j<game->cols&&game->board[i][j] == 'b'){
				i++; j++;
			}
			if (j <game->cols && i<game->rows && game->board[i][j] == 'w'){
				return 1;
			}
		}
	}
	else{
		if (move->y + 1<game->cols&&game->board[move->x][move->y + 1] == 'w'){
			int i = move->y + 1;
			while (game->cols > i&&game->board[move->x][i] == 'w'){
				i++;
			}
			if (i < game->cols&&game->board[move->x][i] == 'b'){
				return 1;
			}
		}
		if (move->y - 1 >= 0 && game->board[move->x][move->y - 1] == 'w'){
			int i = move->y - 1;
			while (0 < i&&game->board[move->x][i] == 'w'){
				i--;
			}
			if (i >= 0 && game->board[move->x][i] == 'b'){
				return 1;
			}
		}
		if (move->x + 1<game->rows&&game->board[move->x + 1][move->y] == 'w'){
			int i = move->x + 1;
			while (game->rows > i&&game->board[i][move->y] == 'w'){
				i++;
			}
			if (i < game->rows&&game->board[i][move->y] == 'b'){
				return 1;
			}
		}
		if (move->x - 1 >= 0 && game->board[move->x - 1][move->y] == 'w'){
			int i = move->x - 1;
			while (0 <= i&&game->board[i][move->y] == 'w'){
				i--;
			}
			if (i >= 0 && game->board[i][move->y] == 'b'){
				return 1;
			}
		}
		//cross left top
		if (move->x - 1 >= 0 && move->y - 1 >= 0 && game->board[move->x - 1][move->y - 1] == 'w'){
			int i = move->x - 1;
			int j = move->y - 1;
			while (0 <= j && 0 <= i&&game->board[i][j] == 'w'){
				i--; j--;
			}
			if (j >= 0 && i >= 0 && game->board[i][j] == 'b'){
				return 1;
			}
		}
		//bottem left
		if (move->x + 1<game->rows && move->y - 1 >= 0 && game->board[move->x + 1][move->y - 1] == 'w'){
			int i = move->x + 1;
			int j = move->y - 1;
			while (0 <= j && i<game->rows&&game->board[i][j] == 'w'){
				i++; j--;
			}
			if (0 <= j && i<game->rows && game->board[i][j] == 'b'){
				return 1;
			}
		}
		//top right
		if (move->x - 1 >= 0 && move->y + 1 <game->cols && game->board[move->x - 1][move->y + 1] == 'w'){
			int i = move->x - 1;
			int j = move->y + 1;
			while (0 <= i && j<game->cols&&game->board[i][j] == 'w'){
				i--; j++;
			}
			if (0 <= i && j<game->cols && game->board[i][j] == 'b'){
				return 1;
			}
		}
		//bottem right
		if (move->x + 1 <game->rows && move->y + 1 <game->cols && game->board[move->x + 1][move->y + 1] == 'w'){
			int i = move->x + 1;
			int j = move->y + 1;
			while (i<game->rows&&j<game->cols&&game->board[i][j] == 'w'){
				i++; j++;
			}
			if (i<game->rows&&j<game->cols && game->board[i][j] == 'b'){
				return 1;
			}
		}
	}
	return 0;
}


/*
Check if the player can move , if the player is not able to move, he looses the turn
and the opponent gets the chance to play.
If both players are not able to make a move, then the game ends.
*/

int hasMove(ReversiGame *game){
	ReversiMove *rm = new ReversiMove;
	for (int i = 0; i < game->rows; i++){
		for (int j = 0; j < game->cols; j++){
			rm->x = i;
			rm->y = j;
			if (isValidMove2(game, rm)){
				//modifyTurn(game);
				return 1;
			}
		}
	}
	endGame(game);
	modifyTurn(game);
	return 0;
}

/*
Increment the number of moves in ReversiGame struct.
*/
void incrementMoves(ReversiGame *game) {
	game->NumberofMoves++;
	return;
}

/*
Toggle the turn in Reversi Game.
This function is to be called when you want to change the turn.
*/
void modifyTurn(ReversiGame *game) {
	if (game->turn == 1){
		game->turn = -1;
	}
	else{
		game->turn = 1;
	}
	return;
}

/*
End Reversi Game.
Populate game->winner field accordingly with who won. 1 for white, -1 for black.
This function is to be called when the game is ended.
*/
void endGame(ReversiGame *game) {

	if (game->whiteCount > game->blackCount){
		game->winner = 1;
	}
	else if (game->whiteCount < game->blackCount){
		game->winner = -1;
	}
	else{
		game->winner = 0;
	}
	return;
}

/*
	Wrapper function you will call only modify to increment moves and modify the turn.
*/

void modify(ReversiGame *game) {
	incrementMoves(game);
	modifyTurn(game);
}


/*
	This function performs move action on the board
	Note : call validity check performs using above functions before making a move
	returns :
	true on move sucess
	false if move is invalid
*/

bool playMove(ReversiGame *game, ReversiMove *move) {
	if (isValidMove(game, move)){
		modify(game);
		return true;
	}
	//modifyTurn(game);
	return false;
}


void printWinner(ReversiGame *game) {
	/*
	Sample output :
	Result Praveen has won. / Game is Drawn.
	*/
	if (game->winner == 1){
		printf("Result %s has won.\n", game->player1name);
	}
	else if (game->winner == -1){
		printf("Result %s has won.\n", game->player2name);
	}
	else{
		printf("Game is Drawn.\n");
	}
}