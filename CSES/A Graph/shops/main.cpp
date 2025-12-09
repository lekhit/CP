#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class DistSource {
    public:
    int dst, src;
    DistSource(int d = MOD, int s = -1) : dst(d), src(s) {}
    // DistSource()  {dst = MOD;  src = -1;}
    bool operator<(const DistSource& other) const {
        return dst < other.dst;
    }
    DistSource& operator=(const DistSource& other) {
        if (this != &other) {
            dst = other.dst;
            src = other.src;
        }
        return *this;
    }
};

class City {
    public:
    int id;
    bool isShop;
    vector<DistSource> sources;
    
    City(int i = 0, bool shop = false) : id(i), isShop(shop) {
        DistSource d;
        sources.push_back(d);
        sources.push_back(d);
    }

    bool updateSources(City& parent) {
        unordered_map<int, int> uniqueSrcDist;
        sort(parent.sources.begin(), parent.sources.end());
        
        if(parent.isShop) {
            uniqueSrcDist[parent.id] = 1;
        }
        
        for(const auto& d : parent.sources) {
            uniqueSrcDist[d.src] = min(uniqueSrcDist[d.src], d.dst + 1);
        }
        
        for(const auto& d : sources) {
            if(d.src != id) {
                uniqueSrcDist[d.src] = min(uniqueSrcDist[d.src], d.dst);
            }
        }
        
        uniqueSrcDist.erase(id);
        vector<DistSource> newSources;
        for(const auto& [src, dst] : uniqueSrcDist) {
            newSources.emplace_back(dst, src);
        }
        
        sort(newSources.begin(), newSources.end());
        if(newSources.size() > 2) {
            newSources.resize(2);
        }
        
        bool changed = sources.size() != newSources.size();
        if(!changed) {
            for(size_t i = 0; i < sources.size(); i++) {
                if(!(sources[i].dst == newSources[i].dst && sources[i].src == newSources[i].src)) {
                    changed = true;
                    break;
                }
            }
        }
        sources = newSources;
        return changed;
    }

    int getClosestShop() {
        sort(sources.begin(), sources.end());
        return sources[0].dst == MOD ? -1 : sources[0].dst;
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<City> cities(n + 1);
    for(int i = 1; i <= n; i++) {
        cities[i] = City(i, false);
    }
    
    queue<City> shops;
    for(int i = 0; i < k; i++) {
        int shop;
        cin >> shop;
        cities[shop].isShop = true;
        shops.push(cities[shop]);
    }
    
    vector<vector<int> > adj(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    while(!shops.empty()) {
        City& parent = shops.front();
        shops.pop();
        for(int nbr : adj[parent.id]) {
            if(cities[nbr].updateSources(parent)) {
                shops.push(cities[nbr]);
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        cout << cities[i].getClosestShop() << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while(t--) solve();
    
    return 0;
}
