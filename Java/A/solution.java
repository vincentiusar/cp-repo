package A;

import java.util.*;

public class solution {

    static Scanner cin = new Scanner(System.in);

    public static void main(String[] args) {
        List<Integer> arr = new ArrayList<>();

        int n = cin.nextInt();

        for (int i = 0; i < n; i++) {
            arr.add(cin.nextInt());
        }

        arr.sort(Collections.reverseOrder());

        int i = 0;
        while (i < n && arr.get(i).equals(arr.get(0))){
            i++;
        }

        System.out.println(arr.get(0) + " " + i);
    }
}
