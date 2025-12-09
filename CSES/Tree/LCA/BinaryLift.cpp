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
const int LN=17;
vector<int> Tree[N];
vector<vector<int>> sparse(N, vector<int>(LN+1));

void dfs(int parent, int node){
    sparse[node][0]=parent;
    // the for loop is required before the dfs because rest of the nodes below will require information
    // from this built up
    // also since the previous information will be built up so the present node will not have any trouble
     for(int j=1;j<=LN;j++){
            sparse[node][j]=sparse[sparse[node][j-1]][j-1];
        }
    for(auto i: Tree[node]){
        if(i==parent) continue;
        dfs(node, i);
    }
    
}

int binaryLift(int node, int dist){
    int j=0;
     while(dist>0){
            if(dist & 1){ // we lift the node when dist has 1 in its base location.
                node=sparse[node][j];
            }
            j++;
            dist=dist>>1;
        }
        return node;
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
    dfs(0, 1);
    for(int i=1;i<=k;i++){
        int dist,j=0;
        int node;
        cin>>node>>dist;
       node=binaryLift(node, dist);
       if(node==0) node=-1;
    cout<<node<<endl;
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