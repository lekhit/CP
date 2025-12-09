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

void solve() {
    // Your solution code here
   int n,m;cin>>n>>m;
   vector<vector<int>> grp(n+1);
   vector<int> indegree(n+1,0);
   for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    indegree[b]++;
    grp[a].push_back(b);
   }

   // traversing grp
   // starting with nodes with zero indegree
   stack<int> st;
   // adding nodes with zero degree
   for(int i=1;i<=n;i++) {
    if(indegree[i]==0) st.push(i);
   }
   vector<int> ans; // there are no cycles so no need for visited array
   while(!st.empty()){
    auto node=st.top();st.pop();
    ans.push_back(node);
    for(auto i: grp[node]){
        indegree[i]--;
        if(indegree[i]==0) st.push(i);
    }
   }
   for(int i=1;i<=n;i++) if(indegree[i]>0){
    cout<<"IMPOSSIBLE";return;
   }
   for(auto i: ans) cout<<i<<" ";
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