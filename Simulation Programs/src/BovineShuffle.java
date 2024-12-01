import java.util.*;

public class BovineShuffle {
  IOHandler io;
  int N; int[] ids;
  Map<Integer, Integer> dance;

  public BovineShuffle() throws Exception {
    io = new IOHandler();
    N = io.nextInt();

    dance = new HashMap<>();
    for (int i = 0; i < N; i++) dance.put(io.nextInt() - 1, i);

    ids = new int[N];
    for (int i = 0; i < N; i++) ids[i] = io.nextInt();
  }

  public static void main(String[] args) throws Exception {
    BovineShuffle bs = new BovineShuffle();
    bs.io.printItems(bs.run(3)); bs.io.close();
  }

  public int[] run(int r) {
    for (int $ = 0; $ < r; $++) {
      int[] newID = new int[N];

      for (int i = 0; i < ids.length; i++) {
        newID[dance.get(i)] = ids[i];
      }

      ids = newID;
    }

    return ids;
  }
}