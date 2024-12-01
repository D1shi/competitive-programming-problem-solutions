import java.util.*;

public class CreatingStrings {
  Set<String> strs = new HashSet<>();
  List<Integer> sub = new ArrayList<>();
  int n;
  boolean[] chosen;
  String s;
  IOHandler io;

  /*=
      REASONING:
      todo: write explanation
    =*/
  public CreatingStrings() throws Exception {
    io = new IOHandler();
    s = io.nextStr();
    n = s.length();
    chosen = new boolean[n];
  }

  public static void main(String[] args) throws Exception {
    CreatingStrings cs = new CreatingStrings();
    cs.search();

    cs.io.println(cs.strs.size());

    for (String str : cs.strs.stream().sorted().toList()) cs.io.println(str);
    cs.io.close();
  }

  public void search() {
    if (sub.size() == n) {
      String sa = "";
      for (int i : sub) {
        sa += s.toCharArray()[i];
      }
      strs.add(sa);
    } else {
      for (int i = 0; i < n; i++) {
        if (chosen[i]) continue;
        chosen[i] = true;
        sub.add(i);
        search();
        chosen[i] = false;
        sub.remove(sub.size() - 1);
      }
    }
  }
}


