import java.util.Scanner;
import java.util.TreeSet;

public class MicrowaveInput {
    // Generate valid numbers only once and store them in a TreeSet
    private static final TreeSet<Integer> validNumbers = generateValidNumbers();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();

        // Process each test case
        while (T-- > 0) {
            int k = scanner.nextInt();
            System.out.println(findClosest(validNumbers, k));
        }
        scanner.close();
    }

    // Generate all possible valid numbers with "down" and "right" movements
    private static TreeSet<Integer> generateValidNumbers() {
        TreeSet<Integer> numbers = new TreeSet<>();

        // 4x3 keypad grid layout with 0 in the bottom middle
        Integer[][] keypad = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {null, 0, null}
        };

        // DFS to generate all valid numbers starting from each valid key
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                dfs(keypad, i, j, "", numbers, 0); // Start DFS from each valid key
            }
        }

        return numbers;
    }

    // Depth-first search to create numbers based on "down" and "right" movements
    private static void dfs(Integer[][] keypad, int i, int j, String path, TreeSet<Integer> numbers, int depth) {
        // Out of bounds or invalid key or depth too long
        if (i >= 4 || j >= 3 || keypad[i][j] == null) return;

        // Add 1 to depth
        depth++;

        // Append the current key to the path
        String currentKey = String.valueOf(keypad[i][j]);
        String newPath = path + currentKey;
        int n = 0;

        // Add the number to the set only if the new path is not empty
        if (!newPath.isEmpty()) {
            n = Integer.parseInt(newPath);
        } else if (depth > 1) return; // return if depth is >1 & empty, we dont want to continue an empty path!

        // If new path length is 4 or n > 200, we stop because inputs are <= 200
        if (newPath.length() >= 4 || n > 200) return;

        // Add path to tree set
        numbers.add(n);
        
        // Allow pressing the same key multiple times
        dfs(keypad, i, j, newPath, numbers, depth); // Increment depth

        // Move with updated path recursively
        dfs(keypad, i + 1, j, newPath, numbers, depth); // Move down
        dfs(keypad, i, j + 1, newPath, numbers, depth); // Move right

        // Move with non-updated path recursively (for skipping keys)
        dfs(keypad, i + 1, j, path, numbers, depth); // Move down
        dfs(keypad, i, j + 1, path, numbers, depth); // Move right
    }

    // Find the closest number to k using TreeSet methods
    private static int findClosest(TreeSet<Integer> validNumbers, int k) {
        Integer floor = validNumbers.floor(k);  // Closest number <= k
        Integer ceiling = validNumbers.ceiling(k);  // Closest number >= k

        // If no floor or ceiling, return 180 as a fallback
        if (floor == null && ceiling == null) return 180;
        if (floor == null) return ceiling;
        if (ceiling == null) return floor;

        // Compare distances to k to determine closest number
        if (Math.abs(k - floor) <= Math.abs(k - ceiling)) {
            return floor;
        } else {
            return ceiling;
        }
    }
}
