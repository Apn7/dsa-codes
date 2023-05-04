#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left, *right;
    node(int a){
        data = a;
        left = NULL;
        right = NULL;
    }
};

void creation(node **root, int data){
    node *ptr = new node(data);

    if (*root==NULL){
        *root = ptr;
    }
    else{
        node *temp = *root;
        while (temp!=NULL){
            if (temp->data > data){
                if (temp->left==NULL){
                    temp->left=ptr;
                    break;
                }
                else {
                    temp = temp->left;
                }
            }
            else if(temp->data < data){
                if (temp->right==NULL){
                    temp->right=ptr;
                    break;
                }
                else {
                    temp = temp->right;
                }
            }
        }
    }
}

void rdeleteNode(node** root, int key) {
    if (*root == NULL) {
        return;
    }
    if (key < (*root)->data) {
        rdeleteNode(&((*root)->left), key);
    }
    else if (key > (*root)->data) {
        rdeleteNode(&((*root)->right), key);
    }
    else { // found node to delete
        if ((*root)->left == NULL && (*root)->right == NULL) { // case 1: leaf node
            delete *root;
            *root = NULL;
        }
        else if ((*root)->left == NULL) { // case 2a: node with one child (right)
            node* temp = *root;
            *root = (*root)->right;
            delete temp;
        }
        else if ((*root)->right == NULL) { // case 2b: node with one child (left)
            node* temp = *root;
            *root = (*root)->left;
            delete temp;
        }
        else { // case 3: node with two children
            node* minRight = (*root)->right;
            while (minRight->left) {
                minRight = minRight->left;
            }
            (*root)->data = minRight->data;
            rdeleteNode(&((*root)->right), minRight->data);
        }
    }
}

void deleteNode(node** root, int key) {
    node* curr = *root;
    node* parent = NULL;

    while (curr != NULL && curr->data != key) {
        parent = curr;
        if (key < curr->data) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }

    if (curr == NULL) {
        return; // key not found
    }

    // Case 1: Node has no children
    if (curr->left == NULL && curr->right == NULL) {
        if (curr == *root) {
            *root = NULL;
        }
        else if (parent->left == curr) {
            parent->left = NULL;
        }
        else {
            parent->right = NULL;
        }
        delete curr;
    }
    // Case 2: Node has one child
    else if (curr->left == NULL) {
        if (curr == *root) {
            *root = curr->right;
        }
        else if (parent->left == curr) {
            parent->left = curr->right;
        }
        else {
            parent->right = curr->right;
        }
        delete curr;
    }
    else if (curr->right == NULL) {
        if (curr == *root) {
            *root = curr->left;
        }
        else if (parent->left == curr) {
            parent->left = curr->left;
        }
        else {
            parent->right = curr->left;
        }
        delete curr;
    }
    // Case 3: Node has two children
    else {
        node* successor = curr->right;
        while (successor->left != NULL) {
            successor = successor->left;
        }
        int temp = successor->data;
        deleteNode(root, successor->data);
        curr->data = temp;
    }
}


void rcreat(node **root, int data){
    if (*root == NULL){
        node *ptr = new node(data);
        *root = ptr;
        return;
    }
    if ((*root)->data > data){
        rcreat(&((*root)->left), data);
    }
    else if ((*root)->data < data){
        rcreat(&((*root)->right), data);
    }
}

void print(node *root){
    if (root == NULL) return;
    print(root->left);
    cout << root->data <<" ";
    print(root->right);
}

int main (){
    node *root = NULL;
    int n;cin >> n;
    for (int i=0;i<n;i++){
        int x;cin>> x;
        creation(&root,x);
    }
    rcreat(&root,25);
    rcreat(&root,40);

    deleteNode(&root,19);
    print(root);
}