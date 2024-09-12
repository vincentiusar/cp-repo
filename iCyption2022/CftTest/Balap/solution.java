import java.util.*;

public class solution {

    static Scanner cin = new Scanner(System.in);

    public static void main(String[] args) {
        long finish = cin.nextLong(), start_a = cin.nextLong(), start_b = cin.nextLong(), speed_a = cin.nextInt(), speed_b = cin.nextInt();

        long step_a = ((finish - start_a) / speed_a) + ((finish - start_a) % speed_a != 0 ? 1 : 0);
        long step_b = ((finish - start_b) / speed_b) + ((finish - start_b) % speed_b != 0 ? 1 : 0);

        if (step_a < step_b) {
            System.out.println("okawai koto");
        } else if (step_a > step_b) {
            System.out.println("like a man");
        } else {
            System.out.println("dokoisho");
        }
    }
}
