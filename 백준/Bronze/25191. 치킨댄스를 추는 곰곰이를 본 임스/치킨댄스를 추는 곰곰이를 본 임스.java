import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int halfOfFirst = Integer.parseInt(st.nextToken()) / 2;
        int second = Integer.parseInt(st.nextToken());
        
        int result = Math.min(n, halfOfFirst + second);
        
        System.out.println(result);
    }
}