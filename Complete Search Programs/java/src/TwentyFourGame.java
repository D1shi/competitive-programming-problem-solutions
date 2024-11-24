import java.util.*;

public class TwentyFourGame {
    
    // Main method to evaluate the largest result <= 24 for each hand
    public static int solve(int[] cards) {
        int maxVal = Integer.MIN_VALUE;
        char[] operators = {'+', '-', '*', '/'};

        for (int[] perm : getPermutations(cards)) {
            for (char op1 : operators) {
                for (char op2 : operators) {
                    for (char op3 : operators) {
                        maxVal = Math.max(maxVal, tryAllOrders(perm, op1, op2, op3));
                    }
                }
            }
        }
        return maxVal;
    }

    // Evaluates all possible parenthesized orders for three operators on four cards
    private static int tryAllOrders(int[] perm, char op1, char op2, char op3) {
        int[] results = new int[] {
            evaluate(evaluate(evaluate(perm[0], perm[1], op1), perm[2], op2), perm[3], op3),
            evaluate(evaluate(perm[0], evaluate(perm[1], perm[2], op2), op1), perm[3], op3),
            evaluate(perm[0], evaluate(evaluate(perm[1], perm[2], op2), perm[3], op3), op1),
            evaluate(perm[0], evaluate(perm[1], evaluate(perm[2], perm[3], op3), op2), op1),
            evaluate(evaluate(perm[0], perm[1], op1), evaluate(perm[2], perm[3], op3), op2)
        };
        int maxValid = Integer.MIN_VALUE;
        for (int result : results) {
            if (result != Integer.MIN_VALUE && result <= 24) {
                maxValid = Math.max(maxValid, result);
            }
        }
        return maxValid;
    }

    // Perform basic arithmetic and validate division
    private static int evaluate(int a, int b, char op) {
        return switch (op) {
            case '+' -> a + b;
            case '-' -> a - b;
            case '*' -> a * b;
            case '/' -> (b != 0 && a % b == 0) ? a / b : Integer.MIN_VALUE;
            default -> Integer.MIN_VALUE;
        };
    }

    // Generate all permutations of the array
    private static List<int[]> getPermutations(int[] array) {
        List<int[]> result = new ArrayList<>();
        permute(array, 0, result);
        return result;
    }

    private static void permute(int[] array, int index, List<int[]> result) {
        if (index == array.length) result.add(array.clone());
        else {
            for (int i = index; i < array.length; i++) {
                swap(array, i, index);
                permute(array, index + 1, result);
                swap(array, i, index);
            }
        }
    }

    private static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            int[] cards = {scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt()};
            System.out.println(solve(cards));
        }
        scanner.close();
    }
}


