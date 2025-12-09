#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

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
#define inputvec(v,n) for(int i=0;i<n;i++) {cin>>v[i]; v[i]*=(-1);}
#define makevec(v,n) vi v(n); inputvec(v,n)
#define take(type, name) type name; cin>>name
#define take(type, name, size) type name(size); cin>>name
#define int long long

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

int sol2(){
     int n;cin>>n;
    vi A(n);cin>>A;
    sort(all(A));
    if(n==1) return A[0]*2;
    int sum=0;for(auto i:A)sum+=i;
    sum-=A[n-1];
    if(sum < A[n-1]){ // if time take to read first n-1 books is less than time taken to read nth book then the first person will read all the books. while the second is reading the nth book. 
        sum=A[n-1]*2; // totalSum=(sumTillSecondLastElement+A[n-1]); and time to read books= totalSum - (sumTillSecondLastElement-A[n-1]) {time first person needed to wait}
    }else{
        sum+=A[n-1];
    }
    return sum;

}

void solve() {
    cout<<sol2();
}

int32_t main() {
    fastio;
    
    if(false) {
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