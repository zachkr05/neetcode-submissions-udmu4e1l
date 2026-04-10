class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, currSum = 0;
        unordered_map<int, int> prefix_sum;
        prefix_sum.insert(make_pair(0,1));


        for (auto& num : nums){
            currSum += num;
            //if there is a
            int diff = currSum - k;
            res += prefix_sum[diff];
            prefix_sum[currSum]++;
        }

        return res;


    }
};