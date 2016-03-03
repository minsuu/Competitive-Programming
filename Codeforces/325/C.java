import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	static BigInteger x,y;
	static long[] pa = new long[1111111];
	static long[] pb = new long[1111111];
	static int pn = 0;

	final static BigInteger zero = BigInteger.ZERO;
	final static BigInteger one = BigInteger.ONE;
	final static BigInteger mone = new BigInteger("-1");

	static BigInteger egcd(BigInteger a, BigInteger b){
		BigInteger q = a.divide(b), r = a.mod(b);
		if( r.equals(zero) ){
			x = zero; y = one; return b;
		}
		BigInteger g = egcd( b, r ), t = x;
		x = y; y = t.subtract( q.multiply( y ) );
		return g;
	}

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
		BigInteger A,B,S;

		A = cin.nextBigInteger();
		B = cin.nextBigInteger();
		pn = 0;
		if( solve(A,B) ){
			String ans = new String();
			for(int i=0; i<pn; i++){
				if( pa[i] != 0 ){
					ans = ans + pa[i] + "A";
				}
				if( pb[i] != 0 ){
					ans = ans + pb[i] + "B";
				}
			}
			System.out.println(ans);
		}else System.out.println("Impossible");
	}
	
	public static boolean solve( BigInteger A, BigInteger B ){
		BigInteger g = egcd(A,B);
		if( !g.equals(one) ) return false;
		BigInteger a = zero, b = one, c = one, d = zero;
		while( !a.add(c).equals(A) || !b.add(d).equals(B) )
		{
			BigInteger kn = A.multiply(b).subtract( B.multiply(a) );
			BigInteger km = B.multiply(c).subtract( A.multiply(d) );
			BigInteger k = kn.divide(km);
			if( kn.mod(km).equals(zero) ) k = k.subtract(one);
			pa[pn] = k.longValue();
			a = a.add( k.multiply(c) ); b = b.add( k.multiply(d) );
			
			km = A.multiply(b).subtract( B.multiply(a) );
			
			kn = B.multiply(c).subtract( A.multiply(d) );
			km = A.multiply(b).subtract( B.multiply(a) );
			k = kn.divide(km);
			if( kn.mod(km).equals(zero) ) k = k.subtract(one);
			pb[pn] = k.longValue();
			c = c.add( k.multiply(a) ); d = d.add( k.multiply(b) );
			
			pn++;
		}
		return true;
	}
}

