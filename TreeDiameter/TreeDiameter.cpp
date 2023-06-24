#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<int>graph[200007];
static void dfs(int at,int pt,vector<vector<int>>&dp){
	    if(at!=0&&graph[at].size()==1)return;
	    int max1=0;int max2=0;
	    for(int child:graph[at]) {
	    	if(child==pt)continue;
	    	dfs(child,at,dp);
	    	int x=dp[child][0];
	    	if(1+x>max1) {max2=max1;max1=1+x;}
	    	else if(1+x>max2) {max2=1+x;}
	    	dp[at][2]=max(dp[at][2],dp[child][2]);
	    }
	    dp[at][0]=max1;dp[at][1]=max2;
	    dp[at][2]=max(dp[at][2],max1+max2);
	}
    
void solve(int test){
    int n;
    std::cin>>n;
    if(n==1){
        std::cout<<0;return;
    }
    for(int i=0;i<n-1;i++){
        int x,y;
        std::cin >> x;
        std::cin >> y;
        x--;y--;
        // std::cout << x <<' '<<y << '\n';
        graph[x].push_back(y);graph[y].push_back(x);
    }
    vector<vector<int>> dp(n,vector<int>(3, 0));
    dfs(0,-1,dp);
    std::cout<< dp[0][2];
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


  
    
   


    
      
    
  
     
      
  
  
 
  
    
    
        
    
    
    


