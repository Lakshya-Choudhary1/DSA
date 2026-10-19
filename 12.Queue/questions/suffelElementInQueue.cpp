#include <iostream>
#include <queue>
#include <stack>

using namespace std;


void print(queue<int> que){
     while(!que.empty()){
          cout << "Element : " << que.front() << endl;
          que.pop();
     }
}

int main(){
     queue<int> que;
     que.push(1);
     que.push(2);
     que.push(3);
     que.push(4);
     que.push(5);


     
     print(que);

     return 0;
}