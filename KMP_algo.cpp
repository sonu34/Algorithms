#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends


/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{
     //Your code here
     int ns=s.length();
     int nx=x.length();
     
     int dx[nx]={0};
     int i=0,j=1;
     
     while(j<nx){
         if(x[i]==x[j]){
             dx[j]=i+1;
             i++;
             j++;
         }else
         j++;
     }
     i=0;
     j=0;
     int f=0;
     while(i<ns){
         if(s[i]==x[j]){
             i++;
             j++;
         }
         if(j==nx){
             f=i;
             break;
         }
         else if(i < ns && x[j] != s[i]){
             if(j!=0)
             j=dx[j-1];
             else
             i++;
             //i++;
         }
         
     }
     if(f==0)
     return -1;
     else
     return f-nx;
}
