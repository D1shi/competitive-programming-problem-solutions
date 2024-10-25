import java.io.*;
import java.util.*;

public class Main {
    List<Integer> possible = new ArrayList<>();
    boolean[] used = new boolean[4];
    static int[] cards;
	public static void main(String[] args) throws Exception {
		IOHandler io = new IOHandler();
        int N = io.nextInt();

        for (int i = 0; i < N; i++) {
            cards = new int[4];
            for (int j = 0; j < 4; j++) {
                cards[j] = io.nextInt();
            }
        }
	}

    public void recur() {
        if (possible.size() == 4) {
            // case 1: (n~(n~(n~n)))
            outer: for (int op1 = 0; op1 < 4; op1++) {
                for (int op2 = 0; op2 < 4; op2++) {
                    for (int op3 = 0; op3 < 4; op3++) {
                        // int f = op(n, m, op1);
                    }
                }
            }
        } else {
            for (int i = 0; i < 4; i++) {
				if (used[i]) continue;
				used[i] = true;
				possible.add(cards[i]);
				recur();
				used[i] = false;
				possible.remove(possible.size() - 1);
			}
        }
    }

    public int op(int n1, int n2, int op) {
        switch (op) {
            case 0: return n1 + n2;
            case 1: return n1 - n2;
            case 2: return n1 * n2;
            case 3: 
                if (n2 == 0 || n1 / n2 % 1 != 0) {
                    break;
                }
                return n1 / n2;
        }
        return Integer.MIN_VALUE;
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