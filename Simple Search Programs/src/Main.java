/* This is the main class that runs the methods */
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
    
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