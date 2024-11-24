public class WatchingMooloo {
  IOHandler io;
  int N, K;
  long[] days;
  
  public WatchingMooloo() throws Exception {
    io = new IOHandler();
    N = io.nextInt();
    K = io.nextInt();
    days = new long[N];

    for (int i = 0; i < N; i++) days[i] = io.nextLong();
  }

  public static void main(String[] args) throws Exception {
    WatchingMooloo wm = new WatchingMooloo();
    wm.io.println(wm.run());
    wm.io.close();
  }

  public long run() {
    long out = K + 1; // price

    for (int i = 1; i < N; i++) {
      long dif = days[i] - days[i - 1]; // dist between 2 days
      out += Math.min(K + 1, dif); // see if new subscription costs less
    }

    return out;
  }
}
