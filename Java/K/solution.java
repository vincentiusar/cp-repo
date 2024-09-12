package K;

import java.util.Scanner;

public class solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N;
        N = sc.nextInt();

        if (N <= 3) {
            System.out.println(-1);
            return;
        }

        int ans[] = new int[N];
        for (int i = 0; i < N; i++)
            ans[i] = i + 1;
        for (int i = 0; i < N - 2; i++) {
            int tmp = ans[i];
            ans[i] = ans[i+2];
            ans[i+2] = tmp;
        }

        for (int i = 0; i < N; i++) {
            System.out.print(ans[i]);
            if (i == N - 1) System.out.print("\n");
            else System.out.print(" ");
        }
    }
}