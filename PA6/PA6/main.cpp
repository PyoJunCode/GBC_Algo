#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
 int n1,n2,r=0;int h[200025];
 cin >> n1 >> n2;
 for(int i=0;i<n1;i++)cin >> h[i];
 sort(h,h+n1);
 int s=1,m=h[n1-1]-h[0];
 while(s<=m){
  int md=(s+m)/2,cnt=1,st=h[0];
  for(int i=1;i<n1;i++){
   if(h[i]-st >=md){cnt++; st=h[i];}
  }
  if(cnt<n2)m=md-1;else {if(md>r)r=md;s=md+1;}
 }
 cout<<r<<endl;
 return 0;
}
