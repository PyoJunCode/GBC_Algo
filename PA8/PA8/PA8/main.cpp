#include <iostream>


using namespace std;
long long x,y, z;
int s, m , result;


int main(int argc, const char * argv[]) {
 
 cin >> x >> y ;
z = (y * 100) / x;
if (z >= 99) {  cout << -1; return 0;}
 int s = 0, m = 1000000009;
 
 int result = 0;
 
 while (s <= m)
 {
  int mid = (s+ m) / 2;
  int temp = (100 * (y + mid)) / (x + mid);
  if (z >= temp){result = mid + 1; s = mid + 1;}
  else m = mid - 1;
 }
 cout << result; return 0;
}
