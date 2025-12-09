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
const int N=2e5+10;
vector<int> upTree(N+1,0), downTree(2*N+1,0), nodeVal(N), tin(N), tout(N), timerTree(2*N+1), BitTree(2*N+1);
vector<vector<int>> Tree(N, vector<int>());
int timer;

// following 1 base indexing
int getSum(int index, vector<int> &BitTree){
    int result=0;
    for(int i=index; i>0; i-=(i&(-i))){
        result+=BitTree[i];
    }
    return result;
}
void add(int index, int delta, vector<int> &BitTree){
    for(int i=index;i<(int)BitTree.size();i+=(i&(-i))){
        BitTree[i]+=delta;
    }
}
void build(vector<int> &BitTree, vector<int> sourceArray){
    for(int i=1;i<(int)sourceArray.size();i++){
        add(i, sourceArray[i], BitTree);
    }
}

void dfs(int node, int parent){
    tin[node]=++timer;
    timerTree[tin[node]]=nodeVal[node];
    for(auto i: Tree[node]){
        if(i==parent) continue;
        dfs(i, node);
    }
    tout[node]=++timer;
    timerTree[tout[node]]=-nodeVal[node];
}

void solve() {
    // Your solution code here
    timer=0;
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>nodeVal[i];
    }

    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }
    dfs(1, 0);
    build(BitTree, timerTree);
    while(k--){
        int a;cin>>a;
        if(a==1){int s,x;cin>>s>>x;
            int delta=x-nodeVal[s];
            add(tin[s], delta, BitTree);
            add(tout[s], -delta, BitTree);
            nodeVal[s]=x;
        }
        else{
            int s;cin>>s;
            int sum=getSum(tin[s], BitTree);
            cout<<sum<<endl;
        }
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