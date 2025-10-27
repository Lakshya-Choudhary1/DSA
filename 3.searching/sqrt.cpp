// #include <iostream>
// #include<cmath>
// using namespace std;

// int sqrt(int root){
//      int index{-1},
//           start{0},
//           end{root*root};

//      while(start<=end){
//           int mid = start + (end-start)/2;
//           int val = mid*mid;
//           if(val == root){
//                index = mid;
//                return index;
//           }else if(val>root){
//                //move left
//                end = mid-1;
//           }else if(val<=root){
//                //move right
//                index = mid;
//                start = mid+1;
//           }
//      }
//      return index;
// }


// int main(){

//      int ans = sqrt(8);
//      cout << ans;


//      return 0;
// }
#include <iostream>
#include <climits>
using namespace std;



int main(){
     cout << divide(7,-3) << endl;
     return 0;
}