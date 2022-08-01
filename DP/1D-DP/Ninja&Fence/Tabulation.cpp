#define MOD 1000000007
#include<iostream>
using namespace std;
int add(int a, int b){
    return ( a%MOD + b%MOD )%MOD;
    
}

int mul(int a , int b){
    return ((a%MOD) * 1LL * (b%MOD))%MOD;
}


int solveTab(int n ,int k){
    vector<int> dp(n+1,0);
    dp[1]=k;
    dp[2]=add(k,mul(k,k-1));
    
    for(int i =3;i<=n;i++){
        int first=mul(dp[i-2],k-1);
        int second=mul(dp[i-1],k-1);
        int ans=add(first,second);
        dp[i]=ans; 
    }
    return dp[n];
}
 
int numberOfWays(int n, int k) {
    
    return solveTab(n,k);
}
