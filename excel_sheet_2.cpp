#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
 {
	//code
	ll t;
	cin>>t;
	while(t--){
	   string s;
	   cin>>s;
	   int n=s.length();
	   reverse(s.begin(),s.end());
	   int ans=0,z1=1;
	   for(int i=0;i<n;i++){
	       //cout<<(int(s[i])-64)<<" ! ";
	       ans += (int(s[i])-64)*z1;
	       z1*=26;
	   }
	   cout<<ans<<endl;
	}
	return 0;
}
