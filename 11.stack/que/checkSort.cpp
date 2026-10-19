#include <iostream>
#include <stack>

using namespace std;


bool isSorted(stack<int> s){
     if(s.empty()){
          cout << "stack is empty!" << endl;
          return true;
     }else{
          int top = s.top();
          s.pop();
          while(!s.empty()){
               if(top<s.top()){
                    return false;
               }
               top = s.top();
               s.pop();
          }
     }

     return true;
}

int main(){

     stack<int> s;

     s.push(1);
     s.push(2);
     s.push(3);
     s.push(4);
     s.push(5);
     s.push(6);

     cout <<  isSorted(s);


     return 0;
}