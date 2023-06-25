#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<int>graph[200007];
void dfs(int at,int pt,vector<int>&dis){
    if(pt!=-1) {
			dis[at]=1+dis[pt];
		}
	    if(pt!=-1&&graph[at].size()==1) {
	    	return;
	    }
	    for(int x:graph[at]) {
	    	if(x==pt)continue;
	    	dfs(x,at,dis);
	    }
}
void solve(int test){
        
		std:: cout<< endl;
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


  
    
   


    
      
    
  
     
      
  
  
 
  
    
    
        
    
    
    


