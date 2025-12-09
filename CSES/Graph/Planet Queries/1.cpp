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

    const int INF=1e9+7;
    const int DMAX=30;

    // this solution will not work if one node could have two tunnels(ie you could go in two direction)
    // to solve that question 
    // We will need to know the direction of strongly connected component and then go in that direction
    // So effectively remove other routes and keep only a single route from each node then run this same algorithm(below)

void solve() {
    // Your solution code here
   int n,m;
   cin>>n>>m;
    vector<vector<int>> parent(n+1, vector<int>(DMAX+1, INF));
    for(int i=1;i<=n;i++) cin>>parent[i][0];

    for(int level=1;level<=DMAX;level++){
        for(int node=1;node<=n;node++){
            // say we are looking for node at parent[node][level] = parent[node][4] = 2^4 ==> node who is 16th parent to current node
            // to do that we will go to the parent[node][level-1] = 2^3 node ==> node who is 8th parent to the present node
            // and then go to [8th parent's]^3 node ==> this will take us another 8 levels up
            // thus totalling up to 16 levels
            int parentInPreviouslyComputedLevel = parent[node][level-1];
            parent[node][level] = parent[ parentInPreviouslyComputedLevel ][level-1];
        }
    }

    while(m--){
        int a,b;cin>>a>>b;
        int ans=a;
        for(int i=0;i<=DMAX;i++){
            if(b & (1<<i)) ans=parent[ans][i];
        }
        cout<<ans<<"\n";
    }

}

int main() {
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