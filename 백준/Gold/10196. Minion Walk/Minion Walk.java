import java.io.*;
import java.util.*;

public class Main {
    public static int dx[] = {1, -1, 0, 0};
    public static int dy[] = {0, 0, 1, -1};

    static class Pair{
        int x,y;
        Pair(int x,int y){
            this.x = x;
            this.y = y;
        }
    }

    private static boolean canReach(char[][] wall) {
        Queue<Pair> q = new LinkedList<>();
        if (wall[0][0] == 'O') {
            q.add(new Pair(0, 0));
            wall[0][0] = 'M';
        }
        else return false;
        int nRows = wall.length;
        int nCols = wall[0].length;

        while (!q.isEmpty()) {
            Pair c = q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = c.x + dx[i];
                int ny = c.y + dy[i];

                if (0 <= nx && nx < nRows && 0 <= ny && ny < nCols && wall[nx][ny] == 'O') {
                    wall[nx][ny] = 'M';
                    q.add(new Pair(nx, ny));
                }
            }
        }

        if (wall[nRows - 1][nCols - 1] == 'M') {
            return true;
        }
        return false;
    }

    private static void prettyPrintWall(char[][] wall) {

        int nRows = wall.length;
        int nCols = wall[0].length;

        for (int j = 0; j < nCols; j++) {
            System.out.print("+---");
        }
        System.out.println("+");

        for (int i = 0; i < nRows; i++) {
            // print row contents
            for (int j = 0; j < nCols; j++) {
                switch (wall[i][j]) {
                    case 'X':
                        System.out.print("| X ");
                        break;
                    case 'O':
                        System.out.print("|   ");
                        break;
                    case 'M':
                        System.out.print("| M ");
                        break;

                }
            }
            System.out.println("|");
            // print row separator
            for (int j = 0; j < nCols; j++) {
                switch (wall[i][j]) {
                    case 'X':
                    case 'O':
                    case 'M':
                        System.out.print("+---");
                        break;
                }
            }
            System.out.println("+");
        }
    }

    /**
     *  Main Program
     */
    public static void main(String[] args) throws Exception {
        // read input
        Scanner scanner = new Scanner(System.in);
        int numCases = scanner.nextInt();

        for(int t = 1; t <= numCases; t++) {
            int nRows = scanner.nextInt();	// number of rows in wall
            int nCols = scanner.nextInt();	// number of columns in wall
            scanner.nextLine();				// skip to eol
            char[][] wall = new char[nRows][]; // the wall
            for (int i = 0; i < nRows; i++) {
                wall[i] = new char[nCols];
                String line = scanner.nextLine();
                for (int j = 0; j < nCols; j++) {
                    wall[i][j] = line.charAt(j);
                }
            }

            System.out.println("Case: " + t);// echo input

            boolean result = canReach(wall);					// check for solution
            prettyPrintWall(wall);			 // print the reachable parts of the room

            String outputMessage = result ? "can" : "cannot";		// choose output
            System.out.format("Minions %s cross the room%n", outputMessage);
        }
        scanner.close();					// close input stream
    }
}
