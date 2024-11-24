public class RestStops {
  IOHandler io;
  int N, johnS, bessS;
  int[] grassPos, grassTaste;
  
  /*=
    REASONING:
    Start from highest stop and greedly choose stops depending on quality of grass 
    (it must be higher than previous quality). Then simulate the trip & get the sum.
  =*/

  public RestStops() throws Exception {
    io = new IOHandler();

    io.nextInt(); // path length - not used
    N = io.nextInt(); // number of stops
    johnS = io.nextInt(); // John's speed
    bessS = io.nextInt(); // Bessie's speed

    grassPos = new int[N];
    grassTaste = new int[N];

    for (int i = 0; i < N; i++) {
      grassPos[i] = io.nextInt();
      grassTaste[i] = io.nextInt();
    }
  }

  public static void main(String[] args) throws Exception {
    RestStops rs = new RestStops();
    rs.io.println(rs.run()); rs.io.close();
  }

  public long run() {
    // Mark good stops
    boolean[] good = new boolean[N];
    int maxTaste = -1;

    for (int i = N - 1; i >= 0; i--) {
      if (grassTaste[i] > maxTaste) {
        maxTaste = grassTaste[i];
        good[i] = true;
      }
    }

    // simulate 
    long totalTastiness = 0;
    int previousPosition = 0;

    for (int i = 0; i < N; i++) {
      if (good[i]) {
        int distance = grassPos[i] - previousPosition; // Distance from the last stop
        long timeGap = (long) (johnS - bessS) * distance;
        totalTastiness += grassTaste[i] * timeGap;
        previousPosition = grassPos[i]; // Update last position where Bessie stopped
      }
    }

    return totalTastiness;
  }
}

