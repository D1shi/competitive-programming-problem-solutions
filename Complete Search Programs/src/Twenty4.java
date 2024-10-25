import java.util.*;

public class Twenty4 {
  public static Integer evalExpression(String expr) {
    try {
      double result = (double) new ScriptEngineManager().getEngineByName("javascript").eval(expr);
      if (result == (int) result) {
        return (int) result;
      }
    } catch (Exception e) {
      return null;
    }
    return null;
  }

  public static int solve(int[] cards) {
    int maxVal = Integer.MIN_VALUE;
    int target = 24;
    String[] ops = {"+", "-", "*", "/"};
    
  }
}
