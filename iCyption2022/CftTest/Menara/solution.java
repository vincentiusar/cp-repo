import java.util.*;

public class solution {

    static Scanner cin = new Scanner(System.in);

    public static void main(String[] args) {
        int n = cin.nextInt(), tinggi, dipakai, tambah;

        tinggi = 0;
        dipakai = 0;
        tambah = 2;
        
        while (dipakai <= n) {
            dipakai += tambah;
            tambah += 3;
            ++tinggi;
        }

        System.out.println(--tinggi + " " + (n-dipakai+tambah-3));
    }
}
