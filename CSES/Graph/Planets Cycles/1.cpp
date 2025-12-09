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
   vector<int> next(n+1);
   vector<int> ans(n+1, -1);
   for(auto &i:next) cin>>i;
   const int UNVISITED=-1,VISITED=1,TRAVERSING=0;
   vector<int> nodeState(n+1, UNVISITED);
    for(int i=1;i<=n;i++){
        if(nodeState[i]==VISITED) continue;
        int at=i;
        vector<int> mem;
        while(nodeState[at]==UNVISITED){
            mem.emplace_back(at);
            nodeState[at]=TRAVERSING;
            at=next[at];
        }
        reverse(mem.begin(), mem.end()); // converting to stack
        // now 'at' is either at TRAVERSING or VISITED node;
        if(nodeState[at]==TRAVERSING){
            int count=0;
            while(mem[count++]!=at && count < mem.size());
            int i=0;
            // give count to cycle elements
            ans[at]=count;
            nodeState[at]=VISITED;
            while(mem[i]!=at){
                ans[mem[i]]=count;
                nodeState[mem[i]]=VISITED;
                i++;
            }
            // give count to remaining elements
            while(i<mem.size()){
                ans[mem[i]]=++count;
                nodeState[mem[i]]=VISITED;
                i++;
            }

        }else{
            //VISITED
            int count=ans[at];
            for(auto i: mem){
                ans[i]=++count;
                nodeState[i]=VISITED;
            }
        }
    }
    // cout<<"hello";
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
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