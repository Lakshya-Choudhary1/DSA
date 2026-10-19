#include <iostream> 
using namespace std;

class Node{
     private:
          int data;
          Node* prev;// point to prev node
          Node* next;// point to next node
     public:
     
     friend void deleteAtPositionFromTail(int index, Node* &head,Node* &tail);
     friend void deleteFromHead( Node* &head,Node* &tail);
     friend void deleteAtPositionFromHead(int index ,Node* &head,Node* &tail);
     friend void deleteFromTail(Node* &head,Node* &tail);
     friend void insertAtTail(int value , Node* &head,Node* &tail);
     friend void insertAtHead(int value , Node* &head,Node* &tail);
     friend int findLength(Node* head);
     friend void printFromHead(const Node* head); // ->->->
     friend void printFromTail(const Node* tail); // <-<-<-
     friend void insertAtPositionFromHead(int value,int position,Node* &head,Node* &tail);
     friend void insertAtPositionFromTail(int ,int ,Node* &,Node* &);
     friend int findNodePositionFromHead(int value,const Node* head,const Node* tail);
     friend int findNodePositionFromTail(int value,const Node* head,const Node* tail);

     Node(int value):data(value),prev(NULL),next(NULL){} // constructor 
};

int findLength(Node* head){
     if(head==NULL) return -1;
     int index = 0;
     while(head!=NULL){
          index++;
          head = head->next;
     }
     return index;
}

void insertAtHead(int value , Node* &head,Node* &tail){
     if(head == NULL && tail == NULL){
          Node* newNode = new Node(value);
          head = newNode;
          tail = newNode;
     }else{
          Node* newNode = new Node(value);
          newNode->next = head;
          head->prev = newNode;
          head = newNode;
     }
}

void insertAtTail(int value , Node* &head,Node* &tail){
     if(head == NULL && tail == NULL){
          Node* newNode = new Node(value);
          head = newNode;
          tail = newNode;
     }else{
          Node* newNode = new Node(value);
          tail->next = newNode;
          newNode->prev = tail;
          tail = newNode;
     }
}

void insertAtPositionFromHead(int value,int position,Node* &head,Node* &tail){
     int length = findLength(head);
     if(position<=0){//insert at head
          insertAtHead(value,head,tail);
     }else if(position >= length){ // insert at tail
          insertAtTail(value,head,tail);
     }else{
          int index = 0;
          Node* prevNode = head;
          while(index < position-1){
               index++;
               prevNode = prevNode->next;
          }
          Node* newNode = new Node(value);
          newNode->prev = prevNode;
          newNode->next = prevNode->next;
          prevNode->next->prev = newNode;
          prevNode->next = newNode;
     } 
}

void insertAtPositionFromTail(int value,int position,Node* &head,Node* &tail){
     int length = findLength(head);

     if(position<=0){
          insertAtTail(value,head,tail);
     }else if(position>=length){
          insertAtHead(value,head,tail);
     }else{
          int index{0};
          Node* prevNode = tail;
          while(index<position-1){
               index++;
               prevNode = prevNode->prev;
          }
          Node* newNode = new Node(value);
          newNode->next = prevNode;
          newNode->prev = prevNode->prev;
          prevNode->prev->next = newNode;
          prevNode->prev=newNode;
     }
}

void printFromHead(const Node* head){
     while(head!=NULL){
          cout << "DATA :  " << head->data << endl;
          head = head->next;
     }
}

void printFromTail(const Node* tail){
     while(tail!=NULL){
          cout << "DATA :  " << tail->data << endl;
          tail = tail->prev; 
     }
}

int findNodePositionFromHead(int value,const Node* head,const Node* tail){
     int index{0};
     while(head!=NULL){
          if(head->data == value) return index;
          index++;
          head = head->next;
     }
     return -1;
}

int findNodePositionFromTail(int value,const Node* head,const Node* tail){
     int index{0};
     while(tail!=NULL){
          if(tail->data == value) return index;
          index++;
          tail = tail->prev;
     }
     return -1;
}

void deleteFromTail(Node* &head,Node* &tail){
     if(head == NULL && tail == NULL){
          return;
     }else if(head == tail){
          delete head;
          head = NULL;
          tail = NULL;
     }else{
          Node* deleteNode = tail;
          tail = tail->prev;
          tail->next = NULL;
          delete deleteNode;
     }
}

void deleteFromHead( Node* &head,Node* &tail){
     if(head==NULL&&tail==NULL){
          return;
     }else if(head==tail){
          delete head;
          head = NULL;
          tail = NULL;
     }else{
          Node* deleteNode = head;
          head = head->next;
          head->prev=NULL;
          delete deleteNode;
     }
}

void deleteAtPositionFromHead(int index ,Node* &head,Node* &tail){
     int length = findLength(head);
     if(head==NULL&&tail==NULL){
          return;
     }else if(index<=0){
          deleteFromHead(head,tail);
     }else if(index>=length-1){
          deleteFromTail(head,tail);
     }else{
          int position{0};
          Node* prevNode = head;
          while(position<index-1){
               position++;
               prevNode = prevNode->next;
          }
          Node* deleteNode = prevNode->next;
          prevNode->next = deleteNode->next;;
          prevNode->next->prev = prevNode;
          delete deleteNode;
     }
}

void deleteAtPositionFromTail(int index, Node* &head,Node* &tail){
     int length = findLength(head);
     if(head==NULL && tail==NULL){
          return;
     }else if(index<=0){
          deleteFromTail(head,tail);
     }else if(index>=length-1){
          deleteFromHead(head,tail);
     }else{
          int position{0};
          Node* prevNode = tail;
          while(position<index-1){
               position++;
               prevNode = prevNode->prev;
          }
          Node* deleteNode = prevNode->prev;

          deleteNode->prev->next = prevNode;
          prevNode->prev = deleteNode->prev;

          delete deleteNode;
     }
}

int main(){

     Node* head = NULL;
     Node* tail = NULL;

     insertAtHead(1,head,tail);
     insertAtTail(3,head,tail);
     insertAtPositionFromHead(2,1,head,tail);
     insertAtPositionFromTail(89,2,head,tail);
     // deleteAtPositionFromTail(12,head,tail);

     printFromHead(head);
     cout << "POSITON OF DATA 3 FROM HEAD : " << findNodePositionFromHead(3,head,tail) << endl;
     cout << "POSITON OF DATA 3 FROM tail : " << findNodePositionFromTail(3,head,tail) << endl;
     cout << "LL length : " << findLength(head) << endl;

     return 0;
}