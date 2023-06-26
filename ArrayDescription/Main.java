import java.io.*;
import java.util.*;
import static  java.lang.Math.*;
import java.math.*;
 public class Main {
	 static void init() {
	    	try{
	    		System.setIn(new FileInputStream("C:\\Users\\Rishi\\eclipse-workspace\\RishiF\\src\\test_input.txt"));
	    		System.setOut(new PrintStream(new FileOutputStream("C:\\Users\\Rishi\\eclipse-workspace\\RishiF\\src\\output.txt")));
	    		inputStream = System.in; outputStream = System.out; 
	    		in = new InputReader(inputStream); out = new PrintWriter(outputStream);
	    	}
	    	catch(Exception e){}
	    }
	 static void closeInit() throws Exception{
	    	try {
	    	File f1=new File("C:\\Users\\Rishi\\eclipse-workspace\\RishiF\\src\\test_output.txt");
	    	File f2=new File("C:\\Users\\Rishi\\eclipse-workspace\\RishiF\\src\\output.txt");
	    	Equal e=new Equal(f1,f2);
	    	out = new PrintWriter(console);
	    	if(e.isEqual()) {
	    		out.println("Accepted");
	    	}
	    	else {
	    		out.println("Rejected");
	    	}
	    	}
	    	catch(Exception e) {System.out.println(e);}
	    }
	public static void main(String[] args)throws Exception {
//	  init();
	  int t=1;
//	   t = in.nextInt();
      for (int i = 1; i <= t ; i++) solve();	
//      out.flush();
//      closeInit();
      out.close();
	}
	
	static long mod=(int)1e9+7;
	static ArrayList<Integer>[]graph ;
	static long[]sbans=new long[2*100000+10];
	static long[]numNode=new long[2*100000+10];
	static long [] ans=new long[200001];
	public static void solve() {
		int n=in.nextInt();
		int m=in.nextInt();
		long ans=0;
		int[]arr=input(n);
		long[][]dp=new long[n+1][m+2];
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if(i==1) {
					if(arr[0]==0||arr[0]==j)dp[i][j]=1;
				}
				else {
					if(arr[i-1]==0||arr[i-1]==j) {
						dp[i][j]=((dp[i-1][j-1]+dp[i-1][j])%mod+dp[i-1][j+1])%mod;
					}
				}
			}
		}
		for(int i=1;i<=m;i++) {
			ans=(ans+dp[n][i])%mod;
		}
		println(ans);
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
	 static class Equal{	
	 	static File f1;
	 	static File f2;
	 	Equal(File f1, File f2){
	 		
	 		this.f1=f1;
	 		this.f2=f2;
	 	}
	     boolean isEqual()throws IOException {
	     	BufferedReader reader1 = new BufferedReader(new FileReader(f1.getPath()));
	         BufferedReader reader2 = new BufferedReader(new FileReader(f2.getPath()));
	          
	         String line1 = reader1.readLine();
	          
	         String line2 = reader2.readLine();
	          
	         boolean areEqual = true;
	          
	         int lineNum = 1;
	          
	         while (line1 != null || line2 != null)
	         {
	             if(line1 == null || line2 == null)
	             {
	             	System.out.println("abdbbd1");
	                 areEqual = false;
	                  
	                 break;
	             }
	             else if(! line1.trim().equalsIgnoreCase(line2.trim()))
	             {
	                 areEqual = false;
	                 break;
	             }
	              
	             line1 = reader1.readLine();
	              
	             line2 = reader2.readLine();
	              
	             lineNum++;
	         }
	         reader1.close();
	         reader2.close();
	         return areEqual;
	     }
	 }
}
