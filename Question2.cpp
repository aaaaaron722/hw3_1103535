#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to perform BFS traversal of the graph.
    vector<int> bfsOfGraph(int V, vector<vector<int>>& adj) {
        vector<int> bfs; // Stores the BFS traversal result.
        vector<bool> visited(V, false); // Keeps track of visited nodes.
        
        queue<int> q; // Queue for BFS.
        q.push(0); // Start BFS from vertex 0.
        visited[0] = true; // Mark 0 as visited.
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node); // Add current node to the result.
            
            // Traverse all adjacent nodes of the current node.
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor); // Add neighbor to the queue.
                    visited[neighbor] = true; // Mark neighbor as visited.
                }
            }
        }
        
        return bfs; // Return the BFS traversal.
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
    vector<int> result = sol.bfsOfGraph(6, adj);
    cout << "[";
    // Output the result of BFS traversal.
    for (int v : result) {
        cout << v;
        if(v != result.size() - 1){
            cout << ',';
        }
    }
    cout << "]";
    return 0;
}
