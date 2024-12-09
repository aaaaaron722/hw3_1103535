#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Helper function to perform DFS traversal from a given node.
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
        visited[node] = true;  // Mark the current node as visited.
        result.push_back(node); // Add the current node to the DFS result.

        // Traverse all adjacent vertices of the current node.
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, result); // Recur for unvisited neighbors.
            }
        }
    }

    // Function to perform DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<vector<int>>& adj) {
        vector<int> result; // Stores the DFS traversal result.
        vector<bool> visited(V, false); // Keeps track of visited nodes.

        // Start DFS from vertex 0.
        dfs(0, adj, visited, result);
        
        return result; // Return the DFS traversal.
    }
};

int main() {
    // Define the adjacency list for the graph.
    vector<vector<int>> adj = {
        {1, 2}, 
        {0, 3, 4},
        {0, 5},
        {1},
        {1},
        {2}
    };

    Solution sol;
    vector<int> result = sol.dfsOfGraph(6, adj);
    cout << "[";
    // Output the result of DFS traversal.
    for (int v : result) {
        cout << v;
        if(v != result.size() - 1){
            cout << ',';
        }
    }
    cout << "]";
    return 0;
}
