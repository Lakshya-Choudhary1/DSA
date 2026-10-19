#include <iostream>

using namespace std;

class MyCircularDeque {
private:
    int *arr;
    int front , rear , size;

public:
    MyCircularDeque(int k) : size(k) {
        front = rear = -1;
        arr = new int[k]();
    }
    
    bool insertFront(int value) {
        if((rear + 1) % size == front){
            return false;
        }else if(front == -1 && rear == -1){
            front = rear = 0;
        }else{
            front = (front-1+size)%size;
        }
        arr[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if((rear + 1) % size == front){
            return false;
        }else if(front == -1 && rear == -1){
            front = rear = 0;
        }else{
            rear = (rear+1)%size;
        }
        arr[rear] = value;
        return true;
    }

    bool deleteFront() {
        if(front == -1 && rear == -1){
            return false;
        }else if(front == rear){
            front = rear = -1;
        }else{
            front = (front+1)%size;
        }
        return true;
    }
    
    bool deleteLast() {
        if(front == -1 && rear == -1){
            return false;
        }else if(front == rear){
            front = rear = -1;
        }else{
            rear = (rear-1+size)%size;
        }
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : arr[front];
    }
    
    int getRear() {
         return isEmpty() ? -1 : arr[rear];
    }
    
    bool isEmpty() {
        return front==-1;
    }
    
    bool isFull() {
        if((rear+1)%size == front) return true;
        return false;
    }
};

int main(){
     MyCircularDeque dq(5);

     cout <<  dq.insertFront(1);


     return 0;
}