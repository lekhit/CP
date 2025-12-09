import java.io.*;
import java.util.*;

class Room{
    Room(int s, int e){
        start=s;
        end=e;
        size=e-s;
    }
    int getSize(){
        size=end-start;
        return size;
    }
    int start;
    int end;
    int size;
}

public class Main {
    static void solve() throws IOException {
        // Your solution here
        int n=in.nextInt(),m=in.nextInt();
        int[] arr=readArray(m);
        // MultiSet<Room> rooms = new MultiSet<>((r1, r2)-> r1.start-r2.start);
        MultiSet<Integer> lamps=new MultiSet<>();
        lamps.add(0);
        lamps.add(n);
        MultiSet<Integer> maxlengths=new MultiSet<>();
        maxlengths.add(n-0);
        StringBuilder results = new StringBuilder();
        for(int i:arr){
            int low=lamps.lower(i),high=lamps.higher(i);
            maxlengths.remove(high-low);
            lamps.add(i);
            maxlengths.add(i-low);
            maxlengths.add(high-i);
            results.append(maxlengths.lastKey()).append(" ");
        }   
        out.println(results.toString().trim());
        /*
         * 
         * 1 2 3 4 5 6 7 8
         * 
         * 
         * 0 2 3 6 8
         * 3:3
         */
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
    static class Pair<T1, T2> {
        T1 first;
        T2 second;
        
        Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
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
 
static class MultiSet<T> extends TreeMap<T, Integer> {
    int size;

    MultiSet() {
        super();
    }

    public MultiSet(Comparator<T> comparator) {
        super(comparator);
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