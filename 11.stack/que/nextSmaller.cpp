//find next smaller number

#include <iostream>
#include <stack>



using namespace std;



//TC: O(n)  SC: O(n)
int main(){

     

     //<------------------------- BRUTE FORCE METHOD -------------------------> tc(n^2) sc:(n);
     //int arr[] = {8,4,6,2,3};
     // int size = sizeof(arr)/sizeof(arr[0]);
     // int newArr[size]{0};

     // for(int i=0 ; i<size ; i++){
     //      for(int j = i+1 ; j<size ; j++){
     //           if(arr[j]<arr[i]){
     //                newArr[i] = arr[j];
     //                break;
     //           }
     //      }
     // }

     // for(auto a : newArr){
     //      cout << a << endl;
     // }

     //<-------------------------------optimised approach--------------------------> tc(n) sc:(n);

     int arr[] = {8,4,6,2,3};
     int size = sizeof(arr)/sizeof(arr[0]);
     int newArr[size];
     stack<int>stk;
     stk.push(-1);
     
     for(int i = size-1 ; i>=0 ; i--){
          if(stk.top()<arr[i]){
               newArr[i] = stk.top();
          }else{
               stk.pop();
               newArr[i] = stk.top();
          }
          stk.push(arr[i]);
     }


     for(auto a : arr){
          cout << a << "\t" ;
     }
     cout << endl;
     for(auto a : newArr){
          cout << a << "\t" ;
     }


     return 0;
}
