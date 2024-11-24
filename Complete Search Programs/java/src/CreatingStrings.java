/*=
  MADE BY DISHI
 
  code to put in main:
    CreatingStrings cs = new CreatingStrings();
		cs.bronze(); cs.io.close();
=*/

import java.util.*;

public class CreatingStrings {
  Set<String> strs = new HashSet<>();
  List<Integer> sub = new ArrayList<>();
  int n;
  boolean[] chosen;
  String s;
  IOHandler io;

  
  public CreatingStrings() throws Exception {
    io = new IOHandler();
    s = io.nextStr();
    n = s.length();
    chosen = new boolean[n];
  }

  public void bronze() {
    /*=
      REASONING:
      todo: write explanation
    =*/
    search();

    io.println(strs.size());

    for (String str : strs.stream().sorted().toList()) io.println(str);
    io.close();
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


