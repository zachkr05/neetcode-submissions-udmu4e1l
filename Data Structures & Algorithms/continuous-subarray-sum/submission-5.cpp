class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> _map;
        _map[0] = -1;
        int curr_num = 0;

        for (int i = 0; i <nums.size(); i++){

            //Calc remainder
            curr_num += nums[i];
            int r = curr_num % k;
            
            if (!_map.contains(r)){
                _map[r] = i;
            } else if (i - _map[r] > 1){
                return true;
            }

        }

        return false;
        
        
    }
};