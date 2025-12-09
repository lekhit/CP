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
   int MOD=1e9+7;
   vector<int> arr(n);for(auto &i: arr)cin>>i;
   vector<int> pre(m+1, 0), cur(m+1,0);
   // base case
   if(arr[0]==0) {cur.assign(m+1, 1);cur[0]=0;}
   else cur[arr[0]]=1;
   // iteration starts
   for(int index=1;index<n;index++){
        int i=arr[index];
        pre=cur;
        cur.assign(m+1, 0);
        if(i==0){
            for(int k=1;k<=m;k++){
                for(int j: {-1, 0, 1}){
                    if(j+k>0 && j+k <= m)
                    (cur[k]+=pre[j+k])%=MOD;
                }
            }
        }else{
            for(int j: {-1, 0, 1}){
                if(i+j>0 && i+j <= m){
                    (cur[i]+=pre[i+j])%=MOD;
                }
            }
        }

   }
   int ans=0;
   for(auto i: cur) (ans+=i)%=MOD;
   cout<<ans;
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