class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;

        while(start <= end)
        {
            int mid = (start+end)/2;

            //左半递增
            if(nums[mid] == target)
            {
                return mid;
            }
            //左半递增
            else if(nums[mid] >= nums[start])
            {
                if(target >= nums[start] && target < nums[mid])
                {
                    end = mid -1;
                }
                else 
                {
                    start = mid + 1;
                }
            }
            //右半递增
            //else if(arr[mid] < arr[end])
            else 
            {
                if(target <= nums[end] && target > nums[mid])
                {
                    start = mid +1;
                }
                else 
                {
                    end = mid -1;
                }
            }
        }
        return -1;
    }
};