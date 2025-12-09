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

int solve() {
    // Your solution code here
   int n;cin>>n;
vector<int> v(n);for(auto &i:v)cin>>i;
int ans=v[0];
for(int i=1;i<n;i++){
  ans=max(ans, min(abs(v[i]-v[i-1]), v[i]));
}
reverse(v.begin(), v.end());
int ans2=v[0];
for(int i=1;i<n;i++){
  ans2=max(ans2, min(abs(v[i]-v[i-1]), v[i]));
}
return min(ans, ans2);
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
cin>>t;
   for(int i=1;i<=t;i++){
       int ans= solve();
      printf("Case #%d: %d\n",i, ans);
    }

    
    return 0;
}