class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        

        // cout << (int)tolower('A') - 97;

        map<vector<int>, vector<string>> freq;

        for (string curr_str : strs){
            vector<int> curr_freq(26,0);
            for(char ch : curr_str){
                curr_freq[tolower(ch) - 97]++; 
            }
            freq[curr_freq].push_back(curr_str);
        }

        vector<vector<string>> res;
        for (auto const& [key, val] : freq){
            res.push_back(val);
        }

        return res;


    }
};
