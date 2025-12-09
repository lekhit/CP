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

int MOD=1e9+7;
bool canJump(int i1, int i2, int j1, int j2, int w){
    int ans=sqrt(pow(i1-j1, 2) + pow(i2-j2, 2));
    return ans <= w;
}
int solve2(int n, int m, int w, vector<string> s){
    char VALID='X';
    reverse(s.begin(),s.end());
    vector<vector<int>> grid(n+1,vector<int>(m+1,0));
    vector<vector<int>> jumpGrid(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<m;i++){
       if(s[0][i]==VALID) grid[0][i]=1;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j] == VALID){
                // same level jumps
                for(int J=0;J<m;J++){
                    if(s[i][J]==VALID && canJump(i,j,i,J,w)){
                        (jumpGrid[i][J]+=grid[i][j])%=MOD;
                    }
                }
                for(int J=0;J<m;J++){
                    if(i+1 < n && canJump(i,j,i+1,J,w) && s[i+1][J]==VALID){
                        (grid[i+1][J]+=(jumpGrid[i][j]+grid[i][j])%MOD)%=MOD;
                    }
                }
            }
        }
    }
    int ans=0;
    for(int j=0;j<m;j++){
        (ans+=grid[n-1][j])%=MOD;
    }
    return ans;
}
void solve() {
    // Your solution code here
   int n,m,w;
   vector<string> s;
   cin>>n>>m>>w;
   for(int i=0;i<n;i++) cin>>s[i];
   
  
    solve2(n,m,w,s);
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