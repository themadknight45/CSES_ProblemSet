#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<long long>graph[200007];int mod=1e9+7;
// int dp[1000][1000];
void solve(int test){
    int n;
    cin>>n;
    string str[n];
    for(int i=0;i<n;i++){
        string s; getline(cin, s);
        str[i]=s;
    }
    int dp[n][str[0].length()];
    for(int i=0;i<n;i++)for(int j=0;j<str[0].length();j++)dp[i][j]=-1;

}
int dfs(int i,int j,vector<vector<int>>dp,string str[]){
    if(i<0||j<0||i>=dp.size()||j>=dp[0].size()){
        return 1e9;
    }
    if(i==dp.size()-1&&j==dp[0].size()-1){return 0;}
    int min=
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


  
    
   


    
      
    
  
     
      
  
  
 
  
    
    
        
    
    
    


