#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<int>graph[200007];
void solve(int test){
    int n;int m;
    cin>>n;cin>>m;
    vector<vector<long long>> dp(n+1,vector<long long>(m+1, -1));
    for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if(i==j) {dp[i][j]=0;continue;}
				if(i==1) {dp[i][j]=j-1;continue;}
				if(j==1) {dp[i][j]=i-1;continue;}
				long long mini=(long)1e9;
				for(int k=1;k<=i-1;k++)mini= min(mini,dp[i-k][j]+dp[k][j]+1);
				for(int k=1;k<=j-1;k++)mini= min(mini,dp[i][j-k]+dp[i][k]+1);
				dp[i][j]=mini;
			}
		}
    int x=dp[n][m];
    cout<<x;
	cout<< endl;
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
    std::cout<<endl;
    return 0;
}


  
    
   


    
      
    
  
     
      
  
  
 
  
    
    
        
    
    
    


