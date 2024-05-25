import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int K;
        int[] dpA = new int[46];
        int[] dpB = new int[46];
        dpA[0] = 1;
        dpB[0] = 0;
        dpA[1] = 0;
        dpB[1] = 1;

        Scanner sc = new Scanner(System.in);
        K = sc.nextInt();
        for (int i = 2; i <= K; i++) {
            dpA[i] = dpA[i - 1] + dpA[i - 2];
            dpB[i] = dpB[i - 1] + dpB[i - 2];
        }
        System.out.println(dpA[K] + " " + dpB[K]);
    }
}