#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        vector<vector<int>> adj(V);

        for (const pair<int,int> edge : edges) { 
            int u = edge.first;
            int v = edge.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }
};
int main(){
    Solution test;
    vector<pair<int, int>>edges = {
        {0, 1},
        {0, 3},
        {2, 4},
        {2, 1},
        {3, 2},
        {3, 4},
        {1, 3}
    };
    vector<vector<int>> adjList = test.printGraph(5, edges);
    //print out the adjacency list
    cout << "[";
    for (int i = 0; i < adjList.size(); i++) {
        cout << "[";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j];
            if (j != adjList[i].size() - 1) // No comma after the last element
                cout << ",";
        }
        cout << "]";
        if (i != adjList.size() - 1) // No comma after the last list
            cout << ", ";
    }
    cout << "]" << endl;  
    return 0;
}