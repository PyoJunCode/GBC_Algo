#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ice{
 vector<int> adj;
 bool visit = false;
 int height;
};

ice sea[301][301];
ice temp[301][301];


int size = 0, year = 0;
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1}; // L U R D


int BFS(int one, int two){
 
 int cnt = 0;
 queue<pair<int, int>> e;
 e.push({one,two});
 //temp[one][two].visit = true;
 
 while(!e.empty()){
  
  
  
  
  int curx = e.front().first;
  int cury = e.front().second;
  
  if(temp[curx][cury].visit == false)
   cnt ++;

  
  temp[curx][cury].visit = true;
  
  e.pop();
  
  for(int d = 0; d < 4; d++) // check around
  {
   
   int x = curx + dirX[d];
   int y = cury + dirY[d];
   
   if(temp[x][y].height != 0 && temp[x][y].visit == false){
    e.push({x,y});
   }
  } //check around
  
  
  
 }
 
 
 return cnt;
}

int main(int argc, const char * argv[]) {
 
 int N, M;
 
 cin >> N >> M ;
 
 
 for(int i = 0; i < N; i ++){
  for(int j = 0; j < M ; j ++){
   cin >> sea[i][j].height;
   if(sea[i][j].height > 0){
    size ++;
    temp[i][j].height = sea[i][j].height ;
   }
  }
 }
 
 while(size != 0){
  
  queue<pair<int,int>> exist;
  
  for(int i = 0; i < N; i ++){
   for(int j = 0; j < M ; j ++){
    
    int around = 0;
    
    if(sea[i][j].height > 0){
     
     for(int d = 0; d < 4; d++) // check around
     {
      
      int x = i + dirX[d];
      int y = j + dirY[d];
      
      if(sea[x][y].height == 0)
       around ++;
     } //check around
     
     temp[i][j].height = temp[i][j].height - around;
     temp[i][j].visit = false;
     
     if(temp[i][j].height <= 0){
      temp[i][j].height = 0;
      size --;
     }
     else exist.push({i,j});
     
    } //if
    else temp[i][j].height = 0;
   } //second for
  } //first for
  
  year ++ ;
  
  int cmp = BFS(exist.front().first, exist.front().second);
  
  if( cmp != size){
   cout  <<year << endl;
   return 0;
  }
  
  
  
  
 } //while
 
 
 cout << "0"  ;
 
 return 0;
}
