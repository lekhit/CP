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
   int n;cin>>n;
   multiset<pair<int,int>> ms;
   int c=0;
   vector<int> ans(n);
   int i=0;
   vector<tuple<int,int,int>> v(n);for(auto &[end, start, j]:v){cin>>start>>end;j=i++;}
   sort(v.begin(), v.end());
   for(auto [end,start,i]: v){
    auto it=ms.lower_bound({(-start+1), 0});
    if(it!=ms.end()){
      auto [ee, room]=(*it);
      ms.erase(it);
      ms.insert({(-end), room});
      ans[i]=room;
    }else{
      c+=1;
      ms.insert({(-end), c});
      ans[i]=c;
    }
   }
   cout<<c<<endl;
   for(auto i: ans)cout<<i<<" ";
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