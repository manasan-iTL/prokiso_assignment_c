#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5     //盤面の縦・横の大きさ
#define BOARD_BLANK 0    //空白（駒が置かれていない場所）
#define BOARD_CIRCLE 1   //○（駒が置かれている場所）先行
#define BOARD_CROSS 2    //☓（駒が置かれている場所）後攻


void initBoard(int board[][BOARD_SIZE]) {
  for(int i=0; i<BOARD_SIZE; i++) {
    for(int k=0; k<BOARD_SIZE; k++) {
      board[i][k] = BOARD_BLANK;
    }
  }
}

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
      printf("counter:%d\n",*counter);
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
