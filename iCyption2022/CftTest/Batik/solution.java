import java.util.*;

public class solution {

    static Scanner cin = new Scanner(System.in);

    public static void main(String[] args) {
        int n = cin.nextInt();
        char grid[][] = new char[n][n];

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                grid[i][j] = ' ';

        for (int i = 0; i < n; i++) grid[i][0] = '*';
        for (int i = 0; i < n; i++) grid[0][i] = '*';
        for (int i = 0; i < n; i++) grid[i][n-1] = '*';
        for (int i = 0; i < n; i++) grid[n-1][i] = '*';
        for (int i = 0; i < n; i++) grid[i][i] = '*';
        for (int i = 0; i < n; i++) grid[i][n-i-1] = '*';

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(grid[i][j]);
            }
            System.out.println();
        }
    }
}
