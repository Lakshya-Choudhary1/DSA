// input : queue-> 1 2 3 4 5 6 7 8 , k=3;
// output : 3 2 1 6 5 4 7 8 

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void rotateNode(queue<int> &q , int k , int count){

     if(count<k){
          while(count!=0){
               q.push(q.front());
               q.pop();
               count--;
          }
          return;
     }

     stack<int> s;
     for(int i=0 ; i<k ; i++){
          s.push(q.front());
          q.pop();
     }

     for(int i=0; i<k ; i++){
          q.push(s.top());
          s.pop();
     }

     return rotateNode(q,k,count-k);
}

void print(queue<int> q){
     while(!q.empty()){
          cout << q.front() << "\t" ;
          q.pop();
     }
     cout << endl;
}

int main(){

     queue<int> q;
     q.push(1);
     q.push(2);
     q.push(3);
     q.push(4);
     q.push(5);
     q.push(6);
     q.push(7);
     q.push(8);

     //input
     cout << "<---INPUT--->" << endl;
     print(q);

     rotateNode(q,8,q.size());

     //output
     cout << "<---OUTPUT--->" << endl;
     print(q);

     return 0;
}

