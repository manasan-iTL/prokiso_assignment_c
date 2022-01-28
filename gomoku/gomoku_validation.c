#include <stdio.h>
#include <stdbool.h>
#include "gomoku_validation.h"

#define BOARD_SIZE 5     //盤面の縦・横の大きさ
#define BOARD_BLANK 0    //空白（駒が置かれていない場所）


//バリデーションチェック
bool validateInputTurn(int input) {
  if(input != 1 && input != 2) {
    printf("1か2を入力してください。\n");
    return true;
  } else { return false; }
}

bool validateInputNumber(int pos_x, int pos_y) {
  if((pos_x >= BOARD_SIZE || pos_y >= BOARD_SIZE)|| (pos_x < 0 && pos_y < 0)) {
    printf("その数は範囲外です。0~%dを入力してください\n", BOARD_SIZE);
    return true;
  } else{ return false; } 
}

bool validateBlank(int board[][BOARD_SIZE], int pos_x, int pos_y, int *counter) {
  if((pos_x >= BOARD_SIZE || pos_y >= BOARD_SIZE)|| (pos_x < 0 && pos_y < 0)) { 
    return true;
  } else if(board[pos_y][pos_x] == BOARD_BLANK){
      *counter = *counter + 1;
      return false; 
  } else if(*counter == BOARD_SIZE*BOARD_SIZE) {
       return false;

  } else if(board[pos_y][pos_x] != BOARD_BLANK){ 
       printf("その場所はすでに駒が置いてあります。\n");
       return true;
  }
}

bool validateInputPos(int board[][BOARD_SIZE], int pos_x, int pos_y, int *counter) {
  //入力された値が範囲内かどうか
  bool error1 = validateInputNumber(pos_x, pos_y);
  
  //空白マスかどうか
  bool error2 = validateBlank(board, pos_x, pos_y, counter);
  
  if(error1 || error2) {
    return true;
  } else { return false; }
}
