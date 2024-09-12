import java.util.*;

public class solution {

    static Scanner cin = new Scanner(System.in);

    public static int min(int a, int b) {
        if (a > b) 
            return b;
        return a;
    }

    static int INF = 1000000005;
    static ArrayList< ArrayList <Integer> > g;
    static ArrayList<Integer> timeFound;

    public static void dfs(int node, int prev, int timer) {
        timeFound.set(node, min(timeFound.get(node), timer));
        for (int child : g.get(node)) {
            if (child == prev) continue;
                dfs(child, node, timer + 1);
        }
    }

    public static void main(String[] args) {
        int n = cin.nextInt(), k = cin.nextInt();

        g = new ArrayList< ArrayList <Integer> > (n);
        timeFound = new ArrayList<Integer> (n);

        for (int i = 0; i < n; i++) timeFound.add(INF);
        for (int i = 0; i < n; i++) g.add(new ArrayList<Integer>());

        int x, y;
        for (int i = 0; i < n-1; i++) {
            x = cin.nextInt(); y = cin.nextInt(); x--; y--;
            g.get(x).add(y);
            g.get(y).add(x);
        }

        for (int i = 0; i < k; i++) {
            x = cin.nextInt(); x--;
            dfs(x, -1, 0);
        }

        int maxo = Collections.max(timeFound);
        ArrayList<Integer> ans = new ArrayList<Integer> ();

        for (int i = 0; i < n; i++)
            if (timeFound.get(i) == maxo) 
                ans.add(i + 1);

        System.out.println(ans.size());
        for (int a : ans)
            System.out.print(a + " ");
        }
}
