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
int n,x,mod=10000005;cin>>n>>x;

vector<int> v(n), pre(mod+1,mod ), curr(x);
for(auto &i:v)cin>>i;
pre[0]=0;
for(int coin=0;coin<n;coin++)
for(auto i=1;i<=x;i++){
        if((i-v[coin])>=0)
        {pre[i]=min(pre[i-v[coin]]+1, pre[i]);
        // for(auto i: pre) cout<<i<<" ";cout<<endl; 
    }
}
if((pre[x]==mod))
cout<<"-1";
else cout<< pre[x];
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