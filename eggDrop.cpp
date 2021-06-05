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


//Memoization
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    vector<vector<int>> dp;
    int help(int n, int k) {
        if(k<=1) return 1;
        if(n==1) return k;
        if(dp[n][k] != -1) return dp[n][k];
        
        int ans=INT_MAX;
        for(int x=k-1;x>0;x--) {
            ans = min(ans, max(help(n, k-x), help(n-1, x-1)) + 1);
        }
        return dp[n][k] = ans;
    }
    int eggDrop(int n, int k) 
    {
        // your code here || n=egg, k=floor
        dp.resize(n+1, vector<int>(k+1, -1));
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<k;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++) {
            dp[i][1]=1;
        }
        for(int i=1;i<=k;i++) {
            dp[1][i]=i;
        }
        return help(n, k);
    }
};
