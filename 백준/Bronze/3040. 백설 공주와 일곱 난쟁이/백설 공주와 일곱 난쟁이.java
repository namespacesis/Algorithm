import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    static int[] arr = new int[9];
    static int res = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 0; i < 9; i++) {
            res += arr[i] = Integer.parseInt(br.readLine());
        }

        for (int i = 0; i < 8; i++) {
            for (int j = i + 1; j < 9; j++) {
                if (arr[i] + arr[j] == res - 100) {
                    arr[i] = arr[j] = 0;
                    break;
                }
            }
            if (arr[i] == 0) break;
        }

        for (int i = 0; i < 9; i++) {
            if (arr[i] != 0) {
                System.out.println(arr[i]);
            }
        }

        br.close();
    }
}