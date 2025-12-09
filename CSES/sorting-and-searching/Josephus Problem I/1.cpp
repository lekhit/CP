#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = true;
#endif

// Type definitions
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

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

void solve() {
    int n,K;cin>>n>>K;
    int root=sqrt(n);
    if((root*root) < n) root++;
    vector<list<int>> lt;
    vector<int> elementCountInRow;
    list<int> l;
    for(int i=1;i<=n;i++){
        if(i%root != 0){
            l.push_back(i);
        }else{
            l.push_back(i);
            lt.push_back(l);
            elementCountInRow.push_back(l.size());
            l.clear();
        }
    }
    vector<int> ans;
    int row=0;
    auto it=lt[0].begin();
    while(ans.size()<n){
        int k=K;
        cout<<row;
        while(k>0){
            if(elementCountInRow[row] < k){
               k-=elementCountInRow[row]; row=(row+1)%root; 
            }
            else{
            while(k>0){
                    it++;
                    k--;
                }
                ans.push_back((*it));
                lt[row].erase(it); // automatically jumps to next node;
                elementCountInRow[row]--;
            }
        }

    }
    for(auto i:ans)cout<<i<<" ";

}

void solve2(){
    int n,K;cin>>n>>K;
    int root=sqrt(n);
    if((root*root) < n) root++;
    vector<list<int>> lt;
    vector<int> elementCountIn;
    list<int> l;
    for(int i=1;i<=n;i++){
        if(i%root != 0){
            l.push_back(i);
        }else{
            l.push_back(i);
            lt.push_back(l);
            elementCountIn.push_back(l.size());
            l.clear();
        }
    }
    if (!l.empty()) {  // Don't forget last partial row
        lt.push_back(l);
        elementCountIn.push_back(l.size());
    }
    
    vi ans;
    int row = 0;
    auto it = lt[0].begin();
    
    while(ans.size() < n) {
        int k = K;
        while(k > 0) {
            // Find next non-empty row if current is empty
            while(row < lt.size() && lt[row].empty()) {
                row++;
                if(row >= lt.size()) row = 0;
            }
            
            // Calculate steps in current row
            int stepsInRow = distance(it, lt[row].end());
            
            if(stepsInRow <= k) {
                // Move to next row
                k -= stepsInRow;
                row = (row + 1) % lt.size();
                // Find next non-empty row
                while(row < lt.size() && lt[row].empty()) {
                    row = (row + 1) % lt.size();
                }
                it = lt[row].begin();
            } else {
                // Move within current row
                advance(it, k);
                k = 0;
            }
        }
        
        ans.push_back(*it);
        auto next_it = next(it);
        lt[row].erase(it);
        elementCountIn[row]--;
        it = next_it;
        if(it == lt[row].end()) {
            row = (row + 1) % lt.size();
            while(row < lt.size() && lt[row].empty()) {
                row = (row + 1) % lt.size();
            }
            if(row < lt.size()) {
                it = lt[row].begin();
            }
        }
    }
    
    for(auto i : ans) cout << i << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);
    
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