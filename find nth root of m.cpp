#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
 {
	//code
	ll t;
	cin>>t;
	while(t--){
	   ll n,m;
	   cin>>n>>m;
	   float p = (log10(m))/n;
	   float q=ceil(pow(10,p));
	   float u=floor(pow(10,p));
	   int r=pow(q,n);
	   int s=pow(u,n);
	   //cout<<s<<" "<<r<<endl;
	   if(r==m)
	   cout<<q;
	   else if(s==m)
	   cout<<u;
	   else
	   cout<<"-1";
	   cout<<endl;
	}
	return 0;
}
