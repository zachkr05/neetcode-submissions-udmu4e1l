class Solution {
public:
    int findLucky(vector<int>& arr) {
        

        unordered_map<int, int> nums;
        int res = -1;
        for (int num : arr){
            nums[num] += 1;
        }

        for (const auto& [key, value] : nums){
            if (key == value){
                res = max(res, key);
            }
        }

        return res;
    }
};