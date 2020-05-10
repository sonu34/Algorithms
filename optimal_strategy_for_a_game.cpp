#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
 {
	//code
	ll t;
	cin>>t;
	while(t--){
	   int n;
	   cin>>n;
	   int a[n];
	   for(int i=0;i<n;i++)
	   cin>>a[i];
	   
	   pair<int,int> p;
	   vector<pair<int,int>> v1;
	   vector<vector<pair<int,int>>> vp;
	   //vector<vector<pair<int,int>>> vvp;
	   
	   for(int i=0;i<n;i++){
	       for(int j=0;j<n;j++){
	           if(i==j){
	               p.first=a[i];
	               p.second=0;
	           }
	           else{
	           p.first=0;
	           p.second=0;
	           }
	           v1.push_back(p);
	           //cout<<"("<<vp[i][j].first<<","<<vp[i][j].second<<")";
	       }vp.push_back(v1);
	       v1.clear();
	      // cout<<endl;
	   }
	   
	   for(int i=0;i<n;i++){
	       int k=0;
	       for(int j=i+1;j<n;j++){
	           
	               int f1=vp[k+1][j].second+a[k];
	               int f2=vp[k][j-1].second+a[j];
	               cout<<i<<" "<<a[k]<<" "<<a[j]<<endl;
	               vp[k][j].first= max(f1,f2);
	               
	               if( vp[k][j].first == f1 )
	               vp[k][j].second = vp[k+1][j].first;
	               else
	               vp[k][j].second = vp[k][j-1].first;
	           
	           //cout<<"("<<vp[k][j].first<<","<<vp[k][j].second<<")";
	           k++;
	       }//cout<<endl;
	   }
	   //for(int i=0;i<n;i++){
	   //    for(int j=0;j<n;j++){
	   //        cout<<"("<<vp[i][j].first<<","<<vp[i][j].second<<")";
	   //    }
	   //    cout<<endl;
	   //}
	   cout<<vp[0][n-1].first<<endl;
	}
	return 0;
}
