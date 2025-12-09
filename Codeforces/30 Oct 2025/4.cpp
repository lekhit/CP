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
#define int long long

    vector<int> prime;
void c_prime(){
  int n=100;
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
for(int i=2;i<=n;i++){
  if(is_prime[i]) prime.push_back(i);
}
}
void solve() {
    // Your solution code here
   
   int n;cin>>n;
   vector<int>v(n);for(auto &i: v)cin>>i;
   auto isPossible=[&](int n){
    for(auto i: v){
      if(i%n != 0) return true;
    }
    return false;
   };
   
   for(auto i: prime){
    if(isPossible(i)){
      cout<<i<<"\n"; return;
    }
   }
   cout<<"-1";
   cout<<"\n";
}

int32_t main() {
    fastio;
    c_prime();
    
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