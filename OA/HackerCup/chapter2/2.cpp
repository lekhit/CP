#include <iostream>
#include <vector>
#include <map>
#include <numeric> // For std::gcd
#include <cstdlib> // For rand()
#include <ctime>   // For time()

// Use __int128 for modular multiplication to prevent overflow with large numbers
using int128 = __int128;

// --- Number Theory Utilities for Factoring ---

// Modular multiplication: (a * b) % mod
long long mul(long long a, long long b, long long mod) {
    return (long long)((int128)a * b % mod);
}

// Modular exponentiation: (base^exp) % mod
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = mul(res, base, mod);
        base = mul(base, base, mod);
        exp /= 2;
    }
    return res;
}

// Miller-Rabin primality test helper
bool check_composite(long long n, long long a, long long d, int s) {
    long long x = power(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int r = 1; r < s; r++) {
        x = mul(x, x, n);
        if (x == n - 1) return false;
    }
    return true;
};

// Miller-Rabin primality test
bool is_prime(long long n) {
    if (n < 2) return false;
    int s = 0;
    long long d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    // These bases are sufficient for deterministic checking up to 2^64
    for (long long a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) return true;
        if (check_composite(n, a, d, s)) return false;
    }
    return true;
}

// Pollard's Rho algorithm to find a non-trivial factor
long long pollard(long long n) {
    if (n % 2 == 0) return 2;

    long long x = rand() % (n - 2) + 2;
    long long y = x;
    long long c = rand() % (n - 1) + 1;
    long long d = 1;

    auto f = [&](long long val) {
        return (mul(val, val, n) + c) % n;
    };

    while (d == 1) {
        x = f(x);
        y = f(f(y));
        d = std::gcd(std::abs(x - y), n);
    }
    return d;
}

// Recursive helper for factorization
void factorize(long long n, std::map<long long, int>& factors) {
    if (n <= 1) return;
    if (is_prime(n)) {
        factors[n]++;
        return;
    }
    long long d = pollard(n);
    // If pollard fails (finds n), try again with different random values
    while (d == n) {
        d = pollard(n);
    }
    factorize(d, factors);
    factorize(n / d, factors);
}

// Main factorization function
std::map<long long, int> get_prime_factorization(long long n) {
    std::map<long long, int> factors;
    factorize(n, factors);
    return factors;
}


// --- Main Problem Logic (from previous answer) ---

const int MOD = 1e9 + 7;
const int MAX_EXP = 65;
long long fact[MAX_EXP];
long long invFact[MAX_EXP];

long long power_mod(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (int128)res * base % MOD;
        base = (int128)base * base % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power_mod(n, MOD - 2);
}

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAX_EXP; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAX_EXP - 1] = modInverse(fact[MAX_EXP - 1]);
    for (int i = MAX_EXP - 2; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long combinations(int k, long long N) {
    if (k < 0) return 0;
    if (k == 0) return 1;
    long long num = 1;
    long long N_mod = N % MOD;
    for (int i = 0; i < k; ++i) {
        num = (num * (N_mod + i)) % MOD;
    }
    return (num * invFact[k]) % MOD;
}

std::vector<std::pair<long long, int>> factors_B;
long long T_table[15][MAX_EXP];
std::map<long long, long long> memo[15];
long long N_val, A_val;

long long solve(int idx, long long current_X) {
    if (idx == factors_B.size()) return 1;
    if (memo[idx].count(current_X)) return memo[idx][current_X];

    long long total_ways = 0;
    long long p = factors_B[idx].first;
    int b = factors_B[idx].second;
    long long power_p = 1;

    for (int x = 0; x <= b; ++x) {
        if (current_X > A_val / power_p) break;
        long long next_X = current_X * power_p;
        long long term = (T_table[idx][x] * solve(idx + 1, next_X)) % MOD;
        total_ways = (total_ways + term) % MOD;
        if (x < b) power_p *= p;
    }
    return memo[idx][current_X] = total_ways;
}

void solve_test_case() {
    long long B_val;
    std::cin >> N_val >> A_val >> B_val;
    if (B_val == 1) {
        std::cout << 1 << std::endl;
        return;
    }
    auto factors_map = get_prime_factorization(B_val);
    factors_B.assign(factors_map.begin(), factors_map.end());
    for (size_t i = 0; i < factors_B.size(); ++i) memo[i].clear();
    for (size_t i = 0; i < factors_B.size(); ++i) {
        int b = factors_B[i].second;
        for (int x = 0; x <= b; ++x) {
            long long ways1 = combinations(x, N_val);
            long long ways2 = combinations(b - x, N_val);
            T_table[i][x] = (ways1 * ways2) % MOD;
        }
    }
    std::cout << solve(0, 1) << std::endl;
}

int main() {
   {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    srand(time(0)); // Seed for Pollard's Rho
    precompute_factorials();
    int T;
    std::cin >> T;
    for (int i = 1; i <= T; ++i) {
        std::cout << "Case #" << i << ": ";
        solve_test_case();
    }
    return 0;
}