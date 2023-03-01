class Solution {
public:
    void heapify(vector<int>& arr, int N, int i){
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < N && arr[l] > arr[largest])
            largest = l;
        if (r < N && arr[r] > arr[largest])
            largest = r;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, N, largest);
        }
    }
    void heapsort(vector<int>& nums){
        int n = nums.size();
        for(int i=n/2-1;i>=0;i--)
            heapify(nums,n,i);
        for(int i=n-1;i>0;i--){
            swap(nums[0],nums[i]);
            heapify(nums,i,0);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        heapsort(nums);
        return nums;
    }
};