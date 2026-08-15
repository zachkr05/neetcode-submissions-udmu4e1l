class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int len = size(nums);

        for (int i = 0; i<len+1; i++){
            if (std::ranges::find(nums, i) == nums.end()){
                return i;
            }
        }

        return 0;
    }
};
