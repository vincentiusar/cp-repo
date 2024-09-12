import java.util.*;

public class solution {

    static Scanner cin = new Scanner(System.in);

    public static void main(String[] args) {

        long n = cin.nextLong(), m = cin.nextLong();

        if (n % 3 == 2 && m % 3 == 2) {
            System.out.println(n*m/3 - 1);
        } else {
            System.out.println(n*m/3);
        }
    }
}
