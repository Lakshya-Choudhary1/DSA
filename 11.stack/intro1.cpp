// <----------IMPLEMENTATION OF STACK USING ARRAY---------->

// #include <iostream>

// using namespace std;

// class Stack{
//    private:

//      int *arr;
//      int capacity;
//      int top{-1};

//    public:

//      void pop(){
//           if(top == -1){
//                cout << "<---STACK UNDERFLOW CANNOT POP MORE ELEMENT--->" << endl;
//                return;
//           }else{
//                arr[top] = 0;
//                top--;
//           }
//      }

//      void push(int val){
//           //handle overflow
//           if(top == capacity-1){
//                cout << "<---STACK OVERFLOW CANNOT PUSH MORE ELEMENT--->" << endl;
//                return;
//           }else{
//                top++;
//                arr[top] = val;
//           }
//      }

//      void print(){
//           if(top == -1){
//                cout << "<---STACK IS EMPTY--->" << endl;
//           }else{
//                for(int i = 0 ; i<capacity ; i++){
//                     cout << "Index [" << i << "] : " << arr[i] << endl;
//                }
//           }
//      }

//      int peek(){
//           if(top == -1){
//                cout << "<---STACK IS EMPTY--->" << endl;
//                return -1;
//           }else{
//                return arr[top];
//           }
//      }

//      bool empty(){
//           if(top == -1){
//                return true;
//           } else {
//                return false;
//           }
//      }

//      int getSize(){return top+1;}
//      int getCapacity(){return capacity;}

//      Stack(int capacity): capacity(capacity) {
//           arr = new int[capacity];
//      }
// };

// int main(){
     
//      Stack *stk = new Stack(5);
//      Stack st(5);
//      st.push(1);

//      cout << st.empty() << endl;
     
//      //check for empty
//      cout << "Empty : " << stk->empty() << endl;

//      //top of stack
//      cout << "top : " << stk->peek() << endl;

//      //push
//      cout << "<---INSERTING INTO STACK--->" << endl;
//      stk->push(1);
//      stk->push(2);
//      stk->push(3);
//      stk->push(4);
//      stk->push(5);
//      stk->push(6);


//      //printing stack
//      cout << "<---PRINT STACK--->" << endl;
//      stk->print();

//      //pop 
//      cout << "<---POP IN STACK--->" << endl;
//      stk->pop();
//      stk->pop();
//      stk->pop();
//      stk->pop();

//      stk->print();

//      //get size
//      cout << "size : " << stk->getSize() << endl;

//      //get capacity
//      cout << "capacity : " << stk->getCapacity() << endl;

//      //peek
//      cout << "peek : " << stk->peek() << endl;

//      delete stk;

//      return 0;
// }



// <----------IMPLEMENTATION OF STACK USING SINGELY LINKED LIST---------->
#include <iostream>
using namespace std;

class Node{
     public :
          int data;
          Node* next;

     Node(int data): data(data){
          next = NULL;
     }
};

class Stack{
     Node* top = NULL;

     public:

     void push(int data){
          Node* newNode = new Node(data);
          if(top == NULL){
               top = newNode;
          }else{
               newNode->next = top;
               top = newNode;
          }
     }

     void pop(){
          if(top == NULL){
               cout << "<--- STACK UNDERFLOW --->" << endl;
          }else{
               Node* temp = top;
               top = top->next;
               delete temp;
          }
     }

     void peek(){
          if(top == NULL){
               cout << "<--- CANNOT PEEK STACK IS EMPTY --->" << endl;
          }else{
               cout << "PEEK : " << top->data << endl;
          }
     }

     void size(){
          int length{0};
          Node* it = top;
          while(it!=NULL){
               length++;
               it = it->next;
          }

          cout << "LENGTH IS : " << length << endl;
     }

     void empty(){
          if(top == NULL){
               cout << "EMPTY : true " << endl;
          }else{
               cout << "EMPTY : false " << endl;
          }
     }

     void print(){
          if(top == NULL){
               cout << "<--- STACK IS EMPTY CANNOT PRINT --->" << endl;
          }else{
               Node* it = top;
               while(it!=NULL){
                    cout << "DATA : " << it->data << endl;
                    it = it->next;
               }
          }
     }

     Stack(){}
     ~Stack(){
          while(top!=NULL){
               Node *temp = top;
               top = top->next;
               delete temp;
          }
     }
};


int main(){

     Stack *stack = new Stack();

     stack->push(1);
     stack->push(2);
     stack->push(3);
     stack->push(4);

     stack->pop();
     stack->peek();
     stack->empty();
     stack->size();

     stack->print();
     
     delete stack;
     return 0;
}