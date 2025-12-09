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


int N;
const int VISITED=1,UNVISITED=-1,TRAVESING=0, INF=1e9+8;
vector<int> grp;
vector<int> state;
vector<int> ans;
pair<int,int> dfs(int node){ // return size of chain and start of chain
    if(state[node]==TRAVESING){
        // cycle found 
        int size=getSize(node);
        return make_pair(size, node);
    }
    if(state[node]==VISITED) return make_pair(-1,-1);
    state[node]=TRAVESING;
    auto [size, start] = dfs(grp[node]);
    ans[node]=size;
    state[node]=VISITED;

}

int getSize(int node){
    int at=node, count=0;
    while(grp[at]!=node){
        count++;
        at=grp[at];
    }
    return count;
}

void solve() {
    // Your solution code here
    cin>>N;
    grp.resize(N+1);
    state.assign(N+1, UNVISITED);
    ans.assign(N+1, INF);
    for(int i=1;i<=N;i++) cin>>grp[i];
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