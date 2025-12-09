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
   int n;cin>>n;
   int sum=0;
   vector<int> coins(n);for(auto &i: coins){cin>>i;sum+=i;}
   vector<vector<int>> dp(n, vector<int> (sum+1, 0));
   dp[0][0]=1;
   dp[0][coins[0]]=1;
    for(int i=1;i<n;i++){
        int coin=coins[i];
        for(int j=0;j<=sum;j++){
            dp[i][j]=dp[i-1][j];
            if(j-coin >= 0 ){
                if(dp[i-1][j-coin]==1){
                    dp[i][j]=1;
                }
            }
        }
    }
    vector<int> ans;
    for(int i=1;i<=sum;i++){
        if(dp[n-1][i]==1) ans.push_back(i);
    }
    cout<<ans.size()<<"\n";
    for(auto i: ans) cout<<i<<" ";
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