import java.util.*;
import java.math.BigInteger;

public class solution {

    static Scanner cin = new Scanner(System.in);

    public static boolean isPalindrome(String s1) {
        int l = 0, r = s1.length() - 1;
        while (l < r) {
            if (s1.charAt(l) != s1.charAt(r)) {
                return false;
            }
            l++; r--;
        }
        return true;
    }

    public static void main(String[] args) {
        String s;
        int a=0, b=0, n = cin.nextInt();

        for(int i=1; i<=n; ++i) {
            s = cin.next();
            if (isPalindrome(s)) {
                if (i%2 == 1) ++a;
                else ++b;
            }
        }

        if(a>b) System.out.println("Andi menang");
        else if (a<b) System.out.println("Budi menang");
        else System.out.println("Gaada yang menang");
    }
}
