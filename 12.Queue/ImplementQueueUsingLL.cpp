#include <iostream>

using namespace std;

class Node{
     public:
          int val;
          Node* next;

     Node(int val) : val(val){
          next = NULL;
     }

};

class Queue{

     private:
          Node* f;
          Node* b;
          

     public:

     void push(int val){
          Node* newNode = new Node(val);
          if(f == NULL && b == NULL){
               f = newNode;
               b = newNode;
          }else{
               b->next = newNode;
               b = newNode;
          }
     }

     void pop(){
          if(f == NULL){
               return;
          }else if(f==b){
               delete f;
               f = NULL;
               b = NULL;
          }else{
               Node* temp = f;
               f = f->next;
               delete temp;
          }
     }

     bool isEmpty(){
          if(f==NULL) return true;
          return false;
     }

     int front(){
          if(f==NULL){
               cout << "QUEUE IS EMPTY NO FRONT ELEMENT EXISTS" << endl;
               return -1;
          }

          return f->val;
     }

     int back(){
         if(b==NULL){
               cout << "QUEUE IS EMPTY NO REAR ELEMENT EXISTS" << endl;
               return -1;
          }

          return b->val; 
     }

     int size(){
          int length{0};
          Node* temp = f;
          while(temp!=NULL){
               temp = temp->next;
               length++;
          }
          return length;
     }


     Queue(){
          f = NULL;
          b = NULL;
     }
     ~Queue(){
          while(f!=NULL){
               Node* temp = f ;
               f = f->next;
               delete temp;
          }
          b = NULL;
     }
};

int main(){

     Queue *que = new Queue();

     que->push(1);
     que->push(2);
     que->push(3);
     que->push(4);
     que->push(5);

     que->pop();

     cout << "Print front : " << que->front() << endl;
     cout << "Print Back : " << que->back() << endl;
     cout << "Print isEmpty : " << que->isEmpty() << endl;
     cout << "Print size : " << que->size() << endl;




     return 0;
}