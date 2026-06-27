class Solution {

private: 
    vector<vector<char>> _board;
    int _ROWS, _COLS;
    set<tuple<int,int>> path;

    bool dfs(int row, int col, int idx, string word){

        //base case
        if (idx == word.size()) return true;
        tuple<int,int> curr_pos = {row,col};

        if (row < 0 || col < 0 || 
            row>=_ROWS || col>=_COLS ||
            _board[row][col] != word[idx] || 
            path.contains(curr_pos)) {
                return false;
            }

        //Check cross-section
        path.insert(curr_pos);
        std::cout << "IDX: " << idx << "cur_pos:" << std::get<0>(curr_pos) << ", " << std::get<1>(curr_pos) << std::endl;
        bool res = dfs(row+1,col,idx+1,word) || dfs(row,col+1,idx+1,word) || 
                    dfs(row-1,col,idx+1,word) || dfs(row,col-1,idx+1,word);
        path.erase(curr_pos);
        return res;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->_board = board;
        _ROWS = board.size();
        _COLS = board[0].size();

        for (int r = 0; r<_ROWS; r++){
            for (int c = 0; c<_COLS; c++){
                
                if(dfs(r,c,0,word)) return true;

            }
        }
        
        return false;

    }
};
