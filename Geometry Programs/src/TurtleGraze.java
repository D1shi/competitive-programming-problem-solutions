public class TurtleGraze {
  IOHandler io;
  Rect[] zones;

  public TurtleGraze() throws Exception {
    io = new IOHandler();

    int[] c = new int[] {io.nextInt(), io.nextInt(), io.nextInt(), io.nextInt()};
    zones = new Rect[io.nextInt() + 1];
    zones[0] = new Rect(c[0], c[1], c[2], c[3]);

    for (int i = 1; i < zones.length; i++) {
      zones[i] = new Rect(io.nextInt(), io.nextInt(), io.nextInt(), io.nextInt());
    }
  }

  public static void main(String[] args) throws Exception {
    TurtleGraze tg = new TurtleGraze();
    tg.io.println(tg.run()); tg.io.close();
  }

  public long run() {
    long out = zones[0].area; // field area
    for (int i = 1; i < zones.length; i++) if (zones[0].intersects(zones[i])) out -= zones[0].getIntersect(zones[1]).area;

    return out;
  }
}
