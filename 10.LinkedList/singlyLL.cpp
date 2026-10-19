#include <iostream>

using namespace std;

//singly linkedlist
class Node{
     public:
          int data;
          Node *next;
     Node(int val): data(val),next(NULL){}
};

void InsertAtHead(int val,Node* &head, Node* &tail){
     //create a new node;
     Node* newNode = new Node(val);
     if(head == NULL && tail == NULL){
          head = newNode;
          tail = newNode;
     }else{
          newNode->next = head;
          head = newNode;
     }
}

void InsertAtTail(int val , Node* &head,Node* &tail){
     Node* newNode = new Node(val);
     if(head == NULL && tail == NULL){
          head = newNode;
          tail = newNode;
     }else{
          tail->next = newNode;
          tail = newNode;
     }
}

int findLength(Node* head){
     int length=0;
     while(head !=NULL){
          length++;
          head = head->next;
     }
     return length;
}

void InsertAtPosition(int val,int position,Node* &head,Node* &tail){
     int length = findLength(head);
     if(tail == NULL && head == NULL){//no node exists
          Node* newNode = new Node(val);
          head = newNode;
          tail = newNode;
     }else if(position<=1){ // insert at head
          InsertAtHead(val,head,tail);
     }else if(position>length){ // insert at tail
          InsertAtTail(val,head,tail);
     }else{
          int index=1;
          Node* iterator = head;
          while(index<position-1){
               index++;
               iterator = iterator->next;
          }
          Node* newNode = new Node(val);
          newNode->next = iterator->next;
          iterator->next = newNode;
     }
}

void print(Node* head){
     while(head != NULL){
          cout << "DATA :  " << head->data << endl;
          head = head->next;
     }
}

int findNodePosition(int val,Node* head){
     int index=0;
     while(head!=NULL){
          if(head->data == val) return index;
          index++;
          head = head->next;
     }
     return -1;
}

void deleteAtHead(Node* &head,Node* &tail){
     if(head == NULL && tail == NULL){
          return;
     }else if(head == tail){
          delete head;
          head = NULL;
          tail = NULL;
     }else{
          Node* node = head;
          head = head->next;
          delete node;
     }
}

void deleteAtTail(Node* &head,Node* &tail){
     if(head == NULL && tail == NULL){
          return;
     }else if(head==tail){
          delete tail;
          head=NULL;
          tail=NULL;
     }else{  
          Node* iterator = head;
          while(iterator->next != tail){
               iterator = iterator->next;
          }
          delete tail;
          tail = iterator;
          tail->next = NULL;
     }
}

void deleteAtPosition(int index,Node* &head,Node* &tail){
     int length = findLength(head);
     if(head == NULL && tail == NULL){
          return;
     }else if(index<=0){
          deleteAtHead(head,tail);
     }else if(index>=length-1){
          deleteAtTail(head,tail);
     }else{   
          int position=0;
          Node* iterator = head;
          while(position<index-1){
               position++;
               iterator = iterator->next;
          }
          Node* deletionNode = iterator->next;
          iterator->next = iterator->next->next;
          delete deletionNode;
     }
}

int main(){
     Node* head = NULL;
     Node* tail = NULL;

     InsertAtHead(20,head,tail);
     InsertAtHead(10,head,tail);
     InsertAtTail(30,head,tail);
     InsertAtPosition(9,2,head,tail);
     
     int length = findLength(head);
     cout << "LENGTH : " << length << endl;
     // deleteAtHead(head,tail);
     // deleteAtTail(head,tail);
     // deleteAtPosition(2,head,tail);
     print(head);

     cout << "find data:30 position : " << findNodePosition(30,head) << endl;

     return 0;
}