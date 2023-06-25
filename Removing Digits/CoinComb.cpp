#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<long long>graph[200007];int mod=1e9+7;
int f(int n,int dp[]){
    // cout<<n<<"\n";
    if(n==0)return 0;
    if(n<=9)return 1;
    if(n<0)return INT32_MAX;
    string s=to_string(n);
    if(dp[n]!=-1)return dp[n];
    int mini=INT32_MAX;
    for(char x:s){
        int tmp=x-'0';
        if(tmp!=0)
         mini=min(mini,1+f(n-tmp,dp));
    }
    return dp[n]=mini;
}
void solve(int test){
    int n;cin>>n;
		int dp[n+1];
        for(int i=0;i<=n;i++)dp[i]=-1;
		cout<<f(n,dp);
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


  
    
   


    
      
    
  
     
      
  
  
 
  
    
    
        
    
    
    


