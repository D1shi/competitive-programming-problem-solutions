import java.io.IOException;

public class Drought {
  IOHandler io;
  int T;
  
  public Drought() throws IOException {
    io = new IOHandler();
    T = io.nextInt();
  }

  public static void main(String[] args) throws IOException {
    Drought d = new Drought();
    d.run(); d.io.close();
  }

  public void run() throws IOException {
    for (int $ = 0; $ < T; $++) {
      int N = io.nextInt();
      int sum = 0;
      long[] cows = new long[N];
      for (int c = 0; c < N; c++) {
        cows[c] = io.nextLong();
        sum += cows[c];
      }

      if (sum % N != 0) { io.println("-1"); continue; }

      long preSum = 0, oper = 0;

      for (long c : cows) {
        preSum += c - sum/N;
        oper += Math.abs(preSum);
      }

      if (preSum == 0) io.println(oper);
      else io.println("-1");
    }
  }
}
