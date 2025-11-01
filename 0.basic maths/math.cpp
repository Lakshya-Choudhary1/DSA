#include <iostream>
using namespace std;

int slowExponential(int a , int b){
     int ans{1};
     for(int i{0} ; i<b ; i++) ans *= a;
     return ans;
}

int fastExponential(int a , int b){
     int ans = 1;
 
     while(b>0){
          if(b&1) ans = ans * a;
          a *= a;
          b >>= 1;
          cout << "A:" << a << " B:" << b << endl;
     }

     return ans;
}

int main(){
    cout << slowExponential(2,) << endl;
    cout << fastExponential(2,5) << endl;
     return 0;
}