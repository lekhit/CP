#include <bits/stdc++.h>
using namespace std;

// Auto-detection for local environment
#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(NULL); cout.tie(NULL)

#define int long long

const int INF = 1e18 + 7;

// Modified Dijkstra to find k shortest distances to all nodes from source node 1
vector<vector<int>> modified_dijkstra(int n, vector<vector<pair<int, int>>>& graph, int k) {
    // dist[v] will store the k shortest distances to node v
    vector<vector<int>> dist(n + 1);

    // Min-heap priority queue: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start from node 1 with distance 0
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();

        // Optimization: If we already have k distances for u and the current one is larger/equal to the k-th, skip
        // This helps prune the search space significantly
        if (dist[u].size() >= k && current_dist >= dist[u].back()) {
             continue;
        }

        // Add this distance to the list for node u
        dist[u].push_back(current_dist);

        // Explore neighbors
        for (auto& [v, weight] : graph[u]) {
            int new_dist = current_dist + weight;

            // Pruning: Only push to queue if we haven't found k paths to v yet,
            // or if the new_dist is better than the worst of the k found so far.
            // This check is crucial for performance.
            if (dist[v].size() < k || new_dist < dist[v].back()) {
                pq.push({new_dist, v});
            }
        }
    }

    // Optional: Sort the final distances for each node (though not strictly needed for the problem's output)
    // The way we use the priority queue and pruning ensures they are added in non-decreasing order mostly,
    // but the final list for a node might not be perfectly sorted due to the pruning logic allowing larger distances sometimes.
    // However, for the specific problem (finding k shortest to destination), we just need the k smallest ones.
    // Sorting here guarantees correctness if we were to take the first k.
    // But given the pruning, the first k elements in dist[n] after processing should be the answer.
    // Let's sort to be absolutely sure, especially if dist[n].size() could be > k due to processing order.
    for (int i = 1; i <= n; ++i) {
         sort(dist[i].begin(), dist[i].end());
    }


    return dist;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> graph(n + 1); // Adjacency list

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    // Find k shortest distances to all nodes
    vector<vector<int>> all_dist = modified_dijkstra(n, graph, k);

    // Extract the k shortest distances to the destination node 'n'
    // Ensure we print exactly k values, even if fewer were found (though problem states at least k exist)
    for (int i = 0; i < k; ++i) {
        if(i < all_dist[n].size()) {
            cout << all_dist[n][i];
        } else {
            // Should not happen given problem constraints, but good practice
            cout << INF; // Or handle error
        }
        if (i < k - 1) cout << " ";
    }
    cout << "\n";
}

int32_t main() {
    fastio;
    // File I/O (local only)
    if (LOCAL_ENV) {
        freopen("i.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}