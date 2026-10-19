#include <iostream>

using namespace std;

class Node{
     public:
          int data;
          Node* left;
          Node* right;
     Node(int data):data(data){
          left = right = NULL;
     }
};

Node* create_tree(){
     int val;
     cout << "Enter value : " ;
     cin >> val;

     if(val == -1) return NULL;
     Node* newNode  = new Node(val);
     newNode->left = create_tree();
     newNode->right = create_tree();

     return newNode;
}

int max_height(Node* root){
     if(root==NULL) return 0;

     int height = 0 ;

     int leftHeight = max_height(root->left);
     int rightHeight = max_height(root->right);

     height = max(leftHeight,rightHeight) + 1;

     return height;
}

int min_height(Node* root){
     if(root==NULL) return 0;

     int height = 0 ;

     int leftHeight = min_height(root->left);
     int rightHeight = min_height(root->right);

     height = min(leftHeight,rightHeight) + 1;

     return height;
}


int diameter(Node* root){
     if(root == NULL) return 0;
     int d{0};
     int op1 = diameter(root->left);
     int op2 = diameter(root->right);
     int op3 = max_height(root->left) + max_height(root->right);
     d = max(op1 , max(op2,op3));
     return d;
}

int main(){

     Node* root = create_tree();

     cout << "Max height : " << max_height(root) << endl;
     cout << "Min height : " << min_height(root) << endl;
     cout << "Diameter : " << diameter(root) << endl;

     return 0;
}