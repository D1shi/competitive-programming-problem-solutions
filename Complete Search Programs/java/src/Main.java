import java.util.*;

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