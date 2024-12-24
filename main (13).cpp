#include <iostream>
#include <vector>
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

// Binary Tree to AVL Tree Converter
class BinaryTreeToAVL {
public:
    // Store nodes in sorted order
    vector<int> nodes;

    // In-order traversal to populate nodes
    void inOrderTraversal(Node* root) {
        if (root != nullptr) {
            inOrderTraversal(root->left);
            nodes.push_back(root->data);
            inOrderTraversal(root->right);
        }
    }

    // Function to build an AVL tree from a sorted array
    Node* sortedArrayToAVL(int start, int end) {
        if (start > end) {
            return nullptr;
        }

        // Middle element to ensure balance
        int mid = (start + end) / 2;
        Node* root = new Node(nodes[mid]);

        // Recursively build left and right subtrees
        root->left = sortedArrayToAVL(start, mid - 1);
        root->right = sortedArrayToAVL(mid + 1, end);

        return root;
    }

    // Convert Binary Tree to AVL Tree
    Node* convertToAVL(Node* root) {
        // Step 1: Populate nodes with in-order traversal
        inOrderTraversal(root);

        // Step 2: Construct AVL tree using sorted array
        return sortedArrayToAVL(0, nodes.size() - 1);
    }

    // Pre-order traversal to display AVL Tree
    void preOrderTraversal(Node* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }
};

// Main Function
int main() {
    // Creating a Binary Tree
    Node* root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(9);
    root->right->left = new Node(20);
    root->right->right = new Node(40);

    cout << "Original Binary Tree (Pre-order): ";
    BinaryTreeToAVL converter;
    converter.preOrderTraversal(root);
    cout << endl;

    // Converting to AVL Tree
    Node* avlRoot = converter.convertToAVL(root);

    cout << "Converted AVL Tree (Pre-order): ";
    converter.preOrderTraversal(avlRoot);
    cout << endl;

    return 0;
}
