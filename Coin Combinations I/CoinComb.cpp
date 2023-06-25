#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
std::vector<long long>graph[200007];
long long ans[200001];
void solve(int test){
    int n;
    std::cin>>n;
    int x;
    std::cin>>x;
    vector<long long>dp(x+1,0);
    dp[0]=1;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];
    long long mod= (long)1e9+7;
    for(int i=0;i<=x;i++) {
        for(int y:arr) {
            if(i-y>=0)dp[i]=(dp[i]+dp[i-y])%mod;
        }
    }
    cout<<dp[x];
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


  
    
   


    
      
    
  
     
      
  
  
 
  
    
    
        
    
    
    


