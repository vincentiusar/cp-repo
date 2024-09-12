import java.util.*;

public class japa {
    public static int[][] rotate90(int[][] g) {
        int r = g.length;
        assert(r > 0);
        int c = g[0].length;
        int[][] tmp = new int[c][r];
        int p1 = 0, p2 = r-1;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                tmp[p1][p2] = g[i][j];
                p1 = (p1 + 1) % c;
            }
            p2--;
        }
        return tmp;
    }

    public static int[][] flipHor(int[][] g) {
        int r = g.length;
        assert(r > 0);
        int c = g[0].length;
        int[][] tmp = new int[r][c];
        int p1 = c-1;
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r; i++) tmp[i][p1] = g[i][j];
            p1--;
        }
        return tmp;
    }

    public static int[][] flipVer(int[][] g) {
        int r = g.length;
        assert(r > 0);
        int c = g[0].length;
        int[][] tmp = new int[r][c];
        int p1 = r-1;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) tmp[p1][j] = g[i][j];
            p1--;
        }
        return tmp;
    }

    public static boolean isEqual(int[][] a, int[][] b) {
        int R1 = a.length, R2 = b.length;
        assert(R1 > 0 && R2 > 0);
        if (R1 != R2) return false;

        int C1 = a[0].length, C2 = b[0].length;
        assert(C1 > 0 && C2 > 0);
        if (C1 != C2) return false;

        for (int i = 0; i < R1; i++)
            for (int j = 0; j < C1; j++)
                if (a[i][j] != b[i][j])
                    return false;

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r1 = sc.nextInt(), c1 = sc.nextInt();
        int[][] g1 = new int[r1][c1];
        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c1; j++)
                g1[i][j] = sc.nextInt();

        int r2 = sc.nextInt(), c2 = sc.nextInt();
        int[][] g2 = new int[r2][c2];
        for (int i = 0; i < r2; i++)
            for (int j = 0; j < c2; j++)
                g2[i][j] = sc.nextInt();

        boolean serupa = false;
        for (int i = 0; i < 4; i++) {
            if (isEqual(g1, g2)) serupa = true;
            if (isEqual(flipHor(g1), g2)) serupa = true;
            if (isEqual(flipVer(g1), g2)) serupa = true;
            g1 = rotate90(g1);
        }

        if (serupa)
            System.out.println("SERUPA");
        else
            System.out.println("TAK SERUPA");
    }
}
