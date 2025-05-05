import java.util.*;

public class Main {
    static int[][] pad = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    static boolean[] visited = new boolean[10];
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int result = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int startX = -1, startY = -1;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (pad[i][j] == K) {
                    startX = i;
                    startY = j;
                }
            }
        }

        visited[K] = true;
        dfs(startX, startY, 1);
        System.out.println(result);
    }

    static void dfs(int x, int y, int count) {
        if (count == 9) {
            result++;
            return;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                int nextNum = pad[nx][ny];
                if (!visited[nextNum]) {
                    visited[nextNum] = true;
                    dfs(nx, ny, count + 1);
                    visited[nextNum] = false;
                }
            }
        }
    }
}