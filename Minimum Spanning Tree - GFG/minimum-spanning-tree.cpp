//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int parent[100000];
    int setSize[100000];
    
    int find(int a){
        if(parent[a] == a)
            return a;
        return (parent[a] = find(parent[a]));
    }
    
    void UNION(int a,int b){
        a = find(a);
        b = find(b);
        if(setSize[a]<setSize[b]){
            swap(a,b);
        }
        setSize[a] += setSize[b];
        parent[b] = a;
    }
    
    void init(int n){
        for(int i=0;i<n;i++){
            parent[i] = i;
            setSize[i] = 1;
        }
    }
    static bool cmp(vector<int> a,vector<int> b){
        return a[2]<b[2];
    }
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<vector<int>> edges;
        for(int i=0;i<V;i++){
            for(auto v:adj[i]){
                if(v[0]<i){
                    edges.push_back({i,v[0],v[1]});
                }
            }
        }
        sort(edges.begin(),edges.end(),cmp);
        init(V);
        int ct = 0;
        for(auto edge:edges){
            int a = edge[0],b = edge[1],c = edge[2];
            if(find(a)!=find(b)){
                ct+=c;
                UNION(a,b);
            }
        }
        return ct;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends