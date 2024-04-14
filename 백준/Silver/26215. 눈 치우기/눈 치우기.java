import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());

        st = new StringTokenizer(br.readLine());
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 0; i < N; i++) {
            pq.add(Integer.parseInt(st.nextToken()));
        }

        int res = 0;

        while (!pq.isEmpty()) {
            int a = pq.poll();

            if (pq.isEmpty()) {
                res += a;
                break;
            }

            int b = pq.poll();
            res += b;
            pq.add(a - b);
        }

        if (res > 1440) {
            System.out.println(-1);
        }
        else {
            System.out.println(res);
        }
    }
}