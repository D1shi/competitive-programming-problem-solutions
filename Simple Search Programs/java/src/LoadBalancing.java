import java.util.*;
// collectors is only here cuz the usaco servers for this problem haven't been updated
import java.util.stream.Collectors;

public class LoadBalancing {
  int N, out;
  int[][] coords;
  int[] xf, yf;

  // SETUP & INPUT
  public LoadBalancing() throws Exception {
    IOHandler io = new IOHandler();
        
    N = io.nextInt();
    out = io.nextInt();

    coords = new int[N][2];
    xf = new int[N]; int[] yf = new int[N];

    for (int i = 0; i < N; i++) {
      coords[i] = new int[] {io.nextInt(), io.nextInt()};
      xf[i] = coords[i][0] + 1; yf[i] = coords[i][1] + 1;
    }

    io.close();
  }

  // SOLUTION: looping through all combinations of the x & y coords (+ 1 cuz even numbers)
  public int bronze() {
    for (int x : xf) {
      for (int y : yf) {
        int[] sect = new int[4];

        for (int[] p : coords) {
          if (p[0] < x) {
            if (p[1] < y) sect[0]++;
            else sect[1]++;
          } else {
            if (p[1] < y) sect[2]++;
            else sect[3]++;
          }
        }

        out = Math.min(Collections.max(Arrays.stream(sect).boxed().collect(Collectors.toList())), out);
      }
    }

    // DONE!
    return out;
  }
}