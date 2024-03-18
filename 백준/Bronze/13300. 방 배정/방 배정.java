import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int numStudents = Integer.parseInt(st.nextToken());
		int maxRoom = Integer.parseInt(st.nextToken());
		int arr[][] = new int[7][2];
		int result = 0;
		for(int i=1; i<=numStudents; i++) {
			st = new StringTokenizer(br.readLine());
			int gender = Integer.parseInt(st.nextToken());
			int grade = Integer.parseInt(st.nextToken());
			arr[grade][gender]++;
		}
		
		
		for(int i=1; i<=6; i++) {
			for(int j=0; j<2; j++) {
				if(arr[i][j] == 0) continue;
				else {
					if(arr[i][j] % maxRoom == 0) result += arr[i][j] / maxRoom;
					else result += arr[i][j] / maxRoom + 1;
					}
				}
			}
		bw.write(String.valueOf(result));
		bw.flush();
		bw.close();
		br.close();
	}

}