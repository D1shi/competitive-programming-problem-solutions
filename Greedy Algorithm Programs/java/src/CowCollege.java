import java.util.*;

public class CowCollege {
  IOHandler io;    
  int N;
  long[] prices;

  public CowCollege() throws Exception {
    io = new IOHandler();
    N = io.nextInt();
    prices = new long[N];

    for (int i = 0; i < N; i++) prices[i] = io.nextLong();
  }

  public static void main(String[] args) throws Exception {
    CowCollege cc = new CowCollege();
    long[] out = cc.run();
    cc.io.println(out[0] + " " + out[1]);
    cc.io.close();
  }

  public long[] run() {
    long[] out = new long[2]; // o[0] = money, o[1] = tuition
    Arrays.sort(prices);

    for (int i = 0; i < N; i++) {
      long currTuit = prices[i] * (N - i);

      if (currTuit > out[0]) {
        out[1] = prices[i];
        out[0] = currTuit;
      }
    }

    return out;
  }
}
