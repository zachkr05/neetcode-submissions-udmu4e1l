class Solution {
public:
    bool validPalindrome(string s) {
        

        size_t l = 0, r = s.size()-1;

        while(l<r){

            if(s[l] != s[r]){
                return isPalindrome(s,l,r-1) || isPalindrome(s,l+1,r);
            }
            l++;
            r--;

        }

        return true;


    }


    bool isPalindrome(string& s,size_t l, size_t r){


        while(l<r){

            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;

        }

        return true;
    }

};