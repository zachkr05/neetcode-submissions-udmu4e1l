class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char,char> close_to_open = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for(char ch : s){
            
            if(close_to_open.count(ch)){

                //if its a match at the top of the stack
                if(!stack.empty() && close_to_open[ch] == stack.top()){
                    stack.pop();
                } else {
                    return false;
                }

            } else{
                stack.push(ch);
            }
        }

        return stack.empty();
    }
};
