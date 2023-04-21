//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<vector<int>> activity;
        for(int i=0;i<n;i++){
            activity.push_back({start[i],end[i]});
        }
        sort(activity.begin(),activity.end(),[](const vector<int> &a,const vector<int> &b){
            return a[1]<b[1];
        });
        
        int curr = -1;
        int ct = 0;
        for(auto i:activity){
            if(curr<i[0]){
                curr = i[1];
                ct++;
            }
        }
        return ct;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends