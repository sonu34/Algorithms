#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
 {
	//code
	ll t;
	cin>>t;
	while(t--){
	   int n,w;
	   cin>>n;
	   cin>>w;
	   
	   int wt[n],p[n];
	   for(int i=0;i<n;i++)
	   cin>>p[i];
	   
	   for(int i=0;i<n;i++)
	   cin>>wt[i];
	   
	   int dp[n+1][w+1];
	   for(int i=0;i<=n;i++){
	       for(int j=0;j<=w;j++){
	           if(i==0||j==0)
	           dp[i][j]=0;
	           else if( j >= wt[i-1] )
	           dp[i][j] = max( dp[i-1][j-wt[i-1]] + p[i-1] , dp[i-1][j]);
	           else
	           dp[i][j]=dp[i-1][j];
	           
	          //cout<<dp[i][j]<<" ";
	       }//cout<<endl;
	   }
	   cout<<dp[n][w]<<endl;
	}
	return 0;
}
