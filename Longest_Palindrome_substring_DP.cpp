exe:0.08
#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << longestPalindrome(str) << endl;
    }
    return 0;
// User function template for C++

// A : given string
// return the required string
string longestPalindrome(string A) {
    // code here
    int n = A.length();
    bool d[n][n];
    memset(d, 0,sizeof(d));
    int result = 1;
    for(int i=0;i<n;i++)
    d[i][i] = true;
    int start=0,f=0;
    for(int i=0;i<n-1;++i){
        if(A[i]==A[i+1]){
            d[i][i+1]=true;
            if(f==0){
            f=1;
            start=i;
            result = 2;
            }
        }
    }
    for(int k=3;k<=n;++k){
        for(int i=0;i<n-k+1;++i){
            int j=k+i-1;
            if(d[i+1][j-1] && A[i]==A[j]){
                d[i][j]=true;
                
                if(k>result){
                result=k;
                start=i;
                }
            }
        }
    }
    string res="";
    for(int i=start;i<=start+result-1;i++)
    res += A[i];
    
    return res;
}
