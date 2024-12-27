#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS on a graph
void BFS(int startNode, const vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false); // Keep track of visited nodes
    queue<int> q; // Queue to store nodes to visit

    // Start from the given node
    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS traversal starting from node " << startNode << ": ";

    while (!q.empty()) {
        int current = q.front(); // Get the front node
        q.pop(); // Remove it from the queue

        cout << current << " "; // Process the current node

        // Visit all neighbors of the current node
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor); // Add unvisited neighbors to the queue
            }
        }
    }

    cout << endl;
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
    BFS(startNode, graph);

    return 0;
}
