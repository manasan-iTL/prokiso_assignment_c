#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "gomoku_sub.h"
#include "gomoku_validation.h"
#define BOARD_SIZE 5     //盤面の縦・横の大きさ
#define BOARD_BLANK 0    //空白（駒が置かれていない場所）


//初期化処理
void initBoard(int board[][BOARD_SIZE]) {
  for(int i=0; i<BOARD_SIZE; i++) {
    for(int k=0; k<BOARD_SIZE; k++) {
      board[i][k] = BOARD_BLANK;
    }
  }
}


//CPUの駒操作
void moveCpu(int board[][BOARD_SIZE], int cputurn, int *counter) {
  //２つの乱数を生成
  //seedを生成
  srand((unsigned)time(NULL));
  int pos_x, pos_y;
  bool error_blank;
  do {
    pos_x = 0 + rand() % BOARD_SIZE;
    pos_y = 0 + rand() % BOARD_SIZE;
    error_blank = validateBlank(board, pos_x, pos_y, counter);    
  } while(error_blank);
  printf("CPUは座標(%d %d)に駒を置きました。\n", pos_x, pos_y);
  board[pos_y][pos_x]=cputurn;
}

