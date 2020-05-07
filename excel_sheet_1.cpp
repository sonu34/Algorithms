#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define max 50
int main()
 {
	//code
	ll t;
	cin>>t;
	while(t--){
	   char s[max];
	   int n;
	   cin>>n;
	   int i=0;
	   while(n>0){
	       int rem=n%26;
	       if(rem==0){
	           s[i++]=rem + 'Z';
	           n = (n/26) - 1;
	       }else{
	           s[i++]=(rem - 1)+ 'A';
	           n/=26;
	       }
	   }
	   reverse(s,s+strlen(s));
	   cout<<s<<endl;
	}
	return 0;
}
