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

bool isOk(int x, vector<int> &v, deque<int> left){
    for(int i: v){
        if(x>0){
            // min section
            if(min(left.back(), i)!=i)
                return false;
            x--;
            left.pop_back();
        }else{
            if(max(left.front(), i)!=i){
                return false;
            }
            left.pop_front();
        }
    }
    return true;
}

void solve() {
    // Your solution code here
   int n;cin>>n;
   vector<int> v(n);
   for(auto &i: v)cin>>i;
   deque<int> left;
   sort(v.begin(), v.end());
   set<int> st;
   st.insert(v.begin(), v.end());
   for(int i=1,j=0;i<=(2*n) && j<n;i++){
    if(!st.count(i)){
        left.push_back(i);
    }
   }

//    int hi=n, lo=0;
//    while(lo<=hi){
//         int mid=(hi-lo)/2+lo;
//         if(isOk(mid, v, left)){
//             hi=mid-1;
//         }else{
//             lo=mid+1;
//         }
//    }
   int c=0;
   for(int i=0;i<=n;i++){
    if(isOk(i,v,left)) c++;
   }
   cout<<c;
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