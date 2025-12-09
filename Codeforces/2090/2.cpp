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
void print(vvi arr){
    return;
    for(auto i:arr){for(auto j:i){cout<<j<<" ";}cout<<endl;}
}
void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m)), tc(n,vector<int>(m,0)),tr(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char a;cin>>a;
            arr[i][j]=(a=='1');
        }
    }
    print(arr);
    for(int j=0;j<m;j++){
        if(arr[0][j]==1) tc[0][j]=1;
        for(int i=1;i<n;i++){
            if(arr[i-1][j]==1 && arr[i][j]==1) tc[i][j]=1;
            else break;
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i][0]==1) tr[i][0]=1;
        for(int j=1;j<m;j++){
            if(arr[i][j-1]==1 && arr[i][j]==1) tr[i][j]=1;
            else break;
        }
    }
    print(tc);
    print(tr);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                if(!(tc[i][j]==1 || tr[i][j]==1)){cout<<"NO\n";return;}
            }
        }
    }
    cout<<"YES\n";
    
}

int main() {
    fastio;
    
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    
    return 0;
}