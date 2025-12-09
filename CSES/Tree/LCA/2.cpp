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
// const int N = 200005;
const int N=11;
const int LOGN=16;

vector<int> Tree[N];
int sparse[N][LOGN];
int levels[N];
int visited[N];

void dfs(int parent, int node, int level){
    levels[node]=level;
    sparse[node][0]=parent;
    for(auto i: Tree[node]){
        if(i==parent) continue;
        dfs(node, i, level+1);
    }
}

void buildSparseTable(int numberOfNodes){
    for(int j=1;j<=LOGN;j++){
        for(int i=1;i<=numberOfNodes;i++){
            if(sparse[i][j-1]!=-1)
           { int parent=sparse[i][j-1];
            sparse[i][j]=sparse[parent][j-1];}
        }
    }
}

int binaryLift(int node, int diff){
    int jumpIndex=0;
    while(diff>0){
        if(diff & 1){
            node=sparse[node][jumpIndex];
        }
        diff=diff>>1;
        jumpIndex++;
    }
    return node;
}

int LCA(int nodeA, int nodeB){
    if(levels[nodeA] < levels[nodeB]) swap(nodeA, nodeB);
    // Lift nodeA up to the level of nodeB
    int diff = levels[nodeA] - levels[nodeB];
    nodeA = binaryLift(nodeA, diff);
    if(nodeA == nodeB) return nodeA;
    for(int i = LOGN ; i >= 0; i--) {
        if(sparse[nodeA][i] != sparse[nodeB][i]) {
            nodeA = sparse[nodeA][i];
            nodeB = sparse[nodeB][i];
        }
    }
    return sparse[nodeA][0];
}


void solve() {
    // Your solution code here
   int n,q;cin>>n>>q;
   for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b;
    Tree[a].push_back(b);
    Tree[b].push_back(a);
   }
   // using dfs to get levels
   // and also adding first parent in sparse table
   // NOTE: parent of root is 0
   dfs(0, 1, 0); // 0 based leveling

   // building sparse table
   buildSparseTable(n+1);
   while(q--){
    int a,b;cin>>a>>b;
    int result=0;
    int commonAncestor = LCA(a, b);
    result = (levels[a] + levels[b]-(2*levels[commonAncestor]));
    cout << result << endl;
   }
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