package L;

import java.util.Scanner;

public class solution {

    static String ask(int x) {
        Scanner sc = new Scanner(System.in);
        System.out.println(x);

        String res = sc.next();

        return res;
    }

    public static void main(String[] args) {
        int l = 1, r = 1000000000;
        while (l <= r) {
            int mid = (l + r)/2;
            String ans = ask(mid);
            if (ans.equals(">")) l = mid + 1;
            else if (ans.equals("<")) r = mid - 1;
            else break;
        }
    }
}