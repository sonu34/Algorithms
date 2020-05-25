// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int isValid(char *);
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        char s[10000];
        cin >> s;
        cout << isValid(s) << endl;
    }
    return 0;
}// } Driver Code Ends


/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
int rev(int num) 
{ 
    int rev_num = 0; 
    while (num > 0) 
    { 
        rev_num = rev_num*10 + num%10; 
        num = num/10; 
    } 
    return rev_num; 
}
int isValid(char *ip) {
    // your code here
    int n=strlen(ip);
    int k=1;
    int x=1,y=0;
    int cd=0;
    for(int i=0;i<n;i++){
        if((ip[i]=='.' && ip[i-1]=='.') || (ip[i]-'0')>10)
        return 0;
        if(cd>3)
        return 0;
        
        if(ip[i] == '.'){
            cd++;
            y = rev(y);
            if(y>255)
            return 0;
            k=1;
            y=0;
            x=1;
        }else{
            if(k<=3){
              if(x>1 && y==0)
              return 0;
              
              y = y + ((ip[i]-'0')*x);
              x *= 10;
              k++;
              continue;
            }else{
              return 0;
            }
        }
        
    }
    if(cd>3 || cd<3)
        return 0;
    return 1;
}
