#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "gomoku_input.h"
#include "gomoku_output.h"
#include "gomoku_validation.h"
#include "gomoku_sub.h"
#include "gomoku_judge.h"
#include "gomoku_input.h"

#define BOARD_SIZE 5     //盤面の縦・横の大きさ
#define BOARD_BLANK 0    //空白（駒が置かれていない場所）
#define BOARD_CIRCLE 1   //○（駒が置かれている場所）先行
#define BOARD_CROSS 2    //☓（駒が置かれている場所）後攻

int main(int argc, char **argv) {
 //グローバル変数宣言
 int board[BOARD_SIZE][BOARD_SIZE];
 int player_turn;
 int cpu_turn;
 int winner;
 int maxcount = 0;
 
 decideTurn(&player_turn, &cpu_turn);
 initBoard(board);
 printBoard(board);
 
 while(true) {
   if(player_turn == 1) {
      inputPosition(board, player_turn, &maxcount);
      printBoard(board);
      JudgeWinner(board, player_turn, &winner);
      game(winner, player_turn, cpu_turn, maxcount);
      
      printf("CPUの番です。\n");
      moveCpu(board, cpu_turn, &maxcount);
      printBoard(board);
      JudgeWinner(board, cpu_turn, &winner);
      game(winner, player_turn, cpu_turn, maxcount);
   } else if(player_turn == 2) {
      printf("CPUの番です。\n");
      moveCpu(board, cpu_turn, &maxcount);
      printBoard(board);
      JudgeWinner(board, cpu_turn, &winner);
      game(winner, player_turn, cpu_turn, maxcount);
 
      inputPosition(board, player_turn, &maxcount);
      printBoard(board);
      JudgeWinner(board, player_turn, &winner);  
      game(winner, player_turn, cpu_turn, maxcount);
   }
 }
 
 return 0;
}
