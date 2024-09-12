import java.util.*;

public class solution {

    static Scanner cin = new Scanner(System.in);

    public static int min(int a, int b) {
        if (a > b) 
            return b;
        return a;
    }

    public static void main(String[] args) {
        int dp[] = new int[1000001];


        int a = cin.nextInt(), b = cin.nextInt(), c = cin.nextInt();
        int t = cin.nextInt();
        
        for (int i = 0; i <= 1000000; i++) dp[i] = 1000000000;
        
        dp[a] = 1; dp[b] = 1; dp[c] = 1;
        dp[0] = 0;
        
        for (int i = 1; i <= 1000000; i++) {
            if (i - a >= 0) dp[i] = min(dp[i], dp[i-a] + 1);
            if (i - b >= 0) dp[i] = min(dp[i], dp[i-b] + 1);
            if (i - c >= 0) dp[i] = min(dp[i], dp[i-c] + 1);
        }

        // for (int i = 0; i < 20; i++) cout << dp[i] << " ";

        for (int i = 0; i < t; i++) {
            int n = cin.nextInt();

            System.out.println(dp[n] == 1000000000 ? 0 : dp[n]);
        }
    }
}
