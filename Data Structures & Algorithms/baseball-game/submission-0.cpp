class Solution {
public:
    int calPoints(vector<string>& operations) {
        

        stack<int> elements;
        int res = 0;
        //loop thru every element
        for (const string& op : operations){
            if(op == "+"){
                int prevTop = elements.top(); 
                elements.pop();
                int newTop = prevTop + elements.top();
                elements.push(prevTop);
                elements.push(newTop);
                res+=newTop;
                continue;
            } else if (op == "C"){
                res-=elements.top();
                elements.pop();
                continue;
            } else if (op == "D"){
                elements.push(2*elements.top());
                res+=elements.top();
                continue;
            }
            elements.push(stoi(op));
            res+= elements.top();
        }

        return res;
        

    }
};