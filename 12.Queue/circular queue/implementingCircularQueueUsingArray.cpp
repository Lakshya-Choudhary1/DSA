#include <iostream>

using namespace std;

class MyCircularQueue {
    int *arr;
    int front , rear , size;
public: 
    MyCircularQueue(int k): size(k) {
        front = rear = -1;
        arr = new int[k];
    }
    
    bool enQueue(int value) {
        if((rear+1)%size == front){//check if stack is full 
            return false;
        }else if(front == -1){ // if no element 
            front = rear = 0;
        }else{
            rear = (rear+1)%size;
        }
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }else if(front == rear){
            front = rear = -1;
        }else{
            front = (front+1)%size;
        }
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : arr[front]; 
    }
    
    int Rear() {
        return isEmpty() ? -1 : arr[rear]; 
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        if((rear+1)%size == front) return true;
        return false;
    }

};

int main(){


     return 0;
}