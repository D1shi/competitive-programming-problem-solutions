import java.util.*;

public class HaybaleStack {
  IOHandler io;
  Map<Integer, Integer> farm;
  int[][] commands;
  final int N, S; // commands, size
  
  public HaybaleStack() throws Exception {
    io = new IOHandler();
    farm = new TreeMap<>();

    S = io.nextInt();
    N = io.nextInt();

    // put middle val(s)
    farm.put(S/2, 0);
    if (S % 2 == 0) farm.put(S/2 - 1, 0);

    // get commands
    commands = new int[N][2];
    for (int i = 0; i < N; i++) {
      commands[i][0] = io.nextInt();
      commands[i][1] = io.nextInt();
    }
  }

  public static void main(String[] args) throws Exception {
    HaybaleStack hs = new HaybaleStack();
    hs.io.println(hs.run()); hs.io.close();
  }

  public double run() {
    for (int[] c : commands) {
      for (int i = c[0] - 1; i < c[1]; i++) {
        if (farm.containsKey(i)) farm.replace(i, farm.get(i) + 1);
        else farm.put(i, 1);
      }
    }

    // get median
    if (S % 2 == 0) return (farm.get(S/2) + farm.get(S/2 - 1)) / 2;
    else return farm.get(S/2);
  }
}
