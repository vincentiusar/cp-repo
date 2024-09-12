import java.util.*;

public class solution {

    static Scanner cin = new Scanner(System.in);

    public static long sum(long a,long b){
        if ((((a % 2 != 0) && (b % 2 == 0)) || ((a % 2 == 0) && (b % 2 != 0)))){
            long c = a+b;
            long d = (b-a+1)/2;
            return c*d;
        }
        else{
            long c = (a+b)/2;
            long d = (b-a+1);
            return c*d;
        }
    }

    public static long summatrix(long i1, long j1, long i2, long j2){
        return (j2 - j1 + 1)*sum(i1,i2) + (i2 - i1 + 1)*sum(j1,j2);
    }

    public static void main(String[] args) {

        long i1,j1,i2,j2,m,n;
        m = cin.nextLong(); n = cin.nextLong();
        i1 = cin.nextLong(); j1 = cin.nextLong(); i2 = cin.nextLong(); j2 = cin.nextLong();
        long ans = summatrix(i1,j1,i2,j2);
        System.out.println(ans);
    }
}
