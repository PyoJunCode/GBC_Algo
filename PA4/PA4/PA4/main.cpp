#include <iostream>
#include <vector>

using namespace std;

struct Computer {
 
 vector <int> adj;
 bool visit;
 
};

int infected ;

Computer com[128];

void DFS(int num)
{
 com[num].visit = true;
 for(int i = 0; i < com[num].adj.size(); i ++)
 {
  if(!com[com[num].adj[i]].visit){
   infected ++;
   DFS(com[num].adj[i]);
  }
 }
}

int main(int argc, const char * argv[]) {

 int num, pair;
 int from, to;
 
 cin >> num >> pair;
 
 for(int i = 0 ; i < pair ; i ++)
 {
  cin >> from >> to;
  com[from].adj.push_back(to);
  com[to].adj.push_back(from);
 }
 
 DFS(1); //always start from 1
 
 cout << infected << endl;
 
 return 0;
}
