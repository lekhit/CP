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

void solve() {
    // Your solution code here
   int n, s, m;cin>>n>>s>>m;
   vector<pair<int,int>> v(n);
   for(auto &[end, start]: v){
    cin>>start>>end;
   }
   v.push_back({0,0});
   v.push_back({m, m});
   sort(v.begin(), v.end());
   for(int i=1;i<v.size();i++){
    if(v[i].second-v[i-1].first >= s){
      cout<<"YES";return;
    }
   }
   cout<<"NO";
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
cout<<"\n";
    }

    
    return 0;
}