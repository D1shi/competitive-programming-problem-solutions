public class MooBuzz {
  final int N;
  IOHandler io;

  public MooBuzz() throws Exception {
    io = new IOHandler();
    N = io.nextInt();
  }

  public static void main(String[] args) throws Exception {
    MooBuzz mb = new MooBuzz();
    mb.io.println(mb.run()); mb.io.close();
  }

  public int run() {
    int n = 1; int out = 0;

    for (int i = 0; i < N; i++) {
      if (n % 3 == 0 || n % 5 == 0) i--;
      else out = n;
      n++;
    }

    return out;
  }
}
