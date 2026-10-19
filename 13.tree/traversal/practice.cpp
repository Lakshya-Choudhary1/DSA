#include <iostream>
#include <queue>

using namespace std;

//node
class Node{
     public:
          int data;
          Node* left;
          Node* right;


          Node(int data):data(data){
               left = right = NULL;
          }
};

//create tree
Node* create_tree(){
     int val;
     cout << "Enter val : " ;
     cin >> val;

     if(val==-1) return NULL;

     Node* newNode = new Node(val);
     cout << "Enter left of" << val << endl; 
     newNode->left = create_tree();
     cout << "Enter right of" << val << endl; 
     newNode->right = create_tree();

     return newNode;
}

//preorder
void pre_order(Node* root){
     if(root==NULL) return;

     cout << "Node : " << root->data << endl;
     pre_order(root->left);
     pre_order(root->right);
}

//postorder
void post_order(Node* root){
     if(root==NULL) return;

     post_order(root->left);
     post_order(root->right);
     cout << "Node : " << root->data << endl;
}
//inorder
void in_order(Node* root){
     if(root==NULL) return;

     in_order(root->left);
     cout << "Node : " << root->data << endl;
     in_order(root->right);
}

//level order
void level_order(Node* root){
     queue<Node*> que;
     que.push(root);
     que.push(NULL);
     
     while (!que.empty()){
          Node* front = que.front();
          que.pop();
          if(front == NULL){
               cout << endl;
               if(!que.empty()) que.push(NULL);
          }else{
               cout << front->data << ",";

               if(front->left != NULL) que.push(front->left);
               if(front->right != NULL) que.push(front->right);
          }
          
     }
}

int main(){

     Node* root = create_tree();

     pre_order(root);
     in_order(root);
     post_order(root);

     level_order(root);



     return 0;
}