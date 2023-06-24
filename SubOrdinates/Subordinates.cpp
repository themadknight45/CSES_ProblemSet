#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int inf = 1e6;
int N = 2e5;
int M = 1e9 + 7;
vector<long long> fact(N, 0);

void factorial(){fact[0] = 1;for(long long i=1;i<N;i++) fact[i]=(fact[i-1]*i)%M;}

long long binpow(long long b,long long e, long long m){b%=m;long long res=1; while(e>0){if(e%2){res=(res*b)%m;} b=(b*b)%m; e/=2;} return res;}

long long nCr(long long n,long long r){if(n<r) return 0; long long a=fact[n]; long long  b=fact[n-r]*fact[r]; long long inv_b=binpow(b,M-2,M);return(a*inv_b)%M;}
long long nPr(long long n,long long r){if(n<r) return 0; long long a=fact[n]; long long  b=fact[n-r]; long long inv_b=binpow(b,M-2,M);return(a*inv_b)%M;}

long long neutral = 0;
template<class T>
void vprint(T a){
    for (auto i : a) cout << i << " ";
    cout << '\n';}  

template<class T>
void hprint(T h){
    for (auto i : h) cout << i.first << ":" << i.second << " ";
    cout << '\n';};

template <class T>
void print(T n, string s = "newline"){
    if(s == " ") cout << n << " ";
    else cout << n << '\n';}

vector<int>tree[200001];
void dfs(int at,int pt,vector<int>&ans){
    int sum=0;
    	for(int x:tree[at]) {
    		dfs(x,at,ans);
    		sum+=1+ans[x];
    	}
    	ans[at]=sum;
}

void solve(int test){
    int n;
    cin >>n;
    vector<int>ans(n);
    for(int i=0;i<n-1;i++){
        int par;cin>>par;
        tree[par-1].push_back(i+1);
    }
    dfs(0,-1,ans);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<"\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) solve(i);
}


  
    
   


    
      
    
  
     
      
  
  
 
  
    
    
        
    
    
    


