#include <iostream>
#include <queue>

using namespace std;

class Node{
     public:
          int data;
          Node* left;
          Node* right;
     
     Node(int data): data(data){
          left = right = NULL;
     }
};

void level_order_traversal(queue<Node*> &que){
     if(que.empty()) return ;

     Node* current = que.front();
     que.pop();

     if(current == NULL){
          cout << endl;
          if(!que.empty()) que.push(NULL);
     }else{
          cout << current->data << "," ;
          if(current->left != NULL) que.push(current->left);
          if(current->right != NULL) que.push(current->right);
     }
     level_order_traversal(que);
}

void print(Node* root){
     if(root == NULL) return ;

     queue<Node*> que;

     que.push(root);
     que.push(NULL);

     level_order_traversal(que);
}

void bst_insertion( Node* &root ,int val ){
     if(root == NULL){
          root = new Node(val);
          return ;
     }

     if(val < root->data){
          bst_insertion(root->left,val);
     }else{
          bst_insertion(root->right,val);
     }

}    

Node* create_bst(){
     Node* root = NULL;

     int val;

     while(true){
          cout << "ENTER VALUE : " ;
          cin >> val;

          if(val == -1) break;

          bst_insertion(root,val);
     }



     return root;
}

void inorder_traversal(Node* root , vector<int>& inorder){
     if(root == NULL) return ;
     inorder_traversal(root->left,inorder);
     inorder.push_back(root->data);
     inorder_traversal(root->right,inorder);
}

void bst_min(Node* root){
     if(root == NULL) return ;
     if(root->left == NULL) cout << "min is : " << root->data << endl;
     bst_min(root->left);
}
void bst_max(Node* root){
     if(root == NULL) return ;
     if(root->right == NULL) cout << "max is : " << root->data << endl;
     bst_max(root->right);
}

int  search_in_bst(Node* root,int data){
     if(root == NULL) return -1;
     int ans =-1;
     while(root!=NULL){
          if(root->data == data){
               ans = data;
               break;
          }

          if(data < root->data){
               root = root->left;
          }else{
               root = root->right;
          }
     }
     return ans;
}

int main(){
     vector<int> inorder;
     Node* root = create_bst();
     
     cout << "Level order traversal" << endl;
     print(root);

     cout << "Inorder traversal" << endl;
     inorder_traversal(root,inorder);
     for(auto a : inorder) cout << a ;
     cout << endl;

     cout << "bst_min" << endl;
     bst_min(root);

     cout << "bst_max" << endl;
     bst_max(root);

     cout << "search in bst : " << endl;
     int data = search_in_bst(root,800);
     cout << data << endl;

     return 0;
}