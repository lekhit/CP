import java.io.*;
import java.util.*;

public class Main {
    static void solve2() throws IOException {
        int n=in.nextInt();

        int[] arr=readArray(n);
        Set<Integer> runningMax=new HashSet<>();
        int back=0,maxSize=0;
        for(int i=0;i<n;i++){
            if(runningMax.contains(arr[i])){
                // find duplicate index
                int duplicateIndex=back;
                while(duplicateIndex<i && arr[duplicateIndex]!=arr[i]){
                    duplicateIndex++;
                }
                // remove till duplicate index;
                while(back<=duplicateIndex){
                    runningMax.remove(arr[back]);
                    back++;// set back to duplicate index + 1
                }

            }

            runningMax.add(arr[i]);
            maxSize=Math.max(runningMax.size(),maxSize);
                
            
        }
        out.print(maxSize);
    }

    static void solve() throws IOException {
        // Your solution here
        int n=in.nextInt();
         int[] arr=readArray(n);
        Map<Integer, Integer> posMapping = new HashMap<>();
        int rearGuard=0, lead=0, maxArraySize=0;
            //continue till we get first negative
            while(lead<n){
                
                if(posMapping.containsKey(arr[lead]) && posMapping.get(arr[lead]) >= rearGuard){
                    rearGuard=posMapping.get(arr[lead])+1;
                    maxArraySize=Math.max(maxArraySize, lead-rearGuard+1);
                }else{
                    posMapping.put(arr[lead],lead);
                    maxArraySize=Math.max(maxArraySize, lead-rearGuard+1);
                    lead++;
                }
                
        }
        out.print(maxArraySize);
    }
    public static void main(String[] args) throws IOException {
        if (isLocalEnvironment() && args.length >= 2) {

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
    static class Pair<T1, T2> {
        T1 first;
        T2 second;
        
        Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
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
}