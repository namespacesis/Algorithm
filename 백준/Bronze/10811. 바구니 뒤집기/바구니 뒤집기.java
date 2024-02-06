import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int basket = sc.nextInt();
        int M = sc.nextInt();

        int[] basketArray = new int[basket];
        for(int i = 0; i < basket; i++){
            basketArray[i] = i+1;
        }

        for(int i = 0; i < M; i++){
            int from = sc.nextInt()-1;
            int to = sc.nextInt()-1;

            while(from < to){
                int temp = basketArray[from];
                basketArray[from] = basketArray[to];
                basketArray[to] = temp;
                from++;
                to--;
            }
        }

        for(int i = 0; i < basket; i++){
            System.out.print(basketArray[i]+ " ");
        }
    }
}