class Solution {
public:
    int characterReplacement(string s, int k) {
        
        //XYYX
        vector<int> freq(26, 0);
        int l = 0;
        int r = 0;
        int res = 0;
        //loop thru each character

        for(auto& ch : s){
            freq[ch - 'A']++;
            

            auto max_it = max_element(freq.begin(), freq.end());
            int max_freq = *max_it;
            while(((r-l+1) - max_freq) > k){
                freq[s[l] - 'A']--;
                l++;
            }
            r++;
            res = max(res, (r-l));
            
        }

        return res;

    }
};
