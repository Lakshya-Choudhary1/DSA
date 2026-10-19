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

void insertion(Node* &root ,const int& data){

     if(root == NULL){
          root = new Node(data);
          return;
     }

     if(data < root->data ){
          insertion(root->left,data);
     }else{
          insertion(root->right,data);
     }

}

Node* create_bst(){
     cout << "<------------------------>\nCreating Binary search tree\n<------------------------>" << endl;

     Node* root = NULL;
     int data;

     while(true){
          cout << "ENTER NODE VALUE : " ;
          cin >> data ;
          cout << endl;

          if(data == -1) break;

          insertion(root,data);
     }

     return root;
}

void inorder_traversal(Node* root){
     if(root == NULL) return ;

     inorder_traversal(root->left);
     cout << root->data << "   " ;
     inorder_traversal(root->right);

}

bool search(Node* root ,int target){
     
     if(root==NULL) return false;

     if(root->data == target) return true;

     bool ans = false;

     if(target<root->data){
          ans = search(root->left,target);
          if(ans) return ans;
     }else{
          ans = search(root->right,target);
          if(ans) return ans;
     }

     return ans;
}

int main(){
     Node* root = create_bst();

     inorder_traversal(root);

     cout <<  search(root,9);

     return 0;
}