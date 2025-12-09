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

int solve() {
    // Your solution code here
   int n,m;cin>>n>>m;
   vector<vector<int>> grp(n+1);
   vector<int> colours(n+1,-1);
   for(int i=0;i<m;i++){
    int a,b; cin>>a>>b;
    grp[a].push_back(b);
    grp[b].push_back(a);
   }
   // not considering the fact that the grp can be disconnected

   for(int i=1;i<n;i++){
    if(colours[i]!=-1) continue;
   queue<int> q;
   q.push(i);
   int toggle=0;
   colours[i]=toggle;
   while (!q.empty())   
   {
    auto node= q.front();
    q.pop();
    toggle=(colours[node]+1)%2 ;
    for(auto i: grp[node]){
        if(colours[i]==-1){
            colours[i]=toggle;
            q.push(i);
        }else{
            if(colours[i]==colours[node]) return -1; // impossible
        }
    }
   }
}
   for(int i=1;i<=n;i++){
    cout<<(colours[i]+1)<<" ";
   }
   return 0;
   
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
        int i=solve();
        if(i==-1) cout<<"IMPOSSIBLE";
    }

    
    return 0;
}