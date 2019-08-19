#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 987654321
using namespace std;

struct node{
 vector<pair<int,int>> adj;
 vector<pair<int,int>> root;
 bool visit[600] ;
};

node nd[600];

int N,M,S,D,c, start, destination;

void BFS(int );

int findPath(node *);

int main(int argc, const char * argv[]) {
 while(1){
  
  memset(nd,0,sizeof(nd));
  
  cin>>N>>M; if(N==0&&M==0) break;
  cin>>start>>destination;
  for(int i =0; i<M; i++){
   cin>>S>>D>>c;
   nd[S].adj.push_back({D,c});
  }
 
 
 findPath(nd);
 BFS(destination);
 int result = findPath(nd);
 
 if(result == INF) cout << "-1" << endl;
  else cout << result << endl;
 
 }
 return 0;
}

void BFS(int dest){
 queue<int> que;
 
 que.push(dest);
 while(!que.empty()){
  int cur = que.front();
  que.pop();
  
  for(int i = 0 ; i < nd[cur].root.size(); i++){
   int near = nd[cur].root[i].first;
   
   for(int i =0; i< nd[near].adj.size(); i++){
    if(nd[near].adj[i].first  == cur){
     nd[near].adj[i].second = -1;
    }
    
   }
   que.push(near);
  }
 }
 
}

int findPath(node *nd){ //dijkstra
 vector<int> dist(N+1, INF);
 priority_queue<pair<int,int>> pq;
 pq.push({0,start}); //start
 dist[start] = 0;
 while(!pq.empty()){
  int cost = -pq.top().first; // reverse for smallest
  int cur = pq.top().second;
  pq.pop();
  
  if(dist[cur] < cost) continue;
  
  for(int i = 0 ; i<nd[cur].adj.size(); i++){
   int near = nd[cur].adj[i].first;
   int nearDist = nd[cur].adj[i].second;
   
   if(nearDist == -1) continue;
   
   if(dist[near] > cost + nearDist){
    dist[near]= cost + nearDist;
    pq.push({-dist[near],near});
    nd[near].root.clear();
    nd[near].root.push_back({cur,dist[near]});
   }
   else if(dist[near] == cost + nearDist) nd[near].root.push_back({cur,dist[near]});
  }
 }
 return dist[destination];
}
