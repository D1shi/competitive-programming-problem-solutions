import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		IOHandler io = new IOHandler();
		
    int N = io.nextInt(); io.nextInt();
    int[] arr = new int[N];
		int out = 0;
 
    for (int i = 0; i < N; i++) arr[i] = io.nextInt();

		int[] check = check(arr);
 
		while (Arrays.stream(check).sum() != -2) {
			for (int i = 0; i < arr.length; i++) {
				int n = arr[i];

				if (n == check[1]) {
					arr[i] = check[0];
					out++;
				}
			}

			check = check(arr);
		}
    
		io.println(out);
    io.close();
	}

	public static int[] check(int[] arr) {
		Map<Integer, Integer> blocks = new HashMap<>();
		int prev = arr[0];

		for (int i = 1; i < arr.length; i++) {
			int n = arr[i];
			if (blocks.containsKey(n)) return new int[] {n, prev};

			if (n != prev) blocks.put(prev, i - 1);
			prev = n;
		}

		return new int[] {-1, -1};
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