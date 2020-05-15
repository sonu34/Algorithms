/*3 string di hui h agr ek string A ko C string se remove kiya jaye to remaing string B hogi*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string A, string B, string C);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		cout<<isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}// } Driver Code Ends


/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this method */
//unordered_set<int> st;
int compare1(string a, string b, unordered_set<int> &st)
{
    int n = b.length(),i,j = 0;
    for(i=0;i<n;i++)
    {
        if(b[i] == a[j])
        {
            st.insert(i);
            j++;
            if(j == a.length())
                return true;
        }
    }
    return false;
}
int compare2(string a, string b, unordered_set<int> &st)
{
    int n = b.length(),i,j = 0;
    for(i=0;i<n;i++)
    {
        if(b[i] == a[j] && st.find(i) == st.end())
        {
            st.insert(i);
            j++;
            if(j == a.length())
                return true;
        }
    }
    return false;
}

bool isInterleave(string A, string B, string C) 
{
    //Your code here
    unordered_set<int> st;
    bool l = compare1(A,C,st);
    if( l && compare2(B,C,st))
        return true;
    st.clear();
    //set<int> st;
    l = compare1(B,C,st);
    if( l && compare2(A,C,st))
        return true;
    return false;
}
