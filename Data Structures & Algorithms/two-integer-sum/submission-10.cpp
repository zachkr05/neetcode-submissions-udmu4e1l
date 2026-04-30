class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // 

        //convert to a hashmap

        unordered_map<int, int> mp;

        for (int i=0; i<nums.size(); i++){
            mp[nums[i]] = i; // map of {number -> index}
            // cout << "mapped: " i
        }
        for (int i = 0; i<nums.size(); i++){

            int curr_target = target - nums[i];
            //if (curr_target == nums[i]) continue;
            auto it = mp.find(curr_target);
            if (it != mp.end() && i != it->second ){
                int val = it->second;
                cout << val;
                cout << it->first;
                return {i, val};
            }

        }

        return {0};

        //
        
    }
};
