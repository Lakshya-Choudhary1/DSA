#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
     stack<int> s;

     //push
     s.push(0);
     s.push(1);
     s.push(2);
     s.push(3);

     //pop
     s.pop();

     //empty
     cout << "Is empty : " << ((s.empty() == 0) ? "false" : "true") << endl;

     //size
     cout << "length : " << s.size() << endl; 

     //peek at top
     cout << "top of stack :" << s.top() << endl;

     cout << "<-- iteration -->" << endl;
     stack<int> it = s;
     while(!it.empty()){
          cout << it.top() << endl;
          it.pop();
     } 


     return 0;
}