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
   int MOD=1e9+7;
   vector<int> pre(n), cur(n);
   cur[0]=1;
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        char ch;cin>>ch;
        if(ch=='*') {
            cur[j]=0;
        }else{
            (cur[j]+=pre[j])%=MOD;
            if(j-1 >= 0)
                (cur[j]+=cur[j-1])%=MOD;
        }
    }
    pre=cur;
    cur.assign(n, 0);
   }
   cout<<pre[n-1];
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