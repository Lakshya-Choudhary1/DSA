#include <iostream>
#include <stack>

using namespace std;


void init(stack<int> &s,int count ){
     int i=1;
     while(i<=count){
          s.push(i);
          i++;
     }
     cout << "<--- STACK INITIALISED SUCCESSFULL --->" << endl;
}

void print(stack<int> s){
     while(!s.empty()){
          cout << "s : " << s.top() << endl;
          s.pop();
     }
}

int findMiddle(stack<int>s){
     int mid = s.size()/2;

     int count=0;
     while(count<mid){
          s.pop();
          count++;
     }

     return s.top();
}

int main(){
     stack<int> s;
     init(s,5);

     print(s);
     
     cout << "Middle Element : " << findMiddle(s);

     return 0;
}
