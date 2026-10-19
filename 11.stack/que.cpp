//implement two stack in an single shared memory(array);

#include <iostream>

using namespace std;

class Stack{
     private: 
          int *arr;
          int top1;
          int top2;
          int capacity;
          int mid;
     public:
          //push 1
          void push1(int data){
               if(top1 == mid-1){
                    cout << "<--- CANNOT PUSH IN PUSH1! STACK OVERFLOW --->" << endl;
               }else{
                    top1++;
                    arr[top1] = data;
               }
          } 

          //push 2
          void push2(int data){
               if(top2 == capacity-1){
                    cout << "<--- CANNOT PUSH IN PUSH2! STACK OVERFLOW --->" << endl;
               }else{
                    top2++;
                    arr[top2] = data;
               }
          }

          //pop 1
          void pop1(){
               if(top1 == -1){
                    cout << "<--- CANNOT POP IN POP1! STACK UNDERFLOW --->" << endl;
               }else{
                    arr[top1] = 0;
                    top1--;
               }
          }

          //pop 2
          void pop2(){
               if(top2 == mid-1){
                    cout << "<--- CANNOT POP IN POP2! STACK UNDERFLOW --->" << endl;
               }else{
                    arr[top2] = 0;
                    top2--;
               }
          }

          void isTop1Empty(){
               if(top1 == -1){
                    cout << "TOP1 EMPTY : TRUE " << endl;
               }else{
                    cout << "TOP1 EMPTY : FALSE " << endl; 
               }
          }

          void isTop2Empty(){
               if(top2 == mid-1){
                    cout << "TOP2 EMPTY : TRUE " << endl;
               }else{
                    cout << "TOP2 EMPTY : FALSE " << endl; 
               }
          }

          void peek1(){
               if(top1 == -1){
                    cout << "<---CANNOT PEAK TOP1 IS EMPTY--->" << endl;
               }else{
                    cout << "TOP1 PEEK : " << arr[top1] << endl;
               }
          }

          void peek2(){
               if(top2 == mid-1){
                    cout << "<---CANNOT PEAK TOP2 IS EMPTY--->" << endl;
               }else{
                    cout << "TOP2 PEEK : " << arr[top2] << endl;
               }
          }

          void print1(){
               if(top1 == -1){
                    cout << "<--- CANNOT PRINT1 STACK UNDERFLOW--->" << endl;
               }else{
                    for(int i = 0 ; i<mid ; i++){
                         cout << "TOP1 ["<< i << "] : " << arr[i] << endl;
                    }
               }
          }

          void print2(){
               if(top2 == mid-1){
                    cout << "<--- CANNOT PRINT2 STACK UNDERFLOW--->" << endl;
               }else{
                    for(int i = mid ; i<capacity ; i++){
                         cout << "TOP2 ["<< i << "] : " << arr[i] << endl;
                    }
               }
          }

     Stack(int capacity): capacity(capacity){
          mid = capacity/2;
          arr = new int[capacity];   
          top1 = -1;
          top2 = mid-1;
     }
};


int main(){
     Stack stack(10);

     stack.push1(1);
     stack.push1(2);
     stack.push1(3);
     stack.push1(4);
     stack.push1(5);

     stack.push2(1);
     stack.push2(2);
     stack.push2(3);
     stack.push2(4);
     stack.push2(5);

     stack.print1();
     stack.print2();

     stack.isTop1Empty();
     stack.isTop2Empty();


     return 0;
}
