import java.util.*;

public class WLMOJKnapsack {

    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int w = sc.nextInt();
    int[] weights = new int[n];
    int[] values = new int[n];
    int[][] nums = new int[w + 1][n + 1];

    public void stuff() {
        for (int i = 0; i < n; i++) {
            weights[i] = sc.nextInt();
            values[i] = sc.nextInt();
        }
        int temp = 0;
        boolean temporary = false;
        for (int i = 1; i < n + 1; i++) {     // y axis --> # of pieces
            for (int j = 1; j < w + 1; j++) {     // x axis --> capacity
                temporary = false;
                if (j / weights[i - 1] > 0) {
                    nums[j][i] = values[i - 1];
                    temporary = true;
                }
                if (temporary == true) {
                    nums[j][i] += nums[j - weights[i - 1]][i - 1];
                }
                nums[j][i] = Math.max(nums[j][i], nums[j][i - 1]);
                if (nums[j][i] > temp) {
                    temp = nums[j][i];
                }
            }
        }
        System.out.print(temp);
    }

    public static void main(String[] args) {
        WLMOJKnapsack w = new WLMOJKnapsack();
        w.stuff();
    }

}