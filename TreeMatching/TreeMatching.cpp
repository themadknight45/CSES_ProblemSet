#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<int>graph[200007];
void dfs(int at,int pt,vector<vector<int>>&dp){
    if(at!=0&&graph[at].size()==1){
        return;
    }
    
    vector<int>ch;
    for(int child:graph[at]){
        if(child==pt)continue;
        ch.push_back(child);
        dfs(child,at,dp);
    }
    vector<int>ps(ch.size());vector<int>suff(ch.size());
    for(int i=0;i<ps.size();i++){
        ps[i]=max(dp[ch[i]][0],dp[ch[i]][1]);
        if(i>0)ps[i]+=ps[i-1];
    }
    for(int i=suff.size()-1;i>=0;i--){
        suff[i]=max(dp[ch[i]][0],dp[ch[i]][1]);
        if(i<suff.size()-1)suff[i]+=suff[i+1];
    }
    dp[at][0]=suff[0];
    int mx=1;
    if(ps.size()==1){
        mx=max(mx,1+dp[ch[0]][0]);
    }
    else 
        for (int i=0;i<ps.size();i++){
            if(i==0){mx=max(mx,1+dp[ch[i]][0]+suff[i+1]);}
            else if(i==suff.size()-1){mx=max(mx,1+dp[ch[i]][0]+ps[i-1]);}
            else  mx=max(mx,1+ps[(i-1)]+dp[ch[i]][0]+suff[i+1]);
        }   
    dp[at][1]=mx;
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
        graph[x].push_back(y);graph[y].push_back(x);
    }
    vector<vector<int>> dp(n,vector<int>(2, 0));
    dfs(0,-1,dp);
    std::cout<< max(dp[0][0],dp[0][1]);
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


  
    
   


    
      
    
  
     
      
  
  
 
  
    
    
        
    
    
    


