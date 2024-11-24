import java.io.IOException;
import java.util.*;

public class BovineGenomics {
  int N; int M;
  char[][] spottG, plainG;

  static final Map<Character, Integer> GENOME_ID =
  Map.ofEntries(Map.entry('A', 0), Map.entry('T', 1), Map.entry('C', 2), Map.entry('G', 3));

  // SETUP & INPUT
  public BovineGenomics() throws IOException {
    IOHandler io = new IOHandler();

    N = io.nextInt();
    M = io.nextInt();
    spottG = new char[N][M];
    plainG = new char[N][M];

    for (int i = 0; i < N; i++) {
      spottG[i] = io.nextStr().toCharArray();
    }

    for (int i = 0; i < N; i++) {
      plainG[i] = io.nextStr().toCharArray();
    }

    io.close();
  }

  // SOLUTION - Looping through each char in each genome to find if they have any common char
  public int bronze() {
    int out = 0;

    for (int i = 0; i < M; i++) {
      Set<Integer> spottC = new HashSet<>();
      Set<Integer> plainC = new HashSet<>();

      // ADDING - Adding chars to sets
      for (int gI = 0; gI < N; gI++) {
        char[] gA = spottG[gI];
        spottC.add(GENOME_ID.get(gA[i]));
        gA = plainG[gI];
        plainC.add(GENOME_ID.get(gA[i]));
      }


      // INTERSECT - Finding common elements by intersect the 2 sets
      Set<Integer> common = new HashSet<>(spottC);
      common.retainAll(plainC);
      
      // CHECK - Check if there isn't anything common
      if (common.isEmpty()) out++;
    }

    return out;
  }

  // SOLUTION: Looping through each unqiue pair & and making a code for it to see if there are any common codes
  public int sliver() {
    int out = 0;

    for (int i = 0; i < M; i++) {
      for (int j = i + 1; j < M; j++) {
        for (int k = j + 1; k < M; k++) {
          Set<Integer> spottC = new HashSet<>();
          Set<Integer> plainC = new HashSet<>();

          // ADDING - Adding unique code to sets
          for (int gI = 0; gI < N; gI++) {
            char[] gA = spottG[gI];
            spottC.add(GENOME_ID.get(gA[i]) * 16 + GENOME_ID.get(gA[j]) * 4 + GENOME_ID.get(gA[k]));
            gA = plainG[gI];
            plainC.add(GENOME_ID.get(gA[i]) * 16 + GENOME_ID.get(gA[j]) * 4 + GENOME_ID.get(gA[k]));
          }

          // INTERSECT - Finding common codes by intersecting the 2 sets
          Set<Integer> common = new HashSet<>(spottC);
          common.retainAll(plainC); // O(N) cuz plainC.len = N
  
          // CHECK - Check if there isn't anything common
          if (common.isEmpty()) out++;
        }
      }
    }

    return out;
  }
}