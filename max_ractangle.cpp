// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends

int maxhis(int arr[],int m){
    stack<int> s;
    int max=0,i;
    int area=0;
    for(i=0;i<m;){
        if( s.empty() || arr[s.top()] <= arr[i] )
        s.push(i++);
        else{
            
            int tp = s.top();
            s.pop();
            if(s.empty())
            area=arr[tp]*i;
            else
            area=arr[tp] * (i - s.top() - 1);
            //s.push(i);
            if(area>max)
            max=area;
        }
        
    }
        while(!s.empty()){
            int area=0;
            int tp = s.top();
            s.pop();
            if(s.empty())
            area=arr[tp]*i;
            else
            area=arr[tp] * (i - s.top() - 1);
            if(area>max)
            max=area;
        }
    return max;
}

/*You are required to complete this method*/
int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here
    int arr[m]={0};
    int max=0,area=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j]==0)
            arr[j]=0;
            else
            arr[j] += 1;
            //cout<<arr[j]<<" ";
        }
        //cout<<endl;
        area=maxhis(arr,m);
        if(max<area)
        max=area;
    }
    
    return max;
}
