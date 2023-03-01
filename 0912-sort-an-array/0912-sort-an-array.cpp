class Solution {
public:
    void countSort(vector<int> &arr){
        unordered_map<int,int> count;
        int mn = *min_element(arr.begin(),arr.end());
        int mx = *max_element(arr.begin(),arr.end());
        
        for(auto i:arr){
            count[i]++;
        }
        int idx = 0;
        for(int i=mn;i<=mx;i++){
            while(count[i]>0){
                arr[idx]=i;
                idx+=1;
                count[i]--;
            }
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        countSort(nums);
        return nums;
    }
};