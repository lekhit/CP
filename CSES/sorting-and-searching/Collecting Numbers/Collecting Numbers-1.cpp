#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define int int64_t
#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); cout.tie(nullptr)

// Type definitions
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

// Utility macros
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()

// Generic input function for pairs
template<typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
    in >> p.first >> p.second;
    return in;
}

// Generic input function for vectors
template<typename T>
istream& operator>>(istream& in, vector<T>& arr) {
    for (auto& x : arr) in >> x;
    return in;
}



// New macro for multiple vector inputs
#define TS(...) [&]() { \
    return std::make_tuple(__VA_ARGS__); \
}()

// Add generic input function
template<typename T>
T take(size_t size = 0) {
    if constexpr (std::is_same_v<T, vector<int>> || 
                  std::is_same_v<T, vector<long long>> ||
                  std::is_same_v<T, vector<double>> ||
                  std::is_same_v<T, string>) {
        T v(size);
        for(auto& x : v) cin >> x;
        return v;
    } else {
        T x;
        cin >> x;
        return x;
    }
}

class MergeSort
{
private:
    vi arr;
    vi temp;
    int size;
    int swapCount;
public:
    MergeSort(vi &inputArray);
    ~MergeSort();

    void merge(int start,int mid, int end){
        int i=start,j=mid;
        int index=start;
        while(i<mid && j<end){
            if(arr[j]<arr[i]){
                // swap is required
                swapCount++;
                temp[index]=arr[j];
                j++;
            }else{
                // swap is not required
                temp[index]=arr[i];
                i++;
            }
            index++;
        }

        while(i<mid){
            temp[index]=arr[i];
                i++;index++;
        }

        while(j<end){
            swapCount++;
                temp[index]=arr[j];
                j++;index++;
        }
    }
    void split(int start, int end){
        if(start==end){
            return;
        }
        int mid=start+(end-start)/2;
        split(start, mid);
        split(mid, end);
        merge(start,mid, end);
    }
    int getSwapCount(){
        return swapCount;
    }
    void begin(){
        int start=0,end=size;
        split(start,end);
    }

};

MergeSort::MergeSort(vi &inputArray)
{
    temp=arr=inputArray;
    size=arr.size();
    swapCount=0;
}

MergeSort::~MergeSort()
{
}


void solve() {
    // Example usage:
    auto [n, arr] = TS(take<int>(), take<vi>(10));  // Creates and reads two vectors
    for(auto i:arr)cout<<i<<' ';
    cout<<"\n"<<n;
}

int32_t main() {
    fastio;
    
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    
    return 0;
}