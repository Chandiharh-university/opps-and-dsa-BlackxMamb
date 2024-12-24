#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Binary Search Tree class
class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // Function to insert a node
    Node* insert(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }
        if (value < root->data) {
            root->left = insert(root->left, value);
        } else {
            root->right = insert(root->right, value);
        }
        return root;
    }

    // Wrapper for insert
    void insert(int value) {
        root = insert(root, value);
    }

    // Function to perform in-order traversal
    void inOrder(Node* root) {
        if (root != nullptr) {
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }
    }

    // Function to perform pre-order traversal
    void preOrder(Node* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    // Function to perform post-order traversal
    void postOrder(Node* root) {
        if (root != nullptr) {
            postOrder(root->left);
            postOrder(root->right);
            cout << root->data << " ";
        }
    }

    // Function to perform all traversals
    void performTraversals() {
        cout << "In-order Traversal: ";
        inOrder(root);
        cout << endl;

        cout << "Pre-order Traversal: ";
        preOrder(root);
        cout << endl;

        cout << "Post-order Traversal: ";
        postOrder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    // Insert nodes into the BST
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Perform all traversals
    tree.performTraversals();

    return 0;
}
