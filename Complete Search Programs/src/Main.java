import java.io.*; import java.util.*;
import java.util.stream.*;

public class Main {
    static Set<String> strs = new HashSet<>();
    static List<Integer> sub = new ArrayList<>();
    static int n;
    static boolean[] chosen;
    static String s;
    static IOHandler io = new IOHandler();

    public static void main(String[] args) throws Exception {
        s = io.nextStr();
        n = s.length();
        chosen = new boolean[n];
        
        search();

        io.println(strs.size());

        for (String str : strs.stream().sorted().collect(Collectors.toList())) io.println(str);
        io.close();
    }

    static void search() {
        if (sub.size() == n) {
            String sa = "";
            for (int i : sub) {
                sa += s.toCharArray()[i];
            }
            strs.add(sa);
        } else {
            for (int i = 0; i < n; i++) {
                if (chosen[i]) continue;
                chosen[i] = true;
                sub.add(i);
                search();
                chosen[i] = false;
                sub.remove(sub.size() - 1);
            }
        }
    }
    
}

class IOHandler extends PrintWriter {
    StreamTokenizer st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
  
    // Setup
    public IOHandler() { super(new BufferedWriter(new OutputStreamWriter(System.out))); }
  
    // Input handling
    int nextInt() throws IOException { st.nextToken(); return (int) st.nval; }    // takes next int
    String nextStr() throws IOException { st.nextToken(); return st.sval; }       // takes next string
    long nextLong() throws IOException { st.nextToken(); return (long) st.nval; } // takes next long
  
    // Output handling
    void qprintln(Object o) { this.println(o); this.flush(); }          // prints new line and flushes
    void qprint(Object o) { this.print(o); this.flush(); }              // prints and flushes
  
    void printItems(Object[] o) { for (Object i : o) this.println(i); } // prints multiple objects
    void printItems(int[] o) { for (int i : o) this.println(i); }       // prints multiple integers
}
