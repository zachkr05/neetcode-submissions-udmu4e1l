class Solution {

private:
    set<vector<int>> visited;

    void bfs(int row, int col, vector<vector<char>>& grid){

        visited.insert({row,col});
        deque<vector<int>> q;
        q.push_front({row,col});
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){

            auto it = q.front();
            int r = it[0];
            int c = it[1];
            q.pop_front();

            for(auto& curr_dir : dir){
                row = r + curr_dir[0];
                col = c + curr_dir[1];

                if(row < grid.size() && col < grid[0].size() && row >= 0 && col >= 0 &&
                grid[row][col] == '1' && (visited.find({row, col}) == visited.end())){
                    q.push_front({row,col});
                    visited.insert({row,col});
                }
            }

        }

        return;

    }

public:
    int numIslands(vector<vector<char>>& grid) {
        
        int islands=0;

        for(int r = 0; r < grid.size(); r++){
            for (int c=0; c<grid[r].size(); c++){
                
                if((visited.find({r, c}) == visited.end()) 
                && grid[r][c] == '1'){
                    bfs(r, c, grid);
                    islands +=1;
                }


            }
        }
        
        return islands;
    }
};
