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

string ans2(string firstInfo, string secondInfo) {
    secondInfo=secondInfo.substr(0, firstInfo.size()-1);
    sort(firstInfo.begin(), firstInfo.end());
    if (firstInfo > secondInfo) return firstInfo;
    while (next_permutation(firstInfo.begin(), firstInfo.end())) {
        if (firstInfo > secondInfo) return firstInfo;
    }
    return "-1";
}

string ans(string firstInfo, string secondInfo) {
    int n = firstInfo.size();
    multiset<char> info(firstInfo.begin(), firstInfo.end());
    string res = "";
    bool greater = false;

    for (int i = 0; i < n; ++i) {
        if (greater) {
            // Already greater, pick smallest remaining
            res += *info.begin();
            info.erase(info.begin());
            continue;
        }
        // Try to pick the smallest character > secondInfo[i]
        auto it = info.upper_bound(secondInfo[i]);
        if (it != info.end()) {
            // Found a strictly greater character
            res += *it;
            info.erase(it);
            // Fill the rest with smallest
            for (auto ch : info) res += ch;
            return res;
        }
        // Otherwise, try to match secondInfo[i]
        it = info.find(secondInfo[i]);
        if (it == info.end()) {
            // Can't match, so not possible
            return "-1";
        }
        res += *it;
        info.erase(it);
        // Continue to next position
    }
    // If we reach here, res == secondInfo, so not strictly greater
    return "-1";
}

string ans1(string firstInfo, string secondInfo){
    string ss="";
    for(int i=0;i<firstInfo.size() && i<secondInfo.size();i++) ss+=secondInfo[i];
    secondInfo=ss;
    multiset<char> info;
    for(auto i: firstInfo) info.insert(i);
    string ans="";
    for(auto i: secondInfo) {
        auto it=info.lower_bound(i);
        if(it==info.end()){
           break;
        }
        ans+=(*it);
        info.erase(it);
    }
    if(ans<secondInfo) return "-1";
    if(!info.empty()){for(auto i: info) ans.push_back(i);}
   
    
    return ans;
}


void solve() {
    // Your solution code here
    string a,b;cin>>a>>b;
    // cout<<a;
    cout<<ans1(a,b);
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