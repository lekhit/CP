
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class testTemp {
      static FastReader in;
    static PrintWriter out;
    
    // Constants
    static final int MOD = 1_000_000_007;
    static final int INF = Integer.MAX_VALUE;
    static final long LINF = Long.MAX_VALUE;
    static final double EPS = 1e-9;
    
    // Useful data structures
    static class Pair<T1, T2> {
        T1 first;
        T2 second;
        
        Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    static class SegmentTree {
        int[] tree;
        int n;
        
        SegmentTree(int size) {
            n = size;
            tree = new int[4 * n];
        }
        
        void update(int index, int value) { update(1, 0, n - 1, index, value); }
        
        void update(int node, int start, int end, int index, int value) {
            if (start == end) {
                tree[node] = value;
                return;
            }
            int mid = (start + end) / 2;
            if (index <= mid)
                update(2 * node, start, mid, index, value);
            else
                update(2 * node + 1, mid + 1, end, index, value);
            tree[node] = Math.max(tree[2 * node], tree[2 * node + 1]);
        }
        
        int query(int left, int right) { return query(1, 0, n - 1, left, right); }
        
        int query(int node, int start, int end, int left, int right) {
            if (left > end || right < start) return Integer.MIN_VALUE;
            if (left <= start && right >= end) return tree[node];
            int mid = (start + end) / 2;
            return Math.max(
                query(2 * node, start, mid, left, right),
                query(2 * node + 1, mid + 1, end, left, right)
            );
        }
    }
    
    // Input methods
    static <T> List<T> readList(int n) throws IOException {
        List<T> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add((T) Integer.valueOf(in.nextInt()));
        }
        return list;
    }
    
    static int[] readArray(int n) throws IOException {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
        }
        return arr;
    }

    static long[] readLongArray(int n) throws IOException {
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextLong();
        }
        return arr;
    }
    
    // Math utilities
    static long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }
    static long lcm(long a, long b) { return (a * b) / gcd(a, b); }
    


    static <T> T take(Class<T> type, int n) throws IOException {
        @SuppressWarnings("unchecked")
        T result = null;
                if(type == Integer.class) {
            result = type.cast(in.nextInt());
        } else if(type == Long.class) {
            result = type.cast(in.nextLong());
        } else if(type == Double.class) {
            result = type.cast(in.nextDouble());
        } else if(type == String.class) {
            result = type.cast(in.next());
        }
        return result;
    }
    
    @SafeVarargs
    static <T> T[] takeInput(Class<T> type, String... variableNames) throws IOException {
        @SuppressWarnings("unchecked")
        T[] result = (T[]) java.lang.reflect.Array.newInstance(type, variableNames.length);
        for(int i = 0; i < variableNames.length; i++) {
            if(type == Integer.class) {
                result[i] = type.cast(in.nextInt());
            } else if(type == Long.class) {
                result[i] = type.cast(in.nextLong());
            } else if(type == Double.class) {
                result[i] = type.cast(in.nextDouble());
            } else if(type == String.class) {
                result[i] = type.cast(in.next());
            }
        }
        return result;
    }

    static long modPow(long base, long exp, long modulus) {
        if (exp == 0) return 1;
        long half = modPow(base, exp / 2, modulus);
        if (exp % 2 == 0) return (half * half) % modulus;
        return (((half * half) % modulus) * base) % modulus;
    }
    
    // Binary Search utilities
    static int upperBound(int[] arr, int x) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= x) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    
    static int lowerBound(int[] arr, int x) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= x) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    
    // Sorting utilities
    static void sort(int[] arr) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int x : arr) list.add(x);
        Collections.sort(list);
        for (int i = 0; i < arr.length; i++) arr[i] = list.get(i);
    }
    
    static void solve() throws IOException {
        // Example usage
        Integer[] vars = takeInput(Integer.class, "n", "m", "k");
        int n = vars[0], m = vars[1], k = vars[2];
        take(int.class,1);
        out.println(n + " " + m + " " + k);
    }
    
    public static void main(String[] args) throws IOException {
        if (isLocalEnvironment()) {
             String currentDir = Paths.get("").toAbsolutePath().toString();
            in = new FastReader(new FileInputStream(Paths.get(currentDir, "input.txt").toString()));
            out = new PrintWriter(new FileOutputStream(Paths.get(currentDir, "output.txt").toString()));
            // in = new FastReader(System.in);
            // out = new PrintWriter(System.out);
        
        } else {
            in = new FastReader(System.in);
            out = new PrintWriter(System.out);
        }
        
        int t = 1;
        // t = in.nextInt(); // Uncomment for multiple test cases
        while (t-- > 0) {
            solve();
        }
        
        out.close();
    }
    
    static boolean isLocalEnvironment() {
        return System.getProperty("ONLINE_JUDGE") == null;
    }
    
    // Fast I/O
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
        
        public FastReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }
        
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
        double nextDouble() { return Double.parseDouble(next()); }
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
