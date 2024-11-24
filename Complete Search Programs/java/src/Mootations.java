import java.util.*;

public class Mootations {
  IOHandler io;
  String gene, s;
  List<String> poGenes;
  
  public Mootations() throws Exception {
    io = new IOHandler();
    gene = io.nextStr();

    poGenes = new ArrayList<>();
    s = "";
  }

  public static void main(String[] args) throws Exception {
    Mootations mt = new Mootations();
    mt.io.println(mt.run()); mt.io.close();
  }

  public int run() {
    generate(0);
    List<String> out = new ArrayList<>(poGenes);

    for (String g : poGenes) {
      char prev = ' ';

      for (char c : g.toCharArray()) {
        if (prev == c) {
          out.remove(out.indexOf(g));
          break;
        }
        prev = c;
      }
    }

    return out.size();
  }

  private void generate(int k) {
    if (k == gene.length()) { poGenes.add(s); return; }
    else {
      String prev = s;
      generate(k + 1);
      s += gene.toCharArray()[k];
      generate(k + 1);
      s = prev;
    }
  }
}