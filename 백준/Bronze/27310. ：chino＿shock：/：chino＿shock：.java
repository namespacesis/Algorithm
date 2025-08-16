import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main extends Exception {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        String str = br.readLine();

        int length = str.length();
        int colone = 0;
        int under = 0;

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);

            if (ch == ':'){
                colone++;
            }

            if (ch == '_'){
                under++;
            }
        }

        int answer = length + colone + (under * 5);

        sb.append(answer);
        System.out.println(sb.toString());
    }
}