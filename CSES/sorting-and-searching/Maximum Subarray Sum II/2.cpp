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

void solve() {
    // Your solution code here
   int n,a,b;cin>>n>>a>>b;
   vector<int> prefixArray(n+1, 0); // n+1 is used to ensure calculation of prefix array is smooth, also this helps to keep a and b in nautral order ie 1<=a<=b<=n
   for(int i=1;i<=n;i++){
    cin>>prefixArray[i];
    prefixArray[i]+=prefixArray[i-1];
   }
   multiset<int> maxKeeper; // multiset is required because when erase is used it is required to erase only one instance. 
   // in case of set all the instances are removed
   
   // create window
   for(int i=a; i<=b; i++){
    maxKeeper.insert(prefixArray[i]);
   } // this part is essential and could not be done in loop below, because it will require a lot of handling of delta values
   int sum=(*maxKeeper.rbegin()); // sum is not set to zero because the original values could be negative; this method ensures that the original value is set.
   for(int deltaIndex=1; deltaIndex+a <= n; ++deltaIndex ){ // keeping deltaIndex = 1 meaning it has moved by one window lenght
    int windowStartIndex=deltaIndex+a, windowEndIndex=deltaIndex+b; // window start and end
    
    // remove the previous element
    auto it = maxKeeper.find(prefixArray[windowStartIndex-1]);
    maxKeeper.erase(it);

    // add new element if it exists
    if(windowEndIndex < (int)prefixArray.size()){
        maxKeeper.insert(prefixArray[windowEndIndex]);
    }

    // calculate the max element in the window; by removing delta denoted by position at d
    sum=max(*maxKeeper.rbegin() - prefixArray[deltaIndex], sum); // the substraction is the most important part of logic
    // basically we are trying to get the max value in the said window, but the value returned by *maxKeeper.rbegin() will be prefix value
    // in order to get the actual value we are removing prefixArray[deltaIndex]; It was not required for the first sum (done out of the loop) because those are the actual subArray sum values.
   }
   cout<<sum;
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