#include <iostream>
#include <stack>

using namespace std;

void reverse(stack<int> &s){
     stack<int> newStack;

     while(!s.empty()){
          newStack.push(s.top());
          s.pop();
     }
     s = newStack;
}

void print(stack<int> s){
     while(!s.empty()){
          cout << "data : " << s.top() << endl;
          s.pop();
     }
}

int main(){
     stack<int> s;
     
     s.push(1);
     s.push(2);
     s.push(3);
     s.push(4);
     s.push(5);

     cout << "<--- BEFORE REVERSE --->" << endl;
     print(s);

     reverse(s);

     cout << "<--- AFTER REVERSE --->" << endl;
     print(s);
     

     return 0;
}