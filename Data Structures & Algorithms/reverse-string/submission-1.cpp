class Solution {
public:
    void reverseString(vector<char>& s) {
        

        vector<char> new_string = s;

        for (size_t i = 0, j = s.size()-1; i<j; i++,j--){
            std::swap(s[i],s[j]);
        }


    }
};