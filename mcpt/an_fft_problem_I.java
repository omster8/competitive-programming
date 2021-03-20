import java.util.*;

public class WLMOJfft1 {
    Scanner sc = new Scanner (System.in);
    int n = sc.nextInt();
    int[] input = new int[n+1];
    long[][] dp = new long[n+1][n+1];
    
    private long mod (long num1, int num2) {
        long answer = num1%num2;
        if (answer < 0) {
            answer += num2;
        }
        return answer;
    }
    
    public void stuff() {
        for (int i = 1; i < n+1; i++) {
            input[i] = sc.nextInt ();
        }
        for (int i = 1; i < n+1; i++) {
            dp[0][i] = 1;
        }
        for (int j = 1; j < n+1; j++) {   // y axis: the values of a
            for (int i = 1; i < n+1; i++) {   // x axis: the size of combinations
                if (i==1 && j==1) {
                    dp[1][1] = input[1];
                } else {
                    dp[i][j] = (dp[i-1][j-1]*input[j] + dp[i][j-1])%998244353; 
                }
                if (j==n) {
                    System.out.print (mod(dp[i][j], 998244353) + " ");
                }
            }
        }
    }
    
    public static void main(String[] args) {
        WLMOJfft1 w = new WLMOJfft1 ();
        w.stuff ();
    }
    
}