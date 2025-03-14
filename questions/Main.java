package questions;


import java.io.*;
import java.util.*;

public class Main {
    static FastReader in;
    static PrintWriter out;

    static final int MOD = 1_000_000_007;
    static final int INF = Integer.MAX_VALUE;
    static final long LINF = Long.MAX_VALUE;
    static final double EPS = 1e-9;

    static class Pair<T1, T2> {
        T1 first;
        T2 second;

        Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return Objects.equals(first, pair.first) && Objects.equals(second, pair.second);
        }

        @Override
        public int hashCode() {
            return Objects.hash(first, second);
        }
        @Override
        public String toString() {
            return "(" + first + ", " + second + ")";
        }
    }


    static <T> List<T> readList(int n, Class<T> clazz) throws IOException {
        List<T> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (clazz == Integer.class) {
                list.add(clazz.cast(in.nextInt()));
            } else if (clazz == Long.class) {
                list.add(clazz.cast(in.nextLong()));
            } else if (clazz == Double.class) {
                list.add(clazz.cast(in.nextDouble()));
            } else if (clazz == String.class) {
                list.add(clazz.cast(in.next()));
            } else {
                throw new IllegalArgumentException("Unsupported type for readList: " + clazz.getName());
            }
        }
        return list;
    }

    static int[] readIntArray(int n) throws IOException {
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

    static double[] readDoubleArray(int n) throws IOException {
        double[] arr = new double[n];
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextDouble();
        }
        return arr;
    }

    static String[] readStringArray(int n) throws IOException {
        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = in.next();
        }
        return arr;
    }

    static int[][] read2DIntArray(int rows, int cols) throws IOException {
        int[][] arr = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = in.nextInt();
            }
        }
        return arr;
    }

    static long[][] read2DLongArray(int rows, int cols) throws IOException {
        long[][] arr = new long[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = in.nextLong();
            }
        }
        return arr;
    }

    static void solve() throws IOException {
        // --- YOUR SOLUTION GOES HERE ---
        out.println("hello");
    }

    public static void main(String[] args) throws IOException {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
        if (local) {
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


    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
            st = null;
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

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }

    static int upperBound(int[] arr, int x) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= x) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    static int upperBound(List<Integer> arr, int x) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr.get(mid) <= x) left = mid + 1;
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

    static int lowerBound(List<Integer> arr, int x) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr.get(mid) >= x) right = mid;
            else left = mid + 1;
        }
        return left;
    }


    static void sort(int[] arr) {
        Arrays.sort(arr);
    }
    static void sort(long[] arr) {
        Arrays.sort(arr);
    }

    static void sortReverse(int[] arr) {
        Arrays.sort(arr);
        reverse(arr);
    }

    static void sortReverse(long[] arr) {
        Arrays.sort(arr);
        reverse(arr);
    }

    static void reverse(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[n - i - 1];
            arr[n - i - 1] = temp;
        }
    }

    static void reverse(long[] arr) {
        int n = arr.length;
        for (int i = 0; i < n / 2; i++) {
            long temp = arr[i];
            arr[i] = arr[n - i - 1];
            arr[n - i - 1] = temp;
        }
    }

    static <T extends Comparable<T>> void sort(List<T> list) {
        Collections.sort(list);
    }

    static boolean isPrime(long n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (long i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    static long power(long a, long b, long m) {
        long res = 1;
        a %= m;
        while (b > 0) {
            if ((b & 1) == 1) res = (res * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    }
     static long modMultiply(long a, long b, long mod) {
        long res = 0;
        a %= mod;
        while (b > 0) {
            if ((b & 1) == 1) res = (res + a) % mod;
            a = (2 * a) % mod;
            b >>= 1;
        }
        return res;
    }
}
