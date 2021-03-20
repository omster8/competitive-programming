import java.util.*;

public class WLMOJAmazingMaze {
    Scanner sc = new Scanner (System.in);
    String temp = sc.nextLine ();
    String input = sc.nextLine ();
    
    public void stuff () {
        for (int i = 0; i < input.length()-1; i++) {
            if (input.charAt(i) == 'A') {
                if (input.charAt(i-1) == 'G' && input.charAt(i+1) == 'G') {
                    System.out.println ("Down");
                } else {
                    System.out.println ("Up");
                }
            } else if (input.charAt(i) == 'a') {
                if (input.charAt(i-1) == 'G' && input.charAt(i+1) == 'G') {
                    System.out.println ("Up");
                } else {
                    System.out.println ("Down");
                }
            } else if (input.charAt(i) == 'O') {
                if (input.charAt(i-1) == 'G' || input.charAt(i+1) == 'G') {
                    System.out.println ("Down");
                } else {
                    System.out.println ("Up");
                }
            } else if (input.charAt(i) == 'o') {
                if (input.charAt(i-1) == 'R' && input.charAt(i+1) == 'R') {
                    System.out.println ("Down");
                } else {
                    System.out.println ("Up");
                }
            } else if (input.charAt(i) == 'X') {
                if ((input.charAt(i-1) == 'R' && input.charAt(i+1) == 'G') || (input.charAt(i-1) == 'G' && input.charAt(i+1) == 'R')) {
                    System.out.println ("Down");
                } else {
                    System.out.println ("Up");
                }
            }
        }
    }
    
    public static void main(String[] args) {
        WLMOJAmazingMaze w = new WLMOJAmazingMaze ();
        w.stuff ();
    }
    
}