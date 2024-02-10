import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] line = br.readLine().split(" ");
        int N = Integer.parseInt(line[0]); // 성의 행
        int M = Integer.parseInt(line[1]); // 성의 열

        boolean[] rowCheck = new boolean[N]; // 각 행에 경비원이 있는지 체크
        boolean[] colCheck = new boolean[M]; // 각 열에 경비원이 있는지 체크

        for (int i = 0; i < N; i++) {
            String row = br.readLine();
            for (int j = 0; j < M; j++) {
                if (row.charAt(j) == 'X') { // 경비원이 있는 경우
                    rowCheck[i] = true; // 해당 행에 경비원이 있음을 표시
                    colCheck[j] = true; // 해당 열에 경비원이 있음을 표시
                }
            }
        }

        int rowCount = 0; // 경비원이 없는 행의 수
        for (boolean row : rowCheck) {
            if (!row) rowCount++;
        }

        int colCount = 0; // 경비원이 없는 열의 수
        for (boolean col : colCheck) {
            if (!col) colCount++;
        }

        // 경비원이 없는 행과 열 중 더 많은 쪽이 최소 추가해야 하는 경비원의 수
        bw.write(Math.max(rowCount, colCount) + "\n");

        br.close();
        bw.flush();
        bw.close();
    }
}