class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int l = 0;
        int r = nums.size()-1;
        int res = nums[0];

        while(l<=r){


            if(nums[l]< nums[r]){
                res = min(nums[l], res);
                break;
            }
            // norm bin search

            

            int mid = l + (r-l) /2;
            res = min(nums[mid], res);
            if(nums[l] <= nums[mid]){
                l = mid+1;
            } else{
                r = mid-1;
            }

        }

        return res;


    }
};
