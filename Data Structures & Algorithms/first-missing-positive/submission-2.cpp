class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

       set<int> seen;

       for(auto& num : nums){
        seen.insert(num);
       }

       for (int i = 1; i<=nums.size(); i++){
        if(seen.count(i) <= 0){
            return i;
        }
       }
        return nums.size()+1;
    }
};