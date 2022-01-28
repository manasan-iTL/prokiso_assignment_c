#ifndef gomoku_judge_h
#define gomoku_judge_h
#define BOARD_SIZE 5     //盤面の縦・横の大きさ

void JudgeWinner(int board[][BOARD_SIZE], int which_turn, int *winner);
void game(int winner, int playerturn, int cputurn, int maxcount);

#endif/* gomoku_judge.h */
