import java.util.Scanner;

class Main {
    static int N;
    static boolean[] arr = new boolean[101];
    static int res = 0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();

        for (int i = 0; i < N; i++) {
            int n = scanner.nextInt();
            if (arr[n]) res++;
            else arr[n] = true;
        }

        System.out.println(res);
        scanner.close();
    }
}