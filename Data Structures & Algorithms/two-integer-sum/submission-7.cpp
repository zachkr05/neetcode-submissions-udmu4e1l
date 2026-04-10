class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> vals;

        for (size_t i = 0; i < nums.size(); i++){
            int curr_val = target - nums[i];    
            if(vals.count(curr_val) == 1){ // found match
                vector<int> ans;
                ans.push_back(vals[curr_val]);
                ans.push_back(i);
                return ans;
            }
            vals[nums[i]] = i;
        } 

    }
};
