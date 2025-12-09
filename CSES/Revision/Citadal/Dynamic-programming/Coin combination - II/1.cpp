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
   int n,x;cin>>n>>x;
   vector<int> coins(n); for(auto &i: coins)cin>>i;
   sort(coins.begin(), coins.end());
   unique(coins.begin(), coins.end());
   vector<int> dp(x+1, 0);
   dp[0]=1;
   int MOD=1e9+7;
//    for(int i=1;i<=x;i++){
//     for(int coin: coins){
//         if(i-coin >= 0)
//         (dp[i]+=dp[i-coin])%=MOD;
//     }
//    }

   for(int coin: coins){
    for(int i=1;i<=x;i++){
        if(i-coin >=0)
        (dp[i]+=dp[i-coin])%=MOD;
    }
   }
   cout<<dp[x];
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