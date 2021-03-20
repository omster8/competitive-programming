import java.util.*;

public class WLMOJCoinProb {
    Scanner sc = new Scanner (System.in);
    int n = sc.nextInt ();
    int s = sc.nextInt ();
    int[] nums = new int[n];
    boolean[] arr = new boolean[s+1];
    
    public void stuff () {
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt ();
        }
        arr[0] = true;
        for (int i = 0; i < s+1; i++) {
            if (arr[i] == true) {
                for (int j = 0; j < n; j++) {
                    if (i+nums[j] < s+1) {
                        arr[i+nums[j]] = true;
                    } 
                }
            }
        }
        if (arr[s] == true) {
            System.out.print ("YES");          
        } else {
            System.out.print ("NO");
        }
    }
    
    public static void main(String[] args) {
        WLMOJCoinProb w = new WLMOJCoinProb ();
        w.stuff ();
    }
    
}