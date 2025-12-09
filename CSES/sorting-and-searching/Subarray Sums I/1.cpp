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
    int n,x;cin>>n>>x;vector<int> v(n);for(auto &i:v)cin>>i;
    int count=0;
    int tempSum=0;
   for(int i=0, j=0;i<n;){
    while(j<n && tempSum < x){ // keep moving j till value increases 
        tempSum+=v[j++];
    }
    if(tempSum == x){ // the value can be greater than x or equal to x
        count++;
        if(j<n)
            tempSum+=v[j++];// make sure the value is greater than x if j exists
    }
    if(tempSum <= x) break; // if despite above logic the value is still less than or equal then no further answer is possible

    while (i<n && tempSum > x)
    {
        tempSum-=v[i++];
    }
   }
   cout<<count;
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