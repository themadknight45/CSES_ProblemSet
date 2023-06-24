
    dp[at][1]=mx;
}
void solve(int test){
    int n;
    std::cin>>n;
    if(n==1){
        std::cout<<0;return;
    }
    for(int i=0;i<n-1;i++){