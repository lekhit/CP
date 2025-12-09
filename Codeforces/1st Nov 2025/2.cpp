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
   int n,m,x,y;
   cin>>n>>m>>x>>y;
   vector<pair<int,int>> v(m),h(n);
   for(int i=0;i<n;i++){
    int a;cin>>a;
    h[i]={a, i+1};
   }
   for(int i=0;i<m;i++){
    int a;cin>>a;
    v[i]={a,i+1};
   }
   int ans=0;
   auto it1= lower_bound(v.begin(), v.end(), make_pair(x, 0));
   if(it1==v.end()){
    ans+=v.size();
   }else{
    ans+=(*it1).second-1;
   }
   auto it2=lower_bound(h.begin(), h.end(), make_pair(y, 0));
   if(it2==h.end()){
    ans+=h.size();
   }else{
    ans+=(*it2).second-1;
   }

cout<<ans<<endl;
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
cin>>t;
    while(t--) {
        solve();
    }

    
    return 0;
}