class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char num){
        for(int i = 0; i < 9; i++){
            if(board[row][i] == num){
                return false;
            }
        }
        for (int i = 0; i < 9 ; i++){
            if (board[i][col] == num){
                return false;
            }
        }
        int startRow = 3 * (row / 3);
        int startCol = 3 * (col / 3);
        for(int i = 0; i < 3; i++){
            for(int j =0; j < 3; j++){
                if(board[startRow + i][startCol + j] == num){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                if(board[r][c] == '.'){
                    for(char num = '1'; num <= '9'; num++){
                        if(isValid(board,r,c,num)){
                            board[r][c] = num;
                            if(solve(board)){
                                return true;
                            }
                            board[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};