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
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    multiset<int> xAxis, yAxis;

    for(auto &[a,b] : v) {
        cin >> a >> b;
        xAxis.insert(a);
        yAxis.insert(b);
    }

    // Edge case: With 1 monster, we move it to a 1x1 spot. Cost is 1.
    // This prevents the empty set crash below.
    if(n == 1) {
        cout << 1;
        return;
    }
    int w = *xAxis.rbegin() - *xAxis.begin() + 1;
        int h = *yAxis.rbegin() - *yAxis.begin() + 1;
        int area = w * h;

    int ans = area; // Initialize with a safe large number
    for(auto [a,b] : v) {
        // 1. Remove the current monster (simulate moving it)
        // Note: Use find() to remove only ONE instance of the coordinate
        xAxis.erase(xAxis.find(a));
        yAxis.erase(yAxis.find(b));

        // 2. Calculate Area of the remaining N-1 monsters
        // Formula: (Max - Min + 1)
        int w = *xAxis.rbegin() - *xAxis.begin() + 1;
        int h = *yAxis.rbegin() - *yAxis.begin() + 1;
        int area = w * h;

        if(area < n)
            area +=min(h, w);
          ans = min(ans, area);
        

        // 4. Add the monster back for the next iteration
        xAxis.insert(a);
        yAxis.insert(b);
    }
    
    cout << ans;
}

int32_t main() {
    fastio;
    
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }

    int t = 1;
    cin >> t;
    while(t--) {
        solve(); 
        cout << "\n";
    }
    
    return 0;
}