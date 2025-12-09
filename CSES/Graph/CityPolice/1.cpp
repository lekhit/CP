#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); cout.tie(nullptr)

// Type definitions
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

// Utility macros
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define inputvec(v,n) for(int i=0;i<n;i++) {cin>>v[i]; v[i]*=(-1);}
#define makevec(v,n) vi v(n); inputvec(v,n)
#define take(type, name) type name; cin>>name
#define take(type, name, size) type name(size); cin>>name

// Generic input function for pairs
template<typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
    in >> p.first >> p.second;
    return in;
}

// Generic input function for vectors
template<typename T>
istream& operator>>(istream& in, vector<T>& arr) {
    for (auto& x : arr) in >> x;
    return in;
}

// Variadic macro for taking multiple inputs of same type
#define TS(type, ...) type __VA_ARGS__; ([&](auto&&... args) { ((cin >> args), ...); }(__VA_ARGS__))

bool dfs(int node, int N, vector<bool> &vis, vector<vector<int>> &graph, vector<bool> &marked){
    if(node==N) return true;
    vis[node]=true;
    bool possible=false;
    for(int i: graph[node]){
        if(i==N){ possible=true; continue;}
        if(vis[i]) continue;
        marked[i]=dfs(i, N, vis, graph, marked);
        possible=marked[i]||possible;
    }
    marked[node]=possible;
    return possible;
}

void solve() {
    int n,m;cin>>n>>m;
    vector<vector<int>> graph(n+1,vector<int>());  // Changed to n+1 for 1-based indexing
    while(m--){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> dfsVisited(n+1, false);
    vector<bool> marked(n+1, false);
    dfs(1, n, dfsVisited, graph, marked);
    marked[n]=true;

    //----bfs
    queue<pair<int,int>> q;
    vector<int> layerRemovalCost(n+1, 0);
    vector<list<pair<int,int>>> layerRemovalNodes(n+1, list<pair<int,int>>());

    vector<int> layerIndependanceCost(n+1, 0);
    vector<list<pair<int,int>>> layerIndependanceNodes(n+1, list<pair<int,int>>());

    vector<bool> vis(n+1, false);  // Changed to bool for visited array
    vector<int> nodeLayerId(n+1,INT_MAX);
    vis[1]=1;
    int layerCount=0;
    q.push({1,0});
    nodeLayerId[1]=0;
    while(!q.empty()){
        auto p=q.front();q.pop();
        int node=p.first; int layer=p.second;
        layerCount=layer;
        for(int neigbour: graph[node]){
            // // if visited ignore
            if(nodeLayerId[neigbour]<=layer) continue;
            if(neigbour==n){
                layerIndependanceCost[layer]++;
                layerIndependanceNodes[layer].push_back(mp(node, neigbour));
                continue;
            }
            if(!marked[neigbour]) continue;
            nodeLayerId[neigbour]=layer+1;
            layerRemovalCost[layer]++; // counting elemets in this layer
            layerRemovalNodes[layer].push_back(mp(node, neigbour));
            // before puting elements in queue color them
            if(vis[neigbour]==0) // neigbour is not yet added to queue
                { 
                    q.push({neigbour, layer+1});
                    vis[neigbour]=1;}
        }
    }
    int ans=INT_MAX;
    int idex=0;
    for(int i=1;i<=n;i++){
        layerIndependanceCost[i]+=layerIndependanceCost[i-1];
    }
    for(int i=0;i<=layerCount;i++){
        int temp=ans;
        ans=min(layerIndependanceCost[i]+layerRemovalCost[i], ans);
        if(ans!=temp) idex=i;
    }

    cout<<ans<<endl;
    for(int j=0;j<=idex;j++) {
        if(!layerIndependanceNodes[j].empty()) {
            for(auto i: layerIndependanceNodes[j]) {
                cout<<i.first<<" "<<i.second<<endl;//
            }
        }
    }

    for(auto i: layerRemovalNodes[idex]){
        cout<<i.first<<" "<<i.second<<endl;
    }
}

int main() {
    fastio;
    
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    
    return 0;
}