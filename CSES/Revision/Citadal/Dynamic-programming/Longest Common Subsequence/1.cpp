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
   int n,m;
   cin>>n>>m;
   vector<int> a(n), b(m);
   for(auto &i:a)cin>>i;
   for(auto &i:b)cin>>i;
   vector<int> pre(m), cur(m);
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        int temp=1e9+7;
        if(a[i]==b[j]){
            temp=min(pre[j-1]+1, temp);
        }
        temp=min(temp, cur[j-1]);
        temp=min(temp, pre[j]);
        cur[j]=temp;
    }
   }
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