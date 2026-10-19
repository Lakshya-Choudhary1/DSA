#include <iostream>

using namespace std;

class Node{
     private:
          int data;
          Node* left;
          Node* right;

     public : 
     int get_data(){
          return data;
     }

     friend Node* create_tree();
     friend void post_order_traversal(Node*);
     Node(int data):data(data){
          left = right = NULL;
     }
};

void post_order_traversal(Node* root){
     if(root==NULL) return ;
     post_order_traversal(root->left);
     post_order_traversal(root->right);
     cout << "NODE : " << root->get_data() << endl;
}

Node* create_tree(){
     int val;
     cout << "Enter Node Value : " ;
     cin >> val;

     if(val==-1) return NULL;

     Node* node = new Node(val);
     
     cout << "Insert Left of " << val << endl;
     node->left = create_tree();
     cout << "Insert Right of " << val << endl;
     node->right = create_tree();

     return node;
}

int main(){

     Node* root = create_tree();
     cout << root->get_data() << endl;
     post_order_traversal(root);
     return 0;
}