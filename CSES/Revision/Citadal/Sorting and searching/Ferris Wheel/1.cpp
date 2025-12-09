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
   int n,k;cin>>n>>k;
   vector<int> v(n);for(auto &i: v)cin>>i;
   sort(v.begin(), v.end());
   int i=0,j=n-1, c=0;
   while(i<=j){
    c++;
    if(i==j){
       break;
    }
    if(v[i]+v[j]<=k){
      i++;
    }
    j--;
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