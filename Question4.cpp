#include <bits/stdc++.h>
using namespace std;

// Function to find the sum of weights of edges in the Minimum Spanning Tree
int spanningTree(int V, vector<vector<pair<int, int>>> &adj) {
    // Min-heap priority queue to select the edge with minimum weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Boolean array to keep track of visited vertices
    vector<bool> visited(V, false);

    // Start from vertex 0, and add all its edges to the priority queue
    pq.push({0, 0}); // {weight, vertex}

    int mstWeightSum = 0; // Store the total weight of the MST

    // While there are vertices left to process
    while (!pq.empty()) {
        // Get the edge with the smallest weight
        auto [weight, u] = pq.top();
        pq.pop();

        // If the vertex is already visited, skip it
        if (visited[u]) continue;

        // Add the weight to the MST
        mstWeightSum += weight;

        // Mark the vertex as visited
        visited[u] = true;

        // Process all adjacent vertices of u
        for (auto &[v, edgeWeight] : adj[u]) {
            if (!visited[v]) {
                // If vertex v is not visited, add the edge to the priority queue
                pq.push({edgeWeight, v});
            }
        }
    }

    return mstWeightSum;
}

int main() {
    // Example input
    int V = 6;  // Number of vertices

    // Create the adjacency list for the graph
    vector<vector<pair<int, int>>> adj(V);

    // Adding edges to the graph (u, v, weight)
    adj[0].push_back({1, 5});
    adj[1].push_back({0, 5});
    
    adj[0].push_back({2, 6});
    adj[2].push_back({0, 6});

    adj[1].push_back({3, 2});
    adj[3].push_back({1, 2});

    adj[2].push_back({3, 4});
    adj[3].push_back({2, 4});

    adj[2].push_back({4, 3});
    adj[4].push_back({2, 3});

    adj[3].push_back({5, 8});
    adj[5].push_back({3, 8});

    adj[4].push_back({5, 1});
    adj[5].push_back({4, 1});

    // Function call to find the sum of weights in the MST
    int mstSum = spanningTree(V, adj);

    // Output the result
    cout << mstSum << endl; // Expected Output: 14

    return 0;
}
