#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// This function rotate array by D elements
// arr: input elements
// n: size of the array
int _gcd(int a, int b){
    if(b==0)
    return a;
    else
    return _gcd(b, a%b);
}
void rotateArr(int arr[], int d, int n){
    
   // Your code here
   d=d%n;
   int g = _gcd(d,n);
   //cout<<g<<"!";
   for(int i=0;i<g;i++){
       int t=arr[i];
       int j=i;
       while(1){
           int k=j+d;
           if(k>=n)
           k=k-n;
           if(k==i)
           break;
           arr[j]=arr[k];
           j=k;
       }
       arr[j]=t;
   }
}



// { Driver Code Starts.

int main() {
	//code
	
	int t;
	cin >> t;
	
	while(t--){
	    int n, d;
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    
	    rotateArr(arr, d,n);
	    
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	    
	}
	
	return 0;
