class Solution {
public:
    bool isPalindrome(std::string s) {
        size_t i = 0;
        size_t j = s.size();

        while (i < j) {
            // Move i forward to next alphanumeric
            while (i < j && !std::isalnum(s[i])) i++;
            // Move j backward to previous alphanumeric
            while (i < j && !std::isalnum(s[j - 1])) j--;

            if (i < j) {
                if (std::tolower(s[i]) != std::tolower(s[j - 1]))
                    return false;
                i++;
                j--;
            }
        }

        return true;
    }
};
