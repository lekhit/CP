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
#define ALL(v) v.begin(), v.end()



class WNode{
    public:
    vector<int> arr;
    vector<int> leftIndex;
    vector<int> leftArr;
    vector<int> rightIndex;
    vector<int> rightArr;
    WNode *left, *right;
    int splitPoint;
    int high, low;
    int n;
    void moveArr(vector<int> &A){
        // fill(ALL(A), ++arr.begin());
        for(int i=1;i<n;i++){
            arr[i]=A[i-1];
        }
    }
    bool getSplitPoint(){
        low=(*min_element(++arr.begin(), arr.end())), high=(*max_element(ALL(arr)));
        splitPoint = low + (high-low)/2;    
        return high!=low;
    }
    void freqSplit(){
        for(int i=1;i<n;i++){
            rightIndex[i]=rightIndex[i-1] + arr[i]>splitPoint;
            leftIndex[i]=leftIndex[i-1] + arr[i]<=splitPoint;
            if(arr[i] > splitPoint){ // will go to right
                rightArr.push_back(arr[i]);
            }else{
                leftArr.push_back(arr[i]);
            }
        }
    }
    WNode(vector<int> &A){
        n=A.size()+1;
        arr.resize(n);
        leftIndex.resize(n);
        rightIndex.resize(n);
        left=right=NULL;
        moveArr(A); getSplitPoint();
        // A will be zero based indexed but arr must be 1 indexed
        if(getSplitPoint())
            freqSplit();
    }
    void print(){
        if(LOCAL_ENV){
        print("arr", arr);
        print("leftArr", leftArr);
        print("rightArr", rightArr);
    }

    }
    void print(string name, vector<int> &v){
        cout<<("name:")<<(name)<<endl;
        for(auto i:v) cout<<i<<" ";cout<<endl;
    }
};

class WTree{
    public:
    WNode *root;
    vector<int> input;
    int N;
    WTree(vector<int> &i){
        input=i;
        N=(int)input.size();
        root=build(i);
    }
    WNode* build(vector<int> &a){
        if(a.size()==0) return NULL;
        WNode *head=new WNode(a);
        head->print();
        if(head->high != head->low){
        head->left=build(head->leftArr);
        head->right=build(head->rightArr);}
        
        return head;
    }

    int countElementsLessThan(int k){
        
    }

};

void solve() {
    // Your solution code here
    int n;cin>>n;vector<int> v(n);
    for(auto &i: v)cin>>i;
    WTree wTree(v);
    
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