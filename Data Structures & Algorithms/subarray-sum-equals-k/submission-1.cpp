class Solution {
public:

    //k
    //the whole sum of subarray = s1
    //partial sum of subarray = s2
    // s1-s2=k
    // s1-k=s2
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, currSum = 0;
        unordered_map<int, int> prefix_sum;
        prefix_sum.insert(make_pair(0,1));


        for (auto& num : nums){
            //s1
            currSum += num;
            //if there is a
            //s2
            int diff = currSum - k;
            //if s2 exists add the value
            res += prefix_sum[diff];
            //store all possible s1's
            prefix_sum[currSum]++;
        }

        return res;


    }
};