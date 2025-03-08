#include <bits/stdc++.h>
using namespace std;
#define LOCAL

// For local development (auto-detected)
#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(NULL); cout.tie(NULL)

void solve(){
    
}

int main() {
    fastio;
    
    // Automatic file redirection (local only)
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }

    // Your code here
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    cout << "Sorted array: ";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}