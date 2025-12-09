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


class Queries {
public:
    int start, end, count;

    // Optional: Constructor for easy initialization
    Queries(int s, int e, int c) : start(s), end(e), count(c) {}

    // Add operator< for comparison
    bool operator<(const Queries& other) const {
        if (end != other.end) {
            return end < other.end;
        }
        return start < other.start;
    }

    // Optional: Overload the << operator for easy printing (for demonstration)
    friend std::ostream& operator<<(std::ostream& os, const Queries& q) {
        os << "Start: " << q.start << ", End: " << q.end << ", Count: " << q.count;
        return os;
    }
};


bool ans(vector<int> nums, vector<vector<int>> queries){
    multiset<Queries> mp;  // Now uses Queries's operator<
    for(auto i: queries){
        if(i[0]==i[1]){
            if(nums[i[0]]>0){
                nums[i[0]]--;
            }
        }else{
        mp.insert({i[0],i[1],2});
    }
    }

    for(int i=0;i<nums.size();i++){
        if(nums[i]==0) continue;
        Queries SearchKey(numeric_limits<int>::min(), i, 0);
        auto it=mp.lower_bound(SearchKey);
        vector<Queries> storeTemp;
        while((it)!=mp.end()){
            // cout<<"I: "<<i<<" S: "<<(it->start)<<" E: "<<(it->end)<<" C: "<<(it->count)<<endl;
            // for(auto k: nums) cout<<k<<" ";cout<<endl;
            if(nums[i]==0) break;
             if(it->start <= i){
                    Queries updated = *it;
                    updated.count = updated.count - 1;
                    it=mp.erase(it);
                    if(updated.count>0)
                        storeTemp.push_back(updated);
                        // mp.insert(updated);
                    nums[i]-=1;
            }else{
                ++it;
            }
        }
        for(auto itr: storeTemp) mp.insert(itr);
        if(nums[i]!=0) return false;
    }
    for(auto i:nums){if(i!=0) return false;}
    return true;
}

void solve(){
    int n,m;cin>>n>>m;
    vector<int> nums(n);
    for(auto &i:nums)cin>>i;

    vector<vector<int>> queries(m);
    for(auto &i:queries){
       int a,b;cin>>a>>b;
       i.push_back(a);
       i.push_back(b);
    }

    cout<<ans(nums, queries);

}

int main() {
    fastio;
    
    // File I/O (local only)
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }

    solve();
    
    return 0;
}