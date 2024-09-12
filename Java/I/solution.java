package I;

import java.util.Scanner;

public class solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] eko = sc.nextLine().split(" ");
        String[] ganesh = sc.nextLine().split(" ");

        int delta = 0;

        for (int i = 0; i < eko.length; i++) {
            if ((eko[i].equals("h") && ganesh[i].equals("a")) || (eko[i].equals("a") && ganesh[i].equals("e")) || (eko[i].equals("e") && ganesh[i].equals("h"))) {
                delta++;
            } else if (!eko[i].equals(ganesh[i])) {
                delta--;
            }
        }
        System.out.println(delta == 0 ? "Draw" : delta > 0 ? "Eko wins" : "Ganesh wins");
    }
}