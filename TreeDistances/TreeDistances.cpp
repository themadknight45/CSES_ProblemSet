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
    vector<int> dis(n,0);vector<int> diss(n,0);
		dfs(0,-1,dis);int n1=0;int n2=0;int max=0;
		for(int i=0;i<n;i++) {
			if(dis[i]>=max) {max=dis[i];n1=i;}
		}
		dfs(n1,-1,diss);max=0;	
		
		for(int i=0;i<n;i++) {
			if(diss[i]>=max) {max=diss[i];n2=i;}
		}
		vector<int> dis1(n,0);
		vector<int> dis2(n,0);
		dfs(n1,-1,dis1);dfs(n2,-1,dis2);
		for(int i=0;i<n;i++) {
			std::cout<< std::max(dis1[i],dis2[i]) <<' ';
		}
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


  
    
   


    
      
    
  
     
      
  
  
 
  
    
    
        
    
    
    


