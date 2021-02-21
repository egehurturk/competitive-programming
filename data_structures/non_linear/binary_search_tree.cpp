#include <iostream>

using namespace std;

class BST {
    int data = 0;
    BST *left = NULL, *right = NULL;

    public:
        BST(); // default constructor

        BST(int); // parameterized constructor

        BST *insert(BST*, int); // insert

        void inorder(BST*); // inorder traversal
};

BST* BST(int value) {
    data = value;
    left = right = NULL;
}

BST* BST::insert(BST* root, int value) {
    if (!root) {
        return new BST(value); // if root does not exist, create one
    }
    if (value > root->data) {
        root->right = insert(root->right, value); // insert right node
    }
    else {
        root->left = insert(root->left, value);
    }
    return root;
}


void BFS::inorder(BST* root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root -> data << endl;
    inorder(root->right);
}

int main() {
    BST b, *root = NULL;
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);

    b.inorder(root);
    return 0;
}
