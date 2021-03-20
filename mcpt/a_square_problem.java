import java.util.*;

public class WLMOJSquareProblem {
    Scanner sc = new Scanner (System.in);
    int num = sc.nextInt ();
    long input1[] = new long[num];
    long input2[] = new long[num];
    String answer[] = new String[num];
    
    public void stuff () {
        for (int i = 0; i < num; i++) {
            input1[i] = Long.parseLong (sc.next());
            input2[i] = Long.parseLong (sc.next());
        }
        for (int i = 0; i < num; i++) {
            if (input1[i]-input2[i] == 1 || input1[i]-input2[i] == -1) {
                for (int x = 2; x <= Math.round (Math.sqrt(input1[i]+input2[i])); x++) {
                    if ((input1[i]+input2[i]) % x == 0) {
                        answer[i] = "NO";
                        break;
                    } else {
                        answer[i] = "YES";
                    }
                }
            } else {
                answer[i] = "NO";
            }
        }
        for (int i = 0; i < num; i++) {
            System.out.println (answer[i]);
        }
    }
    
    public static void main(String[] args) {
        WLMOJSquareProblem w = new WLMOJSquareProblem ();
        w.stuff ();
    }
    
}