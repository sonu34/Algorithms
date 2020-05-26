TC:O(1) exe:0.01
#include<bits/stdc++.h>
using namespace std;
 
// Number of bits to represent int
#define INT_BITS 32
int maxSubarrayXOR(int [], int n);
int main()
{

    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
      scanf("%d",&n);

        for(int i=0;i<n;i++)
            {
            scanf("%d",&a[i]);
            }


   
printf("%d\n",maxSubarrayXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;


    }
}// } Driver Code Ends


// Function to return maximum XOR subset in set[]
int maxSubarrayXOR(int A[], int n)
{
    //Your code here
    int index = 0; 

    for (int i = INT_BITS-1; i >= 0; i--) 
    { 
        int maxInd = index; 
        int maxEle = INT_MIN; 
        for (int j = index; j < n; j++) 
        {  
            if ( (A[j] & (1 << i)) != 0  
                     && A[j] > maxEle ) 
                maxEle = A[j], maxInd = j; 
        } 
  //cout<<maxEle<<endl;
        if (maxEle == INT_MIN) 
        continue; 
        //cout<<"!";
        //cout<<index<<" "<<maxInd<<endl;
        swap(A[index], A[maxInd]); 
  
        maxInd = index; 
  
        for (int j=0; j<n; j++) 
        { 
            if (j != maxInd && (A[j] & (1 << i)) != 0) {
                //cout<<A[j]<<" "<<A[maxInd]<<endl;
                A[j] = A[j] ^ A[maxInd];
            }
            //cout<<A[j]<<" ";
        } //cout<<endl;
        index++; 
    }  
    int res = 0; 
    for (int i = 0; i < n; i++) 
        res ^= A[i]; 
    return res; 

}
