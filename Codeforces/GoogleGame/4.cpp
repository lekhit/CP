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
   pair<int,int> prePos, preNeg, curPos, curNeg;
   for(int i: v){
    if(i>=0){
      pair<int,int> temp={preNeg.first+1, preNeg.second+i};
      curPos=max(prePos, temp);
    }else{
      pair<int,int> temp={prePos.first+1, prePos.second+i};
      curNeg=max(preNeg, temp);
    }
    preNeg=curNeg;
    prePos=curPos;
   }
   auto ans=max(preNeg, prePos);
   cout<<ans.second<<"\n";
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