#ifndef gomoku_sub_h
#define gomoku_sub_h
#define BOARD_SIZE 5     //盤面の縦・横の大きさ

void initBoard(int board[][BOARD_SIZE]);
void moveCpu(int board[][BOARD_SIZE], int cputurn, int *counter); 

#endif/* gomoku_sub_h */
