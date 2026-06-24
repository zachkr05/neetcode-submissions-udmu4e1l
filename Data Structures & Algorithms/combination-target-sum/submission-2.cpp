class Solution {



private:

    vector<vector<int>> res;

    vector<int> candidates;

    void dfs(int idx, vector<int>& curr, int remaining){

        if (remaining==0){
            res.push_back(curr);   
            return; 
        }
        for (int i = idx; i<candidates.size(); i++){

            if (candidates[i] > remaining) break;


            curr.push_back(candidates[i]);
            int curr_rem = remaining - candidates[i];

            dfs(i, curr, curr_rem);
            curr.pop_back();

        }

        return;

    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        std::sort(nums.begin(), nums.end());
        candidates = nums;    
        
        vector<int> path;

        dfs(0,path, target);

        return res;

    }
};
