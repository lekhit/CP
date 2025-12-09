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

class DSU{
    public:
    vector<int> parent, size;
    int componentNumber, largestComponent;
    DSU(int n){
        componentNumber=n;
        largestComponent=1;
        size.assign(n, 1);
        parent.assign(n, 1);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int get(int a){return parent[a]==a?a:(parent[a]=get(parent[a]));}
    bool unite(int a, int b){
        int pA=get(a);
        int pB=get(b);
        if(pA==pB) return false;
        if(size[pA]<size[pB]) swap(pA, pB);

        size[pA]+=size[pB];
        parent[pB]=pA;
        componentNumber--;
        largestComponent=max(largestComponent, size[pA]);
        return true;
    }
    int getNumberOfComponent(){
        return componentNumber;
    }
    int getLargestComponentSize(){
        return largestComponent;
    }
};

void solve() {
    // Your solution code here
    int n,m;cin>>n>>m;
    DSU d(n);
    while(m--){
        int a,b;cin>>a>>b;
        --a;--b; // zero based index;
        d.unite(a,b);
        cout<<d.getNumberOfComponent()<<" "<<d.getLargestComponentSize()<<"\n";
    }
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