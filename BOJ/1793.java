import java.util.*;
import java.io.*;
import java.math.*;

public class Main{
    MyScanner sc;
    PrintWriter out;
 
    int min(int a, int b) {
        return a < b ? a : b;
    }
    int max(int a, int b) {
        return a > b ? a : b;
    }
 
    void sol() {
        sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int N = ni();
        BigInteger a = new BigInteger("1");
        BigInteger b = new BigInteger("1");
        BigInteger c = new BigInteger("0");
        for(int i=1;i<N;i++){
            c = b.add(a); a = b; b = c;
        }
        out.println(b);
        out.close();
    }
 
    public static void main(String args[]) {
        new Main().sol();
    }
 
    class MyScanner {
        BufferedReader br;
        StringTokenizer st;
 
        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
 
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
    }
 
    int ni() {
        return Integer.parseInt(sc.next());
    }
}
