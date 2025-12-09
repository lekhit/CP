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


class Solution{
    public:
    vector<vector<int>> grp, rgrp,components, componentGrp;
    int timer;
    vector<int> component, coins, vis, componentCoinValue, treeNodeVal, treeVis;
    vector<pair<int,int>> tout;
    int N;
    const int UNVISITED=1, FIRST_VISITED=2, SECOND_VISITED=3;
    void dfs(int node){
        if(vis[node]==FIRST_VISITED) return;
        vis[node]=FIRST_VISITED;
        timer++;
        for(auto i: grp[node]){
            dfs(i);
        }
        tout[node]=make_pair(++timer, node);
    }

    void rdfs(int node){
        if(vis[node]==SECOND_VISITED) return;
        vis[node]=SECOND_VISITED;
        component.push_back(node); // creating component
        for(auto i:rgrp[node]){
            rdfs(i);
        }
    }

    void makeComponentGrpAsCondensedTree(){
        int n=components.size();
        componentGrp.resize(n+1);
        unordered_map<int,int> componentNodeMapping;
        for(int i=0;i<n;i++){ // components start with '0' to 'k'
            for(auto j: components[i]){
                componentNodeMapping[j]=i; // creating a map to check which node belongs to which component
            }
        }

        for(int i=1;i<=N;i++){
            int componentId=componentNodeMapping[i];
            for(auto node: grp[i]){
                int connectedComponentId=componentNodeMapping[node];
                if(connectedComponentId==componentId) continue;// same component intenal joint so skipped
                componentGrp[componentId].push_back(connectedComponentId); // Here component ID represents the tree ID. we connect it to the connected node.
            }
        }
    }

    int treeDfs(int treeNode){
        if(treeVis[treeNode]) return treeNodeVal[treeNode];
        treeVis[treeNode]=1;
        int  bestRouteSum=0;
        for(auto i: componentGrp[treeNode]){
            bestRouteSum=max(treeDfs(i), bestRouteSum);
        }
        return treeNodeVal[treeNode]+=bestRouteSum;
    }
    int treeCal(){
        int n=componentGrp.size();
        treeNodeVal.resize(n);
        treeVis.assign(n, 0);
        for(int i=0;i<n;i++) treeNodeVal[i]=componentCoinValue[i]; // setting intial node value
        int maxVal=0;
        for(int i=0;i<n;i++){
            maxVal=max(treeDfs(i), maxVal);
        }
        return maxVal;
    }

    void kosarajuFindComponents(){
                for(int i=1;i<=N;i++){
            dfs(i);
        }
        reverse(tout.begin(), tout.end());
        tout.pop_back();
        sort(tout.rbegin(), tout.rend());

        for(auto [_, node]: tout){
            if(vis[node]!=SECOND_VISITED){
                component.clear();
                rdfs(node);
                int coinSum=0;
                for(auto i: component) coinSum+=coins[i];
                componentCoinValue.push_back(coinSum);
                components.push_back(component);
            }
        }
    }

    void solve(){
        int n,m;cin>>n>>m;
        N=n;
        timer=0;
        coins.resize(n+1);
        for(int i=1;i<=n;i++) cin>>coins[i];
        grp.resize(n+1);
        rgrp.resize(n+1);
        vis.assign(n+1, UNVISITED);
        tout.resize(n+1);
        while(m--){
            int a,b;cin>>a>>b;
            grp[a].push_back(b);
            rgrp[b].push_back(a);
        }
        kosarajuFindComponents();
        makeComponentGrpAsCondensedTree(); // condense the strongly connected nodes into a tree like structure 
        int ans=treeCal(); // then used DP on tree to calculate the max sum 
        cout<<ans;
    }
};

void solve() {
    // Your solution code here
   Solution s;
   s.solve();
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