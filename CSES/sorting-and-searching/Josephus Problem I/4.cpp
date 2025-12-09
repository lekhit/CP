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

void removeElement(vector<int> &v, int idx){
    for(int i=idx;i<v.size()-1;i++){
        v[idx]=v[idx+1];
    }
}

void solve() {
    int n,K,count;cin>>n>>K;
    int root=sqrt(n);
    count=0;
    if((root*root)<n){
        root++;
    }
    vector<vector<pii>> grid;
    vi elementCount;
    vpii a;
    for(int i=1;i<=n;i++){
        if(i%root == 0){
            a.push_back(mp(i,1));
            grid.push_back(a);
            elementCount.push_back(a.size());
            a.clear();
        }else{
            a.push_back({i,1});
        }
    }
    if(a.size()>0){grid.push_back(a);
            elementCount.push_back(a.size());}
    vi ans;
    int idx=0;
    int row=0;
    int skips=K;
    while(ans.size()< n ){
        skips=K%count;
        while(skips>0){
            if(idx <= elementCount[row] && idx!=0){
                while(idx < elementCount[row] && skips>0){
                    idx++; 
                    skips--;
                }
                if(idx >= elementCount[row]){
                    idx=0;row=(row+1)%root;
                }else{
                    // k is 0
                    break;
                }
            }

            idx=0;// start of some row
            if(elementCount[row] <= skips){
                // skip row
                skips-=elementCount[row];
                row=(row+1)%elementCount.size();
            }else{
                //element exists here
                while(skips>0){
                    if(grid[row][idx].second==0) continue;
                    idx++;skips--;
                }
            }
        }
            while(elementCount[row]==0) row=(row+1)%elementCount.size();
            for(int i=idx;i<elementCount[row] && grid[row][i].second==0 ;i++){   
                idx++;
            }
        ans.push_back(grid[row][idx].first);
       auto removeitr=grid[row].begin()+idx;
       grid[row][idx]={grid[row][idx].first,0};
       if(removeitr!=grid[row].end())
            grid[row].erase(grid[row].begin()+idx);
    elementCount[row]--;
    count--;
    }
    for(auto i: ans){
        cout<<i<<" ";
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