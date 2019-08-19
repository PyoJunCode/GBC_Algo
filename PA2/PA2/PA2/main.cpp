//
//  main.cpp
//  PA2
//
//  Created by 서준표 on 02/07/2019.
//  Copyright © 2019 서준표. All rights reserved.
//

#include <iostream>


using namespace std;

int cup = 0;
int sum[10024] = {0}; // lower than 10,000
int mount[10024] {0}; // lower than 1,000

int comp(int ,int );


int main(int argc, const char * argv[]) {
 
 cin >> cup;
 
 for(int i = 1 ; i <= cup ; i ++) //start from 1 cuz mount[i-3]
 {
  cin >> mount[i];
 }
 
 sum[0] = 0; sum[1] = mount[1]; sum[2] = sum[1] + mount[2];
 
 
 for(int i = 3; i <= cup ; i ++)
 {
  sum[i] = comp(sum[i-2] + mount[i], sum[i-3] + mount[i-1] + mount[i]);
  sum[i] = comp(sum[i-1],sum[i]);
 }
 
 cout << sum[cup];
 
 
 
 return 0;
}

int comp(int one, int two){
 int big = one;
 
 if(big < two) big = two;
 
 return big;
 
}
