int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int i =0,j=1;
    int *array = (int *)malloc(sizeof(int)*2);
    while(i<numsSize){
        int x = target - nums[i];
        while(j<numsSize){
            if(x == nums[j] && i!=j){
                array[0] = i;
                array[1] = j;
                return array;
            }
            j++;
        }
        j = i+1;
        i++;
    }
    return 0;
}