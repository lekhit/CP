#include <bits/stdc++.h>
using namespace std;

// Auto-detection for local environment
#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define int long long
#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(NULL); cout.tie(NULL)

void solve() {
   int n,k,l,r;cin>>n>>k>>l>>r;
   vector<int> v(n);for(auto &i: v)cin>>i;
   
   // These maps will track the distinct elements for our two right pointers
   map<int,int> sw, lw; 
   int count=0;

   // sw[v[0]]=1; <-- FIX 1: Removed this line
   // lw[v[0]]=1; <-- FIX 1: Removed this line

   // p = left pointer (start of subarray)
   // q = right pointer for "at least k"
   // r2 = right pointer for "at most k"
   
   // FIX 2: Changed loop condition to p < n
   for(int p=0,q=0,r2=0; p < n; p++){
    
    // --- Find "at least k" bound ---
    // Expand q until the window [p, q-1] has *exactly* k distinct elements
    while(q < n && sw.size() < k){
      sw[v[q]]++;
      q++;
    }
    // After this loop, q points *one past* the end of the first valid window.
    // The first valid *inclusive* end index (c) is q-1.

    // --- Find "at most k" bound ---
    // Expand r2 until the window [p, r2-1] has *at most* k distinct elements
    while(r2 < n && (lw.size()) <= k){
        // Check if adding v[r2] would break the k-limit
        if(lw.count(v[r2]) == 0){ // If v[r2] is a new element...
            if(lw.size() + 1 > k) { // ...and we are already at k elements...
                break; // ...then stop. Do not add it.
            }
        }
        lw[v[r2]]++;
        r2++;
    }
    // After this loop, r2 points *one past* the end of the last valid window.
    // The last valid *inclusive* end index (c) is r2-1.

    // --- Calculate Contribution ---
    // We need to find the intersection of two ranges for the end index 'c':
    // 1. K-distinct rule: c must be in [q-1, r2-1]
    // 2. Length rule:     c must be in [p+l-1, p+r-1]
    
    int start_c = max(q - 1, p + l - 1);
    int end_c = min(r2 - 1, p + r - 1);

    // FIX 3: Use the correct ranges and ensure we don't add negative values
    count += max(0LL, end_c - start_c + 1);

    // --- Slide the window ---
    // Remove the p-th element as we slide the left bound
    if(--lw[v[p]]==0) lw.erase(v[p]);
    if(--sw[v[p]]==0) sw.erase(v[p]);
   }
   
   cout << count << endl;
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
    cin>>t;
    while(t--) {
        solve();
    }
    
    return 0;
}