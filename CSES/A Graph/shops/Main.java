import java.io.*;
import java.util.*;

public class Main {
    static class DistSource implements Comparable<DistSource> {
        int dst;
        int src;
        DistSource(int distance, int source) {
            dst = distance;
            src = source;
        }
        
        @Override
        public int compareTo(DistSource other) {
            return Integer.compare(this.dst, other.dst);
        }
        
        @Override
        public boolean equals(Object o) {
            DistSource that = (DistSource) o;
            return dst == that.dst && src == that.src;
        }

        @Override
        public int hashCode() {
            return Objects.hash(dst, src);
        }

        @Override
        public String toString(){
            return "distance: " +dst+" Source: "+src;
        }
    }
    static class City{
        int id;
        boolean isShop;
        List<DistSource> sources;
        boolean updateSources(City parent){
            Map<Integer, Integer> uniqueSrcDist=new HashMap<>();
            Collections.sort(parent.sources);
            if(parent.isShop){
                uniqueSrcDist.put(parent.id,1);
            }
            for(DistSource d: parent.sources){
                if(uniqueSrcDist.containsKey(d.src)){
                    uniqueSrcDist.put(d.src, Math.min(uniqueSrcDist.get(d.src), d.dst + 1));
                }else{
                    uniqueSrcDist.put(d.src, d.dst+1);
                }
            }
            for(DistSource d: sources){
                if(d.src!=this.id){
                    if(uniqueSrcDist.containsKey(d.src)){
                    uniqueSrcDist.put(d.src, Math.min(uniqueSrcDist.get(d.src), d.dst));
                    }else{
                    uniqueSrcDist.put(d.src, d.dst);
                    }
                }
            }
            uniqueSrcDist.remove(this.id);
            List<DistSource> newSources = new ArrayList<>();
            for(Map.Entry<Integer, Integer> entry : uniqueSrcDist.entrySet()) {
                newSources.add(new DistSource(entry.getValue(), entry.getKey()));
            }
            Collections.sort(newSources);
            // Keep only top 2 shortest distances
            if (newSources.size() > 2) {
                newSources = newSources.subList(0, 2);
            }
            
            boolean changed = sources == null || sources.size() != newSources.size();
            if (!changed) {
                for (int i = 0; i < sources.size(); i++) {
                    if (!sources.get(i).equals(newSources.get(i))) {
                        changed = true;
                        break;
                    }
                }
            }
            sources = newSources;
            return changed;
        }
        int getClosestShop(){
        Collections.sort(sources);
        if(sources.get(0).dst == MOD) return -1;
        return sources.get(0).dst;
        }
        City(int i, boolean shop){
            id=i;
            isShop=shop;
            sources = new ArrayList<>();
            DistSource d=new DistSource(MOD, -1);
            sources.add(d);
            sources.add(d);
        }

        @Override
        public String toString(){
            return "Id: "+id+" isShop: "+isShop+" Source:"+sources.toString();
        }
    }
    static void solve() throws IOException {
        int n,m,k;
        n=in.nextInt();
        m=in.nextInt();
        k=in.nextInt();
        
         City[] cities = new City[n+1];
        for(int i = 1; i <= n; i++) {
            cities[i] = new City(i, false); // initially no shops
        }
        
        // Read k shops and mark them
        Deque<City> shops = new ArrayDeque<>();
        for(int i = 0; i < k; i++) {
            int shop = in.nextInt();
            cities[shop].isShop = true;
            shops.addLast(cities[shop]);
        }
        
        List<Integer>[] adj = new ArrayList[n+1];
        for(int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }
        
        // Read m edges
        for(int i = 0; i < m; i++) {
            int a = in.nextInt() ;
            int b = in.nextInt() ;
            adj[a].add(b);
            adj[b].add(a); // bidirectional
        }
        
       

        solveGraph(adj, cities, shops);
    }

    static void solveGraph(List<Integer>[] graph, City[] cities, Deque<City> q) {
        while(!q.isEmpty()) {
            City parent = q.pollFirst();
            for(int neighborId : graph[parent.id]) {
                City neighbor = cities[neighborId];
                if(neighbor.updateSources(parent)) {
                    q.addLast(neighbor);
                }
            }
        }
        for(City c: cities){
            if(c!=null)
            out.print(c.getClosestShop()+" ");
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