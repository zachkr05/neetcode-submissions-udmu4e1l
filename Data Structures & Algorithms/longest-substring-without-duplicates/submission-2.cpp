class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int res = 0;
        int window = 0;
        set<char> seen;
        
        int l = 0;
        int r = 0;

        while(r!= s.size()){
            
            char ch = s[r];
            
            if (!seen.contains(ch)){
                seen.insert(ch);
                r++;
                window++;
            }else{
                while(seen.contains(ch)){
                    
                    seen.erase(s[l]);
                    l++;
                    window--;
                }
            }

            if(window>res){
                res = window;
            }
            
        }

        return res;
        
    }
};
