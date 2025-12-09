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
   int n,m;cin>>n>>m;
   vector<int> v(n);for(auto &i: v)cin>>i;
   int lo=(*max_element(v.begin(), v.end())), hi=1e18+7;
   auto getCount=[&](int target){
    vector<vector<int>> s;
    vector<int> temp;
    int sum=0, c=1;
    for(int i: v){
      if(sum+i > target){
        c++;
        sum=0;
        s.push_back(temp);temp.clear();
      }
      sum+=i;
      temp.push_back(i);
    }
    return c;
   };
   while(lo<hi){
    int mid=lo+(hi-lo)/2;
    int count=getCount(mid);
    if(count > m){
      lo=mid+1;
    }else{
      hi=mid;
    }
   }
   cout<<lo;
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