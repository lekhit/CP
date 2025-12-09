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
   int n;cin>>n;
   vector<int>v(n);for(auto &i:v)cin>>i;
   sort(v.begin(), v.end());
   int sum=accumulate(v.begin(), v.end(), 0L);
   if(sum-v[n-1] < v[n-1]){
    sum=((v[n-1])<<1);
   }
   cout<<sum;
}

int sol2(){
     int n;cin>>n;
    vector<int> A(n);
    for(auto &i:A)cin>>i;
    sort(A.begin(), A.end());
    int sum=0;for(auto i:A)sum+=i;
    sum-=A[n-1];
    if(sum < A[n-1]){
        sum=A[n-1]*2;
    }else{
        sum+=A[n-1];
    }
    cout<<sum;
    return sum;
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
//cin>>t;
    while(t--) {
        solve();
    }

    
    return 0;
}