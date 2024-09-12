import java.util.*;

public class solution {

    static Scanner cin = new Scanner(System.in);

    public static void main(String[] args) {
        int n = cin.nextInt();

        boolean reachable[][] = new boolean[n][n];
        int arr[][] = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                arr[i][j] = cin.nextInt();

        reachable[0][0] = true;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j <= i; j++) {
            if (reachable[i][j]) {
                if (arr[i][j] >= arr[i+1][j])
                    reachable[i+1][j] = true;
                if (arr[i][j] >= arr[i+1][j+1])
                    reachable[i+1][j+1] = true;
            }
            }
        }

        boolean bisa = false;
        for (int j = 0; j < n; j++)
            if (reachable[n-1][j])
                bisa = true;

        System.out.println(bisa ? "BISA" : "MUSTAHIL");
    }
}
