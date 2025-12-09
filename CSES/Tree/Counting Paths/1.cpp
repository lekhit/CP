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

vector<vector<int>> Tree;
vector<vector<int>> up;
vector<int> tin, tout, delta, countStore;
int N,LN,timer;

int dfs(int node, int parent){
    int count=delta[node];
    tin[node]=++timer;
    up[node][0]=parent;
    for(int i=1;i<=LN;i++){
        up[node][i]=up[up[node][i-1]][i-1];
    }
    for(auto i: Tree[node]){
        if(i==parent) continue;
        count+=dfs(i, node);
    }
    tout[node]=++timer;
    return countStore[node]=count;
}
bool isAncester(int node, int proposedAncester){
    return tin[proposedAncester] <= tin[node] && tout[proposedAncester] >= tout[node];
}

int lca(int a, int b){
    if(isAncester(a,b)) return b;
    if(isAncester(b, a)) return a;
    for(int i=LN; i>=0; i--){
        if(up[a][i]>0 && !isAncester(b, up[a][i])){
            a=up[a][i];
        }
    }
    return up[a][0];
}
void solve() {
    // Your solution code here
    timer=0;
   int n,m;
   cin>>n>>m;
   N=n+1;
   LN=ceil(log2(N));
   Tree.resize(N);
   tin.resize(N);
   tout.resize(N);
   delta.resize(N);
   countStore.resize(N);
   up.resize(N, vector<int>(LN+1));

   while(--n){
    int a,b;cin>>a>>b;
    Tree[a].push_back(b);
    Tree[b].push_back(a);
   }
   dfs(1, 0);
   while(m--){
    int a,b;cin>>a>>b;
    int c=lca(a,b);
    delta[a]+=1;
    delta[b]+=1;
    delta[c]-=1;
    delta[up[c][0]]-=1;
   }
   dfs(1, 0);
   for(int i=1;i<N;i++){
    cout<<countStore[i]<<" ";
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