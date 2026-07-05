class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();
        if (n == 0) return "";

        //Make a table that has start x end dimensions
        
        //self contained strings are always valid

        vector<vector<int>> dp(s.size(), vector(s.size(), 0));
        for (int i = 0; i <s.size(); i++){
            dp[i][i] = 1;
        }

        string res = s.substr(0,1); // a length of 1 is always a palindrome

        for (int start = n-1; start>=0; start--){
            for (int end = start;end<s.size();end++){

                int len = (end - start + 1);

                //check if palindrome and inner substring is a palindrome
                if(s[start] == s[end]){
                    if(len<=2 || dp[start+1][end-1] == 1){
                        dp[start][end] = 1;
                        if (res.size() < len ){
                            res = s.substr(start,len);
                        }

                    }

                    
                }
            }
        }


        return res;
    }
};
