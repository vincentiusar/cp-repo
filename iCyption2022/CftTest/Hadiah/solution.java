import java.util.*;

public class solution {

    static Scanner cin = new Scanner(System.in);

    static long volume(long s, long V, long a, long b){
        return s*(s+a)*(s+b) - V;
    }

    static long bisection(long lo, long hi, long V, long a, long b){
        long sol = -1; long mid;
        if (((volume(lo,V,a,b) > 0) && (volume(hi,V,a,b) > 0)) || 
        ((volume(lo,V,a,b) < 0) && (volume(hi,V,a,b) < 0))){
            sol = -1;
        }
        else{
            boolean found = false;
            while ((hi - lo > 1) && (found == false)){
                mid = (lo + hi )/2;
                if (volume(mid,V,a,b) == 0){
                    found = true;
                    sol = mid;
                }
                else if (((volume(lo,V,a,b) < 0) && (volume(mid,V,a,b) > 0)) || 
                ((volume(lo,V,a,b) > 0) && (volume(mid,V,a,b) < 0))){
                    hi = mid;
                }
                else{
                    lo = mid;
                }
            }		
        }
        return sol;
    }

    static long solve(long V, long a, long b){
        long root = bisection(0,1000000,V,a,b);
        return root;
    }

    static long area(long s, long a, long b){
        return 2*(s*(s+a) + s*(s+b) + (s+a)*(s+b));
    }


    public static void main(String[] args) {
        long V, a, b, root, q;
        q = cin.nextLong();
        for (int i = 0; i < q; i++) {
            V = cin.nextLong(); a = cin.nextLong(); b = cin.nextLong();
            root = solve(V, a, b);
            if (root != -1){
                System.out.println(area(root,a,b));
            }
            else
                System.out.println("MUSTAHIL");
        }
    }
}
