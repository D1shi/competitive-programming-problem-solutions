import java.util.*;
// import java.util.stream.Collectors;

public class CreatingStrings {
  static Set<String> strs = new HashSet<>();
  static List<Integer> sub = new ArrayList<>();
  static int n;
  static boolean[] chosen;
  static String s;
  static IOHandler io = new IOHandler();

  
  public CreatingStrings() throws Exception {
    s = io.nextStr();
    n = s.length();
    chosen = new boolean[n];

    io.close();
  }

  public Object[] bronze() {

    search();

    Object[] out = new Object[strs.size() + 1];
    out[0] = strs.size();

    /* 
    strs = strs.stream().sorted().collect(Collectors.toList());

    for (String str : ) ;
    */

    return out;
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


