class Solution {


private:

    vector<vector<char>> _board;
    set<tuple<int,int>> _path;

    bool rrt(int r, int c, int idx, string word){


        if(idx == word.size()){
            return true;
        }

        if (r>=this->_board.size() || c>=this->_board[0].size() || r<0 || c<0 
            || this->_path.contains({r,c}) || _board[r][c] != word[idx]){
            return false;
        }
        

        _path.insert({r,c});
        //rrt up left down right
        bool val = rrt(r+1, c, idx+1, word) || rrt(r-1, c, idx+1, word)  || rrt(r, c+1, idx+1, word)  || rrt(r, c-1, idx+1, word);
        _path.erase({r,c});

        return val;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->_board = board;
        //set<tuple<int,int>> path;

        for(int r = 0; r<board.size(); r++){
            for (int c = 0; c<board[0].size(); c++){
                
                    
                if (rrt(r,c, 0, word)){
                    return true;
                }



            }
        }

        return false;
        
    }
};
