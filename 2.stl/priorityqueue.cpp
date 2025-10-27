#include <iostream>
#include <queue>
using namespace std;

int main(){
     //creation
     priority_queue<int> pq;
     //max-heap -> maximum value -> Highest Priority

     pq.push(10);
     //10

     pq.push(25);
     //10 25
     
     pq.push(55);
     //10 25 55 

     pq.push(21);
     //10 25 55 21

     //top element(highest) -> HIGHEST PRIORITY ELEMENT
     
     //55

     pq.pop();
     //highest priority element -> pop
     //ie -> 55
     //10 25 21

     cout << pq.top() << endl;
     pq.pop();
     //25 pop 
     //10 21 

     cout << pq.top() << endl;

     //size
     cout << pq.size() << endl;

     return 0;
}