#include <bits/stdc++.h>
using namespace std;

// Auto-detection for local environment
#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define int long long
#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(NULL); cout.tie(NULL)


int timer;
    // 1 based bitTREE so all index are supposed to be shifted by 1
  void add(int index, int delta, vector<int> &BIT){
    for(int i=index; i<(int)BIT.size(); i+=(i&(-i))){
        BIT[i]+=delta;
    }
  }

  int query(int index, vector<int> &BIT){
    int result=0;
    for(int i=index; i>0; i-=(i&(-i))){
        result+=BIT[i];
    }
    return result;
  }

  void build(vector<int> &sourceArray, vector<int> &BIT){
    BIT.resize(sourceArray.size()+1);
    for(int i=1;i<sourceArray.size();i++){
        add(i, sourceArray[i], BIT);
    }
}
vector<int> tin, tout;
void dfs(int n, int p, vector<vector<int>> &grp, vector<int> &Etree, vector<int> &nodeVal){
    tin[n]=++timer;
    Etree[tin[n]]=nodeVal[n];
    for(auto i: grp[n]){
        if(i==p) continue;
        dfs(i, n, grp, Etree, nodeVal);
    }
    tout[n]=++timer;
    Etree[tout[n]]=-nodeVal[n];
}

void solve() {
    // Your solution code here
    timer=0;
    int n;cin>>n;
    int q;cin>>q; 
    vector<vector<int>> grp(n+1, vector<int>());
    tin.resize(n+1);
    tout.resize(n+1);
    vector<int> Etree(2*(n+1));
    vector<int> nodeVal(n+1);
    for(int i=1;i<=n;i++) cin>>nodeVal[i];
    for(int i=0;i<(n-1); i++){
        int a,b;cin>>a>>b;
        grp[a].push_back(b);
        grp[b].push_back(a);
    }
    vector<int> BIT;
    dfs(1, 0, grp, Etree, nodeVal);
    build(Etree, BIT);
    while(q--){
        int a;cin>>a;
        if(a==1){
            int s,x;cin>>s>>x;
            int delta=x-nodeVal[s];
            nodeVal[s]=x;
            add(tin[s], delta, BIT);
            add(tout[s], -delta, BIT);
        }else{
            int s;cin>>s;
            int ans=query(tin[s], BIT);
            cout<<ans<<"\n";
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
// cin>>t;
    while(t--) {
        solve(); 
cout<<"\n";
    }

    
    return 0;
}