#include <iostream>
#include <vector>
#include <queue>
#include <functional>

// {cost, destination_node}
using pii = std::pair<int, int>;

// Structure to represent the MST
struct MSTEdge {
    int to;
    int weight;
};

std::vector<int> results;
std::vector<std::vector<MSTEdge>> mst_adj;

// DFS to calculate answers for all nodes based on the parent's answer
void calculateAnswersDFS(int u, int p) {
    // The parent has already calculated our answer before calling the DFS
    // Now we calculate the answers for our children
    for (const auto& edge : mst_adj[u]) {
        int v = edge.to;
        int weight = edge.weight;
        if (v == p) continue; // Don't go back up to the parent

        // The re-rooting formula
        results[v-1] = results[u-1] - weight + (1 - weight);
        
        calculateAnswersDFS(v, u);
    }
}

std::vector<int> countReverseEdgesOptimized(int g_nodes, int g_edges, const std::vector<int>& g_from, const std::vector<int>& g_to) {
    // Build the full 0-1 weighted graph
    std::vector<std::vector<pii>> adj(g_nodes + 1);
    for (int i = 0; i < g_edges; ++i) {
        int u = g_from[i];
        int v = g_to[i];
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1});
    }

    // --- Step 1: Run Prim's once from Node 1 ---
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<std::tuple<int, int, int>>> pq;
    std::vector<bool> visited(g_nodes + 1, false);
    std::vector<int> parent(g_nodes + 1, 0);
    std::vector<int> edge_weight(g_nodes + 1, 0);
    
    int base_total_reversals = 0;
    int start_node = 1;
    
    pq.push({0, start_node, 0}); // {cost, node, from_node}

    while (!pq.empty()) {
        auto [cost, u, p] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        
        visited[u] = true;
        parent[u] = p;
        edge_weight[u] = cost;
        base_total_reversals += cost;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!visited[v]) {
                pq.push({weight, v, u});
            }
        }
    }
    
    // --- Step 2 & 3: Build MST and run DFS ---
    results.assign(g_nodes, 0);
    mst_adj.assign(g_nodes + 1, std::vector<MSTEdge>());
    
    // Set the answer for our base case
    results[start_node-1] = base_total_reversals;

    // Build the adjacency list for the MST from the parent pointers
    for (int i = 1; i <= g_nodes; ++i) {
        if (parent[i] != 0) {
            mst_adj[i].push_back({parent[i], edge_weight[i]});
            mst_adj[parent[i]].push_back({i, edge_weight[i]});
        }
    }
    
    // Calculate all other answers using DFS
    calculateAnswersDFS(start_node, 0);
    
    return results;
}


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
    
    std::vector<int> result = countReverseEdgesOptimized(g_nodes, g_edges, g_from, g_to);
    
    // Expected Output: 1 0 1
    for (int res : result) {
        std::cout << res << " ";
    }
    std::cout << std::endl;
    
    return 0;
}