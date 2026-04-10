class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

       unordered_map<string, vector<string> >response;

        //initialize a count vector 
        for (const auto& word : strs){
            vector<int> count(26,0);
            for (size_t i = 0; i<word.size(); i++){
                int curr_char = static_cast<int>(word[i]);
                count[curr_char-'a']++;
            }

            string key = to_string(count[0]);
            for(int i = 1; i<count.size();i++){
                key += ',' + to_string(count[i]);
            }
            response[key].push_back(word);
        }

        vector<vector<string>> result;

        for(const auto& pair : response){
            result.push_back(pair.second);
        }

        return result;


    }
};
