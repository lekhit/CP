#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); cout.tie(nullptr)

void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    int count=0;
    vector<int> applicants(n),appartments(m);
    multiset<int> avaliableAppartments;
    for(auto &i: applicants) {cin>>i; }
    for(auto &i:appartments) {cin>>i;avaliableAppartments.insert(i);}
    sort(applicants.begin(),applicants.end());
    for(auto i: applicants){
        auto it = avaliableAppartments.lower_bound(i-k);
        if(it != avaliableAppartments.end()){
            int app = *(it);
            if(app <= i+k){
                avaliableAppartments.erase(it);
                count++;
            }
        }
    }
    cout<<count;

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