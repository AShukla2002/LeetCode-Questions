class Solution {
public:
    int tribonacci(int n) {
        vector<int> nums(n+1);
        if(n==0) return 0;
        if(n==1||n==2) return 1;
        
        nums[0] = 0;
        nums[1] = 1;
        nums[2] = 1;
        for(int i=3;i<n+1;i++){
            nums[i] = nums[i-1]+nums[i-2]+nums[i-3];
        }
        return nums[n];
    }
};