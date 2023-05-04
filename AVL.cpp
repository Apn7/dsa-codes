#include <iostream>
using namespace std;

// AVL tree node class
class Node {
public:
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

// get height of the node
int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// get balance factor of the node
int getBalance(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// right rotate subtree rooted with y
void rightRotate(Node** y) {
    Node* x = (*y)->left;
    Node* T2 = x->right;

    // perform rotation
    x->right = *y;
    (*y)->left = T2;

    // update heights
    (*y)->height = max(height((*y)->left), height((*y)->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // update root pointer
    *y = x;
}

// left rotate subtree rooted with x
void leftRotate(Node** x) {
    Node* y = (*x)->right;
    Node* T2 = y->left;

    // perform rotation
    y->left = *x;
    (*x)->right = T2;

    // update heights
    (*x)->height = max(height((*x)->left), height((*x)->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // update root pointer
    *x = y;
}

// insert a new node into the AVL tree
void insert(Node** root, int data) {
    if (*root == NULL) {
        // create a new node if the tree is empty
        *root = new Node(data);
        return;
    }

    // perform standard BST insertion
    if (data < (*root)->key) {
        insert(&((*root)->left), data);
    } else if (data > (*root)->key) {
        insert(&((*root)->right), data);
    } else { // key already exists
        return;
    }

    // update height of the current node
    (*root)->height = 1 + max(height((*root)->left), height((*root)->right));

    // get the balance factor of the node
    int balance = getBalance(*root);

    // if node is unbalanced, there are four cases

    // left left case
    if (balance > 1 && data < (*root)->left->key) {
        rightRotate(root);
    }

    // right right case
    if (balance < -1 && data > (*root)->right->key) {
        leftRotate(root);
    }

    // left right case
    if (balance > 1 && data > (*root)->left->key) {
        (*root)->left = new Node((*root)->left->key);
        leftRotate(&((*root)->left));
        rightRotate(root);
    }

    // right left case
    if (balance < -1 && data < (*root)->right->key) {
        (*root)->right = new Node((*root)->right->key);
        rightRotate(&((*root)->right));
        leftRotate(root);
    }
}


