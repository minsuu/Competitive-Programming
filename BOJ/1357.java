import java.util.*;
import java.io.*;
import java.math.*; 

public class Main {
    MyScanner sc;
    PrintWriter out;
 
    void sol() {
        sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        String a = (new StringBuilder(sc.next())).reverse().toString();
        String b = (new StringBuilder(sc.next())).reverse().toString();
        BigInteger ai = new BigInteger(a);
        BigInteger bi = new BigInteger(b);
        String ans = (new StringBuilder(ai.add(bi).toString())).reverse().toString();
        out.println(ans);
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
