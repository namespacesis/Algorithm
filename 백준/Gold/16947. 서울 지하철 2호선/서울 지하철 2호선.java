import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static List<Integer>[] arr;
    static boolean[] visited;
    static int[] parent;
    static boolean[] cycle;
    static int[] dist;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        arr = new ArrayList[N];
        visited = new boolean[N];
        parent = new int[N];
        cycle = new boolean[N];
        dist = new int[N];

        for (int i = 0; i < N; i++) {
            arr[i] = new ArrayList<>();
            parent[i] = -1;
        }

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            arr[a].add(b);
            arr[b].add(a);
        }

        for (int i = 0; i < N; i++) {
            if (dfs(i)) break;
        }

        findDistance();

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sb.append(dist[i]).append(" ");
        }
        System.out.println(sb);
    }

    static boolean dfs(int node) {
        visited[node] = true;

        for (int next : arr[node]) {
            if (!visited[next]) {
                parent[next] = node;
                if (dfs(next)) return true;
            }
            else if (next != parent[node]) {
                int cur = node;
                while (cur != next) {
                    cycle[cur] = true;
                    cur = parent[cur];
                }
                cycle[next] = true;
                return true;
            }
        }
        visited[node] = false;
        return false;
    }

    static void findDistance() {
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < N; i++) {
            if (cycle[i]) {
                q.add(i);
                dist[i] = 0;
            }
            else {
                dist[i] = -1;
            }
        }

        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int next : arr[cur]) {
                if (dist[next] == -1) {
                    dist[next] = dist[cur] + 1;
                    q.add(next);
                }
            }
        }
    }
}