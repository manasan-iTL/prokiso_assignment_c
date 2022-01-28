#ifndef gomoku_validation_h
#define gomoku_validation_h
#define BOARD_SIZE 5     //盤面の縦・横の大きさ

bool validateInputTurn(int input);
bool validateInputNumber(int pos_x, int pos_y);
bool validateBlank(int board[][BOARD_SIZE], int pos_x, int pos_y, int *counter);
bool validateInputPos(int board[][BOARD_SIZE], int pos_x, int pos_y, int *counter);

#endif/* gomoku_validation_h */
