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
   int i=n-1, j=m-1;vector<int> ans;
   vector<int> a(n),b(m);
   for(auto &i: a)cin>>i;
   for(auto &i: b)cin>>i;
   vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int upperSide=0, directlyAbove=0, directlySide=0;
            if(a[i]==b[j]){
                if(i-1 >=0 && j-1 >=0)
                upperSide=max(dp[i-1][j-1]+1, dp[i][j]);
                else{
                    upperSide=1;
                }
            }
            if(i-1 >= 0)
            directlyAbove=dp[i-1][j];
            if(j-1 >=0)
            directlySide= dp[i][j-1];
            
            auto [value, choiceNumber] = max(make_pair(directlyAbove, 1), max(make_pair(directlySide, 2), make_pair(upperSide, 3)));
            if(choiceNumber==3) ans.push_back(a[i]);
            dp[i][j]=value;
        }
    }
    
    int count=dp[n-1][m-1];
    while(ans.size()<count){
        if(i-1 >=0 && dp[i-1][j]==dp[i][j] ){
            i-=1;
        }else if(j-1 >= 0 && dp[i][j-1]==dp[i][j]){
            j-=1;
        } else{
            ans.push_back(a[i]);
            i-=1;
            j-=1; 
        }
    }
    cout<<dp[n-1][m-1]<<"\n";
    reverse(ans.begin(), ans.end());
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