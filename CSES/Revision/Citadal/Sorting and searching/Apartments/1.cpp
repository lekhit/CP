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
   int n,m,k;cin>>n>>m>>k;
   vector<int> v(n);for(auto &i: v)cin>>i;
   sort(v.begin(), v.end());
   multiset<int> ss;
   for(int i=0;i<m;i++){
    int a;cin>>a;
    ss.insert(a);
   }
   int c=0;
   for(auto i: v){
    auto it=ss.lower_bound(i-k);
    if(it!=ss.end()){
      if((*it)<=(i+k)){
        c++;
        ss.erase(it);
      }
    }
   }
   cout<<c;
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