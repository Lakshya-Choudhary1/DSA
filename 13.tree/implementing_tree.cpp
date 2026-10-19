#include <iostream>

using namespace std;

//node
class Node{
     private:
          int data;
          Node* right;
          Node* left;

     public:

     friend Node* createNode();

     int getValue(){
          return this->data;
     }
          

     Node(int val) : data(val){
          left = right = NULL;
     }
};


Node* createNode(){
     int val;
     cout << "ENTER THE VALUE FOR NODE : " ;
     cin >> val;
     cout << endl;

     if(val == -1){
          return NULL;
     }

     Node* root = new Node(val);

     cout << "PARENT NODE " << val << " left : " << endl; 
     root->left = createNode();
     cout << "PARENT NODE " << val << " rignt : " << endl; 
     root->right = createNode();

     return root;
};

int main(){
     
     Node* tree;
     tree = createNode();

     cout << "Root Node Value : " << tree->getValue() << endl;
     return 0;
}