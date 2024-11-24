public class OddPhotos {
  IOHandler io;
  int N;
  int[] cows;

  public OddPhotos() throws Exception {
    this.io = new IOHandler();
    this.N = io.nextInt();
    this.cows = new int[N];
    for (int i = 0; i < N; i++) cows[i] = io.nextInt();
  }

  public static void main(String[] args) throws Exception {
    OddPhotos op = new OddPhotos();
    op.io.println(op.run());
    op.io.close();
  }

  public int run() {
    int[] out = new int[2]; // {out[0] even, out[1] odd}
    for (int cow : cows) { out[cow % 2]++; } // depending on divisibility, group cows

    while (out[1] > out[0]) { out[1] -= 2; out[0]++; } // if too many odd, odd -= 2, even++
    if (out[0] > out[1]) { out[0] = out[1] - 1; } // if too many even, even = odd - 1

    return out[0] + out[1];
  }
}
