

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.HashMap;
import java.util.List;
import java.util.Objects;
import java.util.StringTokenizer;
import java.util.TreeMap;


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
            if (this.dst != other.dst) {
                return Integer.compare(this.dst, other.dst);
            }
            return Integer.compare(this.src, other.src); // Stable sort
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            DistSource that = (DistSource) o;
            return dst == that.dst && src == that.src;
        }

        @Override
        public int hashCode() {
            return Objects.hash(dst, src);
        }
    }

    static class City {
        int id;
        boolean isShop;
        List<DistSource> sources; // Always contains 2 DistSource objects

        City(int i, boolean shop) {
            id = i;
            isShop = shop;
            sources = new ArrayList<>();
            sources.add(new DistSource(MOD, -1)); // Placeholder for 1st best
            sources.add(new DistSource(MOD, -1)); // Placeholder for 2nd best
        }

        boolean updateSources(City parent) {
            List<DistSource> candidates = new ArrayList<>();

            // Add current city's existing known sources
            for (DistSource ds : this.sources) {
                if (ds.src != -1) { // Only if it's a valid source
                    candidates.add(ds);
                }
            }

            // Add sources reachable via parent
            if (parent.isShop) {
                candidates.add(new DistSource(1, parent.id));
            }
            for (DistSource dParent : parent.sources) {
                if (dParent.src != -1 && dParent.dst < MOD) {
                    if (dParent.dst + 1 < MOD) {
                         candidates.add(new DistSource(dParent.dst + 1, dParent.src));
                    } else {
                         candidates.add(new DistSource(MOD, dParent.src));
                    }
                }
            }

            Collections.sort(candidates);

            List<DistSource> newTopTwo = new ArrayList<>();
            for (DistSource cand : candidates) {
                if (cand.src == -1) continue; // Should not happen if added correctly

                if (this.isShop && cand.src == this.id) { // Shop cannot target itself
                    continue;
                }

                boolean srcAlreadyInNewTopTwo = false;
                for (DistSource chosenDs : newTopTwo) {
                    if (chosenDs.src == cand.src) {
                        srcAlreadyInNewTopTwo = true;
                        break;
                    }
                }
                if (srcAlreadyInNewTopTwo) {
                    continue;
                }

                newTopTwo.add(cand);
                if (newTopTwo.size() == 2) {
                    break;
                }
            }

            // Pad newTopTwo to always have 2 elements
            while (newTopTwo.size() < 2) {
                newTopTwo.add(new DistSource(MOD, -1));
            }

            boolean changed = false;
            if (!this.sources.get(0).equals(newTopTwo.get(0)) ||
                !this.sources.get(1).equals(newTopTwo.get(1))) {
                changed = true;
            }

            if (changed) {
                this.sources = newTopTwo;
            }
            return changed;
        }

        int getClosestShop() {
            // sources.get(0) is the best one after filtering logic in updateSources
            if (sources.get(0).dst == MOD) {
                return -1;
            }
            return sources.get(0).dst;
        }
    }

    static void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();

        City[] cities = new City[n + 1];
        for (int i = 1; i <= n; i++) {
            cities[i] = new City(i, false);
        }

        Deque<Integer> q = new ArrayDeque<>(); // Queue of City IDs

        for (int i = 0; i < k; i++) {
            int shopId = in.nextInt();
            cities[shopId].isShop = true;
            q.addLast(shopId); // Add shop ID to queue
        }

        List<Integer>[] adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            int u = in.nextInt();
            int v = in.nextInt();
            adj[u].add(v);
            adj[v].add(u);
        }

        while (!q.isEmpty()) {
            int parentId = q.pollFirst();
            City parentCity = cities[parentId];

            for (int neighborId : adj[parentId]) {
                City neighborCity = cities[neighborId];
                if (neighborCity.updateSources(parentCity)) {
                    q.addLast(neighborId);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            out.print(cities[i].getClosestShop());
            if (i < n) {
                out.print(" ");
            }
        }
        out.println();
    }

    public static void main(String[] args) throws IOException {
        // Fast I/O setup (from user's template)
        if (System.getProperty("LOCAL") != null && args.length == 2) {
             in = new FastReader(new FileInputStream(args[0]));
             out = new PrintWriter(new FileOutputStream(args[1]));
        } else {
            in = new FastReader(System.in);
            out = new PrintWriter(System.out);
        }
        
        int t = 1;
        // t = in.nextInt(); 
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

