
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

vector<int> k_shortest_paths(int n, vector<vector<pair<int,int>>>& adj, int k) {
    vector<int> ans;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    
    while (!pq.empty() && ans.size() < k) {
        auto [cost, u] = pq.top(); pq.pop();
        cost = -cost;
        
        if (u == n) {
            ans.push_back(cost);
            continue;
        }
        
        for (auto [v, w] : adj[u]) {
            pq.push({-(cost + w), v});
        }
    }
    
    return ans;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int,int>>> adj(n+1);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    
    auto paths = k_shortest_paths(n, adj, k);
    for (int cost : paths) {
        cout << cost << " ";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}