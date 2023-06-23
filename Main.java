import java.io.*;
import java.util.*;
import static  java.lang.Math.*;
import java.math.*;
 public class Main {
	 
	public static void main(String[] args)throws Exception {
	  init();
	  int t = in.nextInt();
      for (int i = 1; i <= t ; i++) solve();	
      out.flush();
      closeInit();
      out.close();
	}
	static long mod=(int)1e9+7;
	static long ct;
	static ArrayList<Integer>[]graph ;
	public static void solve() {
		int n=in.nextInt();
		int m=n-1;
		graph(n,m);
		int[]dp=new int[n];
		dfs(0,-1,dp);
//		println(dp);
		int q=in.nextInt();
		for(int i=0;i<q;i++) {
			int a=in.nextInt();int b=in.nextInt();
			println((long)dp[a-1]*dp[b-1]);
		}
	}
	
		static void dfs(int at,int pt,int[]dp) {
//			println(at);
			if(at!=0&&graph[at].size()==1) {
				dp[at]=1;return;
			}
			int sum=0;
			for(int child:graph[at]) {
				if(child==pt)continue;
				dfs(child,at,dp);
				sum+=dp[child];
			}
			dp[at]=sum;
		}
		
	static HashMap<Integer,Integer>freq(int[]a){
		HashMap<Integer,Integer>h=new HashMap<>();
		for(int i=0;i<a.length;i++) {
			if(!h.containsKey(a[i]))h.put(a[i],0);
			h.put(a[i], h.get(a[i])+1);
		}
		return h;
	 }
	 static void graph(int n,int m) {
		graph=new ArrayList[n];
    	for(int i=0;i<n;i++)graph[i]=new ArrayList<>();
    	for(int i=0;i<m;i++) {
    		int x= in.nextInt();
    		int y= in.nextInt();
    		graph[x-1].add(y-1);
    		graph[y-1].add(x-1);
    	}
	 }
	 static void init() {
	    	try{
	    		System.setIn(new FileInputStream("input.txt"));
	    		System.setOut(new PrintStream(new FileOutputStream("output.txt")));
	    		inputStream = System.in; outputStream = System.out; 
	    		in = new InputReader(inputStream); out = new PrintWriter(outputStream);
	    	}
	    	catch(Exception e){}
	    }
	 static void closeInit() throws Exception{
	    	try {
	    	File f1=new File("expected.txt");
	    	File f2=new File("output.txt");
	    	Equal e=new Equal(f1,f2);
	    	if(e.isEqual()) {
	    		out.println("Accepted");
	    	}
	    	else {
	    		out.println("Rejected");
	    	}
	    	}
	    	catch(Exception e) {System.out.println(e);}
	    }
	 static long[]input(long n){long[]arr=new long[(int)n];for(int i=0;i<n;i++) {arr[i]=in.nextLong();}return arr;}
	 static void fill(int[][]arr) {for(int i=0;i<arr.length;i++) {for(int j=0;j<arr[0].length;j++) arr[i][j]=-1;}}
	 static void println(long c) {out.println(c);}
	 static void print(long c)   {out.print(c);}
	 static void print(int c) 	{out.print(c);}
	 static void println(int x) 	{out.println(x);}
	 static void print(String s) {out.print(s);}
	 static void println(String s){out.println(s);}
	 static void println(boolean b){out.println(b);}
	 static void println(int[][]arr) {for(int i=0;i<arr.length;i++) {for(int j=0;j<arr[0].length;j++)print(arr[i][j]+" "); println("");}}
	 static void println(long[][]arr) {for(int i=0;i<arr.length;i++) {for(int j=0;j<arr[0].length;j++) print(arr[i][j]+" "); print("\n");}}
	 static void println(int[]arr){for(int i=0;i<arr.length;i++)print(arr[i]+" ");print("\n");}
	 static void println(long[]arr){ for(int i=0;i<arr.length;i++) print(arr[i]+" ");print("\n"); }
	 static void println(char x) {out.println(x);}
	 static int[]input(int n){ int[]arr=new int[n];for(int i=0;i<n;i++)arr[i]=in.nextInt();return arr;} 
	 static int mini(int arr[]) {return Arrays.stream(arr).min().getAsInt();}
	 static int maxi(int arr[]) {return Arrays.stream(arr).max().getAsInt();}
	 static InputStream inputStream = System.in;
	 static OutputStream console=System.out;
	 static OutputStream outputStream = System.out;
	 static InputReader in = new InputReader(inputStream);
	 static PrintWriter out = new PrintWriter(outputStream);
	 static class InputReader {public BufferedReader reader;public StringTokenizer tokenizer;public int nextInt() {return Integer.parseInt(next());}
		 public InputReader(InputStream stream) {reader = new BufferedReader(new InputStreamReader(stream), 32768);tokenizer = null;}
		 public String next() {while (tokenizer == null||!tokenizer.hasMoreTokens()) {try {tokenizer = new StringTokenizer(reader.readLine());
	 }catch (IOException e) {throw new RuntimeException(e);}}return tokenizer.nextToken();}public long nextLong() {return Long.parseLong(next());}}
	 
	 static class Pair implements Comparable<Pair>{
		int first;int second;Pair(int f,int s){this.first=f;this.second=s;}
		public int compareTo(Pair p) {return this.first-p.first;}
	} 
}
