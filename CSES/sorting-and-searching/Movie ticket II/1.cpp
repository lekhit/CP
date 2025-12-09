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

class Compare{
    public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.first>b.first;
    }
};


void solve() {
    // Your solution code here
   int n,k;cin>>n>>k;
   vector<pair<int,int>> v(n);
   for(auto &[first,second]:v)cin>>second>>first;
   //sort based on start time of movie is not required.
   sort(v.begin(), v.end());
   // custom comparator is required because by default it is max heap
   priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;//min heap by movie end time; ie movie which ended first will be on top
   int ans=0;
   for(auto [end, start]: v){
    while(!pq.empty() && pq.top().first <= start){
        // if heap is not empty check if we can remove the movie.
        //  pq.top().first --> first end time of the movie; start --> start time of new movie
        pq.pop();
    }
    if(pq.size() < k){
        pq.emplace(end, start);
        ans++;
    }
   }
   cout<<ans;
}

int main() {
    fastio;
    
    // File I/O (local only)
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }

int t=1;
//cin>>t;
    while(t--) {
        solve();
    }

    
    return 0;
}