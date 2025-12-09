#include <iostream>
#include <vector>
#include <queue>

// Define a pair for the priority queue: {cost, destination_node}
using pii = std::pair<int, int>;

// Function to calculate the cost for a single source node using Prim's algorithm
int primMST(int start_node, int g_nodes, const std::vector<std::vector<pii>>& adj) {
    // Priority queue to store {cost, node}, ordered by smallest cost
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    
    // Visited array to keep track of nodes included in the MST
    std::vector<bool> visited(g_nodes + 1, false);
    
    int total_reversals = 0;
    
    // Start with the source node
    pq.push({0, start_node});
    
    while (!pq.empty()) {
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        // If node is already visited, skip
        if (visited[u]) {
            continue;
        }
        
        // Mark node as visited and add the edge cost to our total
        visited[u] = true;
        total_reversals += cost;
        
        // Explore neighbors
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }
    
    return total_reversals;
}


std::vector<int> countReverseEdges(int g_nodes, int g_edges, const std::vector<int>& g_from, const std::vector<int>& g_to) {
    // Step 1: Build the weighted adjacency list
    // adj[i] stores a list of pairs {neighbor, weight}
    std::vector<std::vector<pii>> adj(g_nodes + 1);
    for (int i = 0; i < g_edges; ++i) {
        int u = g_from[i];
        int v = g_to[i];
        
        // Original edge u -> v has 0 cost
        adj[u].push_back({v, 0});
        
        // Conceptual reversed edge v -> u has 1 cost (a reversal)
        adj[v].push_back({u, 1});
    }
    
    std::vector<int> results;
    
    // Step 2 & 3: Iterate through each node and run Prim's
    for (int i = 1; i <= g_nodes; ++i) {
        results.push_back(primMST(i, g_nodes, adj));
    }
    
    return results;
}

// Example main function to test with the sample case
int main() {
   freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    int g_nodes = 3;
    int g_edges = 2;
    std::vector<int> g_from;
    std::vector<int> g_to;
    std::cin>>g_nodes>>g_edges;
    for(int i=0;i<g_edges;i++){
      int a,b;std::cin>>a>>b;
      g_from.push_back(a);
      g_to.push_back(b);
    }
    
    std::vector<int> result = countReverseEdges(g_nodes, g_edges, g_from, g_to);
    
    // Expected Output: 1 0 1
    for (int res : result) {
        std::cout << res << " ";
    }
    std::cout << std::endl;
    
    return 0;
}