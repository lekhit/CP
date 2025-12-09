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
class DSU
{
public:
    int N;
    vector<int> parent, size;
    // using zero based indexing 
    DSU(int n)
    {
        N = n; // will be sticking to exact N
        // if N is to be included in queries then give n+1 as input
        N++;
        parent.resize(N);
        for(int i=0;i<N;i++) parent[i]=i; 
        size.assign(N, 1);
    }

    int findParent(int a)
    {
        if (a == parent[a])
            return a;
        return parent[a]=findParent(parent[a]); // path compression
    }

    int combine(int a, int b)
    { // 1--> successful 0--> already connected
        int parentA = findParent(a);
        int parentB = findParent(b);
        if (parentA == parentB)
            return 0;
        if (size[parentA] < size[parentB])
            swap(parentA, parentB);

        size[parentA] += size[parentB];
        parent[parentB] = parentA;
        return 1;
    }

    bool isConnected(int a, int b)
    {
        return (findParent(a) == findParent(b));
    }
};


void solve() {
    // Your solution code here
   // first thing is to check if the graph is fully connected
   // then find the min spanning tree

   int n,m;cin>>n>>m;
   DSU dsu(n+1), dsu2(n+1);
   vector<tuple<int,int,int>> Edges(m);
   for(auto &[w, u, v]: Edges){
    cin>>u>>v>>w;
    dsu2.combine(u, v);
   }
   // check if graph is completely connected; could have used DFS but needed to reformat graph then so used this instead
   int root=dsu2.findParent(1);
   for(int i=1;i<=n;i++) {
    if(root!=dsu2.findParent(i)){
        cout<<"IMPOSSIBLE";
        return;
    }
   }
   // khruskal
   sort(Edges.begin(), Edges.end());
   int weight=0, edgeTake=0;
   for(auto [w, u, v]: Edges){
    if(dsu.isConnected(u, v)) continue;
    weight+=w;
    edgeTake++;
    dsu.combine(u,v);
    if(edgeTake==n-1) break; // optimisation
   }
   cout<<weight;
}

int32_t main() {
    fastio;
    
    // File I/O (local only)
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }

int t=1;
//cin>>t;
    while(t--) {
        solve();
    }

    
    return 0;
}