class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int st = 0,end = n-1;
        while(st<=end){
            int mid = st + (end-st)/2;
            
            if(arr[mid]-(mid+1)<k)
                st = mid+1;
            else
                end = mid-1;
        }
        return st+k;
    }
};