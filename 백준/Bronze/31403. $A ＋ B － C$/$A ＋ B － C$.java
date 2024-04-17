import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int A = Integer.parseInt(br.readLine());
        int B = Integer.parseInt(br.readLine());
        int C = Integer.parseInt(br.readLine());

        int res1 = A + B - C;
        int res2 = Integer.parseInt(Integer.toString(A) + Integer.toString(B)) - C;

        System.out.println(res1);
        System.out.println(res2);
    }
}