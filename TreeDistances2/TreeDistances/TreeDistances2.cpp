#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
std::vector<long long>graph[200007];
long long sbans[2*100000+10];
long long numNode[2*100000+10];
long long ans[200001];
static void pre(int at,int pt){
		long long sum=0;
		long long nodes=1;
		if(pt!=-1&&graph[at].size()==1) {
			sbans[at]=0;numNode[at]=nodes;return;
		}
		for(int ch:graph[at]) {
			if(ch==pt)continue;
			pre(ch,at);
			nodes+=numNode[ch];
			sum+=sbans[ch]+numNode[ch];
		}
		sbans[at]=sum;
		numNode[at]=nodes;
	}
    static void answ(int at,int pt) {
    	ans[at]=ans[pt]+numNode[0]-2*numNode[at];
    	if(graph[at].size()==0)return;
    	for(int child:graph[at]) {
    		if(child==pt)continue;
    		answ(child,at);
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
        pre(0,-1);
		ans[0]=sbans[0];
		for(int child:graph[0])answ(child,0);
		for(int i=0;i<n;i++) {
			std::cout<<ans[i]<<' ';
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


  
    
   


    
      
    
  
     
      
  
  
 
  
    
    
        
    
    
    


