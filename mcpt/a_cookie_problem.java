import java.util.*;

public class WLMOJCookie {

    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    long[] max = new long[n + 2];
    int[] input = new int[n + 2];
    long answer = 0, temp = 0;

    public void stuff() {
        for (int i = 2; i < n + 2; i++) {
            input[i] = sc.nextInt();
            max[i] = input[i];
            if (max[i] > answer) {
                answer = max[i];
            }
        }
        for (int i = 2; i < n + 2; i++) {
            if (i == 2) {
                temp = 0;
            } else {
                temp = Math.max(temp, max[i-2]);
            }
            max[i] += temp;
            if (max[i] > answer) {
                answer = max[i];
            }
        }
        System.out.print(answer);
    }

    public static void main(String[] args) {
        WLMOJCookie w = new WLMOJCookie();
        w.stuff();
    }

}