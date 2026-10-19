#include <iostream>
#include <queue>

using namespace std;

class Node{
     public:
          int data;
          Node* left;
          Node* right;

     Node(int val):data(val){
          left = right = NULL;
     }
};

Node* create_tree(){
     int val;
     cout << "Enter  : " ;
     cin >> val;
     
     if(val==-1) return NULL;

     Node* node = new Node(val);
     cout << "Enter left Node for Parent " << val << " Node : " << endl;
     node->left = create_tree();

     cout << "Enter right Node for Parent " << val << " Node : " << endl;
     node->right = create_tree();

     return node;
}

void level_order_traversal(queue<Node*>&que){
     if(que.empty()) return;

     Node* front = que.front();
     cout << "Node : " << front->data << endl;
     que.pop();

     if(front->left != NULL)que.push(front->left);    
     if(front->right != NULL) que.push(front->right);    

     level_order_traversal(que);
}

int main(){
     Node* root = create_tree();

     queue<Node*> que;
     que.push(root);

     level_order_traversal(que);

     return 0;
}