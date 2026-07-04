class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> begin = std::vector<int>(nums.begin()+1, nums.end());
        vector<int> end = std::vector<int>(nums.begin(), nums.end()-1);
        int temp = max(nums[0], dfs(begin));
        return max(temp, dfs(end));

    }

    int dfs(vector<int>& nums){

        int rob1 = 0;
        int rob2 =0;

        for (int i = 0; i<nums.size(); i++){

            int curr_rob = nums[i];

            int temp = rob1;
            rob1 = rob2;
            rob2 = max(curr_rob+temp, rob2);

        }

        return rob2;

    }
};
