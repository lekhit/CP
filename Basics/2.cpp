#include <bits/stdc++.h>
using namespace std;

// Auto-detection for local environment
#ifdef LOCAL
const bool LOCAL_ENV = false;
#else
const bool LOCAL_ENV = false;
#endif

#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(NULL); cout.tie(NULL)

int main() {
    fastio;
    
    // File I/O (local only)
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }

    int n;cin>>n;
    cout<<(n+1);
    
    return 0;
}