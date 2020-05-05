//execution 0.01
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
 {
	//code
	ll t;
	cin>>t;
	while(t--){
	   int egg,f;
	   cin>>egg>>f;
	   int dp[egg+1][f+1]={0};
	   
	   for(int i=1;i<=egg;i++){
	       for(int j=1;j<=f;j++){
	           if(i==1)
	           dp[i][j]=j;
	           else if(j==1)
	           dp[i][j]=1;
	           else{
	               //cout<<i<<" "<<j<<"!!";
	               int s=0,y=INT_MAX;
	               for(int k=j-1;k>=0;k--){
	                   y=min( y, max(dp[i][s],dp[i-1][k]) );
	                   s++;
	               }
	               dp[i][j]=y+1;
	           }
	           //cout<<dp[i][j]<<" ";
	       }//cout<<endl;
	   }
	   cout<<dp[egg][f]<<endl;
	}
	return 0;
}
