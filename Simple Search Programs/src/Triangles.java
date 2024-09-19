public class Triangles {
  public int[][] coords;
  public int N;

  // SETUP & INPUT
  public Triangles() throws Exception {
    IOHandler io = new IOHandler();
        
    N = io.nextInt();
    coords = new int[N][2];

    for (int i = 0; i < N; i++) coords[i] = new int[] {io.nextInt(), io.nextInt()};
    io.close();
  }

  // SOLUTION: loop through all pairs of 3 points and check
  public int bronze() {
    int out = 0;

    for (int i = 0; i < coords.length; i++) {
      for (int j = 0; j < coords.length; j++) {
        for (int k = 0; k < coords.length; k++) {
          if (coords[i][1] == coords[j][1] && coords[i][0] == coords[k][0]) {
              int a = Math.abs((coords[j][0] - coords[i][0]) * (coords[k][1] - coords[i][1]));
              out = Math.max(out, a);
          }
        }
      }
    }

    return out;
  }
}