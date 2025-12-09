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
 
const int N=2e5+6;
// const int N=13;
const int LN=17;
vector<int> Tree[N];
vector<vector<int>> sparse(N, vector<int>(LN+1));
int levels[N];
 
void dfs(int parent, int node, int level){
    levels[node]=level;
    sparse[node][0]=parent;
     for(int j=1;j<=LN;j++){
            sparse[node][j]=sparse[sparse[node][j-1]][j-1];
        }
    for(auto i: Tree[node]){
        if(i==parent) continue;
        dfs(node, i, level+1);
    }
    
}
 
int binaryLift(int node, int dist){
    int j=0;
     while(dist>0){
            if(dist & 1){
                node=sparse[node][j];
            }
            j++;
            dist=dist>>1;
        }
        return node;
}

int LCA(int nodeA, int nodeB){
    if(nodeA == nodeB) return nodeA;
    for(int i=LN; i>=0; i--){
        if(sparse[nodeA][i]!=sparse[nodeB][i]){
            nodeA=sparse[nodeA][i];
            nodeB=sparse[nodeB][i];
        }
    }
    return sparse[nodeB][0];
}
 
void solve() {
    int n,k;cin>>n>>k;
    for(int i=2;i<=n;i++){
        int a;cin>>a;
        int b=i;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }
    //dfs with binary builtup
    dfs(0, 1, 0);
    for(int i=1;i<=k;i++){
        int dist,j=0;
        int a,b; cin>>a>>b;
        if(levels[a]<levels[b]) swap(a,b);
        dist=levels[a]-levels[b];
       a=binaryLift(a, dist);
    cout<<LCA(a,b)<<endl;
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