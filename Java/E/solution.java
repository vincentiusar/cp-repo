package E;

import java.math.BigInteger;
import java.util.Scanner;

public class solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger N = sc.nextBigInteger();
        if(N.compareTo(new BigInteger("4")) == 1 ){
            System.out.println(N.subtract(new BigInteger("2")));
        }else{
            System.out.println(-1);
        }
    }
}