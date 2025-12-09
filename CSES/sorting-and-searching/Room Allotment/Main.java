import java.io.*;
import java.util.*;

public class Main {
    static void solve() throws IOException {
        // Your solution here
        int n=in.nextInt();
        Pair<Integer, Integer> cutomer;
        Pair<Integer, Integer> room;
        ArrayList<Pair<Integer,Integer>> customers=new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int a=in.nextInt(),b=in.nextInt();
                customers.add(new Pair<Integer,Integer>(a,b));
        }
        customers.sort((p1, p2) -> p1.first.compareTo(p2.first));
        MultiSet<Pair<Integer,Integer>> hotel=new MultiSet<>();
        int roomNo=0;
        for (var customer: customers){
            
        }
    }
    public static void main(String[] args) throws IOException {
        if (isLocalEnvironment() && args.length == 2) {

            in = new FastReader(new FileInputStream(args[0]));
            out = new PrintWriter(new FileOutputStream(args[1]));
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
    
    static FastReader in;
    static PrintWriter out;
    
    // Constants
    static final int MOD = 1_000_000_007;
    static final int INF = Integer.MAX_VALUE;
    static final long LINF = Long.MAX_VALUE;
    static final double EPS = 1e-9;
    
    // Type definitions using static classes
    static class Pair<T1 extends Comparable<T1>, T2 extends Comparable<T2>> implements Comparable<Pair<T1, T2>> {

        T1 first;
        T2 second;
        
        Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair<T1, T2> other) {
            int cmp = this.first.compareTo(other.first);
            if (cmp != 0) return cmp;
            return this.second.compareTo(other.second);
        }
    }
    
    // Utility methods
    static <T> List<T> readList(int n) throws IOException {
        List<T> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            // Assuming T is Integer, modify as needed
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
    
    
    static boolean isLocalEnvironment() {
        return System.getProperty("LOCAL") != null;
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
    
    // Additional utility methods
    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
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
    
    static int lowerBound(int[] arr, int x) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= x) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    
    static void sort(int[] arr) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int x : arr) list.add(x);
        Collections.sort(list);
        for (int i = 0; i < arr.length; i++) arr[i] = list.get(i);
    }
    /*
     * 
     * 3
2 8 3
2 2 8 8 3 3

     */

    static class MultiMap<Key, Value> extends TreeMap<Key, ArrayList<Value>> {

    }
 
static class MultiSet<T> extends TreeMap<T, Integer> {
    int size;

    MultiSet() {
        super();
    }

    void add(T e) {
            Integer n = super.get(e);
            super.put(e, n != null ? n + 1 : 1);
            size++;
    }

    T higher(T e) {
        return super.higherKey(e);
    }

    T lower(T e){
        return super.lowerKey(e);
    }

    @Override
    public Integer remove(Object e) {
        
        if (super.containsKey(e)) {
            int n = super.get(e);
            n -= 1;
            if (n == 0) {
                super.remove(e);
            }
            size--;
            return n;
        }else{
            return null;
        }
        
        
    }

    @Override
    public int size() {
        return size;
    }

}
static class UnorderedMultiSet<T> extends HashMap<T, Integer> {
    int size;

    UnorderedMultiSet() {
        super();
    }

    void add(T e) {
            Integer n = super.get(e);
            super.put(e, n != null ? n + 1 : 1);
            size++;
    }

    @Override
    public Integer remove(Object e) {
        
        if (super.containsKey(e)) {
            int n = super.get(e);
            n -= 1;
            if (n == 0) {
                super.remove(e);
            }
            size--;
            return n;
        }else{
            return null;
        } 
    }

    boolean contains(T e){
        return super.containsKey(e);
    }

    @Override
    public int size() {
        return size;
    }

  }
}