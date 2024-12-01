public class Rect {
    // Varibles
    // (x1, y1) is bottom left, (x2, y2) is top right
    final int x1, y1, x2, y2;
    final long width, length;
    final long perimeter, area;
   
    // Initiation / Constructor method
    Rect(int x1, int y1, int x2, int y2) {
      // Set points 
      this.x1 = x1;
      this.y1 = y1;
      this.x2 = x2;
      this.y2 = y2;
   
      // Get width & length
      this.width = Math.abs(x2 - x1);
      this.length = Math.abs(y2 - y1);
   
      // Get perimeter & area
      this.perimeter = 2 * (width + length);
      this.area = width * length;
    }
   
    // Intersection methods
    boolean intersects(Rect r) {
      return !(this.x1 >= r.x2 || this.x2 <= r.x1 || this.y1 >= r.y2 || this.y2 <= r.y1);
    }
   
    Rect getIntersect(Rect r) {
      // Get rect
      Rect o = new Rect(Math.max(this.x1, r.x1), Math.max(this.y1, r.y1), Math.min(this.x2, r.x2), Math.min(this.y2, r.y2));
   
      // Check validity
      if (o.width <= 0 || o.length <= 0) return new Rect(0, 0, 0, 0);
      else return o;
    }
  }
