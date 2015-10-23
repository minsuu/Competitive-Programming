import java.util.*;
import java.io.*;

public class Main{
	InputStream is;
	PrintWriter out;
	
	static class Edge{
		int t,rev,cap,f;
		public Edge(int t, int rev, int cap) {
			this.t = t;
			this.rev = rev;
			this.cap = cap;
		}
	}
	
	public static List<Edge>[] createGraph(int nodes){
		List<Edge>[] graph = new List[nodes];
		for(int i=0; i<nodes; i++)
			graph[i] = new ArrayList<Edge>();
		return graph;
	}

	public static void addEdge(List<Edge>[] graph, int s, int t, int cap) {
		graph[s].add( new Edge(t, graph[t].size(), cap));
		graph[t].add( new Edge(s, graph[s].size() - 1, 0));
	}
	public static void addEdge2(List<Edge>[] graph, int s, int t, int cap, int cap2) {
		graph[s].add( new Edge(t, graph[t].size(), cap));
		graph[t].add( new Edge(s, graph[s].size() - 1, cap2));
	}
	
	static boolean dinicBfs(List<Edge>[] graph, int src, int dest, int[] dist){
		Arrays.fill( dist, -1 );
		dist[src] = 0;
		int[] Q = new int[graph.length];
		int sizeQ = 0;
		Q[sizeQ++] = src;
		for(int i=0; i<sizeQ; i++){
			int u = Q[i];
			for( Edge e : graph[u] ){
				if( dist[e.t] < 0 && e.f < e.cap ){
					dist[e.t] = dist[u] +1;
					Q[sizeQ++] = e.t;
				}
			}
		}
		return dist[dest] >= 0;
	}

	static int dinicDfs(List<Edge>[] graph, int[] ptr, int[] dist, int dest, int u, int f, int d ){
		if( u==dest )
			return f;
		for( ; ptr[u] < graph[u].size(); ++ptr[u]) {
			Edge e = graph[u].get(ptr[u]);
			if( dist[e.t] == dist[u] + 1 && e.f < e.cap ){
				int df = dinicDfs( graph, ptr, dist, dest, e.t, Math.min(f, e.cap - e.f ), d+1);
				if( df > 0 ){
					e.f += df;
					graph[e.t].get(e.rev).f -= df;
					return df;
				}
			}
		}
		return 0;
	}
	
	public static int maxFlow(List<Edge>[] graph, int src, int dest) {
		int flow = 0;
		int[] dist = new int[graph.length];
		while(dinicBfs(graph, src, dest, dist)){
			int[] ptr = new int[graph.length];
			while( true ){
				int df = dinicDfs(graph, ptr, dist, dest, src, Integer.MAX_VALUE, 0);
				if( df== 0)
					break;
				flow += df;
			}
		}
		return flow;
	}
	
	private int grid(int x, int y, int z){
		return x * 100 + y * 10 + z;
	}

	void solve(){
		int tc = ni();
		while( tc-- > 0 ){
			List<Edge>[] graph = createGraph(1002);
			int s = 1000, t = 1001;
			for(int x=0; x<10; x++){
				for(int y=0; y<10; y++){
					for(int z=0; z<9; z++){
						addEdge2( graph, grid(x,y,z), grid(x,y,z+1), 1, 1 );
						addEdge2( graph, grid(x,z,y), grid(x,z+1,y), 1, 1 );
						addEdge2( graph, grid(z,x,y), grid(z+1,x,y), 1, 1 );
					}
					addEdge( graph, grid(0,x,y), t , 1);
					addEdge( graph, grid(9,x,y), t , 1);
					addEdge( graph, grid(x,0,y), t , 1);
					addEdge( graph, grid(x,9,y), t , 1);
					addEdge( graph, grid(x,y,0), t , 1);
					addEdge( graph, grid(x,y,9), t , 1);
				}
			}
			int n = ni();
			for(int i=0; i<n; i++){
				int x = ni(), y = ni(), z = ni();
				addEdge( graph, s, grid(x,y,z), 6 );
			}
			out.println( maxFlow(graph, s, t) );
			graph = null;
		}
	}
	
	private void run() throws Exception
	{
		is = System.in; out = new PrintWriter(System.out);
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }

}
