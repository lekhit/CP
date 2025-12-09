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
vector<int> prices(n), pages(n);
for(auto &i: prices)cin>>i;
for(auto &i: pages)cin>>i;
vector<int> pre(x+1, 0), cur(x+1,0);

for(int i=0;i<n;i++){
    for(int j=0;j<=x;j++){
        cur[j]=pre[j];
        if(j-prices[i] >= 0) // equal to is important because that shows the case where the we are only taking a single book
        cur[j]=max(cur[j], pre[j-prices[i]] + pages[i]);
    }
    pre=cur;
    cur.assign(x+1, 0);
}
cout<<pre[x];
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