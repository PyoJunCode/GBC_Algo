#include <iostream>
using namespace std;int n1,n2,s,m,r;int main(int argc, const char * argv[]){cin>>n1>>n2;int s=1,m=n2;while(s<=m){int md=(s+m)/2, c=0;for(int i = 1; i<=n1;i++){if(md/i > n1) c+=n1;else c+=(md/i);}if(c<n2)s=md+1;else{r=md;m=md-1;}}cout<<r;return 0;}
