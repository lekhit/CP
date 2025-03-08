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

// Variadic macro for taking multiple inputs of same type
#define takes(type, ...) type __VA_ARGS__; ([&](auto&&... args) { ((cin >> args), ...); }(__VA_ARGS__))

void solve() {
    take(int, n);
    vpii customersEntryExit(n);
    if(n==0) {cout<<0; return;}
    for(auto &[i,j]:customersEntryExit){cin>>j>>i;}
    sort(all(customersEntryExit));
    int count=1;
    auto [exitLast,entryLast] = customersEntryExit[0];
    for(auto [exit, entry]:customersEntryExit){
        if(exitLast > entry) {
            count++;
        }else{

        }
        entryLast=entry; exitLast=exit;
    }
}

int main() {
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