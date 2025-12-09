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

    string isPrime(long long n) {
    if (n <= 1) return "NO";
    if (n <= 3) return "YES";
    if (n % 2 == 0 || n % 3 == 0) return "NO";

    // Check divisors starting from 5, skipping even numbers
    // We go up to i*i <= n to avoid floating point issues with sqrt()
    for (long long i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return "NO";
    }
    return "YES";
}

void solve() {
    // Your solution code here
   int n,k;cin>>n>>k;
   vector<int> v={0,1, 11, 111, 1111,11111, 111111, 1111111};
   if(n==1){
    cout<<isPrime(v[k]); return;
   }
   if(k>1){
    cout<<"NO";
   }else{
    cout<<isPrime(n);
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