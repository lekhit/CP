#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

// Type definitions
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
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
#define inputvec(v, n)          \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> v[i];            \
        v[i] *= (-1);           \
    }
#define makevec(v, n) \
    vi v(n);          \
    inputvec(v, n)
#define take(type, name) \
    type name;           \
    cin >> name
#define take(type, name, size) \
    type name(size);           \
    cin >> name

// Generic input function for pairs
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p)
{
    in >> p.first >> p.second;
    return in;
}

// Generic input function for vectors
template <typename T>
istream &operator>>(istream &in, vector<T> &arr)
{
    for (auto &x : arr)
        in >> x;
    return in;
}

// Variadic macro for taking multiple inputs of same type
#define TS(type, ...) \
    type __VA_ARGS__; \
    ([&](auto &&...args) { ((cin >> args), ...); }(__VA_ARGS__))

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
    void moveToTemp(int start, int end){
        for(int i=start;i<end;i++){
            temp[i]=arr[i];
        }
    }
   void merge(int start, int mid, int end){
int i=start,j=mid,index=start;
while(i<mid || j<end){
    if(i<mid && j<end){
        if(arr[j]>temp[i]){
            swapCount++;
            arr[index] = temp[i++];
        }else{
            arr[index]=arr[j++];
        }
    }else if(i<mid){
        arr[index]=temp[i++];
    }else{
        arr[index]=arr[j++];
    }
    index++;
}
   }

    void split(int start, int end)
    {
        if (end - start <= 1)
        {
            return;
        }
        int mid = (start + end) / 2;
        split(start, mid);
        split(mid, end);
        merge(start, mid, end);
        // cout<<start<<" "<<end;
    }
    int getSwapCount()
    {
        return swapCount;
    }
    vi sort()
    {
        int start = 0, end = size;
        split(start, end);
        return arr;
    }
};

MergeSort::MergeSort(vi &inputArray)
{
    temp = arr = inputArray;
    size = arr.size();
    swapCount = 0;
}

MergeSort::~MergeSort()
{
}

void solve()
{
    TS(int, n);
    take(vi, arr, n);
    MergeSort mergeSort(arr);
    auto ans = mergeSort.sort();
    for (auto i : ans)
        cout << i << " ";

    cout << mergeSort.getSwapCount();
}

int main()
{
    fastio;

    if (LOCAL_ENV)
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}