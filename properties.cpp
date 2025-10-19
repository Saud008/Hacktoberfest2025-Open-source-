class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        
        // Build the adjacency list (graph)
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (intersect(properties[i], properties[j]) >= k) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        // Count connected components using DFS
        vector<bool> visited(n, false);
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;  // Increment component count
                dfs(i, graph, visited);
            }
        }
        return components;
    }
    
private:
    // Optimized intersection function using hash map
    int intersect(const vector<int>& a, const vector<int>& b) {
         unordered_set<int> setA(a.begin(), a.end()); // Store only              distinct values
    int count = 0;
    for (int num : b) {
        if (setA.count(num)) {
            count++;
            setA.erase(num); // Ensure distinct counting
        }
    }
    return count;
    }
    
    // DFS to explore components
    void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited);
            }
        }
    }
};
