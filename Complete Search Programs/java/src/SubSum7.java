import java.util.Arrays;

public class SubSum7 {
  public static void main(String[] args) throws Exception {
    IOHandler io = new IOHandler();

    int N = io.nextInt();
    int out = 0; // Initialize to 0 to handle cases where no subsequence exists
    int[] good = new int[7];
    Arrays.fill(good, -1); // Fill with -1 to handle the first occurrences properly
    good[0] = 0; // Start with good[0] as 0 to handle the case when remainder is 0
    int remainder = 0;

    for (int i = 1; i <= N; i++) {
      int cow = io.nextInt();
      remainder = (remainder + cow) % 7;

      if (good[remainder] == -1) {
        good[remainder] = i; // First time we see this remainder
      } else {
        out = Math.max(out, i - good[remainder]);
      }
    }

    io.println(out);
    io.close();
  }
}
