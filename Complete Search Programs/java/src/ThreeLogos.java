/*=
  MADE BY DISHI
 
  code to put in main:
    ThreeLogos tl = new ThreeLogos();
    tl.run(); tl.io.close();
=*/

import java.util.*;

public class ThreeLogos {
  int[][] logos;
  IOHandler io = new IOHandler();

  public ThreeLogos() throws Exception {
    logos = new int[3][2];
    for (int i = 0; i < logos.length; i++) {
      logos[i] = new int[] {io.nextInt(), io.nextInt()};
    }
  }

  public void run() {
    // STEP 1: Check for validility
    int a1 = logos[0][0] * logos[0][1];
    int a2 = logos[1][0] * logos[1][1];
    int a3 = logos[2][0] * logos[2][1];

    /*=
      REASONING:
        If square root of sums of the areas of the logos is an int, 
        that means you can put the logos in a perfect square 
    =*/
    
    int max = (int) Math.sqrt((double) a1 + a2 + a3);

    if ((double) max != Math.sqrt((double) a1 + a2 + a3)) {
      io.println("-1");
      return;
    }

    // STEP 2: Use rotate mask to try all rotations of the logos
    for (int rtMask = 0; rtMask < 8; rtMask++) {
      int placed = 0;

      // STEP 2a: make grid empty
      char[][] grid = new char[max][max];
      for (int i = 0; i < max; i++) {
        Arrays.fill(grid[i], ' ');
      }

      // STEP 2b: try to put the logo
      whole: for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
          // If there is an empty space...
          if (grid[i][j] == ' ') {
            if (placed == 3) break whole;

            int w = logos[placed][0];
            int h = logos[placed][1];

            // Rotate logo if it meets specfic conditions
            if ((rtMask & (1 << placed)) != 0) {
              int store = w;
              w = h;
              h = store;
            }

            // STEP 2C: Put logo on grid
            for (int r = i; r < i + h; r++) {
              for (int c = j; c < j + w; c++) {
                // If it touches another logo or goes off the grid, try again w/ other position
                if (r >= max || c >= max || grid[r][c] != ' ') {
                  continue whole;
                }

                // Use ascii codes to get char to set the tiles
                grid[r][c] = (char) (placed + 'A');
              }
            }

            // Add placed by 1 so we know we placed a logo
            placed++;
          }
        }
      }

      // STEP 3: Print output
      if (placed == 3) {
        io.println(max);
        for (char[] cs : grid) {
          io.println(new String(cs));
        }
        return;
      }
    }

    // STEP 3A: this prints if there is no solution
    io.println("-1");
  }
}
