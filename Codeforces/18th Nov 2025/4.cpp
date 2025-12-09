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
   int n,q;cin>>n>>q;
   vector<int> v(n);cin>>v[0];
   for(int i=1;i<n;i++){
    cin>>v[i];
    v[i]+=v[i-1];
   }
   while(q--){
    int a,b,k;cin>>a>>b>>k;
    a--; b--;
    int sum=0;
    if(a-1 >= 0) sum+=v[a-1];
    if(b < n) sum+=v[n-1]-v[b];
    sum+=(b-a+1)*k;
    if(sum&1) cout<<"YES";
    else cout<<"NO";
    cout<<'\n';
   }
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
cout<<"\n";
    }

    
    return 0;
}