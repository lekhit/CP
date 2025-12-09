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
   int n;cin>>n;
   vector<int> v(n);for(auto &i: v)cin>>i;
   set<int> ss;
   vector<pair<int,int>> ans;
   for(auto i: v){
    auto it=ss.lower_bound(i);
    int tempMin=i;
      for(auto j=ss.begin(); j!=it; j=ss.erase(j)){
        ans.push_back({*j, i});
        tempMin=min(tempMin, *j);
      }
      ss.insert(tempMin);
   }
   if(ss.size()==1){
    cout<<"YES"<<"\n";
    for(auto [a,b]: ans){
      cout<<a<<" "<<b<<"\n";
      
    }
   }else {
    cout<<"NO";
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
cin>>t;
    while(t--) {
        solve(); 
cout<<"\n";
    }

    
    return 0;
}