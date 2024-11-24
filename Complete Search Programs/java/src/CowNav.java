import java.util.*;

public class CowNav {
  Scanner sc;
  final int N;
  int out = 0;
  boolean[][] grid;

  public CowNav() throws Exception {
    sc = new Scanner(System.in);
    N = sc.nextInt(); sc.nextLine();

    grid = new boolean[N][N];

    for (int i = 0; i < N; i++) {
      char[] s = sc.nextLine().toCharArray();
      for (int j = 0; j < N; j++) if (s[j] == '*') grid[i][j] = true;
    }
  }

  public static void main(String[] args)  throws Exception {
    CowNav cn = new CowNav();
    System.out.println(cn.run());
  }

  public int run() {
    path(0, 0);
    return out;
  }

  public void path(int x, int y) {
    if (x >= N || y >= N || grid[y][x]) return;
    if (x == N - 1 && y == N - 1) {
      out++;
      return;
    }

    if (x + 1 < N) if (!grid[y][x + 1]) path(x + 1, y);
    if (y + 1 < N) if (!grid[y + 1][x]) path(x, y + 1);
  }
}
