#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
 
 int result;
 int ea;
 
 cin >> ea >> result;
 
 int store[ea] ;
 int num[10024] = {0, };
 
 num[0] = 1;
 
 for(int i = 1; i <= ea ; i++)
 {
  cin >> store[i];
  
  for(int j = store[i] ; j <= result ; j++)
  {
   num[j] = num[j] + num[j-store[i]] ;
  }
  
 }
 
 cout << num[result] ;
 
 return 0;
}
