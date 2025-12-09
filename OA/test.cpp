#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
const bool LOCAL_ENV = true;
#else
const bool LOCAL_ENV = false;
#endif

#define fastio ios_base::sync_with_stdio(false); \
    cin.tie(NULL); cout.tie(NULL)

vector<int> findHighlightOrder(vector<int> heights) {
    vector<int> highlightOrder;

    while (!heights.empty()) {
        int n = heights.size();
        vector<int> highlights;


        for (int i = 0; i < n; ++i) {
            bool leftOk  = (i == 0)          || (heights[i] > heights[i - 1]);
            bool rightOk = (i == n - 1)      || (heights[i] > heights[i + 1]);
            if (leftOk && rightOk) highlights.push_back(heights[i]);
        }


        if (highlights.empty()) break;


        int smallest = *min_element(highlights.begin(), highlights.end());
        highlightOrder.push_back(smallest);


        heights.erase(find(heights.begin(), heights.end(), smallest));
    }
    return highlightOrder;
}

int main() {
    fastio;

int t=1;
cin>>t;
    while(t--) {
    }

    
    return 0;
}