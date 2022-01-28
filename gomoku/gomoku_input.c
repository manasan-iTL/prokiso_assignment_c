#include <stdio.h>
#include <stdbool.h>
#include "gomoku_input.h"
#include "gomoku_validation.h"

#define BOARD_SIZE 5     //盤面の縦・横の大きさ
#define BOARD_BLANK 0    //空白（駒が置かれていない場所）
#define BOARD_CIRCLE 1   //○（駒が置かれている場所）先行
#define BOARD_CROSS 2    //☓（駒が置かれている場所）後攻


//入力処理

void decideTurn(int *playerturn, int *cputurn) {
  do {
    printf("先行・後攻どちらが良いですか？　先行なら1、後攻なら2を入力してください\n");
    printf("警告　全角英数文字を入力しないでください。\n");
    printf("ご入力した場合はCtrc+C 等でプログラムを停止してください。\n");
    printf("入力：");
    scanf("%d", playerturn);
    
  } while(validateInputTurn(*playerturn)); 
    
  if(*playerturn == 1) {
    printf("あなたは、先行です。\n");
    *cputurn = 2;
  } else {
    printf("あなたは後攻です。\n");
    *cputurn = 1;
  }
}

void inputPosition(int board[][BOARD_SIZE], int playerturn, int *counter) {

  int pos_x, pos_y;
  do {
    printf("駒を置く場所を入力してください。入力：(x軸)1(半角スペース)(y軸)2\n");
    printf("入力例：1 2\n");
    printf("入力：");
    scanf("%d %d", &pos_x, &pos_y);
  } while(validateInputPos(board, pos_x, pos_y, counter));
      
  printf("あなたは座標(%d %d)に駒を置きました。\n", pos_x, pos_y);
  board[pos_y][pos_x] = playerturn;
}

