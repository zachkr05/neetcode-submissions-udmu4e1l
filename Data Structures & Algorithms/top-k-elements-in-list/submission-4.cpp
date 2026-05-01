class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> count;
        int n = nums.size();
        for (int i = 0; i<nums.size(); i++){
                count[nums[i]]++;
        }

        cout << "a";

        vector<vector<int>> bkt(n+1);
        for(auto& [num, freq] : count){
            bkt[freq].push_back(num);
        }
        
        vector<int> res;

        for (int i = bkt.size()-1; i>=0 && res.size()<k;i--){
            for (int num : bkt[i]){
                res.push_back(num);
                if (res.size() == k){
                    break;
                }
            }
        }

        return res;


        
    }
};
