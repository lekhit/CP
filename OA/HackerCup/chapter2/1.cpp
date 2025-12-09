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

vector<int> solve() {
    // Your solution code here
   int n,a,b;cin>>n>>a>>b;
   vector<int> ans;
   for(int i=0;i<(n<<1)-1;i++){
    ans.push_back(1);
   }
   ans.push_back(b);
   return ans;
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
       auto ans= solve();
      printf("Case #%d: ",i);
      for(auto i: ans) printf("%i ",i);
      printf("\n");
    }

    
    return 0;
}