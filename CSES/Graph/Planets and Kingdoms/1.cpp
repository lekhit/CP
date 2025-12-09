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

vector<vector<int>> grp,rgrp, components;
vector<int> vis, component;
vector<pair<int,int>> tout;
int timer;
const int secondVisited=2;

void dfs(int n){
    if(vis[n]) return;
    timer++;
    vis[n]=1;
    for(auto i: grp[n]){
        dfs(i);
    }
    tout[n]={++timer,n};
}

void rdfs(int n){
    if(vis[n]==secondVisited) return;
    vis[n]=secondVisited;
    component.push_back(n);
    for(auto i:rgrp[n]){
        rdfs(i);
    }
}
void dfs(int n, vector<int> &vis){
    if(vis[n]) return;
    vis[n]=1;
    for(auto i: grp[n]){
        dfs(i,vis);
    }
}

pair<int,int> canReach(vector<int> component1, vector<int> component2){
    int start1=component1[0];
    int start2=component2[0];
    vector<int> vis(grp.size()+1, 0);
    dfs(start1, vis);
    return vis[start1]==vis[start2]? make_pair(start2, start1):make_pair(start1, start2);
}

void solve() {
    // Your solution code here
    int n,m;cin>>n>>m;
    timer=0;
    vis.assign(n+1, 0);
    tout.resize(n+1);
    grp.resize(n+1);
    rgrp.resize(n+1);
    vector<int> unconnectedNodes;
    while(m--){
        int a,b;cin>>a>>b;
        grp[a].push_back(b);
        rgrp[b].push_back(a);
    }
    // KOSARAJU'S algorithm 
    for(int i=1;i<=n;i++) { // first doing dfs to get all processing end times 
            dfs(i);
    } 
    sort(tout.rbegin(), tout.rend());// sorting the processing end times into reverse order
    // processing the nodes with reversed processing time.
    for(auto [_, i]: tout){
        if(i==0) continue;
        component.clear(); // making space for new component
        if(vis[i]!=secondVisited){ // checking if 'i' is not previously visited. using the same visited array. So '0' means not visited by first dfs, '1' means visited by first dfs. here '2' means visited second time b
            rdfs(i);
            components.push_back(component); // adding new component
        }
    }
    cout<<components.size()<<"\n";
    unordered_map<int,int> mp;
    for(int i=0;i<components.size();i++){
        for(auto j: components[i]){
            mp[j]=i;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<(mp[i]+1)<<" ";
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