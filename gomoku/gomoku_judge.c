#include <stdio.h>
#include <stdlib.h>
#include "gomoku_judge.h"
#define BOARD_SIZE 5     //盤面の縦・横の大きさ


//勝敗判定
void JudgeWinner(int board[][BOARD_SIZE], int which_turn, int *winner) {

  //右下がり判定
  int downright_count = 0;
  //右上がり判定
  int upright_count = 0;
  

  for(int i=0; i<BOARD_SIZE; i++) {
    //横の判定
    int line_count=0;
    //縦の判定
    int column_count=0;
    
    //斜めのマスのときはカウント
    if(board[i][i]==which_turn) {
      downright_count++;    
    }
    
    if(board[i][4-i]==which_turn) {
      upright_count++;
    }    
    
    for(int k=0; k<BOARD_SIZE; k++) {
      if(board[i][k]==which_turn) {
        line_count++;
      }
      if(board[k][i]==which_turn) {
        column_count++;
      }
    }
    //カウント判定
    if(line_count==5) {
      *winner = which_turn;
    }
    if(column_count==5) {
      *winner = which_turn;
    }
    if(downright_count==5) {
      *winner = which_turn;
    }
    if(upright_count==5) {
      *winner = which_turn;
    }          
  }
}

void game(int winner, int playerturn, int cputurn, int maxcount) {
  if(winner == playerturn) {
    printf("You WIN!!!\n");
    exit(0);
  } else if(winner == cputurn) {
    printf("You Lose...");
    exit(0);
  } else if(maxcount == BOARD_SIZE*BOARD_SIZE) {
    printf("Draw!\n");
    exit(0);
  }
}
