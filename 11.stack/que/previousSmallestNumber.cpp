#include <iostream>
#include <stack>

using namespace std;

int main(){

     int arr[] = {8,4,6,2,3};
     int size = sizeof(arr)/sizeof(arr[0]);
     int newArr[size];
     stack<int> stk;
     stk.push(-1);


     for(int i=0 ; i<size ; i++){
          if(stk.top() < arr[i]){
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