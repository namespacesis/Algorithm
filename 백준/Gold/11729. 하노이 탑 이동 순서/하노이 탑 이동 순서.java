import java.util.*;

class Main {
    static int N;
    static StringBuilder sb;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();

        sb = new StringBuilder();

        sb.append((int) Math.pow(2, N) - 1).append("\n");

        move(N, 1, 2, 3);

        System.out.print(sb.toString());

        scanner.close();
    }

    public static void move(int n, int start, int mid, int end) {
        if (n == 1) {
            sb.append(start).append(" ").append(end).append("\n");
        }
        else {
            move(n - 1, start, end, mid);
            sb.append(start).append(" ").append(end).append("\n");
            move(n - 1, mid, start, end);
        }
    }
}