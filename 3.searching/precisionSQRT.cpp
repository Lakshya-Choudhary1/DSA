//precision sqrt

#include <iostream>
using namespace std;


int mySqrt (int num){
     int s{0},e{num},ans{-1};
     while(s<=e){
          int m = (s+e) >> 1;
          if(m*m<=num){
               //store and compute
               ans=m;
               s=m+1;
          }else{
               e=m-1;
          }
     }
     return ans;
}

long double myPrecision(int num , int precision){
     long double sqrt = mySqrt(num);
     long double step = 0.1;
     while(precision--){
         long double j = sqrt;
          while(j*j<=num){
               sqrt = j;
               j += step;
          }
          step /=10;
     }
     return sqrt;
}

int main(){
     cout << myPrecision(63,6)<< endl;
     return 0;
}