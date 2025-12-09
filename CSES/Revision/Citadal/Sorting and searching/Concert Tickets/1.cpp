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
   vector<int> v(n);for(auto &i: v){int a;cin>>a;i=(-a);}
   multiset<int> ms(v.begin(), v.end());
   for(int i=0;i<m;i++){
    int a;cin>>a;
    auto it=ms.lower_bound(-a);
    if(it!=ms.end()){
      ms.erase(it);
      cout<<((*it)*-1)<<'\n';
    }else{
      cout<<-1<<'\n';
    }
   }
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