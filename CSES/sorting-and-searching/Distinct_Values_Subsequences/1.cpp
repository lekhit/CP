#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<long long> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    long long MOD = 1e9 + 7;

    // last_contribution[val] stores the number of distinct-element subsequences
    // that ended specifically at the *last* index where 'val' occurred.
    // We use a map because the values of x_i can be large (up to 10^9).
    map<long long, long long> last_contribution;

    // total_sum_contributions stores the sum of last_contribution[v]
    // for all distinct values v seen so far in the processed prefix.
    // This variable accumulates the counts and will hold the final answer.
    long long total_sum_contributions = 0;

    for (int i = 0; i < n; ++i) {
        long long val = x[i];

        // Get the contribution from the previous time 'val' appeared.
        // If 'val' hasn't appeared before, map::operator[] inserts it with value 0,
        // or map::find can be used more explicitly.
        long long prev_contribution_val = 0;
        if (last_contribution.count(val)) {
            prev_contribution_val = last_contribution[val];
        }

        // Calculate the number of distinct-element subsequences ending exactly at index i.
        // It's 1 (for the subsequence [val] itself) plus the sum of contributions ending at the last occurrence
        // of all *other* values seen previously.
        // This sum is (total_sum_contributions - prev_contribution_val).
        // We add MOD before taking modulo to handle potential negative results.
        long long current_contribution = (1 + total_sum_contributions - prev_contribution_val + MOD) % MOD;

        // Update the running sum of last contributions.
        // Remove the outdated contribution of val, add the new one for the current index.
        total_sum_contributions = (total_sum_contributions - prev_contribution_val + current_contribution + MOD) % MOD;

        // Store the contribution of this occurrence (index i) of val.
        last_contribution[val] = current_contribution;
    }

    // The final answer is the sum of the contributions from the last occurrences
    // of all values encountered after processing the entire array.
    cout << total_sum_contributions << endl;

    return 0;
}