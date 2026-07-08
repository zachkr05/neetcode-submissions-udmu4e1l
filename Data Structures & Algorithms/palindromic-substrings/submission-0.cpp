class Solution {
public:
    int countSubstrings(string s) {


        //start = row
        //end = columns
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(),false));

        //set diagonals as true --> all strings of length 1 are palindromes

        for (int i = 0 ; i<s.size(); i++){
            dp[i][i] = true;
        }
        int res = 0;
        //Loop through bottom right 

        for(int start = s.size(); start>=0; start--){
            for(int end = start; end<s.size(); end++){
                

                if ( s[start]==s[end]&& ((end - start <= 2) || dp[start+1][end-1]) == true){
                    dp[start][end] = true;
                    res++;
                }
            }
        }

        return res;
        
    }
};
