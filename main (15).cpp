#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS on a graph
void DFS(int currentNode, const vector<vector<int>>& graph, vector<bool>& visited) {
    // Mark the current node as visited
    visited[currentNode] = true;
    cout << currentNode << " "; // Process the current node

    // Visit all unvisited neighbors of the current node
    for (int neighbor : graph[currentNode]) {
        if (!visited[neighbor]) {
            DFS(neighbor, graph, visited);
        }
    }
}

int main() {
    // Example graph as an adjacency list
    vector<vector<int>> graph = {
        {},           // Node 0 (no edges for this example)
        {2, 3, 4},    // Node 1 is connected to nodes 2, 3, and 4
        {1, 5, 6},    // Node 2 is connected to nodes 1, 5, and 6
        {1},          // Node 3 is connected to node 1
        {1, 7},       // Node 4 is connected to nodes 1 and 7
        {2},          // Node 5 is connected to node 2
        {2},          // Node 6 is connected to node 2
        {4}           // Node 7 is connected to node 4
    };

    int startNode = 1; // Specify the starting node
    vector<bool> visited(graph.size(), false); // Keep track of visited nodes

    cout << "DFS traversal starting from node " << startNode << ": ";
    DFS(startNode, graph, visited);
    cout << endl;

    return 0;
}
