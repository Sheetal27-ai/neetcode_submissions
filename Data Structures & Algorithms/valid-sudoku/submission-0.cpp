class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set <int> s;
        for(int i = 0; i < 9; i++){
            
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(s.count(board[i][j])){
                    return false;
                }
                s.insert(board[i][j]);
            }
            s.clear();
        }

        for(int j=0; j < 9; j++){
            for(int i =0; i < 9; i++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(s.count(board[i][j])){
                    return false;
                }
                s.insert(board[i][j]);
            }
            s.clear();
        }
        
        for(int row = 0; row < 9; row += 3){
            for(int col = 0; col < 9; col += 3){
                for(int i =0; i < 3; i++){
                    for(int j = 0 ; j < 3; j++){
                        if(board[row+i][col+j] == '.'){
                            continue;
                        }
                        if(s.count(board[row+i][col+j])){
                            return false;
                        }
                        s.insert(board[row+i][col+j]);
                    }
                }
                s.clear();
            }
        }
        return true;

    }
};
