#include <bits/stdc++.h>
using namespace std;

// Auto-detection for local environment
#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define int long long
#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(NULL); cout.tie(NULL)

void solve() {
    // Your solution code here
   int n,k,l,r;cin>>n>>k>>l>>r;
   vector<int> v(n);for(auto &i: v)cin>>i;
   map<int,int> sw, lw;
   int count=0;
   for(int p=0,q=0,r2=0;p+l-1<n; p++){
    while(q<n && sw.size() < k){
      // q will be at place where the size will exact k
    //   if(sw.count(v[q])==0){
    //     if(sw.size()+1 == k) break;
    //   }
      sw[v[q]]++;
      q++;
    }
    while(r2<n && (lw.size()) <= k){
        if(lw.count(v[r2])==0){
            if(lw.size()+1 > k) break;
        }
        lw[v[r2]]++;
        r2++;
    }
    count+=(min(p+r-1, r2-1)-max(q, p+l-1) + 1);
    if(--lw[v[p]]==0) lw.erase(v[p]);
    if(--sw[v[p]]==0) sw.erase(v[p]);
   }
   cout<<count<<endl;
}

int32_t main() {
    fastio;
    
    // File I/O (local only)
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }

int t=1;
cin>>t;
    while(t--) {
        solve();
    }

    
    return 0;
}