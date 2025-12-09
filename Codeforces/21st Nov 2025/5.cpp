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
   int n, q, localMax=1, tempSum=0;cin>>n>>q;
   map<int,int> mp;
   vector<int> v(n), m;for(auto &i: v){
    cin>>i;
    tempSum+=i;
    localMax=max(localMax, i);
    m.push_back(localMax);
    mp[-localMax]=tempSum;
   }
   while(q--){
    int a;cin>>a;
    auto it=mp.lower_bound(-a);
    if(it==mp.end()) cout<<0;
    else cout<<((*it).second);
    cout<<" ";
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