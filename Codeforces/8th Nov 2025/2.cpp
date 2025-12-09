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
    vector<pair<int,int>> t(4), v;
    for(auto &[a,b]: t){
      cin>>a;
      b=0;
    }
    if(t[0]==t[3]){
      cout<<0; return;
    }
    t[2].second=1;
    t[3].second=1;
    sort(t.begin(), t.end());
    if(t[0].second && t[1].second){
      cout<<4;
    }else if(t[0].second || t[1].second){
      cout<<2;
    }else {
      cout<<0;
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