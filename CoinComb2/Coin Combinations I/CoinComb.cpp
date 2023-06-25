#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<long long>graph[200007];
void solve(int test){
    int n,x;cin>>n;cin>>x;
    vector<int>arr(n,0);
    int mod=1e9+7;
	for(int i=0;i<n;i++){int u;cin>>u;arr[i]=u;}
		int dp[n+1][x+1];
        for(int i=0;i<=n;i++)for(int j=0;j<=x;j++)dp[i][j]=0;
		for(int i=0;i<=n;i++) {
			for(int j=0;j<=x;j++) {
				if(i==0||j==0) {
					if(i==0)dp[i][j]=0;
					if(j==0)dp[i][j]=1;
				}
				else {
				if(i>0)dp[i][j]=(int) ((dp[i][j]+dp[i-1][j])%mod);
				if(j-arr[i-1]>=0)dp[i][j]=(int) ((dp[i][j]+dp[i][j-arr[i-1]])%mod);}
			}
		}
		cout<<(dp[n][x]);
}
int main(){
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t=1;
    // std::cin >> t;
    // cout<<t;
    for(int i=0;i<t;i++){
        solve(t);
    }
    cout<<endl;
    return 0;
}


  
    
   


    
      
    
  
     
      
  
  
 
  
    
    
        
    
    
    


