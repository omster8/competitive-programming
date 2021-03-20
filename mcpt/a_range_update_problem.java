import java.util.*;

public class WLMOJRangeUpdate {

    static Scanner sc = new Scanner(System.in);
    int arrLength = sc.nextInt();
    int numUpdates = sc.nextInt();
    long answer[] = new long[arrLength];
    long diffArr[] = new long[arrLength + 1];
    int num1, num2, update;

    public void differenceArray() {
        diffArr[0] = answer[0];
        for (int i = 1; i < arrLength; i++) {
            diffArr[i] = answer[i] - answer[i - 1];
        }
    }

    public void updateRange() {
        diffArr[num1] += update;
        diffArr[num2 + 1] -= update;
    }

    public void stuff() {
        for (int i = 0; i < arrLength; i++) {
            answer[i] = sc.nextLong();
        }
        differenceArray();
        for (int i = 0; i < numUpdates; i++) {
            num1 = (sc.nextInt()) - 1;
            num2 = (sc.nextInt()) - 1;
            update = sc.nextInt();
            updateRange();
        }
        answer[0] = diffArr[0];
        System.out.print(answer[0] + " "); 
        for (int j = 1; j < arrLength; j++) {
            answer[j] = diffArr[j] + answer[j - 1];
            System.out.print(answer[j] + " ");
        }
    }

    public static void main(String[] args) {
        WLMOJRangeUpdate w = new WLMOJRangeUpdate();
        w.stuff();
    }

}