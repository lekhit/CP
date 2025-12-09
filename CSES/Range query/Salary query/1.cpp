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

class BitTree{
    public:
    vector<int> tree;
    // using 1 based indexing
    int N;
    BitTree(vector<int> arr){
        N=arr.size();
        tree.resize(N+1);
        for(int i=1;i<=N;i++){
            updateValue(i, arr[i-1]);
        }
    }
    int getSum(int index){
        int sum=0;
        for(;index>0;index-=(index&(-index))){
            sum+=tree[index];
        }
        return sum;
    }
    void updateValue(int index, int delta){
        for(;index<=N;index+=(index&(-index))){
            tree[index]+=delta;
        }
    }
        
    
    int getSumZeroBased(int index){
        return getSum(index+1);
    }
    void updateValueZeroBased(int index, int delta){
       updateValue(index+1, delta);
    }
};

void solve() {
    // Your solution code here
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);for(auto &i:arr)cin>>i;
    
    while(q--){
        char ch;cin>>ch;
        if(ch=='?'){

        }else{

        }
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