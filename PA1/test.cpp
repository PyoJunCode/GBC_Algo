//
//  main.cpp
//  PA1
//
//  Created by 서준표 on 01/07/2019.
//  Copyright © 2019 서준표. All rights reserved.
//

#include <iostream>
#include <string.h>

enum dir{
 M_RIGHT,
 M_UP,
 M_LEFT,
 M_DOWN
};

int matrix;
int counter;
int row = 0, column = 0;
int moveDir = 0;
int errored = 0;

void calMove(int number);
void calDir(int number);
void printErr();

using namespace std;

int main(int argc, const char * argv[]) {

 string buff;
 int num;


 cin >> matrix >> counter ;

 while(counter != 0 ){

  buff = "";
  num = 0;

  cin >> buff >> num;


  if(buff.compare("MOVE") == 0){
   calMove(num);
   
  }

  else if(buff.compare("TURN") == 0){
   calDir(num);
  }







  counter --;
 }


 if(errored == 1){
 cout << "-1" << endl;;
 }

else
 cout << column << " "<< row << endl; // 가로 세로

 return 0;
}

void calMove(int number){


 if(moveDir == M_RIGHT) column += number;
 else if(moveDir == M_LEFT) column -= number;
 else if(moveDir == M_UP) row += number;
 else if(moveDir == M_DOWN) row -= number;

 if(row < 0 || column < 0 || row > matrix || column > matrix)
  errored = 1;
}

void calDir(int number){
 //if(number != 0 && number != 1) printErr();


 if(number == 0){
  if(moveDir == M_DOWN) moveDir = 0;
  else moveDir ++;
 }
 else if(number == 1){
  if(moveDir == M_RIGHT) moveDir = 3;
  else moveDir --;
 }
}

void printErr(){
 cout << "-1" << endl;
}
