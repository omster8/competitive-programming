import java.util.*;

public class WLMOJFactorial {

    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    private int findTrailingZeros(int num) {
        int numTrailing = 0;
        int temp;
        for (int i = 1; true; i++) {
            temp = num / ((int) (Math.pow(5, i)));
            if (temp == 0) {
                break;
            }
            numTrailing += temp;
        }
        return numTrailing;
    }

    public void stuff() {
        int start = 4 * n;
        int end = 5 * n;
        int mid = 9 * n / 2;
        int temp;
        boolean noAnswer = false;
        if (n == 0) {
            System.out.print(1);
        } else {
            while (true) {
                temp = findTrailingZeros(mid);
                if (temp == n) {
                    mid -= mid % 5;
                    break;
                } else if (temp < n) {
                    start = mid;
                    mid = (start + end) / 2;
                } else if (temp > n) {
                    end = mid;
                    mid = (start + mid) / 2;
                }
                if (start == mid || end == mid) {
                    if (findTrailingZeros(end) == n) {
                        mid = end;
                        break;
                    } else {
                        noAnswer = true;
                        break;
                    }
                }
            }
            if (noAnswer == false) {
                System.out.print(mid);
            } else {
                System.out.print("No solution");
            }
        }
    }

    public static void main(String[] args) {
        WLMOJFactorial w = new WLMOJFactorial();
        w.stuff();
    }

}