#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverseUsingStack(queue<int> &que){
     stack<int> stk;

     while(!que.empty()){
          stk.push(que.front());
          que.pop();
     }

     while(!stk.empty()){
          que.push(stk.top());
          stk.pop();
     }

}

void reverseUsingRecursion(queue<int>& que){
     if(que.empty()) return ;
     
     int element = que.front();
     que.pop();
     reverseUsingRecursion(que);

     que.push(element);
}

int main(){

     queue<int> que;

     que.push(1);
     que.push(2);
     que.push(3);
     que.push(4);
     que.push(5);

     queue<int>temp = que;
     while(!temp.empty()){
          cout << "queue : " << temp.front() << endl;
          temp.pop();
     }


     // reverseUsingStack(que);
     reverseUsingRecursion(que);


     cout << "<----- AFTER REVERSE ------->" << endl;
     temp = que;
     while(!temp.empty()){
          cout << "queue : " << temp.front() << endl;
          temp.pop();
     }

     return 0;
}