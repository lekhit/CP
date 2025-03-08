#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); cout.tie(nullptr)

// Add these new macros
#define vi vector<int>
#define vvi vector<vector<int>>
#define inputvec(v,n) for(int i=0;i<n;i++) {cin>>v[i]; v[i]*=(-1);}
#define makevec(v,n) vi v(n); inputvec(v,n)
#define take(name, type) type name; cin>>name

// Variadic macro for taking multiple inputs of same type
#define takes(type, ...) type __VA_ARGS__; ([&](auto&&... args) { ((cin >> args), ...); }(__VA_ARGS__))

void solve() {
    takes(int, n, m);
    makevec(tickets, n);
    makevec(prices, m);
    multiset<int> sellingTickets;
    for(auto i:tickets) sellingTickets.insert(i);
    for(auto price: prices){
        auto itr = sellingTickets.lower_bound(price);
        int value = *itr;
        if( itr != sellingTickets.end()){
            cout<<((*itr)*-1)<<endl;
            sellingTickets.erase(itr);
        }else{
            cout<<-1<<endl;
        }
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