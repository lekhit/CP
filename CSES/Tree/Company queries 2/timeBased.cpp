#include <bits/stdc++.h>
using namespace std;
//Time in out solution 
// Accepted

// Auto-detection for local environment
#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(NULL); cout.tie(NULL)

    const int N=2e6+5;
    const int LN=17;
vector<int> Tree[N];
vector<vector<int>> up(N, vector<int>(LN+1));
vector<int> inTime(N,0);
vector<int> outTime(N,0);
int timer;

void dfs(int node, int parent){
    inTime[node]=++timer;
    up[node][0]=parent;
    for(int i=1;i<=LN;i++){
        up[node][i]=up[up[node][i-1]][i-1];
    }
    for(auto i: Tree[node]){
        if(i==parent) continue;
        dfs(i, node);
    }
    outTime[node]=++timer;
}

bool isAncestor(int node, int proposedAncestor){
    return inTime[proposedAncestor] <= inTime[node] && outTime[proposedAncestor] >= outTime[node];
}

int lca(int a, int b){
    if(isAncestor(a,b)) return b;
    if(isAncestor(b,a)) return a;
    for(int i=LN;i>=0;i--){
        if(  up[a][i] > 0 && !isAncestor(b, up[a][i])){ 
            //up[a][i] > 0  is required to avoid the LN level nodes which are not significant
            // so the way ensure up[a][i] points to a valid node which starts with 1->n
            a=up[a][i];
        }
    }
    return up[a][0];
}


void solve() {
    // Your solution code here
    timer=0;
    int n,k;cin>>n>>k;
    for(int i=2;i<=n;i++){
        int a;cin>>a;
        Tree[i].push_back(a);
        Tree[a].push_back(i);
    }
    dfs(1, 0);
    while(k--){
        int a,b;
        cin>>a>>b;
        int c=lca(a,b);
        cout<<c<<endl;
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