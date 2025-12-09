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
#define int long long
const int MOD=1e9+7;
class BitTree{
    public:
    vector<int> bitTree;
    int N;
    // one based index
    BitTree(int n){
        N=n+1;
        bitTree.resize(n+1);
    }
    void update(int index, int value){
        index++; //convert to one based index
        printf("\nupdate i: %lld value: %lld\n",index,value);
        for(int i=index;i<N;i+=(i&(-i))){
            
            bitTree[i]+=value;
        }
    }
    int query(int index){
        if(index<0) return 0;
        index++;int ans=0;
        for(int i=index;i>0;i-=(i&(-i))){
            ans+=bitTree[i];
        }
        printf("\nquery: index: %lld ans: %lld\n",index, ans);
        return ans;
    }
};

void solve() {
    // Your solution code here
   int n;cin>>n;
   vector<int> v(n),arr;for(auto &i: v){cin>>i;}
   arr=v;
   sort(arr.begin(),arr.end());
   for(auto i: v) cout<<i<<" ";cout<<endl;
   BitTree bitTree(n);
   vector<int> st;
   int count=0;
   for(auto i: v){
    // auto it= lower_bound(st.begin(), st.end(), i);
    // if(it==end(st)){
    //     st.push_back(i);
    // }else{
    //     *it=i;
    // }
    int result=bitTree.query(i-1) + 1;
    bitTree.update(i, result);
    (count+=result)%=MOD;
    printf("count: %lld result: %lld, i: %lld", count,result ,i);
   }
   cout<<count;
}

int32_t main() {
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