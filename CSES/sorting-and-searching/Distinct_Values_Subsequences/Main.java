import java.io.*;
import java.util.*;

public class Main {
    static void solve3(){
         int n=in.nextInt();
        int[] s = new int[n];
        for (int i = 0; i < n; i++) s[i] = in.nextInt();
        Map<Integer, Integer> lastOccuranceCount = new HashMap<>(); 
        // Array to store the last occurrence count of each character
        int totalDistinctSubsequences = 0; // Variable to store the total count of distinct subsequences

        // Iterate through each character in the string
        for (int i = 0; i < s.length; ++i) {
            // Determine the alphabet index of current character
            int alphabetIndex = s[i];
          
            // Calculate the number to add. This number represents the new subsequences that will be formed by adding the new character.
            // Subtract the last occurrence count of this character to avoid counting subsequences formed by prior occurrences of this character.
            // And add 1 for the subsequence consisting of the character itself.
            int newSubsequences = (totalDistinctSubsequences - lastOccuranceCount.getOrDefault(alphabetIndex,0) + 1 + MOD) % MOD;
          
            // Update the totalDistinctSubsequences by adding newSubsequences
            totalDistinctSubsequences = (totalDistinctSubsequences + newSubsequences) % MOD;

            
            // Update the last occurrence count for this character in the lastOccurrenceCount array
            int updatedValue=(lastOccuranceCount.getOrDefault(alphabetIndex,0) + newSubsequences + MOD)%MOD;
            lastOccuranceCount.put(alphabetIndex, updatedValue);
        }

        // Since the result can be negative due to the subtraction during the loop,
        // we add MOD and then take the modulus to ensure a non-negative result
        out.print((totalDistinctSubsequences + MOD) % MOD);
    }
    static void solve2(){
       int n=in.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = in.nextInt();

        Map<Integer, Integer> last = new HashMap<>();
        int[] dp = new int[n + 1];
        dp[0] = 1; // empty subsequence

        for (int i = 1; i <= n; i++) {
            dp[i]=dp[i-1];
            int x = arr[i - 1];
            if (last.containsKey(x)) {
                dp[i] = (1 + dp[i]  + MOD) % MOD;
            }else{
                dp[i] = (1+ 2 * dp[i]+MOD) % MOD;
            }
            last.put(x, i);
        }
        // Subtract 1 to exclude the empty subsequence
        out.println((dp[n] - 1 + MOD) % MOD);
    }
    static void solve() throws IOException {
        // Your solution here
        int n=in.nextInt();
        int[] arr=readArray(n);
        int[] sum=new int[n];
        Arrays.sort(arr);
        sum[0]=1;
        for (int i = 1; i < n; i++) {
            if(arr[i-1]==arr[i]){
                sum[i]=(sum[i-1]+1+MOD)%MOD;
            }else{
                sum[i]=((sum[i-1]*2)+1+MOD)%MOD;
            }
        }
        out.println(sum[n-1]);
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
            solve2();
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