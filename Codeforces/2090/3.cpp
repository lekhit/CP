#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

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
#define inputvec(v,n) for(int i=0;i<n;i++) {cin>>v[i]; v[i]*=(-1);}
#define makevec(v,n) vi v(n); inputvec(v,n)
#define take(type, name) type name; cin>>name

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

// Variadic macro for taking multiple inputs of same type
#define TS(type, ...) type __VA_ARGS__; ([&](auto&&... args) { ((cin >> args), ...); }(__VA_ARGS__))

void addTables(queue<pii> &qq, int counter){

}

void solve() {
    int n;cin>>n;
    stack<pii> st;
    queue<pii> qq;
    auto compare = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        int distA=a.first+a.second;
        int distB=b.first+b.second;
        if(a.first==a.second && a.first!=1) distA+=2;
        if(b.first==b.second && b.first!=1) distB+=2;
        // cout<<distA<<" "<<distB<<" "<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second<<endl;
        if(distA==distB){
            if (a.first != b.first) {
                return a.first > b.first; // Order by first value (ascending)
            } else {
                return a.second > b.second; // If first values are equal, order by second (ascending)
            }
        }else{
        return distA > distB;
    }
    };

    // Create a priority queue using the custom comparator
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> pq(compare);

    int counter=0;
    auto addTables = [&](){
        for(int x=0;x<=counter;x++){
            qq.push({x,counter-x});
        }
        counter++;
    };

    auto useTable = [&](){
        if(qq.empty()) addTables();
        auto val=qq.front();
        qq.pop();
        return val;
    };

    auto getSeats = [&](pii table){
        auto [x,y]=table;
        x*=3;y*=3;
        vpii seats;
        seats.emplace_back(x+1, y+1);
        seats.emplace_back(x+1,y+2);
        seats.emplace_back(x+2,y+1);
        seats.emplace_back(x+2,y+2);
        return seats;
    };
    auto getRemainingSeats = [&](pii table){
        auto [x,y]=table;
        x*=3;y*=3;
        vpii seats;
        seats.emplace_back(x+1,y+2);
        seats.emplace_back(x+2,y+1);
        seats.emplace_back(x+2,y+2);
        return seats;
    };
    auto getSeat=[&](pii table){
    
            auto [x,y]=table;
            x*=3;y*=3;
            return make_pair(x+1, y+1);
    };

vpii answer;
    while(n--){
        int choise;cin>>choise;
        if(choise==0){
            // add new table and add remaining seats to the pq
            //give the customer the lowest seat on this table
            pii table=useTable();
            answer.push_back(getSeat(table));
            auto remainingSeats=getRemainingSeats(table);
            // Fix: Push each remaining seat individually
            for(const auto& seat : remainingSeats) {
                pq.push(seat);
            }

        }else{
            //give a seat from pq
            // in case all seats are empty add a new table
            if(pq.empty()){
                auto table=useTable();
                auto seats=getSeats(table);
                // Fix: Push each seat individually
                for(const auto& seat : seats) {
                    pq.push(seat);
                }
            }
            auto seat=pq.top();
            pq.pop(); // Don't forget to remove the used seat
            answer.push_back(seat);
        }
    }
    for(auto i:answer){
        cout<<i.first<<" "<<i.second<<"\n";
    }
}

int main() {
    fastio;
    
    if(LOCAL_ENV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    
    return 0;
}