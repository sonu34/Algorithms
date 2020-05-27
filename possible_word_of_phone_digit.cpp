TC:4^n exe:0.08 Space:O(1)
#include <bits/stdc++.h>
#include <string>

using namespace std;

void possibleWords(int a[],int n);


int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	  possibleWords(a,N);
	   cout << endl;
	}
	
	return 0;
}// } Driver Code Ends


//Complete this function
string hashtable[] = {"", "", "abc", "def", "ghi", "jkl", 
                               "mno", "pqrs", "tuv", "wxyz"};

void permute(int a[], int curr, vector<string> &v, int n, char op[]){
    if(curr==n){
        //cout<<op<<" ";
        v.push_back(op);
        return;
    }
    for(int i=0;i<(hashtable[a[curr]]).length();i++){
        op[curr] = hashtable[a[curr]][i];
        permute(a,curr+1,v,n,op);
        if(a[curr]==0||a[curr]==1)
        return;
    }
}
void possibleWords(int a[],int N)
{
    //Your code here
    vector<string> v;
    char op[N];
    op[N]='\0';
    //string op="";
    permute(a,0,v,N,op);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
}
