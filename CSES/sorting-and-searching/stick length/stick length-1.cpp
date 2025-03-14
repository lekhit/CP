#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define int int64_t
#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); cout.tie(nullptr)

// Type definitions
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

// Utility macros
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define inputvec(v,n) for(int i=0;i<n;i++) cin>>v[i]
#define makevec(v,n) vi v(n); inputvec(v,n)
#define take(type, name) type name; cin>>name
#define take(type, name, size) type name(size); cin>>name
// Generic input function for pairs
template<typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
    in >> p.first >> p.second;
    return in;
}

// Generic input function for vectors
template<typename T>
istream& operator>>(istream& in, vector<T>& arr) {
    for (auto& x : arr) in >> x;
    return in;
}

// Variadic macro for taking multiple inputs of same type
#define TS(type, ...) type __VA_ARGS__; ([&](auto&&... args) { ((cin >> args), ...); }(__VA_ARGS__))

void solve() {
  TS(int, n);
  take(vi, arr, n);
  sort(all(arr));
  int median = arr[n/2];
  int sum=0;
  for(auto i:arr){
    sum+=abs(i-median);
  }
  cout<<sum;

}

int32_t main() {
    fastio;
    
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    
    return 0;
}