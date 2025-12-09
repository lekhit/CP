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
   int n;cin>>n;vector<pair<int,int>> v(n), v2;
   int c=0;
   vector<int>ans;
   for(auto &i: v){cin>>i.first;i.second=c++;}
   auto M=*max_element(v.begin(), v.end());
   for(int i=0;i<n;i++){
    if(i!=M.second){
      v2.push_back(v[i]);
    }}
    auto sM=*max_element(v2.begin(), v2.end());
    
    for(auto [a,b]: v){
      if(b==M.second){
        ans.push_back(a-sM.first);
      }else{
        ans.push_back(a-M.first);
      }
    }

   for(auto i: ans){
    cout<<i<<" ";
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