//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int DP[1001][1001];
    int solve(int W,int i,int wt[],int val[]){
        if(i<0||W<=0){
            return 0;
        }
        if(DP[W][i]!=-1) return DP[W][i];
        int take=0,discard=0;
        discard = solve(W,i-1,wt,val);
        if(W>=wt[i]){
            take = solve(W-wt[i],i-1,wt,val)+val[i];
        }
        return DP[W][i] =  max(discard,take);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
        memset(DP,-1,sizeof(DP));
        int v = solve(w,n-1,wt,val);
        return v;
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends