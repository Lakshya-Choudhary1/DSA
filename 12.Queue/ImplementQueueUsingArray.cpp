#include <iostream>

using namespace std;

class Queue{
     private:
          int *arr, length, front, back;
     public:
          void push(int val){
               if(back == length-1){
                    cout << "QUEUE OVERFLOW CANNOT PUSH" << endl;
                    return;
               }else if(front == -1 && back == -1){
                    front++;
                    back++;
                    arr[front] = val;
               }else{
                    back++;
                    arr[back] = val;
               }
          }

          void pop(){
               if(front == -1 && back == -1){
                    cout << "QUEUE UNDERFLOW CANNOT POP" << endl;
                    return;
               }else if(front == back){
                    front = -1;
                    back = -1;
               }else{
                    front++;
               }
          }

          int top(){
               if(front == -1){
                    cout << "STACK UNDERFLOW NO FRONT ELEMENT" << endl;
                    return -1;
               }
               return arr[front];
          }

          int end(){
               if(back == -1){
                    cout << "STACK UNDERFLOW NO BACK ELEMENT" << endl;
                    return -1;
               }
               return arr[back];
          }

          bool isEmpty(){
               if(front==-1){
                    return true;
               }
               return false;
          }

          int size(){
               if(front == -1 && back == -1){
                    return 0;
               }
               return back-front+1;
          }

     Queue(int length): length(length){
          arr = new int[length];
          front = -1;
          back = -1;
     }

     ~Queue(){
          delete[] arr;
     }
};

int main(){
     Queue que{5} ;

     que.push(1);
     que.push(2);
     que.push(3);
     que.push(4);
     que.push(5);

     que.pop();
     cout << que.top() << endl;
     cout << que.end() << endl;

     cout << que.isEmpty() << endl;
     cout << que.size() << endl;

     return 0;
}