#include <iostream>

using namespace std;

class Node{
     public:
          int data;
          Node* next;

     Node(int data):data(data),next(NULL){}
};

void insertAtTail(int data, Node* &head, Node* &tail){
     if(head == NULL && tail == NULL){
          Node* newNode  = new Node(data);
          head = newNode;
          tail = newNode;
     }else{
          Node* newNode = new Node(data);
          tail->next = newNode;
          tail = newNode;
     }
}

void insertAtHead(int data , Node* &head , Node* &tail){
     if(head == NULL && tail == NULL){
          Node* newNode = new Node(data);
          head = newNode;
          tail = newNode;
     }else{
          Node* newNode = new Node(data);
          newNode->next = head;
          head = newNode;
     }
}

void print(Node* head){
     int index{0};
     while(head!=NULL){
          cout << "DATA AT INDEX " << index << " is : " << head->data << endl;
          index++;
          head = head->next;
     }
}

int findLength(Node* head){
     int len = 0;
     while(head!=NULL){
          head = head->next;
          len++;
     }
     return len;
}

Node* mid1(Node* head){
     int length = findLength(head);
     if(length <=0 ){
          return head;
     }else{
          int index{0};
          while(index<length/2){
               index++;
               head = head->next;
          }
     }
     return head;
}

Node* mid2(Node* head){
     if(head == NULL) return head;
     Node* slow = head;
     Node* fast = head;
     while(fast != NULL && fast->next != NULL){
          slow = slow->next;
          fast = fast->next->next;
     }
     return slow;
}

Node* mid3(Node* head){
     if(head == NULL) return head;

     Node* slow = head;
     Node* fast = head;

     while(fast!=NULL){
          fast = fast->next;
          if(fast != NULL){
               slow = slow->next;
               fast = fast->next;
          }
     }

     return slow;
}

int main(){

     Node* head = NULL;
     Node* tail = NULL;

     insertAtHead(4,head,tail);
     insertAtHead(3,head,tail);
     insertAtHead(2,head,tail);
     insertAtHead(1,head,tail);
     insertAtTail(5,head,tail);
     insertAtTail(6,head,tail);
     insertAtTail(7,head,tail);
     insertAtTail(8,head,tail);
     insertAtTail(9,head,tail);
     print(head);
     cout << "LENGTH OF LL : " << findLength(head) << endl;

     Node* m1 = mid1(head);
     Node* m2 = mid2(head);
     Node* m3 = mid3(head);
     cout << "MIDDLE NODE DATA : " << m1->data << endl;
     cout << "MIDDLE NODE DATA USING SLOW AND FAST POINTER METHOD 1 : " << m2->data << endl;
     cout << "MIDDLE NODE DATA USING SLOW AND FAST POINTER METHOD 2 : "
     << m3->data << endl;

     return 0;
}