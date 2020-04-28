#include<bits/stdc++.h>
using namespace std;

void topo(int i,vector<int> adj[],stack<int> &s,bool vis[]){
    vis[i]=true;
    for(auto it = adj[i].begin();it!=adj[i].end();it++){
        if(!vis[*it])
        topo(*it,adj,s,vis);
    }
    s.push(i);
}
int* topoSort(int v, vector<int> adj[])
{
    // Your code here
    stack<int> s;
    bool *vis = new bool[v];
    for(int i=0;i<v;i++)
    vis[i]=false;
    
    for(int i=0;i<v;i++){
        if(!vis[i])
        topo(i,adj,s,vis);
    }
    static int arr[50]; 
    int k=0;
    while(k < v){
        arr[k] = s.top();
        s.pop();
        k++;
    }
    return arr;
}


bool check(int V, int* res, vector<int> adj[]){
    bool flag =true;
    for(int i=0;i<V && flag;i++)
    {
        int n=adj[res[i]].size();
        for(auto j : adj[res[i]])
        {
            for(int k=i+1;k<V;k++)
            {
                if(res[k]==j )
                    n--;
            }
        }
        if(n!=0)
            flag =false;
    }
    if(flag==false)
        return 0;
    return 1;
}

// Driver Code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,E;
        cin>>E>>N;
        int u,v;
        
        vector<int> adj[N];
        
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
    
        int *res = topoSort(N, adj);
        
        cout<<check(N, res, adj)<<endl;
       
    }
}
