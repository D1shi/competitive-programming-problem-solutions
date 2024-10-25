/*
 MADE BY DISHI

 code to put in main:
		RotateNShift rs = new RotateNShift();
		for (Object i : rs.run()) {
			rs.io.print(i + " ");
		}
		rs.io.close();
*/

import java.util.*;
import java.util.stream.*;

public class RotateNShift {
  int N, A, T;
  List<Integer> active, cows;
  IOHandler io = new IOHandler();

  public RotateNShift() throws Exception {
    N = io.nextInt(); A = io.nextInt(); T = io.nextInt();
    active = new ArrayList<>(); cows = new ArrayList<>();

    for (int i = 0; i < A; i++) active.add(io.nextInt());
    cows = IntStream.range(0, N).boxed().toList();
  }

  public Object[] run() {
    /*
     * REASONING:
     * Use a new array list to store all the changes
     * we do to the orginal list, then change the orginal 
     * @ end of the step
     */

    for (int t = 0; t < T; t++) {
      // STEP 1: Change the order of the cows
      List<Integer> Ncows = new ArrayList<>(cows);
      List<Integer> NA = new ArrayList<>(active);

      for (int i = 0; i < A; i++) {
        // STEP 1A: get active cow
        int a = active.get(i);
        
        // STEP 2: Change active positions by 1. If it goes oversize, set to 0
        if (a == Ncows.size() - 1) NA.set(i, 0);
        else NA.set(i, a + 1);

        // STEP 1B: get cow to switch with
        int Na;

        // if out of bounds, get the first index pos in A
        try {
          Na = active.get(i + 1);
        } catch (Exception e) {
          Na = active.get(0);
        }

        // STEP 1C: Set new cow to new position
        Ncows.set(Na, cows.get(a));
      }

      // and then replace the orginals
      cows = Ncows;
      active = NA;
    }

    return cows.toArray();
  }
}
