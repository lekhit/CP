import java.io.*;
import java.util.*;
import java.nio.file.*;

public class Main {
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

    // Input methods
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
    
    static void solve() throws IOException {
        // Your solution here
        int n = in.nextInt();
        int[] arr = readArray(n);
        // Add your solution logic here
        out.println("Solution");
    }
    
    public static void main(String[] args) throws IOException {
        if (isLocalEnvironment()) {
            String currentDir = Paths.get("").toAbsolutePath().toString();
            in = new FastReader(new FileInputStream("input.txt"));
            out = new PrintWriter(new FileOutputStream("output.txt"));
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