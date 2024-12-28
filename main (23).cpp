#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Helper function to find root-to-leaf paths using DFS
void findPaths(TreeNode* root, string currentPath, vector<string>& paths) {
    if (!root) return;

    // Add the current node's value to the path
    currentPath += to_string(root->val);

    // Check if it's a leaf node
    if (!root->left && !root->right) {
        paths.push_back(currentPath); // Add the path to the result
    } else {
        currentPath += "->"; // Append the arrow for further nodes
        // Recur for left and right subtrees
        findPaths(root->left, currentPath, paths);
        findPaths(root->right, currentPath, paths);
    }
}

// Function to get all root-to-leaf paths
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    findPaths(root, "", paths);
    return paths;
}

// Helper function to create a tree manually
TreeNode* createExampleTree() {
    // Create the example tree: [1, 2, 3, null, 5]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    return root;
}

int main() {
    TreeNode* root = createExampleTree();

    vector<string> paths = binaryTreePaths(root);

    cout << "Root-to-leaf paths:" << endl;
    for (const string& path : paths) {
        cout << path << endl;
    }

    return 0;
}
