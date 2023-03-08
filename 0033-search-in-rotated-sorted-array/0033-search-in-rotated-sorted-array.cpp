class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int n = nums.size();
        int left = 0,right = n-1;
        
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]==tar)
                return mid;
            
            if(nums[left]<=nums[mid]){
                if (tar >= nums[left] && tar < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else{
                if (tar <= nums[right] && tar > nums[mid])
                    left = mid+1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};