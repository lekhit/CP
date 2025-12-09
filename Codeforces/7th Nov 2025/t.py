import sys

def solve():
    k, l1, r1, l2, r2 = map(int, sys.stdin.readline().split())

    ans = 0
    pow_k = 1  # This is k**0
    
    # We loop by multiplying pow_k by k each time.
    # This is safer than using math.log and handles k=1 (though k>=2 here)
    while True:
        # Calculate the x-range derived from the y-range [l2, r2]
        # lower_x = ceil(l2 / pow_k)
        lower_x = (l2 + pow_k - 1) // pow_k
        
        # upper_x = floor(r2 / pow_k)
        upper_x = r2 // pow_k

        # Find the intersection of [l1, r1] and [lower_x, upper_x]
        a = max(l1, lower_x)
        b = min(r1, upper_x)

        # If the intersection is valid, add the count
        if a <= b:
            # This is the (b - a + 1) fix
            ans += (b - a + 1)
            
        # Stop if k**n is already too large to produce a valid x
        # (i.e., x >= 1 implies x*pow_k >= pow_k)
        if pow_k > r2:
            break
            
        # Optimization: If multiplying by k will overflow or
        # guarantee pow_k > r2, we can stop.
        # r2 // k < pow_k is a safe way to check if pow_k * k > r2
        if r2 // k < pow_k:
            break
            
        # Go to the next power
        pow_k *= k

    print(ans)

# Read the number of test cases
t = int(sys.stdin.readline())
for _ in range(t):
    solve()