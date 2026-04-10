class Solution {
public:
    int findMin(vector<int> &nums) {
        
        //binary search

        int l = 0;
        int r = nums.size()-1;
        int res = nums[0];
        while(l<=r){
            
            if(nums[l]< nums[r]){
                res = min(res,nums[l]);
                break;
            }
            int mid = l + (r - l) / 2;
            int num_mid = nums[mid];
            res = min(num_mid, res);

            if (num_mid>= nums[r]){
                l = mid+1;
            } else if (num_mid <= nums[l]){
                r = mid -1;
            }
        }

        return res;

    }
};
