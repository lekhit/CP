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

void solve() {
    // Your solution code here
   int n;cin>>n; 
   const int unvisited=-1,visited=1,traversing=0;
   vector<int> nxt(n+1);
   for(int i=1;i<=n;i++)cin>>nxt[i];

    vector<int> status(n+1, unvisited), dist(n+1, 0);
   for(int start=1;start<=n;start++){
    if(status[start]==visited) continue;
    int at=start;
    status[at]=traversing;
    vector<int> mem;mem.push_back(at);
    {
        // traverse till we find a visited node or a traversing (cycle)
        // OR we will not see any of that and the chain is straight ( though according to the format of question there will always be a cycle)
        while(status[nxt[at]]==unvisited){
            cerr<<at<<" "<<endl;
            at=nxt[at];
            status[at]=traversing;
            mem.emplace_back(at);
        }
        reverse(mem.begin(), mem.end()); // reversing the memory to ensure we follow the last node first; this helps in keeping count
    }
    // the next node to at is visited or traversing
    if(status[nxt[at]]==traversing){
        // found a cycle
        int cycleEntryPoint=nxt[at];
        int cycleSize=0;
        for(int i=0;i<=mem.size();i++){
            cycleSize++; // calculating the size of the cycle
            if(mem[i]==cycleEntryPoint) break; // since nxt[at] is the cycleEntryPoint; so we will keep going till that point.
        }

        // give each element its size
        int dis=cycleSize, passedCycleEntryPoint=false;
        for(int i: mem){
            if(passedCycleEntryPoint) dis++; //  so effectively we are in tree for here.
            dist[i]=dis;
            status[i]=visited;
            if(i==cycleEntryPoint) passedCycleEntryPoint=true; //this means the point from which the chain enterned into cycle;
        }
    }
    else{
        // previously visited node is reached so we back track to tree and keep adding the distance
        int disTillVisitedNode=dist[nxt[at]];
        for(auto i:mem){
            dist[i]=++disTillVisitedNode;
            status[i]=visited;
        }
    }
    
   }
   for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
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