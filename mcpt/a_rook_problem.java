import java.util.*;

public class WLMOJRookProblem {
    Scanner sc = new Scanner (System.in);
    long n = Long.parseLong (sc.next());
    long k = Long.parseLong (sc.next());
    long answer;
    
    public long factorial (long num) {
        long factorialAnswer = 1;
        for (int i = 2; i <= num; i++) {
            factorialAnswer *= i;
        }
        return factorialAnswer;
    }
    
    public void stuff () {
        if (n == k) {
            answer = factorial(n);
        } else if (k > n) {
            answer = 0;
        } else if (n > k) {
            answer = factorial(n)*factorial(n)/(factorial(k)*factorial(n-k)*factorial(n-k));
        }
        System.out.print (answer);
    }
    
    public static void main(String[] args) {
        WLMOJRookProblem w = new WLMOJRookProblem ();
        w.stuff();
    }
    
}