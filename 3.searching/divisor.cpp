#include <iostream>
#include <stdlib.h>
using namespace std;

int findQ(int dividend , int divisor){
     int q{0};

     for(int start=dividend*-1 , end=dividend ; start<=end ;){
          int mid = start + (end-start)/2;

          if(divisor*mid == dividend){
               return mid;
          }else if(divisor*mid < dividend){
               //move right
               start = mid+1;
               q = mid;
          }else if(divisor*mid > dividend){
               //move left
               end = mid-1;
          }
     }
     return q;
}

int main(){
     int dividend = 10, divisor = -2;
     int ans = findQ(abs(dividend),abs(divisor));

     if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)){
          ans *= -1;
     }

     cout << "QUENTIENT = " << ans << endl;

     return 0;
}