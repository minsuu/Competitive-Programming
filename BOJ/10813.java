import java.io.*;
import java.util.*;
import java.util.stream.*;

public class Main {
    InputStream is;
    PrintWriter out;
    Boolean oj = true;

    void solve()
    {
        int[] array = IntStream.range(0, 5).toArray();
        for (int v : array) {
            System.out.println(v);
        }
        for (int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }
        List<Integer> list = IntStream.range(0, 5).boxed().collect(Collectors.toList());
        for (int v : list) {
            System.out.println(v);
        }
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }

        IntStream stream = IntStream.range(0, 5);
        stream.forEach(System.out::println);
		
		int N = ni(), M = ni();
		int[] bags = new int[N];
		for(int i=0; i<N; i++) bags[i] = i+1;
		for(int i=0; i<M; i++){
			int a = ni(), b = ni(); a--; b--;
			int t = bags[a]; bags[a] = bags[b]; bags[b] = t;
		}
		for(int i=0; i<N; i++) out.printf("%d ",bags[i]);
	}
     
    void run() throws Exception
    {
        is = System.in;
        out = new PrintWriter(System.out);
         
        long s = System.currentTimeMillis();
        solve();
        out.flush();
        tr(System.currentTimeMillis()-s+"ms");
    }
     
    public static void main(String[] args) throws Exception { new Main().run(); }
     
    private byte[] inbuf = new byte[1024];
    private int lenbuf = 0, ptrbuf = 0;
     
    private int readByte()
    {
        if(lenbuf == -1)throw new InputMismatchException();
        if(ptrbuf >= lenbuf){
            ptrbuf = 0;
            try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
            if(lenbuf <= 0)return -1;
        }
        return inbuf[ptrbuf++];
    }
     
    private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
    private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
     
    private double nd() { return Double.parseDouble(ns()); }
    private char nc() { return (char)skip(); }
     
    private String ns()
    {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
     
    private char[] ns(int n)
    {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while(p < n && !(isSpaceChar(b))){
            buf[p++] = (char)b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }
     
    private char[][] nm(int n, int m)
    {
        char[][] map = new char[n][];
        for(int i = 0;i < n;i++)map[i] = ns(m);
        return map;
    }
     
    private int[] na(int n)
    {
        int[] a = new int[n];
        for(int i = 0;i < n;i++)a[i] = ni();
        return a;
    }
     
    private int ni()
    {
        int num = 0, b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
         
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
     
    private long nl()
    {
        long num = 0;
        int b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
         
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }

    private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}
