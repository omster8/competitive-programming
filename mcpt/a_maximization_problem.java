import java.util.*;

public class WLMOJMaximization {
    Scanner sc = new Scanner (System.in);
    long n = sc.nextLong ();
   
    public void stuff () {
        long first = n/3;
        long second = (n-first)/2;
        long third = n-first-second;
        System.out.print (first*second*third + first*second + first*third + second*third);
    }
    
    public static void main(String[] args) {
        WLMOJMaximization w = new WLMOJMaximization ();
        w.stuff ();
    }
    
}