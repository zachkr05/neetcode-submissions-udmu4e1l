class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> set;
        size_t l=0;
        size_t res=0;

        for (size_t i=0; i<s.size(); i++){

            while(set.find(s[i]) != set.end()){   
                set.erase(s[l]);
                l++;
            }

            set.insert(s[i]);
            res=max(res, i-l+1);

        }

        return res;

//zxyzxyz

//

// res = 3

    }
};
