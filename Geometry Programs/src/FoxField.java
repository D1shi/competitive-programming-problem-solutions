public class FoxField {
  IOHandler io;
  Rect f1, f2;

  public FoxField() throws Exception {
    io = new IOHandler();
    f1 = new Rect(io.nextInt(), io.nextInt(), io.nextInt(), io.nextInt());
    f2 = new Rect(io.nextInt(), io.nextInt(), io.nextInt(), io.nextInt());
  }

  public static void main(String[] args) throws Exception {
    FoxField ff = new FoxField();
    ff.io.println(ff.run()); ff.io.close();
  }

  public long run() {
    long out = f1.area + f2.area;
    if (f1.intersects(f2)) out -= f1.getIntersect(f2).area;
    return out;
  }
}

