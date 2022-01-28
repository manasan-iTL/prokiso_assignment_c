#ifndef gomoku_input_h
#define gomoku_input_c
#define BOARD_SIZE 5     //盤面の縦・横の大きさ

void decideTurn(int *playerturn, int *cputurn);
void inputPosition(int board[][BOARD_SIZE], int playerturn, int *counter);

#endif /* gomoku_input_h */ 
