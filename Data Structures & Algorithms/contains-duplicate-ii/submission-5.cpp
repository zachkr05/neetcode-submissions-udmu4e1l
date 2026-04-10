class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        

        //set: 1 2 
        std::unordered_set<int> set;
        int left = 0;
        int right = 1;

        
        for (int i = 0; i<nums.size()-1; i++){


            set.insert(nums[left]);
            //set.insert(nums[right]);

            if (std::abs(right - left) > k){
                set.erase(nums[left]);
                left++;
            }
            if (set.find(nums[right]) != set.end()){
                    return true;
                }
            set.insert(nums[right]);
            right++;
            } 
        set.clear();
        return false;
    }
};