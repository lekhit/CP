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
   int n,m, c=0;cin>>n;
   vector<int> boys(n),girls;for(auto &i: boys)cin>>i;
   cin>>m;
   girls.resize(m);for(auto &i: girls)cin>>i;
   sort(boys.begin(), boys.end());
   sort(girls.begin(), girls.end());
   for(int i=0, j=0;i<n && j<m;){
    if(abs(boys[i]-girls[j]) < 2) {c++;i++;j++;}
    else{
      if(boys[i]<girls[j]){
        i++;
      }else{
        j++;
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