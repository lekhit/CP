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
vector<int> q,c;
void solve() {
    // Your solution code here
    int n,k;cin>>n>>k;

    auto isPossible=[](int mid, int n, int k){
        int ans=0, deals=0;
   for(int i=mid; i>=0;i--){
    if(q[i]<=n){
      int t=(n/q[i]);
      ans+=c[i]*t;
      n%=q[i];
      deals+=t;
    }
   }
   return deals<=k;
    };

   int lo=0, hi=(log(n)/log(3))+1;
   while (lo<=hi)
   {
    int mid=lo+(hi-lo)/2;
    if(isPossible(mid, n, k)){
        hi=mid-1;
    }else{
        lo=mid+1;
    }
   }
    int ans=0, deals=0;
   for(int i=lo; i>=0;i--){
    if(q[i]<=n){
      int t=(n/q[i]);
      ans+=c[i]*t;
      n%=q[i];
      deals+=t;
    }
   }
   if(deals>k)cout<<(-1);
   else cout<<ans;
}

int32_t main() {
    fastio;
    
    // File I/O (local only)
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }
    int n=(1e9+7);
    for(int i=1,j=0;i<(n+1);i*=3,j++){
    q.push_back(i);
    c.push_back((i*3+(i*j/3)));
   }
//    reverse(c.begin(), c.end());
//    reverse(q.begin(), q.end());
int t=1;
cin>>t;
    while(t--) {
        solve(); 
cout<<"\n";
    }

    
    return 0;
}