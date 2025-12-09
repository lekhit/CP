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
    // case where min has some while and all are negative I need to return the max sum among them
   int n,a,b;cin>>n>>a>>b;
   vector<int> v(n);for(auto &i:v)cin>>i;
   int sum=v[0];
   for(int i=1;i<n;i++){
    if(sum<0){
        sum=0;
    }
    sum+=v[i];
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