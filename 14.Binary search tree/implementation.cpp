#include <iostream>
#include <queue>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

void level_order_traversal(queue<Node*> &que){

    if(que.empty()) return;

    Node* root = que.front();
    que.pop();

    if(root == NULL){

        cout << endl;

        if(!que.empty()){
            que.push(NULL);
        }

    }else{

        cout << root->data << " ";

        if(root->left){
            que.push(root->left);
        }

        if(root->right){
            que.push(root->right);
        }
    }

    level_order_traversal(que);
}

void print(Node* root){

    if(root == NULL) return;

    queue<Node*> que;

    que.push(root);
    que.push(NULL);

    level_order_traversal(que);
}

void bst_tree_insertion(Node* &root, int val){

    if(root == NULL){
        root = new Node(val);
        return;
    }

    if(val < root->data){
        bst_tree_insertion(root->left, val);
    }else{
        bst_tree_insertion(root->right, val);
    }
}

Node* create_tree(){

    Node* root = NULL;

    int val;

    while(true){

        cout << "ENTER VALUE : ";
        cin >> val;

        if(val == -1){
            break;
        }

        bst_tree_insertion(root, val);
    }

    return root;
}


//delete node
Node* deleteNode(Node* root,int target){
    if(root == NULL) return NULL;

    if(root->data == target){
  
        if(root->left == NULL &&  root->right == NULL){
            delete root;
            return NULL;
        }

        if(root->left != NULL &&  root->right == NULL){
            Node* next = root->left;
            delete root;
            return next;
        }

        if(root->left == NULL &&  root->right != NULL){
            Node* next = root->right;
            delete root;
            return next;
        }

        // both children exist
        Node* parent = root;
        Node* pred = root->left;

        // find inorder predecessor
        while(pred->right != NULL){
            parent = pred;
            pred = pred->right;
        }

        // detach predecessor from its old place
        if(parent != root){
            parent->right = pred->left;
            pred->left = root->left;
        }

        pred->right = root->right;

        delete root;

        return pred;

    }else{

        if(target < root->data){
            root->left = deleteNode(root->left,target);
        }else{
            root->right = deleteNode(root->right,target);
        }

    }

    return root;
}

int main(){

    Node* root = create_tree();

    cout << "\nLEVEL ORDER TRAVERSAL:\n";

    print(root);

    root = deleteNode(root,100);

    print(root);

    return 0;
}