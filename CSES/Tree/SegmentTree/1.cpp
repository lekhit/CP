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

class SegTreeNode{
    public:
    int i;
};

template<typename Node>
class SegmentTree{
    // building 1 based
    public:
    vector<int> tree;
    vector<int> lazy;
    vector<int> deltaArray;
    vector<int> setValue;
    vector<int> setFlag;
    vector<int> arr;
    int N;
    function<int(int,int)> combine;
    SegmentTree(vector<int> inputArr, function<int(int,int)> combineFunction){
        N=2*inputArr.size();
        tree.resize(2*inputArr.size());
        lazy.assign(2*inputArr.size(), 0);
        setValue.assign(N,0);
        setFlag.assign(N,0);
        deltaArray.assign(N,0);
        arr=inputArr;
        combine=combineFunction;
    }
    int L(int index){
        return index*2;
    }
    int R(int index){
        return index*2+1;
    }
    void build(int l, int r, int index){
        if(l==r){
            tree[index]=arr[l];
            return;
        }
        int mid=(l+r)/2;
        build(l, mid, L(index));
        build(mid+1, r, R(index));
        tree[index]=combine(tree[L(index)], tree[R(index)]);
    }
    int query(int l, int r){
        return query(l, r, 1, arr.size()-1, 1);
    }
    int query(int queryLeft, int queryRight, int treeLeft, int treeRight, int treeIndex){
        if(queryLeft == treeLeft && queryRight == treeRight){
            return tree[treeIndex];
        }
        int mid=(treeLeft+treeRight)/2;
        int result=0;
        if(queryLeft <= mid){
            result+=query(queryLeft, min(mid, queryRight),treeLeft, mid, L(treeIndex));
        }
        if(queryRight >= mid+1){
            result+=query(max(mid+1, queryLeft), queryRight, mid+1, treeRight, R(treeIndex));
        }
        return result;
    }
    void push(int index){
        if(L(index)>0 && L(index)<N){
            deltaArray[L(index)]=deltaArray[index];
            setVal[L(index)]=setVal[index];
        }
        if(R(index)>0 && R(index)<N){
            deltaArray(R(index))=deltaArray[index];
            setVal[R(index)]=setVal[index];
        }
        // how will the set val be impacted after propogation down
        setVal[index]=0;
        setFlag[index]=0;
        deltaArray[index]=0;
        
    }
    void setVal(int point, int value){

    }
    void setVal(int l, int r, int value){

    }
    void update(int point, int delta){}
    void update(int l, int r, int delta){

    }
    void update(int queryLeft, int queryRight, int treeLeft, int treeRight, int treeIndex, int delta){
        if(queryLeft==treeLeft && queryRight==treeRight){
            deltaArray[treeIndex]=delta;
        }
    }
};

void solve() {
    // Your solution code here
   
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