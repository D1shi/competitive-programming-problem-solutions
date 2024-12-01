import java.util.*;

public class BlockGame {
  IOHandler io = new IOHandler();
  final int N; int[] out;
  Map<String, String> words;
  
  public BlockGame() throws Exception {
    io = new IOHandler();
    N = io.nextInt();
    out = new int[26];
    
    words = new HashMap<>();
    for (int i = 0; i < N; i++) words.put(io.nextStr(), io.nextStr());
  }

  public static void main(String[] args) throws Exception {
    BlockGame bg = new BlockGame();
    bg.permute(new String[bg.N], 0); bg.io.close();
  }

  public void permute(String[] prev, int depth) {
    if (depth == N) {
      // handle letters
      io.println(Arrays.toString(prev));
      return;
    }

    prev[depth] = (String) words.keySet().toArray()[depth];
    permute(prev, depth + 1);
    prev[depth] = (String) words.values().toArray()[depth];
    permute(prev, depth + 1);
  }
}
