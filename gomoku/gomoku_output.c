#include <stdio.h>
#include "gomoku_output.h"
#define BOARD_SIZE 5     //盤面の縦・横の大きさ
#define BOARD_BLANK 0    //空白（駒が置かれていない場所）
#define BOARD_CIRCLE 1   //○（駒が置かれている場所）先行
#define BOARD_CROSS 2    //☓（駒が置かれている場所）後攻


//出力処理
void printBoard(int board[][BOARD_SIZE]) {
  printf("　");
  for(int i=0; i<BOARD_SIZE; i++) {
    printf("%d ", i);
    if(i==BOARD_SIZE-1) {
      printf("\n");
    }
  }
  
  for(int i=0; i<BOARD_SIZE; i++) {
    printf("%d ", i);
    for(int k=0; k<BOARD_SIZE; k++) {
      switch(board[i][k]) {
        case BOARD_BLANK:
          printf("+ ");
          break;
        case BOARD_CIRCLE:
          printf("O ");
          break;
        case BOARD_CROSS:
          printf("X ");
          break;
      }
    }
    printf("\n");
  }
  printf("\n");
}
